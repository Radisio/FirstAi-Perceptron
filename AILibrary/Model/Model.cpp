//
// Created by ericp on 15-03-22.
//

#include <fstream>
#include "Model.h"


Model::Model(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta) {
    this->entry = entry;
    this->layers = layers;
    this->output = output;
    this->eta = eta;
    fp = NULL;
    this->multiLayer=false;
    if(layers.size()>1)
    {
        this->multiLayer=true;
    }
}

Model::~Model(){
    if(this->fp!=NULL && this->fp != &std::cout)
    {
        delete this->fp;
    }
    this->fp =NULL;
}

void Model::initNbSynapticWeight() {
    ///Set le nombre de poids synaptiques de la première "vrai" couche (je ne compte pas l'entrée)
    /// +1 pour le w0
    this->layers[0].setNbSynapse(this->entry[0].size());
    int nbLayer = this->layers.size();
    for(int i = 1,k=0; i<nbLayer;i++,k++)
    {
        this->layers[i].setNbSynapse(this->layers[k].getNbNeurone());
    }
}

std::vector<Data> Model::evaluateOutput(std::vector<Data> singleEntry) {
    ///Il faut évaluer la sortie pour chaque layers (donc vecteur de donné)
    Util::writeLogEndline(this->fp,"EvaluateOutput");
    int nbLayer = this->layers.size();
    std::vector<Data> outputEval = this->layers[0].evaluateOutput(std::move(singleEntry));

    for (int i = 1; i<nbLayer;i++)
    {
        Util::writeLogEndline(this->fp,"Loop");
        outputEval = this->layers[i].evaluateOutput(outputEval);
    }
    Util::writeLogEndline(this->fp,"Return OutputEval");
    return outputEval;

}

void Model::debugSynapseWeight() {
    if(this->fp!=NULL) {
        int nbLayer = this->layers.size();
        for (int i = 0; i < nbLayer; i++) {
            *this->fp << "Layer : " << i << std::endl;
            this->layers[i].debugSynapseWeight(this->fp);
            *this->fp << "///////////////////////////////////" << std::endl;
        }
    }
}
void Model::debugLastOutputNeurones() {
    if(this->fp!=NULL)
    {
        *this->fp<<"LastOutputNeurones"<<std::endl;
        int nbLayer = this->layers.size();
        for (int i = 0; i < nbLayer; i++) {
            *this->fp << "Layer : " << i << std::endl;
            this->layers[i].debugLastOutputNeurones(this->fp);
            *this->fp << "///////////////////////////////////" << std::endl;
        }
    }
}


void Model::debugLog(std::string file) {
    if(this->fp!= NULL && this->fp!=&std::cout)
        delete this->fp;

    if(file=="stdout")
    {
        this->fp = &std::cout;
    }
    else{
        this->fp = new std::ofstream(file.c_str());
    }
}

std::vector<Data> Model::predict(std::vector<Data> singleEntry) {
    Util::writeLogEndline(this->fp,"Predict");
    return evaluateOutput(std::move(singleEntry));
}


void Model::save(std::string filepath) {
    std::ofstream *out = new std::ofstream(filepath.c_str(), std::ios::trunc);
    if(out->is_open())
    {
        int nbLayer = this->layers.size();
        for(int i =0;i<nbLayer;i++)
        {
            this->layers[i].save(out);
            *out<<std::endl;
        }
        out->close();
    }
    else{
        Util::writeLog(this->fp,"Erreur lors de l'ouverture du fichier pour sauvegarder");
    }
}

Model::Model(std::string filename) {
    readLayersInFile(filename);
    this->fp = NULL;

}

void Model::readLayersInFile(std::string filename) {
    std::ifstream in(filename);
    std::cout<<"ReadLayersInFile"<<std::endl;
    if(in.is_open())
    {
        std::vector<std::string> parsedLayer;
        std::string line;
        std::vector<std::string> parsedSynapse;
        std::vector<Neurone*> vNeurones;
        std::vector<std::string> infoLayer;
        while(std::getline(in,line))
        {
            infoLayer = Util::parseString(Util::parseString(line,"&&")[1],"/");
            parsedLayer = Util::parseString(line,"|");
            size_t nbNeurone = parsedLayer.size()-1;
            Seuil* s = SeuilUtil::intToSeuil(Util::stringVectorToDouble(infoLayer));

            vNeurones.clear();
            for(int i =0;i<nbNeurone;i++)
            {
                parsedSynapse = Util::parseString(parsedLayer[i],",");
                vNeurones.push_back(new Neurone(Util::stringVectorToDouble(parsedSynapse),s));

            }
            this->layers.emplace_back(vNeurones);
        }
    }
}

void Model::zeroDw() {
    int nbLayer = this->layers.size();
    for(int i =0;i<nbLayer;i++)
    {
        this->layers[i].setZeroDw();
    }

}

bool Model::modelValid() {
    ///Vérifie que le nombre de sortie par itération soit égale au nombre de neurone de la couche de sortie
    int lastLayer = this->layers.size()-1;
    return this->layers[lastLayer].getNbNeurone()==this->output[0].size();
}


std::vector<std::vector<double>> Model::getSynapseLastLayer() {
    int lastLayer = this->layers.size()-1;
    int nbNeurone = this->layers[lastLayer].getNbNeurone();
    std::vector<std::vector<double>> returnedVector;
    for(int i =0;i<nbNeurone;i++)
    {
        returnedVector.push_back(this->layers[lastLayer].getSynapseNeurone(i));
    }
    return returnedVector;
}

Seuil *Model::getSeuilLastLayer() {
    int lastLayer = this->layers.size()-1;
    return this->layers[lastLayer].getSeuilNeurones();
}

double Model::getDerive(int i,double x) {
    if(dynamic_cast<SeuilSigmoide*>(this->layers[i].getSeuilNeurones())!= nullptr) {
        return dynamic_cast<SeuilSigmoide*>(this->layers[i].getSeuilNeurones())->getC()*x*(1-x);
    }
    if(dynamic_cast<SeuilTangeanteHyperbolique*>(this->layers[i].getSeuilNeurones())!= nullptr) {
        return 1-(x*x);
    }
    if(dynamic_cast<SeuilIdentite*>(this->layers[i].getSeuilNeurones())!= nullptr) {
        return 1;
    }
    return x;
}



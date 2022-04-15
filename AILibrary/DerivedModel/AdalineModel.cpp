//
// Created by ericp on 30-03-22.
//

#include "AdalineModel.h"

AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta,
                           double seuilMin) : Model(entry, layers, output, eta) {
    this->seuilMin=seuilMin;
    this->stopWhenNoError=false;
}

AdalineModel::AdalineModel(std::string filename) : Model(filename) {

}
AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta)
            : Model(entry,layers,output,eta){
    this->stopWhenNoError=true;

}

void AdalineModel::correction(std::vector<Data> line, double error, int i) {
    int lastLayer = this->layers.size()-1;
    ///Correction poids synaptique dernière couche
    if(this->multiLayer)
    {
        /// Calcul signal neurone couche sortie
            double z = this->layers[lastLayer].getLastOutputNeurone(i).getNumericData();
            double deltamin = error*z*(1-z);

        ///Calcul signaux couches cachée



        ///Correction
    }
    for(int j = lastLayer;j>=0;j--)
    {
        this->layers[j].correction(line,this->eta, error,i);
    }
}
void AdalineModel::correction(std::vector<Data> line, std::vector<double> errorVec) {
    int lastLayer = this->layers.size()-1;
    std::cout<<"ON CORRIGE"<<std::endl;
    ///Correction poids synaptique dernière couche
    if(this->multiLayer)
    {
        std::cout<<"MULTILAYER"<<std::endl;
        int nbLayer = this->layers.size();
        /// Calcul signal neurone couche sortie
        int nbNeurone;
        nbNeurone = this->layers[lastLayer].getNbNeurone();
        std::vector<double> signalsOutputLayer;
        for(int i = 0;i<nbNeurone;i++) {
            std::cout<<"AHHH"<<std::endl;
            double z = this->layers[lastLayer].getLastOutputNeurone(i).getNumericData();
            std::cout<<"AHHH z = "<<z<<std::endl;
            std::cout<<"On va push dans signal neurone couche sortie : " <<errorVec[i] * z * (1 - z)<<std::endl;
            std::cout<<"ErrorVec["<<i<<"]="<<errorVec[i]<<std::endl;
            signalsOutputLayer.push_back(errorVec[i] * z * (1 - z));
            std::cout<<"AHHH"<<std::endl;

        }
        std::cout<<"ON A CALCULE LES SIGNAUX DE LA COUCHE DE SORTIE"<<std::endl;

        ///Calcul signaux couches cachée
        int firstHiddenLayer = lastLayer-1;
        std::vector<std::vector<double>> signalLayers;
        std::vector<std::vector<Data>> outputLayersNeurones;
        signalLayers.push_back(signalsOutputLayer);
        std::vector<double> signalHiddenLayer;
        std::vector<double> synapses;
        std::vector<std::vector<double>> synapsesLayer;
        std::vector<Data> outputNeurones;
        size_t size;
        double tmp;
        for(int i = firstHiddenLayer,k=0,a=i+1;i>=0;i--,k++,a++)
        {
            signalHiddenLayer.clear();
            nbNeurone = this->layers[i].getNbNeurone();
            outputNeurones.clear();
            synapsesLayer = this->layers[a].getSynapsesLayer();
            for(int j = 0; j <nbNeurone;j++) {
                tmp = 0.0;
                synapses.clear();
                double yc = this->layers[i].getLastOutputNeurone(j).getNumericData();
                outputNeurones.push_back(this->layers[i].getLastOutputNeurone(j));
                // phi'(k_c)= y_c(1-yc)
                // delta_j(C) = phi'(k_j)( delta_1(C-1)*w1+delta_2*w2+...+delta_n*w_n)
                //synapses=this->layers[i].getSynapseNeurone(j);
                synapses = Util::getAllXFromTab(synapsesLayer,j);
                size = synapses.size();
                for(int b = 0;b<size;b++)
                {
                    tmp+=signalLayers[k][a]*synapses[a];
                }
                signalHiddenLayer.push_back((yc*(1-yc))*(tmp));
            }
            signalLayers.push_back(signalHiddenLayer);
            outputLayersNeurones.push_back(outputNeurones);
        }
        outputLayersNeurones.push_back(line);
        std::cout<<"ON A CALCULE LES SIGNAUX DE LA COUCHE CACHE"<<std::endl;
        std::cout<<"Signal layer size : " << signalLayers.size()<<std::endl;
        std::cout<<"Output layers neurones size : " << outputLayersNeurones.size()<<std::endl;


        std::cout<<"SIGNAL LAYERS ="<<std::endl;
        for(int i = 0 ; i<signalLayers.size();i++)
        {
            for(int j = 0;j<signalLayers[i].size();j++)
            {
                std::cout<<"SignalLayer["<<i<<"]["<<j<<"]="<<signalLayers[i][j]<<std::endl;
            }
        }

        ///Correction
            /// Couche de sortie
        nbNeurone = this->layers[lastLayer].getNbNeurone();
        for(int i=0;i<nbNeurone;i++)
        {
            std::cout<<"On corrige la couche "<<lastLayer<< " et le neurone " << i << std::endl;
            std::cout << "Signal Layers ["<<0<<"]["<<i<<"]=" << signalLayers[0][i]<<std::endl;
            this->layers[lastLayer].correction(outputLayersNeurones[0],this->eta, signalLayers[0][i],i);
        }
        std::cout<<"ON A CORRIGE LES POIDS DE LA COUCHE DE SORTIE"<<std::endl;
        for(int i =lastLayer-1,k=1;i>=0;i--,k++)
        {
            nbNeurone = this->layers[i].getNbNeurone();
            for(int j =0;j<nbNeurone;j++)
            {
                std::cout<<"On corrige la couche "<<i<< " et le neurone " << j << std::endl;
                std::cout << "Signal Layers ["<<k<<"]["<<j<<"]=" << signalLayers[k][j]<<std::endl;
                this->layers[i].correction(outputLayersNeurones[k],this->eta,signalLayers[k][j],j);
            }
        }
    }
    else{
        int nbNeurone = this->layers[lastLayer].getNbNeurone();
        for(int i=0;i<nbNeurone;i++) {
            this->layers[lastLayer].correction(line, this->eta, errorVec[i],i);
        }
    }
}
void AdalineModel::fit(int maxIteration) {
    int nbIter = 0;
    std::vector<double> emoy;
    int nbExemple = this->output.size();
    int nbOutput = this->output[0].size();
    bool errorBool = false;
    bool loop = false;
    std::vector<double> errorVec;
    Seuil* seuil = getSeuilLastLayer();

    do{
        emoy=setEmoy0(nbOutput);
        errorBool = false;
        for(int i = 0; i < nbExemple; i++) {
            std::vector<Data> y = this->evaluateOutput(this->entry[i]);
            errorVec.clear();
            for(int j =0;j<nbOutput;j++)
            {
               // double y = this->evaluateOutput(this->entry[i])[j].getNumericData();
                double error = this->output[i][j].getNumericData() - y[j].getNumericData();
                errorVec.push_back(error);
                errorBool = errorBool || seuil->seuiledValue(y[j].getNumericData())!= this->output[i][j].getNumericData();
                emoy[j] += (error * error) / 2;
                //correction(this->entry[i], error,j);
            }
            correction(this->entry[i],errorVec);
            debugSynapseWeight();
            Util::writeLogEndline(this->fp,"Iteration num :"+std::to_string(nbIter));
        }
        emoy= divideEmoyByNbExemple(emoy,nbExemple);
        nbIter++;
        loop = this->stopWhenNoError?errorBool:!allEmoyBelowSeuil(emoy) ;
    }while(loop && nbIter<maxIteration);
    std::cout<<"Debug"<<std::endl;
    std::cout<<"Emoy:"<<std::endl;
    for(int i =0;i<nbOutput;i++)
    {
        std::cout<<"Emoy ["<<i<<"]:"<<emoy[i]<<std::endl;
    }

}



void AdalineModel::correction(std::vector<Data> vector, double d) {

}

std::vector<double> AdalineModel::divideEmoyByNbExemple(std::vector<double> emoy, int nbExemple) {
    int emoySize = emoy.size();
    std::vector<double> emoyReturned;
    for(int i =0;i<emoySize;i++)
    {
        emoyReturned.push_back(emoy[i]/nbExemple);
    }
    return emoyReturned;
}

bool AdalineModel::allEmoyBelowSeuil(std::vector<double> emoy) {
    int emoySize = emoy.size();
    for(int i =0;i<emoySize;i++)
    {
        if(emoy[i]>=this->seuilMin)
        {
            return false;
        }
    }
    return true;
}

std::vector<double> AdalineModel::setEmoy0(int size) {
    std::vector<double> returnedEmoy;
    for(int i =0;i<size;i++)
    {
        returnedEmoy.push_back(0);
    }
    return returnedEmoy;
}





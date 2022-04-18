//
// Created by ericp on 29-03-22.
//

#include "DGModel.h"
#include "../ModelBase/WGeneratorFunction.h"

DGModel::DGModel(std::string filename) : Model(filename) {

}

DGModel::DGModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta, double seuilMin) : Model(entry,layers,output,eta){
    this->seuilMin= seuilMin;
    this->stopWhenNoError=false;

}
DGModel::DGModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta) : Model(entry,layers,output,eta){
    this->stopWhenNoError=true;
}
void DGModel::correction(std::vector<Data> vector, double d) {

}

void DGModel::fit(int maxIteration) {
    int nbExemple = this->output.size();
    int nbOutput = this->output[0].size();
    bool errorBool = false;
    bool loop = false;
    int nbLayer = this->layers.size();
    int lastLayer = nbLayer-1;
    std::vector<double> emoy;
    int nbIter=0;
    std::vector<double> errorVec;

    Seuil* seuil = getSeuilLastLayer();
    do{
        emoy=setEmoy0(nbOutput);
        zeroDw();
        errorBool = false;
        std::vector<Data> yVec;
        for(int i = 0;i<nbExemple;i++) {
            yVec = this->evaluateOutput(this->entry[i]);
            errorVec.clear();
            for (int j = 0; j < nbOutput; j++) {
                //double y = this->evaluateOutput(this->entry[i])[j].getNumericData();
                double error = this->output[i][j].getNumericData() - yVec[j].getNumericData();
                errorVec.push_back(error);
                //this->layers[lastLayer].setDwToNeurone(this->entry[i], this->eta, error,j);
                errorBool = errorBool || seuil->seuiledValue(yVec[j].getNumericData()) != this->output[i][j].getNumericData();
                emoy[j] += (error * error)/2;
            }
            setDwToLayers(this->entry[i],errorVec);
        }
        ///Correction des poids synaptiques
        for(int i = 0;i<nbLayer;i++)
        {
            this->layers[i].correctionWDW();
        }

        for(int i = 0;i<emoy.size();i++)
        {
            std::cout<<"Emoy ["<<i<<"] : " << emoy[i]<<std::endl;
        }
        emoy= divideEmoyByNbExemple(emoy,nbExemple);
        nbIter++;
        for(int i = 0;i<emoy.size();i++)
        {
            std::cout<<"Emoy ["<<i<<"] : " << emoy[i]<<std::endl;
        }
       // debugSynapseWeight();
        loop = this->stopWhenNoError?errorBool:!allEmoyBelowSeuil(emoy) ;
        std::cout<<"NbIter = " << nbIter<<std::endl;
    }while(loop&& nbIter<maxIteration);

}


std::vector<double> DGModel::divideEmoyByNbExemple(std::vector<double> emoy, int nbExemple) {
    int emoySize = emoy.size();
    std::vector<double> emoyReturned;
    for(int i =0;i<emoySize;i++)
    {
        emoyReturned.push_back(emoy[i]/nbExemple);
    }
    return emoyReturned;
}

bool DGModel::allEmoyBelowSeuil(std::vector<double> emoy) {
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

std::vector<double> DGModel::setEmoy0(int size) {
    std::vector<double> returnedEmoy;
    for(int i =0;i<size;i++)
    {
        returnedEmoy.push_back(0);
    }
    return returnedEmoy;
}

void DGModel::correction(std::vector<double> errorVec) {
    int lastLayer = this->layers.size()-1;
    if(this->multiLayer){
        int nbLayer = this->layers.size();
        /// Calcul signal neurone couche sortie
        int nbNeurone;
        nbNeurone = this->layers[lastLayer].getNbNeurone();
        std::vector<double> signalsOutputLayer;
        for(int i = 0;i<nbNeurone;i++) {
            double z = this->layers[lastLayer].getLastOutputNeurone(i).getNumericData();
            signalsOutputLayer.push_back(errorVec[i] * z * (1 - z));
        }
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
        int nbNeuroneLastLayer = this->layers[lastLayer].getNbNeurone();
        outputNeurones.clear();
        for(int i = 0;i<nbNeuroneLastLayer;i++)
        {
            outputNeurones.push_back(this->layers[lastLayer].getLastOutputNeurone(i));
        }
        outputLayersNeurones.push_back(outputNeurones);

        ///Correction
        /// Couche de sortie
        nbNeurone = this->layers[lastLayer].getNbNeurone();

        for(int i=0;i<nbNeurone;i++)
        {
            this->layers[lastLayer].correction(outputLayersNeurones[0],this->eta, signalLayers[0][i],i);
        }

        for(int i =lastLayer-1,k=1;i>=0;i--,k++)
        {
            nbNeurone = this->layers[i].getNbNeurone();
            for(int j =0;j<nbNeurone;j++)
            {
                this->layers[i].correction(outputLayersNeurones[k],this->eta,signalLayers[k][j],j);
            }
        }
    }
    else{
        for(int j = lastLayer;j>=0;j--)
        {
            this->layers[j].correctionWDW();
        }
    }
}

void DGModel::correction(std::vector<Data> vector, std::vector<double> vector1) {

}

void DGModel::setDwToLayers(std::vector<Data> entry,std::vector<double> errorVec) {
    int lastLayer = this->layers.size()-1;
    if(this->multiLayer)
    {
        int nbLayer = this->layers.size();
        /// Calcul signal neurone couche sortie
        int nbNeurone;
        nbNeurone = this->layers[lastLayer].getNbNeurone();
        std::vector<double> signalsOutputLayer;
        for(int i = 0;i<nbNeurone;i++) {
            double z = this->layers[lastLayer].getLastOutputNeurone(i).getNumericData();
            signalsOutputLayer.push_back(errorVec[i] * z * (1 - z));
        }
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
        outputLayersNeurones.push_back(entry);

        ///Set signals as DW to each layers (and each neurones)
        nbNeurone = this->layers[lastLayer].getNbNeurone();
        for(int i=0;i<nbNeurone;i++)
        {
            this->layers[lastLayer].setDwToNeurone(outputLayersNeurones[0],this->eta, signalLayers[0][i],i);
        }
        for(int i =lastLayer-1,k=1;i>=0;i--,k++)
        {
            nbNeurone = this->layers[i].getNbNeurone();
            for(int j =0;j<nbNeurone;j++)
            {
                this->layers[i].setDwToNeurone(outputLayersNeurones[k],this->eta,signalLayers[k][j],j);
            }
        }
    }
    else{
        int nbNeurone = this->layers[lastLayer].getNbNeurone();
        for(int i = 0;i<nbNeurone;i++)
            this->layers[lastLayer].setDwToNeurone(entry, this->eta, errorVec[i],i);

    }

}

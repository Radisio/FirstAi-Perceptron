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
    do{
        emoy=setEmoy0(nbOutput);
        zeroDw();
        errorBool = false;

        for(int i = 0;i<nbExemple;i++) {
            for (int j = 0; j < nbOutput; j++) {
                double y = this->evaluateOutput(this->entry[i])[j].getNumericData();
                double error = this->output[i][j].getNumericData() - y;
                this->layers[lastLayer].setDwToNeurone(this->entry[i], this->eta, error,j);
                errorBool = errorBool || y != this->output[i][j].getNumericData();
                std::cout<<"Sortie attendue : " << this->output[i][j].getData()<<" donc errorBool = " << errorBool<<std::endl;
                std::cout << "Sortie : " << y << " sortie attendue : " << this->output[i][j].getData() << std::endl;    emoy[j] += (error * error) / 2;
            }
        }
        std::cout<<"On corrige"<<std::endl;
        ///Correction des poids synaptiques
        for(int j = lastLayer;j>=0;j--)
        {
            this->layers[j].correctionWDW();
        }
        emoy= divideEmoyByNbExemple(emoy,nbExemple);
        nbIter++;
        std::cout<<"SeuilMin" << this->seuilMin<<std::endl;
        debugSynapseWeight();
        loop = this->stopWhenNoError?errorBool:!allEmoyBelowSeuil(emoy) ;
        std::cout<<"Loop = " << loop<<std::endl;
    }while(loop&& nbIter<maxIteration);

}

std::vector<Data> DGModel::predict(std::vector<Data> vector) {
    std::vector<Data> response= Model::predict(vector);
    int size = response.size();
    for(int i =0;i<size;i++)
    {
        response[i].setData(std::to_string(response[i].getNumericData()>=0));
    }
    return response;
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




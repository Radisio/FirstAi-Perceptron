//
// Created by ericp on 29-03-22.
//

#include "DGModel.h"
#include "../ModelBase/WGeneratorFunction.h"
DGModel::DGModel(std::string filename) : Model(filename) {

}

DGModel::DGModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<Data> output, double eta, double seuilMin) : Model(entry,layers,output,eta){
    this->seuilMin= seuilMin;
}

void DGModel::correction(std::vector<Data> vector, double d) {

}

void DGModel::fit(int maxIteration) {
    int nbOutput = this->output.size();
    int nbLayer = this->layers.size();
    int lastLayer = nbLayer-1;
    double emoy;
    int nbIter=0;
    do{
         emoy = 0.0;
        zeroDw();
        for(int i = 0;i<nbOutput;i++) {
            double y = this->evaluateOutput(this->entry[i])[0].getNumericData();
            double error = this->output[i].getNumericData() - y;
            this->layers[lastLayer].setDwToNeurone(this->entry[i],this->eta,error);
            std::cout<<"Sortie : " << y << " sortie attendue : " << this->output[i].getData()<<std::endl;
            std::cout<<"error " << error <<std::endl;

            emoy += (error * error) / 2;

        }
        std::cout<<"emoy"<<emoy<<std::endl;
        std::cout<<"On corrige"<<std::endl;
        ///Correction des poids synaptiques
        for(int j = 0;j< nbLayer;j++)
        {
            this->layers[j].correctionWDW();
        }
        emoy /= nbOutput;
        nbIter++;
        std::cout<<"Emoy : "<<emoy<<std::endl;
        std::cout<<"SeuilMin" << this->seuilMin<<std::endl;
        debugSynapseWeight();
    }while(emoy>this->seuilMin && nbIter<maxIteration);

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


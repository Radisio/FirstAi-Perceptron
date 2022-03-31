//
// Created by ericp on 30-03-22.
//

#include "AdalineModel.h"

AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<Data> output, double eta,
                           double seuilMin) : Model(entry, layers, output, eta) {
    this->seuilMin=seuilMin;
}

AdalineModel::AdalineModel(std::string filename) : Model(filename) {

}

void AdalineModel::correction(std::vector<Data> line, double error) {
    int nbLayer = this->layers.size();
    for(int j = 0;j<nbLayer;j++)
    {
        this->layers[j].correction(line,this->eta, error);
    }
}

void AdalineModel::fit(int maxIteration) {
    int nbIter = 0;
    double emoy;
    int nbOutput = this->output.size();
    do{
        emoy = 0.0;
        for(int i = 0;i<nbOutput;i++) {
            double y = this->evaluateOutput(this->entry[i])[0].getNumericData();
            double error = this->output[i].getNumericData() - y;
            emoy += (error * error) / 2;
            correction(this->entry[i], error);
            debugSynapseWeight();
            Util::writeLogEndline(this->fp,"Iteration num :"+std::to_string(nbIter));
        }
        emoy /= nbOutput;
        Util::writeLogEndline(this->fp,"emoy :"+std::to_string(emoy));
        nbIter++;
    }while(emoy>this->seuilMin && nbIter<maxIteration);

}

std::vector<Data> AdalineModel::predict(std::vector<Data> vector) {
    return Model::predict(vector);
}

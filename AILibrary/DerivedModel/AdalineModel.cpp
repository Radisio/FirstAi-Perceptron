//
// Created by ericp on 30-03-22.
//

#include "AdalineModel.h"

AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta,
                           double seuilMin) : Model(entry, layers, output, eta) {
    this->seuilMin=seuilMin;
    setSeuil(new SeuilPReLu(-1,1));
    this->stopWhenNoError=false;
}

AdalineModel::AdalineModel(std::string filename) : Model(filename) {

}
AdalineModel::AdalineModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta)
            : Model(entry,layers,output,eta){
    this->stopWhenNoError=true;
    setSeuil(new SeuilPReLu(-1,1));

}

void AdalineModel::correction(std::vector<Data> line, double error, int i) {
    int lastLayer = this->layers.size()-1;
    ///Correction poids synaptique dernière couche

    for(int j = lastLayer;j>=0;j--)
    {
        this->layers[j].correction(line,this->eta, error,i);
    }
}

void AdalineModel::fit(int maxIteration) {
    int nbIter = 0;
    std::vector<double> emoy;
    int nbExemple = this->output.size();
    int nbOutput = this->output[0].size();
    bool errorBool = false;
    bool loop = false;

    do{
        emoy=setEmoy0(nbOutput);
        errorBool = false;
        for(int i = 0; i < nbExemple; i++) {
            for(int j =0;j<nbOutput;j++)
            {
                double y = this->evaluateOutput(this->entry[i])[j].getNumericData();
                double error = this->output[i][j].getNumericData() - y;
                std::cout<<"Error = " << error << " / Error seuille = " << this->seuil->seuil(error)<<std::endl;
                errorBool = errorBool || this->seuil->seuil(error) != this->output[i][j].getNumericData();
                std::cout<<"Sortie attendue : " << this->output[i][j].getData()<<" donc errorBool = " << errorBool<<std::endl;
                emoy[j] += (error * error) / 2;
                correction(this->entry[i], error,j);
            }
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

std::vector<Data> AdalineModel::predict(std::vector<Data> vector) {
    return Model::predict(vector);
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



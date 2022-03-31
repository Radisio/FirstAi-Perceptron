//
// Created by ericp on 22-03-22.
//

#include "PerceptronModel.h"

void PerceptronModel::fit(int maxIteration) {
    int nbErrorMax = this->maxErrorAllowed;
    int nbError = nbErrorMax+1;
    int nbOutput = this->output.size();
    int nbIter = 0;
    while((nbError>nbErrorMax) && (nbIter<maxIteration))
    {
        nbError=0;
        for(int i = 0;i<nbOutput;i++)
        {
            ///Sortie du perceptron = somme de tous les wi.xi (x0 = seuil)
            double potentiel = this->evaluateOutput(this->entry[i])[0].getNumericData();
            double y = potentiel>=0;
            double error = this->eta*(this->output[i].getNumericData() - y);
            if(error!=0)
            {
                this->correction(this->entry[i],error);
                nbError++;
            }
            this->debugSynapseWeight();
        }
        std::cout<<"NBError = " << nbError<<std::endl;
        nbIter++;
    }

}


void PerceptronModel::correction(std::vector<Data> line, double error) {
    int nbLayer = this->layers.size();
    for(int i =0;i<nbLayer;i++)
    {
        this->layers[i].correction(line,this->eta,error);
    }


}

PerceptronModel::PerceptronModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<Data> output, double eta,
                                 int maxErrorAllowed) : Model(entry, layers, output, eta){
    this->maxErrorAllowed = maxErrorAllowed;
}

std::vector<Data> PerceptronModel::predict(std::vector<Data> vector) {
    std::vector<Data> response= Model::predict(vector);
    int size = response.size();
    for(int i =0;i<size;i++)
    {
        response[i].setData(std::to_string(response[i].getNumericData()>=0));
    }
    return response;
}

PerceptronModel::PerceptronModel(std::string filename) : Model(filename){
}

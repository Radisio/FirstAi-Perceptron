//
// Created by ericp on 22-03-22.
//

#include "PerceptronModel.h"

void PerceptronModel::fit(int maxIteration) {
    int nbErrorMax = this->maxErrorAllowed;
    int nbError = nbErrorMax+1;
    int nbExample = this->output.size();
    int nbOutput = this->output[0].size();
    int nbIter = 0;
    while((nbError>nbErrorMax) && (nbIter<maxIteration))
    {
        nbError=0;
        for(int i = 0; i < nbExample; i++)
        {
            for(int j=0;j<nbOutput;j++)
            {
                ///Sortie du perceptron = somme de tous les wi.xi (x0 = seuil)
                double y = this->evaluateOutput(this->entry[i])[j].getNumericData();
                double error = this->eta*(this->output[i][j].getNumericData() - y);
                if(error!=0)
                {
                    std::cout<<"On corrige"<<std::endl;
                    this->correction(this->entry[i],error);
                    nbError++;
                }
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

PerceptronModel::PerceptronModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<std::vector<Data>> output, double eta,
                                 int maxErrorAllowed) : Model(entry, layers, output, eta){
    this->maxErrorAllowed = maxErrorAllowed;
}


PerceptronModel::PerceptronModel(std::string filename) : Model(filename){
}

void PerceptronModel::correction(std::vector<Data> vector, std::vector<double> vector1) {

}


//
// Created by ericp on 22-03-22.
//

#include "SimpleModel.h"

void SimpleModel::fit() {
    int nbErrorMax = this->maxErrorAllowed;
    int nbError = nbErrorMax+1;
    int nbOutput = this->output.size();
    while(nbError>nbErrorMax)
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
    }

}


void SimpleModel::correction(std::vector<Data> output,double error) {
    int nbLayer = this->layers.size();
    for(int i =0;i<nbLayer;i++)
    {
        this->layers[i].correction(output,this->eta,error);
    }


}

SimpleModel::SimpleModel(std::vector<std::vector<Data>> entry, std::vector<Layer> layers, std::vector<Data> output, double eta,
                         int maxErrorAllowed) : Model(entry, layers, output, eta){
    this->maxErrorAllowed = maxErrorAllowed;
}

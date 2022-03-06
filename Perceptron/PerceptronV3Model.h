//
// Created by ericp on 06-03-22.
//

#ifndef MYIALIBRARY_PERCEPTRONV3MODEL_H
#define MYIALIBRARY_PERCEPTRONV3MODEL_H


#include "../AILibrary/ModelBase/ModelBase.h"
#include <vector>
class PerceptronV3Model : public ModelBase {
private:

    int sigma;
    int mean;
public:
    PerceptronV3Model(const Dataset &dataset, int resultCol, double eta, double seuil, double sigma = 1.0, double mean=0.0);

    void fit(double) override;
    void fit(double seuilMin,int maxIteration);
    double predict(double d, double d1) override;


void correctW(int i, double error);
};

#endif //MYIALIBRARY_PERCEPTRONV3MODEL_H

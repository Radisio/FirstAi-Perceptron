//
// Created by ericp on 15-02-22.
//

#ifndef MYIALIBRARY_PERCEPTRONV2MODEL_H
#define MYIALIBRARY_PERCEPTRONV2MODEL_H


#include "../AILibrary/ModelBase/ModelBase.h"

class PerceptronV2Model : public ModelBase {
private:

    int sigma;
    int mean;
    std::vector<double> Dw;
    void zeroDW();
public:
    PerceptronV2Model(const Dataset &dataset, int resultCol, double eta, double seuil, double sigma = 1.0,double mean=0.0);

    void fit(double) override;
    void fit(double,int);
    double predict(double d, double d1) override;



};


#endif //MYIALIBRARY_PERCEPTRONV2MODEL_H

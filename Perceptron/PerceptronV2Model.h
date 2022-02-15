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
    void correctW(int i, double d) override;
    std::vector<double> Dw;
public:
    PerceptronV2Model(const Dataset &dataset, int i, double d, double d1, double = 1.0,double=0.0);

    void fit(int i) override;

    double predict(double d, double d1) override;



};


#endif //MYIALIBRARY_PERCEPTRONV2MODEL_H

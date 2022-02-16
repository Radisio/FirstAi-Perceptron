//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_PERCEPTRONV1MODEL_H
#define MYIALIBRARY_PERCEPTRONV1MODEL_H
#include <vector>
#include "../AILibrary/Dataset/Data.h"
#include "../AILibrary/Dataset/Dataset.h"
#include "../AILibrary/ModelBase/ModelBase.h"
#include <iostream>
class PerceptronV1Model : public ModelBase{
public:
    PerceptronV1Model(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output, double, double);
    PerceptronV1Model(Dataset, int, double, double);
    PerceptronV1Model(std::vector<double>);
    void fit(double) override;
    double predict(double,double) override;



};


#endif //MYIALIBRARY_PERCEPTRONV1MODEL_H

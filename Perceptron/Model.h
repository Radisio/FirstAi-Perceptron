//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_MODEL_H
#define MYIALIBRARY_MODEL_H
#include <vector>
#include "../AILibrary/Dataset/Data.h"
#include "../AILibrary/Dataset/Dataset.h"
#include "../AILibrary/ModelBase/ModelBase.h"
#include <iostream>
class Model : public ModelBase{
private:

    double sum(int);
    void correctW(int,double);

public:
    Model(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output,double,double);
    Model(Dataset,int,double,double);
    Model(std::vector<double>);
    void fit(int) override;
    double predict(double,double) override;



};


#endif //MYIALIBRARY_MODEL_H

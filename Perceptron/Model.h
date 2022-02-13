//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_MODEL_H
#define MYIALIBRARY_MODEL_H
#include <vector>
#include "../AILibrary/Dataset/Data.h"
#include "../AILibrary/Dataset/Dataset.h"
#include <iostream>
class Model {
private:
    std::vector<double> w;
    bool predictable;
    std::vector<std::vector<Data>> entry;
    int nbColEntry;
    double seuil;
    double eta;
    std::vector<Data> output;
    double sum(int);
    void correctW(int,double);

public:
    Model(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output);
    Model(Dataset,int);
    Model(std::vector<double>);
    void fit(double,int,double,double=1);
    std::vector<double> predict();
    void displayW();
    std::vector<double> getW();

};


#endif //MYIALIBRARY_MODEL_H

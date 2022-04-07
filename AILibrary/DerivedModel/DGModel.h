//
// Created by ericp on 29-03-22.
//

#ifndef MYIALIBRARY_DGMODEL_H
#define MYIALIBRARY_DGMODEL_H


#include "../Model/Model.h"
#include <vector>
#include "../Seuil/SeuilPReLu.h"

class DGModel: public Model {
private:
    double seuilMin;
public:
    DGModel(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<std::vector<Data>> output, double eta, double seuilMin);
    DGModel(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<std::vector<Data>> output, double eta);

    DGModel(std::string filename);
    void correction(std::vector<Data> vector, double d) override;

    void fit(int=1000) override;

    std::vector<Data> predict(std::vector<Data> vector) override;
    std::vector<double> divideEmoyByNbExemple(std::vector<double>, int);
    bool allEmoyBelowSeuil(std::vector<double>);
    std::vector<double> setEmoy0(int);
};


#endif //MYIALIBRARY_DGMODEL_H

//
// Created by ericp on 30-03-22.
//

#ifndef MYIALIBRARY_ADALINEMODEL_H
#define MYIALIBRARY_ADALINEMODEL_H


#include "../Model/Model.h"
#include "../Seuil/SeuilPReLu.h"
class AdalineModel: public Model {
private:
    double seuilMin;
public:
    AdalineModel(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<std::vector<Data>> output, double eta, double seuilMin);
    AdalineModel(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<std::vector<Data>> output, double eta);
    AdalineModel(std::string filename);

    void correction(std::vector<Data> vector, double d, int i);
    void correction(std::vector<Data> vector, double d) override;
    void fit(int i) override;

    std::vector<double> divideEmoyByNbExemple(std::vector<double>, int);
    bool allEmoyBelowSeuil(std::vector<double>);
    std::vector<double> setEmoy0(int);

    void correction(std::vector<Data> vector, std::vector<double> vector1) override;
};


#endif //MYIALIBRARY_ADALINEMODEL_H

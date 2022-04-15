//
// Created by ericp on 22-03-22.
//

#ifndef MYIALIBRARY_PERCEPTRONMODEL_H
#define MYIALIBRARY_PERCEPTRONMODEL_H
#include "../Model/Model.h"
#include <vector>
class PerceptronModel: public Model {
private:
    int maxErrorAllowed;
public:
    PerceptronModel(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<std::vector<Data>> output, double eta, int maxErrorAllowed);
    PerceptronModel(std::string);
    void fit(int=1000) override;

    void correction(std::vector<Data>,double) override;

    void correction(std::vector<Data> vector, std::vector<double> vector1) override;


};


#endif //MYIALIBRARY_PERCEPTRONMODEL_H

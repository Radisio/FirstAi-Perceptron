//
// Created by ericp on 22-03-22.
//

#ifndef MYIALIBRARY_SIMPLEMODEL_H
#define MYIALIBRARY_SIMPLEMODEL_H
#include "../Model/Model.h"
#include <vector>
class SimpleModel: public Model {
private:
    int maxErrorAllowed;
public:
    SimpleModel(std::vector<std::vector<Data>>, std::vector<Layer>, std::vector<Data> output, double eta, int maxErrorAllowed);
    void fit() override;

    void correction(std::vector<Data>,double) override;
};


#endif //MYIALIBRARY_SIMPLEMODEL_H

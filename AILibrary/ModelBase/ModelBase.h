//
// Created by ericp on 14-02-22.
//

#ifndef MYIALIBRARY_MODELBASE_H
#define MYIALIBRARY_MODELBASE_H

#include <vector>
#include "../Dataset/Data.h"
#include "../Dataset/Dataset.h"
#include <functional>
class ModelBase {
protected:
    std::vector<double> w;
    bool predictable;
    std::vector<std::vector<Data>> entry;
    int nbColEntry;
    double seuil;
    double eta;
    std::vector<Data> output;

    virtual void correctW(int,double){};
    double evaluateY(int);


public:
    ModelBase(const std::vector<std::vector<Data>> &entry, const std::vector<Data> &output,double,double);
    ModelBase(Dataset,int,double,double);
    ModelBase(std::vector<double>);
    void displayW();
    std::vector<double> getW();

    virtual void fit(int) {}
    virtual double predict(double,double){return 0.0;}

    bool isPredictable() const;

    const std::vector<std::vector<Data>> &getEntry() const;

    int getNbColEntry() const;

    double getSeuil() const;

    double getEta() const;

    const std::vector<Data> &getOutput() const;

    void setEntry(const std::vector<std::vector<Data>> &entry);

    void setSeuil(double seuil);

    void setEta(double eta);

    void setOutput(const std::vector<Data> &output);

};


#endif //MYIALIBRARY_MODELBASE_H

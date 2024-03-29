//
// Created by ericp on 15-03-22.
//

#ifndef MYIALIBRARY_NEURONE_H
#define MYIALIBRARY_NEURONE_H

/**
 * Encapsule les opérations mathématiques, jamais directement appelé par l'utilisateur mais via la fonction fit du modèle qui les contients
 */

/// Evaluation de la sortie propre au neurone
#include <vector>
#include "../Dataset/Data.h"
#include "../Seuil/Seuil.h"
#include "../Generator/Generator.h"

class Neurone {
private:
    std::vector<double> synapse;
    std::vector<double> Dw;
    Seuil* seuil;
    Data* lastOutput;
    Generator* generator;
public:
    Neurone(Seuil*, Generator*);
    Neurone(std::vector<double>,Seuil*);
    ~Neurone();
    void setNbSynapse(int);
    void zeroDw();
    Data evaluateOutput(std::vector<Data>);
    std::vector<double> getSynapse();
    void correction(std::vector<Data>,double,double);
    void setDwVec(std::vector<Data>,double,double);
    void correctionWDw();
    Data getLastOutput();
    Seuil* getSeuil();
    std::vector<double> getDw();
};


#endif //MYIALIBRARY_NEURONE_H

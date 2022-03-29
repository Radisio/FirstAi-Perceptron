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

class Neurone {
private:
    std::vector<double> synapse;

public:
    Neurone();
    Neurone(std::vector<double>);
    void setNbSynapse(int);
    Data evaluateOutput(std::vector<Data>);
    std::vector<double> getSynapse();
    void correction(std::vector<Data>,double,double);
};


#endif //MYIALIBRARY_NEURONE_H

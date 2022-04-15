//
// Created by ericp on 12-04-22.
//

#ifndef MYIALIBRARY_DEMO_H
#define MYIALIBRARY_DEMO_H
#include "AILibrary/Dataset/Dataset.h"
#include "AILibrary/Model/Layer.h"
#include "AILibrary/DerivedModel/PerceptronModel.h"
#include "AILibrary/Seuil/SeuilMarche.h"
#include "AILibrary/Generator/GeneratorOnly0.h"
#include "AILibrary/SciplotHelper/SciplotHelper.h"
#include "AILibrary/DerivedModel/DGModel.h"
#include "AILibrary/DerivedModel/AdalineModel.h"
#define SAVED_MODEL_PATH "E:/ProjetPerso/MyIALibrary/SavedModel/"

class Demo {
public:
    /// Perceptron
    static void operateurLogiqueEtTable2_1();
    static void operateurLogiqueEtTable2_3();
    static void classificationDonneeLineairementSeparableTable2_9();
    static void classificationDonneeNonLineairementSeparableTable2_10();
    static void regressionLineaireTable2_11();

    /// Perceptron monocouche
    static void classification3ClassesTable3_1();
    static void classification4ClassesTable3_5();

    /// Perceptron multicouche
    static void operateurLogiqueXorTable4_3();
    static void classification2ClassesNonLineairementSeparableTable4_12();
    static void classification3ClassesNonLineairementSeparableTable4_14();
    static void regressionNonLineaireTable4_17();


    static int menu_choix(std::vector<std::string>, std::string);
    static double choix_emoy(std::vector<double>);
    static int choix_nb_neurones(std::vector<int>, std::string);
};


#endif //MYIALIBRARY_DEMO_H

#include <iostream>
#include "Demo.h"

using namespace sciplot;

int main() {
    int returnedVal = 0;
    do{
        std::cout<<"Projet RNA -- Paque Eric -- Loic Bourge"<<std::endl;
        returnedVal= Demo::menu_choix({"Perceptron","Perceptron monocouche","Perceptron multicouche","Exemples"},"Quitter");
        if(returnedVal!=-1){
            switch (returnedVal) {
                case 0: {
                    std::cout << "Perceptron" << std::endl;
                    returnedVal = Demo::menu_choix({"Operateur logique ET (table 2.1)", "Operateur logique ET (table 2.3)",
                                              "Classification de données linéaires séparables (table 2.9)",
                                              "Classification de données non linéairement séparables (table 2.10)",
                                              "Regression linéaire (table 2.11)"}, "Retour");
                        if(returnedVal!=-1){
                        switch (returnedVal) {
                            case 0: {
                                ///Opérateur logique ET Table 2.1
                                Demo::operateurLogiqueEtTable2_1();
                                break;
                            }
                            case 1: {
                                ///Opérateur logique ET Table 2.3
                                Demo::operateurLogiqueEtTable2_3();
                                break;
                            }
                            case 2 : {
                                ///Classification de données linéaires séparables Table 2.9
                                Demo::classificationDonneeLineairementSeparableTable2_9();
                                break;
                            }
                            case 3: {
                                /// Classification de données linéaires non séparables Table 2.10
                                Demo::classificationDonneeNonLineairementSeparableTable2_10();
                                break;
                            }
                            case 4: {
                                /// Régression linéaire (table 2.11)
                                Demo::regressionLineaireTable2_11();
                                break;
                            }
                        }
                    }
                    returnedVal=-2;
                    break;
                }
                case 1: {
                    std::cout << "Perceptron monocouche" << std::endl;
                    returnedVal = Demo::menu_choix({"Classification à 3 classes (table 3.1)","Classification à 4 classes (table 3.5)"}, "Retour");
                    if(returnedVal!=-1){
                        switch (returnedVal) {
                            case 0: {
                                ///Classification à 3 classes (table 3.1)
                                Demo::classification3ClassesTable3_1();
                                break;
                            }
                            case 1: {
                                ///Classification à 4 classes (table 3.5)
                                Demo::classification4ClassesTable3_5();
                                break;
                            }
                        }
                    }
                    returnedVal=-2;
                    break;
                }
                case 2: {
                    std::cout << "Perceptron multicouche" << std::endl;
                    returnedVal = Demo::menu_choix({"Opérateur logique XOR (table 4.3)",
                                              "Classification à 2 classes non linéairement séparables (table 4.12)",
                                              "Classification à 3 classes non linéairement séparables (table 4.14)",
                                              "Régression non-linéaire (table 4.17)",
                                              "Premier example (1 itération)"}, "Retour");
                    if(returnedVal!=-1){
                        switch (returnedVal) {
                            case 0: {
                                ///Opérateur logique XOR (table 4.3)
                                Demo::operateurLogiqueXorTable4_3();
                                break;
                            }
                            case 1: {
                                ///Classification à 2 classes non linéairement séparables (table 4.12)
                                Demo::classification2ClassesNonLineairementSeparableTable4_12();
                                break;
                            }
                            case 2 : {
                                ///Classification à 3 classes non linéairement séparables (table 4.14)
                                Demo::classification3ClassesNonLineairementSeparableTable4_14();
                                break;
                            }
                            case 3: {
                                ///Régression non-linéaire (table 4.17)
                                Demo::regressionNonLineaireTable4_17();
                                break;
                            }
                            case 4:{
                                ///Premier exemple (1 itération)
                                Demo::premierExemple1Iteration();
                                break;
                            }
                        }
                    }
                    returnedVal=-2;
                    break;
                }
                case 3:{
                    std::cout << "Exemple" << std::endl;
                    returnedVal = Demo::menu_choix({"(Classification) NOR",
                                                    "(Classification) NAND",
                                                    "(Regression) Taille-poids"}, "Retour");
                    if(returnedVal!=-1){
                        switch (returnedVal) {
                            case 0: {
                                ///NOR
                                Demo::Nor();
                                break;
                            }
                            case 1: {
                                ///NAND
                                Demo::Nand();
                                break;
                            }
                            case 2 : {
                                ///Taille-poids
                                Demo::taille_poids();
                                break;
                            }
                        }
                    }
                    returnedVal=-2;
                    break;
                }
            }
        }
    }while(returnedVal!=-1);
    return 0;
}

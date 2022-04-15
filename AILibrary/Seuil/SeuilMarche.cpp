//
// Created by ericp on 31-03-22.
//

#include "SeuilMarche.h"

double SeuilMarche::seuil(double d) {
    return d>=marche;
}

bool SeuilMarche::isActive(double d) {
    return d==marche;
}

SeuilMarche::SeuilMarche(double marche) {
    this->marche=marche;
}

int SeuilMarche::seuiledValue(double d) {
    return d==marche;
}

std::vector<double> SeuilMarche::getInfo() {
    return std::vector<double>({this->marche});
}

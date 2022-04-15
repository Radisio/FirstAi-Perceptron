//
// Created by ericp on 15-04-22.
//

#include <iostream>
#include "SeuilUtil.h"
#include "SeuilIdentite.h"
#include "SeuilMarche.h"
#include "SeuilPReLu.h"
#include "SeuilSigmoide.h"
#include "SeuilTangeanteHyperbolique.h"

Seuil *SeuilUtil::intToSeuil(std::vector<double> infos) {
    std::cout<<"IntToSeuil"<<std::endl;
    std::cout<<"Size : " << infos.size()<<std::endl;
    int type =(int) infos[0];
    for(int i = 0 ; i<infos.size();i++)
        std::cout<<"Infos["<<i<<"]="<<infos[i]<<std::endl;
    switch(type){
        case 0:
            return new SeuilIdentite();
        case 1:
            return new SeuilMarche(infos[1]);
        case 2:
            return new SeuilPReLu(infos[1],infos[2]);
        case 3:
            return new SeuilSigmoide(infos[1]);
        case 4:
            return new SeuilTangeanteHyperbolique();
    }
}

std::vector<double> SeuilUtil::seuilToInt(Seuil *s) {
    std::vector<double> returnedVector;
    if(dynamic_cast<SeuilIdentite*>(s)!= nullptr) {
        returnedVector.push_back(0);
    }
    if(dynamic_cast<SeuilMarche*>(s)!= nullptr){
        returnedVector.push_back(1);
    }
    if(dynamic_cast<SeuilPReLu*>(s)!= nullptr){
        returnedVector.push_back(2);
    }
    if(dynamic_cast<SeuilSigmoide*>(s)!= nullptr){
        returnedVector.push_back(3);
    }
    if(dynamic_cast<SeuilTangeanteHyperbolique*>(s)!= nullptr){
        returnedVector.push_back(4);
    }
    std::vector<double> infos = s->getInfo();
    returnedVector.insert(
            returnedVector.end(),
            std::make_move_iterator(infos.begin()),
            std::make_move_iterator(infos.end())
            );
    return returnedVector;
}

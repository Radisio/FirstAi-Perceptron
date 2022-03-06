//
// Created by ericp on 12-02-22.
//

#include <stdexcept>
#include "Util.h"
bool Util::onlydigits(const std::string & dataString,const char floatingPoint) {
    int virgule = 0;
    for(const char&c : dataString){
        if(std::isdigit(c)==0){
            if(virgule>0)
                return false;
            if(c == floatingPoint)
            {
                virgule++;
            }
        }
    }
    return true;

}


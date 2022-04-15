//
// Created by ericp on 12-02-22.
//

#include <stdexcept>
#include <iostream>
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

void Util::writeLog(std::ostream *fp, const std::string &str) {
    if(fp!=NULL)
    {
        *fp<<str;
    }
}

void Util::writeLogEndline(std::ostream *fp, const std::string &str) {
    writeLog(fp,str+"\n");
}

std::vector<std::string> Util::parseString(std::string toSplit, std::string delimiter) {
    std::vector<std::string> returnedVector;
    size_t end = 0;
    std::string token;
    size_t start = 0;
    size_t delimiterSize = delimiter.size();
    while((end=toSplit.find(delimiter, start))!=std::string::npos)
    {
        token = toSplit.substr(start,end);
        returnedVector.push_back(token);
        start = end+delimiterSize;

    }
    token = toSplit.substr(start,end);
    returnedVector.push_back(token);
    return returnedVector;

}

std::vector<double> Util::stringVectorToDouble(std::vector<std::string> vString) {
    std::vector<double> returnedVector;
    size_t size=vString.size();
    for(int i =0;i<size;i++)
    {
        returnedVector.push_back( strtod(vString[i].c_str(),NULL));
    }
    return returnedVector;

}

std::vector<double> Util::dataVectorToDouble(std::vector<Data> vData) {
    std::vector<double> returnedVector;
    size_t size=vData.size();
    for(int i =0;i<size;i++)
    {
        returnedVector.push_back( vData[i].getNumericData());
    }
    return returnedVector;
}

std::vector<std::vector<double>> Util::dataTabToDouble(std::vector<std::vector<Data>> tData) {
    std::vector<std::vector<double>> returnedVector;
    std::vector<double> tmp;
    size_t size=tData.size();
    size_t size2;
    for(int i =0;i<size;i++)
    {
        tmp.clear();
        size2=tData[i].size();
        for(int j = 0;j<size2;j++)
        {
            tmp.push_back(tData[i][j].getNumericData());
        }
        if(size2>0)
            returnedVector.push_back(tmp);
    }
    return returnedVector;
}

std::vector<double> Util::dataTabToDoubleVector(std::vector<std::vector<Data>> tData, int index) {
    size_t size=tData.size();
    std::cout<<"Size ici lalala : "<<size<<std::endl;
    std::vector<double> returnedVector;
    for(int i =0;i<size;i++)
    {
        returnedVector.push_back(tData[i][index].getNumericData());
    }
    return returnedVector;
}

double Util::findMax(std::vector<double> vec) {
    size_t size = vec.size();
    double returnedVec = -DBL_MIN;
    for(int i =0;i<size;i++)
    {
        returnedVec = returnedVec<vec[i]? vec[i]:returnedVec;
    }
    return returnedVec;
}

double Util::findMin(std::vector<double> vec) {
    size_t size = vec.size();
    double returnedVec = DBL_MAX;
    for(int i =0;i<size;i++)
    {
        returnedVec = returnedVec>vec[i]? vec[i]:returnedVec;
    }
    return returnedVec;
}

std::vector<double> Util::getAllXFromTab(std::vector<std::vector<double>> tab, int i) {
    size_t size = tab.size();
    std::vector<double> returnedVec;
    for(int j = 0 ; j <size;j++)
    {
        returnedVec.push_back(tab[j][i]);
    }
    return returnedVec;
}

bool Util::file_exist(const std::string &name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}



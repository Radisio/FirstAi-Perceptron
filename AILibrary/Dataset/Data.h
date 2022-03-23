//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_DATA_H
#define MYIALIBRARY_DATA_H
#include <string>
#include "Util.h"
#define DATA_TYPE_NUMERIC 0
#define DATA_TYPE_FACTOR 1
class Data {
    private:
        int type;
        std::string data;
    public:
       Data(int, std::string);

       int getType();
        std::string getData();

       void setType(int);
       void setData(std::string);

       double getNumericData();
       std::string getFactorData();
};


#endif //MYIALIBRARY_DATA_H

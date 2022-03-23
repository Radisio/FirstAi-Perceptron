//
// Created by ericp on 12-02-22.
//

#ifndef MYIALIBRARY_DATASET_H
#define MYIALIBRARY_DATASET_H
#include <vector>
#include <string>
#include "Data.h"
#include <fstream>
#include "DataFactory.h"
#include <iostream>
class Dataset {
private:
    std::vector<std::string> header;
    std::vector<std::vector<Data>> data;
    int nbRow;
    int nbCol;
    char floatingPoint;
    void readFile(const std::string&, bool, const std::string&, char);
    int fillHeader(std::string, std::string);
    int fillData(std::string, std::string, DataFactory);
    bool checkColumnNumericData(int col);

public:
    Dataset(const std::vector<std::string>&, const std::vector<std::vector<Data>> &);
    Dataset(const std::string&, bool , const std::string&, char );
    void changeColumnDataType(int, int);
    void displayData();
    void displayHeader();
    void displayAll();
    void displayAllDetailled();
    void displayColInfo(int);

    int getNbRow();
    int getNbCol();

    std::vector<std::vector<Data>> getData();
    std::vector<std::vector<Data>> getColumns(int start, int end);
    std::vector<Data> getColumn(int col);



};


#endif //MYIALIBRARY_DATASET_H

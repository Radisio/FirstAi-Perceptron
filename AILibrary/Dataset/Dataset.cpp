//
// Created by ericp on 12-02-22.
//


#include "Dataset.h"

Dataset::Dataset(const std::vector<std::string> &header, const std::vector<std::vector<Data>> &data) {
    this->header = header;
    this->data = data;
}

Dataset::Dataset(const std::string& filepath, bool header, const std::string& separator, const char floatingPoint) {
    readFile(filepath,header,separator, floatingPoint);
}

void Dataset::readFile(const std::string& filepath, bool header, const std::string& separator, const char floatingPoint) {
    std::ifstream myfile (filepath);
    if(myfile.is_open()){
        this->floatingPoint = floatingPoint;
        this->nbCol=0;
        std::string line;

        if(header){
            std::getline(myfile,line);
            this->nbCol=fillHeader(line,separator);
        }
        DataFactory factory(floatingPoint);
        int tmpElem = 0;
        this->nbRow = 0;
        while(std::getline(myfile,line))
        {
            tmpElem = fillData(line, separator, factory);
            if(this->nbCol==0)
                this->nbCol=tmpElem;
            if(tmpElem != this->nbCol)
                throw std::runtime_error("Data size irregular");
            this->nbRow++;
        }
    //Check data's type
        for(int i = 0;i<this->nbRow;i++)
        {
            int typeTmp = -1;
            for(int j =0;j<this->nbCol;j++)
            {

                if(typeTmp==-1)
                    typeTmp = data[i][j].getType();
                else{
                    if(typeTmp!=data[i][j].getType())
                    {
                        changeColumnDataType(i,DATA_TYPE_FACTOR);
                        break;
                    }
                }
            }
        }
        myfile.close();
    }
    else{
        throw std::runtime_error("File not open");
    }

}

int Dataset::fillHeader(const std::string line, const std::string separator) {
    int start = 0;
    int end = line.find(separator);
    int nb = 0;
    while(end != -1){
        std::string head = line.substr(start, end-start);
        this->header.push_back(head);
        start = end + separator.size();
        end = line.find(separator,start);
        nb++;
    }
    std::string head = line.substr(start);
    this->header.push_back(head);
    return ++nb;
}

int Dataset::fillData(const std::string dataLine, const std::string separator, DataFactory dataFactory) {
    int start = 0;
    int end = dataLine.find(separator);
    std::vector<Data> vectorData;
    int nb = 0;
    while(end != -1){
        std::string dataElement = dataLine.substr(start, end-start);
        Data newData = dataFactory.getData(dataElement);
        vectorData.push_back(newData);
        nb++;
        start = end + separator.size();
        end = dataLine.find(separator,start);

    }
    std::string dataElement = dataLine.substr(start);
    Data newData = dataFactory.getData(dataElement);
    vectorData.push_back(newData);
    this->data.push_back(vectorData);
    return ++nb;
}

void Dataset::changeColumnDataType(int column, int newType) {
    ///If newType is numeric, all data must be valid before changing
    if(!checkColumnNumericData(column))
    {
        throw std::runtime_error("All/some data aren't numerical values");
    }
    for(int i =0 ; i< this->nbRow;i++)
    {
        this->data[i][column].setType(newType);
    }

}

bool Dataset::checkColumnNumericData(int col) {
    for (int i = 0 ; i<this->nbRow;i++)
    {
        if(!Util::onlydigits(this->data[i][col].getData(), this->floatingPoint))
            return false;
    }
    return true;
}

void Dataset::displayData() {
    for(int i = 0; i<this->nbRow; i++)
    {
        for (int j = 0; j<this->nbCol-1;j++)
        {
            std::cout<<this->data[i][j].getData()<<"||";
        }
        std::cout<<this->data[i][this->nbCol-1].getData()<<std::endl;
    }
}

void Dataset::displayHeader() {
    for(int i = 0;i<this->nbCol-1;i++)
    {
        std::cout<<this->header[i]<<"||";
    }
    std::cout<<this->header[this->nbCol-1]<<std::endl;

}

void Dataset::displayAll() {

    this->displayHeader();
    this->displayData();
}

void Dataset::displayAllDetailled() {
    this->displayAll();
    for(int i = 0;i<this->nbCol;i++)
    {
        displayColInfo(i);
    }
}

void Dataset::displayColInfo(int col) {
    std::cout<<"Column name : " << this->header[col]<<std::endl;
    std::cout<<"Data type : " << this->data[0][col].getType()<<std::endl;
}

int Dataset::getNbRow() {
    return this->nbRow;
}

int Dataset::getNbCol() {
    return this->nbCol;
}

std::vector<std::vector<Data>> Dataset::getData() {
    return this->data;
}

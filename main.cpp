#include <iostream>
#include "AILibrary/Dataset/Dataset.h"
#include "Perceptron/Model.h"
int main() {
    std::cout<<"Coucou"<<std::endl;
   Dataset data("E:\\ProjetPerso\\MyIALibrary\\datasetTest\\datasetAndDoor.csv",true,",",'.');
    std::cout<<"YES"<<std::endl;
   data.displayAll();

   std::cout<<"DISPLAY DATA WITH DETAIL"<<std::endl;
   data.displayAllDetailled();
    float f = -0.0;

   std::cout<<"Model"<<std::endl;
   Model model(data,2);
   model.fit(1,0,1);
   model.displayW();

   return 0;
}

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

   std::cout<<"Model"<<std::endl;
   Model model(data,2);
   model.fit(1,0,1);
   model.displayW();


   std::cout<<"1 and 1 gives = " << model.predict(1,1)<<std::endl;
   std::cout<<"0 and 1 gives = " << model.predict(0,1)<<std::endl;
   std::cout<<"1 and 0 gives = " << model.predict(1,0)<<std::endl;
   std::cout<<"0 and 0 gives = " << model.predict(0,0)<<std::endl;
   return 0;
}

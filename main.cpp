#include <iostream>
#include "AILibrary/Dataset/Dataset.h"
#include "Perceptron/PerceptronV1Model.h"
#include "Perceptron/PerceptronV2Model.h"

int main() {
    std::cout<<"Coucou"<<std::endl;
   Dataset data("../datasetTest/datasetAndDoor.csv",true,",",'.');
    std::cout<<"YES"<<std::endl;
   data.displayAll();

   std::cout<<"DISPLAY DATA WITH DETAIL"<<std::endl;
   data.displayAllDetailled();

   std::cout<<"PerceptronV1Model"<<std::endl;
   PerceptronV1Model model(data, 2, 1, 1);
   model.fit(0);
   model.displayW();
    std::cout<<"Is it predictable : " << model.isPredictable()<<std::endl;


    std::cout<<"1 and 1 gives = " << model.predict(1,1)<<std::endl;
   std::cout<<"0 and 1 gives = " << model.predict(0,1)<<std::endl;
   std::cout<<"1 and 0 gives = " << model.predict(1,0)<<std::endl;
   std::cout<<"0 and 0 gives = " << model.predict(0,0)<<std::endl;



   std::cout<<"PERCEPTRON V2 MODEL"<<std::endl;
    Dataset dataV2("../datasetTest/datasetOrDoorV2.csv",true,",",'.');
    PerceptronV2Model modelV2(dataV2,2,0.20,1,1,0);
    modelV2.fit(0.4,10000);
    modelV2.displayW();
    std::cout<<"Is it predictable : " << modelV2.isPredictable()<<std::endl;

    std::cout<<"1 and 1 gives = " << modelV2.predict(1,1)<<std::endl;
    std::cout<<"0 and 1 gives = " << modelV2.predict(0,1)<<std::endl;
    std::cout<<"1 and 0 gives = " << modelV2.predict(1,0)<<std::endl;
    std::cout<<"0 and 0 gives = " << modelV2.predict(0,0)<<std::endl;

   return 0;
}

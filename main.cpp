#include <iostream>
#include "AILibrary/Dataset/Dataset.h"
#include "Perceptron/PerceptronV1Model.h"
#include "Perceptron/PerceptronV2Model.h"
#include "Perceptron/PerceptronV3Model.h"
#include "AILibrary/Model/Model.h"
#include "AILibrary/DerivedModel/PerceptronModel.h"
#include <fstream>
int main() {
    /*
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


    std::cout<<"PERCEPTRON V3 MODEL"<<std::endl;
    Dataset dataV3("../datasetTest/datasetOrDoorV2.csv",true,",",'.');
    PerceptronV3Model modelV3(dataV3,2,0.20,1,1,0);
    modelV3.fit(0.2,10000);
    modelV3.displayW();
    std::cout<<"Is it predictable : " << modelV3.isPredictable()<<std::endl;

    std::cout<<"1 and 1 gives = " << modelV3.predict(1,1)<<std::endl;
    std::cout<<"0 and 1 gives = " << modelV3.predict(0,1)<<std::endl;
    std::cout<<"1 and 0 gives = " << modelV3.predict(1,0)<<std::endl;
    std::cout<<"0 and 0 gives = " << modelV3.predict(0,0)<<std::endl;*/
    Dataset data("../datasetTest/datasetAndDoor.csv",true,",",'.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<Data> output = data.getColumn(2);
    std::vector<Layer> layers({Layer(1)});
    PerceptronModel model(entry, layers, output, 1, 0);
    model.initNbSynapticWeight();
    model.debugLog();
    model.debugSynapseWeight();
    model.fit();
    model.save("E:\\ProjetPerso\\MyIALibrary\\SavedModel\\MyFirstModel.csv");
    std::vector<Data> answer = model.predict(std::vector<Data>({Data(DATA_TYPE_NUMERIC,"1"),Data(DATA_TYPE_NUMERIC,"1")}));
    std::cout<<"Answer = " <<answer[0].getNumericData()<<std::endl;
    std::cout<<"-----------------"<<std::endl;
    PerceptronModel model1("E:\\ProjetPerso\\MyIALibrary\\SavedModel\\MyFirstModel.csv");
    model1.debugLog();
    model1.debugSynapseWeight();





   return 0;
}

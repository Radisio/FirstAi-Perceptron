#include <iostream>
#include "AILibrary/Dataset/Dataset.h"
#include "Perceptron/PerceptronV1Model.h"
#include "Perceptron/PerceptronV2Model.h"
#include "Perceptron/PerceptronV3Model.h"
#include "AILibrary/Model/Model.h"
#include "AILibrary/DerivedModel/PerceptronModel.h"
#include "AILibrary/DerivedModel/DGModel.h"
#include "AILibrary/DerivedModel/AdalineModel.h"
#include <fstream>
//#include "matplotlibcpp.h"
#include "sciplot/sciplot/sciplot.hpp"
#include "AILibrary/Seuil/SeuilSigmoide.h"
#include <math.h>
using namespace sciplot;
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




    /* Dataset data("../datasetTest/datasetAndDoor.csv",true,",",'.');
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
     std::cout<<"Descente du gradient"<<std::endl;
     Dataset dataV2("../datasetTest/datasetOrDoorV2.csv",true,",",'.');
     std::vector<std::vector<Data>> entry2 = dataV2.getColumns(0,1);
     std::vector<Data> output2 = dataV2.getColumn(2);
     std::vector<Layer> layers2({Layer(1)});
     DGModel modelDG(entry2, layers2, output2, 0.2, 0.1250001);
     modelDG.initNbSynapticWeight();
     modelDG.debugLog();
     modelDG.debugSynapseWeight();
     modelDG.fit(10000);
     modelDG.debugSynapseWeight();
     std::vector<Data> answer2 = modelDG.predict(std::vector<Data>({Data(DATA_TYPE_NUMERIC,"1"),Data(DATA_TYPE_NUMERIC,"1")}));
     std::cout<<"Answer = " <<answer2[0].getNumericData()<<std::endl;
     std::cout<<"Adaline"<<std::endl;
     Dataset dataV3("../datasetTest/datasetAndDoorV2.csv",true,",",'.');
     std::vector<std::vector<Data>> entry3 = dataV3.getColumns(0,1);
     std::vector<std::vector<Data>> output3 = dataV3.getColumn(2);
     std::vector<Layer> layers3({Layer(1)});
     AdalineModel modelAda(entry3, layers3, output3, 0.03, 0.134);
     modelAda.initNbSynapticWeight();
     modelAda.debugLog();
     modelAda.debugSynapseWeight();
     modelAda.fit(10000);
     modelAda.debugSynapseWeight();
     std::vector<Data> answer3 = modelAda.predictWithSeuil(std::vector<Data>({Data(DATA_TYPE_NUMERIC,"1"),Data(DATA_TYPE_NUMERIC,"1")}));
     std::cout<<"Answer = " <<answer3[0].getNumericData()<<std::endl;

    Dataset dataV4("../datasetTest/table_3_1.csv", true, ",", '.');
    std::vector<std::vector<Data>> entry4 = dataV4.getColumns(0, 1);
    std::vector<std::vector<Data>> output4 = dataV4.getColumns(2, 4);
    std::vector<Layer> layers4({Layer(3, new SeuilIdentite())});*/
   /* {
    std::cout << "Adaline mono couche" << std::endl;
    Dataset dataV4("../datasetTest/table_3_1.csv", true, ",", '.');
    std::vector<std::vector<Data>> entry4 = dataV4.getColumns(0, 1);
    std::vector<std::vector<Data>> output4 = dataV4.getColumns(2, 4);
    std::vector<Layer> layers4({Layer(3, new SeuilIdentite())});
    AdalineModel modelAda2(entry4, layers4, output4, 0.03);
    modelAda2.initNbSynapticWeight();
    modelAda2.debugLog();
    modelAda2.debugSynapseWeight();
    modelAda2.fit(200);
    modelAda2.debugSynapseWeight();
    std::vector<std::vector<double>> synapses = modelAda2.getSynapseLastLayer();
    std::vector<double> x = Util::dataTabToDoubleVector(dataV4.getColumn(0), 0);
    std::vector<double> y = Util::dataTabToDoubleVector(dataV4.getColumn(1), 0);
    Vec vX((std::valarray<double>(x.data(), x.size())));
    Vec vY(std::valarray<double>(y.data(), y.size()));
    // Create a Plot object
    Plot plot;
    // Set the x and y labels
    plot.xlabel("x");
    plot.ylabel("y");
    plot.legend().title("Adaline Monocouche").atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
    plot.drawPoints(vX, vY).pointType(0).label("Inputs");
    int nbNeurones = synapses.size();
    std::vector<double> vtY;
    Vec tX = linspace(-2, 5, 100);
    int sizeTx = tX.size();
    for (int i = 0; i < nbNeurones; i++) {
        vtY.clear();
        for (int j = 0; j < sizeTx; j++) {
            vtY.push_back((-std::abs(synapses[i][0]) - tX[j] * synapses[i][1]) / -std::abs(synapses[i][2]));
        }
        Vec tY(std::valarray<double>(vtY.data(), vtY.size()));
        plot.drawCurve(tX, tY).label("Boundary decision " + std::to_string(i));
    }
    plot.show();
    }*/
    /*{
        Dataset dataV4("../datasetTest/table_3_1.csv", true, ",", '.');
        std::vector<std::vector<Data>> entry4 = dataV4.getColumns(0, 1);
        std::vector<std::vector<Data>> output4 = dataV4.getColumns(2, 4);
        std::vector<Layer> layers4({Layer(3, new SeuilIdentite())});
        std::cout << "Descente du gradient monocouche" << std::endl;
        DGModel modelDG2(entry4, layers4, output4, 0.0001,0.01);
        modelDG2.initNbSynapticWeight();
        modelDG2.debugLog();
        modelDG2.debugSynapseWeight();
        modelDG2.fit(200);
        modelDG2.debugSynapseWeight();
        std::vector<std::vector<double>> synapses = modelDG2.getSynapseLastLayer();
        std::vector<double> x = Util::dataTabToDoubleVector(dataV4.getColumn(0), 0);
        std::vector<double> y = Util::dataTabToDoubleVector(dataV4.getColumn(1), 0);
        Vec vX((std::valarray<double>(x.data(), x.size())));
        Vec vY(std::valarray<double>(y.data(), y.size()));
        // Create a Plot object
        Plot plot;
        // Set the x and y labels
        plot.xlabel("x");
        plot.ylabel("y");
        plot.legend().title("Descente du gradient Monocouche").atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
        plot.drawPoints(vX, vY).pointType(0).label("Inputs");
        int nbNeurones = synapses.size();
        std::vector<double> vtY;
        Vec tX = linspace(-2, 5, 100);
        int sizeTx = tX.size();
        for (int i = 0; i < nbNeurones; i++) {
            vtY.clear();
            for (int j = 0; j < sizeTx; j++) {
                vtY.push_back((-std::abs(synapses[i][0]) - tX[j] * synapses[i][1]) / -std::abs(synapses[i][2]));
            }
            Vec tY(std::valarray<double>(vtY.data(), vtY.size()));
            plot.drawCurve(tX, tY).label("Boundary decision " + std::to_string(i));
        }
        plot.show();
    }*/
    {
        std::cout << "Adaline multi couche" << std::endl;
        Dataset dataV4("../datasetTest/table_4_12.csv", true, ",", '.');
        std::vector<std::vector<Data>> entry4 = dataV4.getColumns(0, 1);
        std::vector<std::vector<Data>> output4 = dataV4.getColumn(2);
        std::vector<Layer> layers4({Layer(3, new SeuilSigmoide(1)),Layer(1, new SeuilSigmoide(1))});
        AdalineModel modelAda2(entry4, layers4, output4, 0.5);
        modelAda2.initNbSynapticWeight();
        modelAda2.debugLog();
        modelAda2.debugSynapseWeight();
        modelAda2.fit(2000);
        modelAda2.debugSynapseWeight();
        std::vector<std::vector<double>> synapses = modelAda2.getSynapseLastLayer();
        std::vector<double> x = Util::dataTabToDoubleVector(dataV4.getColumn(0), 0);
        std::vector<double> y = Util::dataTabToDoubleVector(dataV4.getColumn(1), 0);
        Vec vX((std::valarray<double>(x.data(), x.size())));
        Vec vY(std::valarray<double>(y.data(), y.size()));
        // Create a Plot object
        Plot plot;
        // Set the x and y labels
        plot.xlabel("x");
        plot.ylabel("y");
        plot.legend().title("Adaline Monocouche").atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
        plot.drawPoints(vX, vY).pointType(0).label("Inputs");
        int nbNeurones = synapses.size();
        std::vector<double> vtY;
        Vec tX = linspace(-2, 5, 100);
        int sizeTx = tX.size();
        for (int i = 0; i < nbNeurones; i++) {
            vtY.clear();
            for (int j = 0; j < sizeTx; j++) {
                vtY.push_back((-std::abs(synapses[i][0]) - tX[j] * synapses[i][1]) / -std::abs(synapses[i][2]));
            }
            Vec tY(std::valarray<double>(vtY.data(), vtY.size()));
            plot.drawCurve(tX, tY).label("Boundary decision " + std::to_string(i));
        }
        plot.show();
    }
    /*Dataset dataV4("../datasetTest/table_3_1.csv",true,",",'.');
    std::vector<std::vector<Data>> entry4 = dataV4.getColumns(0,1);
    std::vector<std::vector<Data>> output4 = dataV4.getColumns(2,4);
    //Vec x = linspace(0.0, PI, 200);
    std::vector<double> x = Util::dataTabToDoubleVector(dataV4.getColumn(0),0);
    std::vector<double> y = Util::dataTabToDoubleVector(dataV4.getColumn(1),0);
    Vec vX((std::valarray<double>(x.data(),x.size())));
    Vec vY(std::valarray<double>(y.data(),y.size()));
    for(int i =0;i<x.size();i++)
    {
        std::cout<<"vX["<<i<<"]="<<x[i]<<std::endl;
    }
    // Create a Plot object
    Plot plot;
    // Set the x and y labels
    plot.xlabel("x");
    plot.ylabel("y");
    plot.legend().title("Adaline Monocouche").atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
    plot.drawPoints(vX,vY).pointType(0);
    double w0,w1,w2;
    w0=0.648616;
    w1=-0.43964;
    w2=-0.1708;

    ///Avoir le vecteur Y
    Vec tX = linspace(-2,5,100);
    std::vector<double> vtY;
    for(int i =0;i<tX.size();i++)
    {
       // vtY.push_back((-(w0/w2)/(w0/w1))*tX[i]+(-w0/w2));
        vtY.push_back((-std::abs(w0)-tX[i]*w1)/w2);
    }
    Vec tY(std::valarray<double>(vtY.data(),vtY.size()));
    plot.drawCurve(tX,tY);

    double w20,w21,w22;
    w20=-1.744914;
    w21=0.065816;
    w22=-0.465358;
    Vec tX2 = linspace(-2,5,100);
    std::vector<double> vtY2;
    for(int i =0;i<tX.size();i++)
    {
        vtY2.push_back((-std::abs(w20)-tX2[i]*w21)/w22);
        std::cout<<"tx2["<<i<<"]="<<tX2[i]<<std::endl;
        std::cout<<"Vty2 ["<<i<<"]="<<vtY2[i]<<std::endl;
    }
    Vec t2Y(std::valarray<double>(vtY2.data(),vtY2.size()));
    plot.drawCurve(tX2,t2Y);


    // Show the plot in a pop-up window
    plot.show();*/
    return 0;
}

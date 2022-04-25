//
// Created by ericp on 12-04-22.
//

#include "Demo.h"
#include "AILibrary/Seuil/SeuilSigmoide.h"
#include "AILibrary/Generator/GeneratorNormalLaw.h"
#include "AILibrary/Seuil/SeuilTangeanteHyperbolique.h"

void Demo::operateurLogiqueEtTable2_1() {
    bool file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"operateurLogiqueETTable2_1.csv");
    int fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    Dataset data("../datasetTest/table_2_1.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0, 1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    Model* model = nullptr;
    if(fitOrModel==0) {
        std::vector<Layer> layers({Layer(1, new SeuilMarche(0), new GeneratorOnly0())});
        model = new PerceptronModel(entry, layers, output, 1, 0);
        model->initNbSynapticWeight();
        model->debugLog();
        model->fit();
        model->debugSynapseWeight();
        if(!file_exist)
            model->save(std::string(SAVED_MODEL_PATH)+"operateurLogiqueETTable2_1.csv");
    }
    else{
        std::cout<<"Résultat"<<std::endl;
        model = new PerceptronModel(std::string(SAVED_MODEL_PATH)+"operateurLogiqueETTable2_1.csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
    std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
    Plot plot =SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Operateur logique ET(Table 2.1)");
    plot.show();
    plot.save("../SavedPlot/Ptable2_1_plot.png");
    delete model;
}

void Demo::operateurLogiqueEtTable2_3() {
    bool file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"operateurLogiqueETTable2_3.csv");
    int fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;

    Dataset data("../datasetTest/table_2_3.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0, 1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model = nullptr;
    if(fitOrModel==0) {
        Dataset data("../datasetTest/table_2_3.csv", false, ",", '.');
        std::vector<std::vector<Data>> entry = data.getColumns(0, 1);
        std::vector<std::vector<Data>> output = data.getColumn(2);
        std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
        model = new DGModel(entry, layers, output, 0.2, 0.1250001);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(10000);
        model->debugSynapseWeight();
        if(!file_exist)
            model->save(std::string(std::string(SAVED_MODEL_PATH)+"operateurLogiqueETTable2_3.csv"));
    }
    else{
        model = new DGModel(std::string(SAVED_MODEL_PATH)+"operateurLogiqueETTable2_3.csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
    std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);

    Plot plot =SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Operateur logique ET(Table 2.3)");
    plot.show();
    plot.save("../SavedPlot/DGtable2_3_plot.png");
    delete model;
}

void Demo::classificationDonneeLineairementSeparableTable2_9() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Dataset data("../datasetTest/table_2_9.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0, 1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    switch (returnedVal) {
        case 0:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"DG_ClassificationDonneeLineaireTable2_9.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0){
                model = new DGModel(entry, layers, output, 0.0011, 0.1);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(1000);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"DG_ClassificationDonneeLineaireTable2_9.csv");
            }
            else{
                model = new DGModel(std::string(SAVED_MODEL_PATH)+"DG_ClassificationDonneeLineaireTable2_9.csv");

            }
            std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
            std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
            std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
            Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Classification donnee lineairement separable (Descente du gradient) (Table 2.9)");
            plot.show();
            plot.save("../SavedPlot/DGtable2_9_plot.png");
            break;
        }

        case 1:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_ClassificationDonneeLineaireTable2_9.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                Dataset data("../datasetTest/table_2_9.csv", false, ",", '.');
                std::vector<std::vector<Data>> entry = data.getColumns(0, 1);
                std::vector<std::vector<Data>> output = data.getColumn(2);
                std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
                model = new AdalineModel(entry, layers, output, 0.012, 0.24);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(1000);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"ADA_ClassificationDonneeLineaireTable2_9.csv");
            }
            else{
                model = new DGModel(std::string(SAVED_MODEL_PATH)+"ADA_ClassificationDonneeLineaireTable2_9.csv");

            }
            std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
            std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
            std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);

            Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Classification donnee lineairement separable (Adaline) (Table 2.9)");
            plot.save("../SavedPlot/Adatable2_9_plot_save.png");
            plot.show();
            break;
        }
    }
}

void Demo::classificationDonneeNonLineairementSeparableTable2_10() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Dataset data("../datasetTest/table_2_10.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0, 1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    switch (returnedVal) {
        case 0:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"DG_ClassificationDonneeNonLineairementSeparableTable2_10.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                model = new DGModel(entry, layers, output, 0.0015, 0.37);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(1000);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"DG_ClassificationDonneeNonLineairementSeparableTable2_10.csv");
            }
            else{
                model = new DGModel(std::string(SAVED_MODEL_PATH)+"DG_ClassificationDonneeNonLineairementSeparableTable2_10.csv");
            }
            std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
            std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
            std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);

            Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Classification donnee non-lineairement separable (Descente du gradient) (Table 2.10)");
            plot.show();
            plot.save("../SavedPlot/DGtable2_10_plot_save.png");
            break;
        }
        case 1:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_ClassificationDonneeNonLineairementSeparableTable2_10.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                model = new AdalineModel(entry, layers, output, 0.0015, 0.375);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(1000);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"ADA_ClassificationDonneeNonLineairementSeparableTable2_10.csv");
            }
            else{
                model = new AdalineModel(std::string(SAVED_MODEL_PATH)+"ADA_ClassificationDonneeNonLineairementSeparableTable2_10.csv");
            }
            std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
            std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
            std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);

            Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Classification donnee non-lineairement separable (Adaline) (Table 2.10)");
            plot.show();
            plot.save("../SavedPlot/Adatable2_10_plot.png");
            break;
        }
    }
}

void Demo::regressionLineaireTable2_11() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Dataset data("../datasetTest/table_2_11.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumn(0);
    std::vector<std::vector<Data>> output = data.getColumn(1);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    switch (returnedVal) {
        case 0:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"DG_RegressionLineaireTable2_11.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                model = new DGModel(entry, layers, output, 0.000167,0.6);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(4000);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"DG_RegressionLineaireTable2_11.csv");
            }
            else{
                model = new DGModel(std::string(SAVED_MODEL_PATH)+"DG_RegressionLineaireTable2_11.csv");
            }
            std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
            std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
            Plot plot = SciplotHelper::drawRegressionCurve(x,y,model,"Régression linéaire (Descente du gradient) (Table 2.11)");
            plot.show();
            plot.save("../SavedPlot/DGtable2_11_plot_save.png");
            break;
        }
        case 1:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_RegressionLineaireTable2_11.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                model = new AdalineModel(entry, layers, output, 0.00014, 0.6);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(8000);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"ADA_RegressionLineaireTable2_11.csv");
            }
            else{
                model = new AdalineModel(std::string(SAVED_MODEL_PATH)+"ADA_RegressionLineaireTable2_11.csv");
            }
            std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
            std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
            Plot plot = SciplotHelper::drawRegressionCurve(x,y,model,"Régression linéaire (Adaline) (Table 2.11)");
            plot.show();
            plot.save("../SavedPlot/Adatable2_11_plot.png");
            break;
        }
    }
    delete model;
}

void Demo::classification3ClassesTable3_1() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Dataset data("../datasetTest/table_3_1.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<std::vector<Data>> output = data.getColumns(2,4);
    std::vector<Layer> layers({Layer(3, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    switch (returnedVal) {
        case 0:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"DG_Classification3ClassesTable2_11.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                model = new DGModel(entry, layers, output, 0.0001, 0.015);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(300);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"DG_Classification3ClassesTable2_11.csv");
            }
            else{
                model = new DGModel(std::string(SAVED_MODEL_PATH)+"DG_Classification3ClassesTable2_11.csv");
            }
            std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
            std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
            std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
            Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Classification 3 classee (Droites) (Descente du gradient) (Table 3.1)");
            Plot plot2 = SciplotHelper::drawBoundariesDecisionZones(x,y,classes,model,"Classification 3 classes (Zones) (Descente du gradient) (Table 3.1)");
            Figure fig = {{plot},{plot2}};
            fig.show();
            fig.save("../SavedPlot/DGtable_3_1_plot.png");
            break;
        }
        case 1:
        {
            file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesTable3_1.csv");
            fitOrModel = 0;
            if(file_exist)
                fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
            if(fitOrModel==-1)
                return;
            if(fitOrModel==0) {
                model = new AdalineModel(entry, layers, output, 0.001,0.21);
                model->initNbSynapticWeight();
                model->debugLog();
                model->debugSynapseWeight();
                model->fit(300);
                model->debugSynapseWeight();
                model->save(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesTable3_1.csv");
            }
            else{
                model = new AdalineModel(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesTable3_1.csv");
            }
            std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
            std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
            std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
            Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Classification 3 classee (Droites) (Adaline) (Table 3.1)");
            Plot plot2 = SciplotHelper::drawBoundariesDecisionZones(x,y,classes,model,"Classification 3 classes (Zones) (Adaline) (Table 3.1)");
            Figure fig = {{plot},{plot2}};
            fig.show();
            fig.save("../SavedPlot/Adatable_3_1_plot.png");
            break;
        }
    }
    delete model;
}

void Demo::classification4ClassesTable3_5() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Model* model;
    Dataset data("../datasetTest/table_3_5.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,24);
    std::vector<std::vector<Data>> output = data.getColumns(25,28);
    std::vector<Layer> layers({Layer(4, new SeuilIdentite(), new GeneratorOnly0())});
    switch (returnedVal) {
        case 0:
        {
            model = new DGModel(entry, layers, output, 0.0001);
            model->initNbSynapticWeight();
            model->debugLog();
            model->debugSynapseWeight();
            model->fit(300);
            model->debugSynapseWeight();
            model->save(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesTable2_11.csv");
            break;
        }
        case 1:
        {
            model = new AdalineModel(entry, layers, output, 0.001,0.05);
            model->initNbSynapticWeight();
            model->debugLog();
            model->debugSynapseWeight();
            model->fit(780);
            model->debugSynapseWeight();
            model->save(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesTable2_11.csv");
            break;
        }
    }
}

void Demo::operateurLogiqueXorTable4_3() {
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    Dataset data("../datasetTest/table_4_3.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    int nbNeuroneCoucheCache = choix_nb_neurones({2,3},"Retour");
    if(nbNeuroneCoucheCache==-1)
        return;
    std::vector<Layer> layers({Layer(nbNeuroneCoucheCache, new SeuilSigmoide(1), new GeneratorNormalLaw(0.0,1.0)),
                               Layer(1, new SeuilSigmoide(1), new GeneratorNormalLaw(0.0,1.0))});
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"DG_OperateurLogiqueXORTable4_3_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    double emoy = determinationEmoy({0.0678,0.05},{2,3},nbNeuroneCoucheCache);
    if(fitOrModel==0) {
        model = new DGModel(entry, layers, output, 0.8, emoy);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(6000);
        model->debugSynapseWeight();
        model->save(std::string(SAVED_MODEL_PATH)+"DG_OperateurLogiqueXORTable4_3_"+ std::to_string(nbNeuroneCoucheCache)+".csv");

    }
    else{
        model = new DGModel(std::string(SAVED_MODEL_PATH)+"DG_OperateurLogiqueXORTable4_3_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
    std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
    Plot plot = SciplotHelper::drawBoundariesDecisionZones(x,y,classes,model,"Operateur logique XOR (Descente du gradient) (Table 4.3)");
    plot.show();
    plot.save("../SavedPlot/DGtable4_3_plot_"+ std::to_string(nbNeuroneCoucheCache)+".png");
    delete model;
}

void Demo::classification2ClassesNonLineairementSeparableTable4_12() {
    Dataset data("../datasetTest/table_4_12.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    int nbNeuroneCoucheCache = choix_nb_neurones({1,2,3,5,10,20},"Retour");
    if(nbNeuroneCoucheCache==-1)
        return;
    double emoy = determinationEmoy({0.1,0.05,0.001,0.001,0.001,0.001},{1,2,3,5,10,20},nbNeuroneCoucheCache);
    std::vector<Layer> layers;
    layers.push_back(Layer(nbNeuroneCoucheCache,new SeuilSigmoide(1), new GeneratorNormalLaw(0,1)));
    layers.push_back(Layer(1, new SeuilSigmoide(1), new GeneratorNormalLaw(0,1)));
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_Classification2ClassesNonLineairementSeparableTable4_12_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    if(fitOrModel==0) {
        model = new AdalineModel(entry, layers, output, 0.5,emoy);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(2000);
        model->debugSynapseWeight();
        model->save(std::string(SAVED_MODEL_PATH)+"ADA_Classification2ClassesNonLineairementSeparableTable4_12_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    else{
        model = new DGModel(std::string(SAVED_MODEL_PATH)+"ADA_Classification2ClassesNonLineairementSeparableTable4_12_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
    std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
    Plot plot= SciplotHelper::drawBoundariesDecisionZones(x,y,classes,model,"Classification 2 classes non linéairement séparable (Zones) (Adaline) (Table 4.12)");
    plot.show();
    plot.save("../SavedPlot/ADAtable_4_12_"+ std::to_string(nbNeuroneCoucheCache)+"_plot.png");
}

void Demo::classification3ClassesNonLineairementSeparableTable4_14() {
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    int nbNeuroneCoucheCache = choix_nb_neurones({1,2,3,5,10,20},"Retour");
    if(nbNeuroneCoucheCache==-1)
        return;
    double emoy = determinationEmoy({0.23,0.06,0.01,0.001,0.001,0.001},{1,2,3,5,10,20},nbNeuroneCoucheCache);
    std::vector<Layer> layers;
    layers.push_back(Layer(nbNeuroneCoucheCache,new SeuilSigmoide(1), new GeneratorNormalLaw(0,1)));
    layers.push_back(Layer(3, new SeuilSigmoide(1), new GeneratorNormalLaw(0,1)));
    Dataset data("../datasetTest/table_4_14.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<std::vector<Data>> output = data.getColumns(2,4);
    std::cout<<"ICI"<<std::endl;
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesNonLineairementSeparableTable4_14_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    if(fitOrModel==0) {
        ///10->0.0022 eta1.2
        model = new AdalineModel(entry, layers, output, 1.2,emoy);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(2000);
        model->save(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesNonLineairementSeparableTable4_14_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    else{
        model = new DGModel(std::string(SAVED_MODEL_PATH)+"ADA_Classification3ClassesNonLineairementSeparableTable4_14_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
    std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
    Plot plot = SciplotHelper::drawBoundariesDecisionZones(x,y,classes,model,"");
    plot.show();
    plot.save("../SavedPlot/ADAtable_4_14_"+ std::to_string(nbNeuroneCoucheCache)+"_plot.png");
}

void Demo::regressionNonLineaireTable4_17() {
    int nbNeuroneCoucheCache = choix_nb_neurones({1,2,3,4,5,10},"Retour");
    if(nbNeuroneCoucheCache==-1)
        return;
    std::vector<Layer> layers;
    layers.push_back(Layer(nbNeuroneCoucheCache,new SeuilTangeanteHyperbolique, new GeneratorNormalLaw(0,1)));
    layers.push_back(Layer(1, new SeuilIdentite(), new GeneratorNormalLaw(0,1)));
    Dataset data("../datasetTest/table_4_17.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumn(0);
    std::vector<std::vector<Data>> output = data.getColumn(1);
    double emoy = determinationEmoy({0.16,0.05,0.05,0.05,0.05,0.05},{1,2,3,4,5,10},nbNeuroneCoucheCache);
    std::cout<<"Emoy = " << emoy<<std::endl;
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"DG_RegressionNonLineaireTable4_17_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    if(fitOrModel==0) {
        model = new DGModel(entry, layers, output, 0.001,0.04);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(10000);
        model->debugSynapseWeight();
        model->save(std::string(SAVED_MODEL_PATH)+"DG_RegressionNonLineaireTable4_17_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    else{
        model = new DGModel(std::string(SAVED_MODEL_PATH)+"DG_RegressionNonLineaireTable4_17_"+ std::to_string(nbNeuroneCoucheCache)+".csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
    std::vector<double> y = Util::dataTabToDoubleVector(output, 0);
    Plot plot = SciplotHelper::drawRegressionCurve(x,y,model,"Régression non linéaire (Descente du Gradient) (Table 4_17)");
    plot.show();
    plot.save("../SavedPlot/DGtable_4_17_plot_"+ std::to_string(nbNeuroneCoucheCache)+".png");
    delete model;
}

void Demo::Nor() {
    Dataset data("../datasetTest/table_nor.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_Nor.csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    if(fitOrModel==0) {
        model = new AdalineModel(entry, layers, output, 0.01,0.128);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(3000);
        model->debugSynapseWeight();
        model->save(std::string(SAVED_MODEL_PATH)+"ADA_Nor.csv");
    }
    else{
        model = new AdalineModel(std::string(SAVED_MODEL_PATH)+"ADA_Nor.csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
    std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
    Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Nor (Adaline)");
    plot.show();
    plot.save("../SavedPlot/AdaNor_plot.png");

    delete model;
}

void Demo::Nand() {
    Dataset data("../datasetTest/table_nand.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,1);
    std::vector<std::vector<Data>> output = data.getColumn(2);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel = 0;
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_Nand.csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    if(fitOrModel==0) {
        model = new AdalineModel(entry, layers, output, 0.1,0.17);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(3000);
        model->debugSynapseWeight();
        model->save(std::string(SAVED_MODEL_PATH)+"ADA_Nand.csv");
    }
    else{
        model = new AdalineModel(std::string(SAVED_MODEL_PATH)+"ADA_Nand.csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(entry, 0);
    std::vector<double> y = Util::dataTabToDoubleVector(entry, 1);
    std::vector<std::vector<double>> classes = Util::dataTabToDouble(output);
    Plot plot = SciplotHelper::drawBoundariesDecisionLines(x,y,classes,model,"Nand (Adaline)");
    plot.show();
    plot.save("../SavedPlot/AdaNand_plot.png");

    delete model;
}

void Demo::taille_poids() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Dataset data("../datasetTest/taile_poids.csv", true, ";", ',');
    std::vector<std::vector<Data>> entry = data.getColumn(0);
    std::vector<std::vector<Data>> output = data.getColumn(1);
    std::vector<Layer> layers({Layer(1, new SeuilIdentite(), new GeneratorOnly0())});
    Model* model;
    bool file_exist;
    int fitOrModel;
    file_exist = Util::file_exist(std::string(SAVED_MODEL_PATH)+"ADA_taille_poids.csv");
    fitOrModel = 0;
    if(file_exist)
        fitOrModel = menu_choix({"Fit","Resultat"},"Retour");
    if(fitOrModel==-1)
        return;
    if(fitOrModel==0) {
        model = new AdalineModel(entry, layers, output, 0.00014);
        model->initNbSynapticWeight();
        model->debugLog();
        model->debugSynapseWeight();
        model->fit(8000);
        model->debugSynapseWeight();
        model->save(std::string(SAVED_MODEL_PATH)+"ADA_taille_poids.csv");
    }
    else{
        model = new AdalineModel(std::string(SAVED_MODEL_PATH)+"ADA_taille_poids.csv");
    }
    std::vector<double> x = Util::dataTabToDoubleVector(data.getColumn(0), 0);
    std::vector<double> y = Util::dataTabToDoubleVector(data.getColumn(1), 0);
    Plot plot = SciplotHelper::drawRegressionCurve(x,y,model,"Taille/poids (Adaline) (Table 2.11)");
    plot.show();
    plot.save("../SavedPlot/Adataille_poids_plot.png");
    delete model;
}
void Demo::premierExemple1Iteration() {
    int returnedVal = menu_choix({"Descente du gradient","Adaline"},"Retour");
    if(returnedVal==-1)
        return;
    Dataset data("../datasetTest/table_1_iteration.csv", false, ",", '.');
    std::vector<std::vector<Data>> entry = data.getColumns(0,2);
    std::vector<std::vector<Data>> output = data.getColumns(3,5);
    std::vector<Layer> layers({{Layer(2, new SeuilSigmoide(1), {{0,0.1,0.15,0.05},{0,0.12,0.18,0.08}})},
                              {Layer(3, new SeuilSigmoide(1), {{0,0.1,0.14},{0,0.125,0.21},{0,0.13,0.07}})}});

    Model* model;
    if(returnedVal==0)
        model = new DGModel(entry, layers,output,1);
    else
        model = new AdalineModel(entry, layers,output,1);

    model->debugLog();
    model->debugSynapseWeight();
    model->fit(1);
    std::cout<<"Ici"<<std::endl;
    model->debugSynapseWeight();
    model->debugLastOutputNeurones();
    delete model;
}
int Demo::menu_choix(std::vector<std::string> choices, std::string leaveBackOption="Quitter")
{
    int returnedVal;
    size_t size = choices.size();
    int maxChoice = size-1;
    for(int i =0;i<size;i++)
    {
        std::cout<<i<<" : "<<choices[i]<<std::endl;
    }
    std::cout<<"-1 : "<<leaveBackOption<<std::endl;
    do{
        std::cout<<"Votre choice : ";std::cin>>returnedVal;std::cout<<std::endl;
    }while(returnedVal<-1 || returnedVal>maxChoice);
    return returnedVal;
}

double Demo::choix_emoy(std::vector<double> emoyChoice) {
    double returnedDouble = 0.0;
    size_t size = emoyChoice.size();
    do{
        std::cout<<"Faites un choix entre de emoyMin: "<<std::endl;
        for(int i = 0 ; i<size;i++)
        {
            std::cout<<i<<" : "<<emoyChoice[i]<<std::endl;
        }
        std::cout<<"Votre choix : "; std::cin>>returnedDouble;std::cout<<std::endl;
    }while(std::find(emoyChoice.begin(),emoyChoice.end(),returnedDouble)!=emoyChoice.end());
    return returnedDouble;
}

int Demo::choix_nb_neurones(std::vector<int> nbNeurones, std::string leaveBackOption) {
    size_t size = nbNeurones.size();
    std::cout<<"Choix du nombre de neurones " <<std::endl;
    int index;
    do{
        std::cout<<"Combien de neurones dans la couche cachée souhaitez-vous ?" << std::endl;
        for(int i = 0;i<size;i++)
        {
            std::cout<<i<<" : "<<nbNeurones[i]<<std::endl;
        }
        std::cout<<"Votre choix : "; std::cin>>index;std::cout<<std::endl;
    }while(index <-1 || index >=size);
    return nbNeurones[index];
}

double Demo::determinationEmoy(std::vector<double> emoyVec, std::vector<int> nbNeuronesVec, int nbNeuronesChoose) {
    std::cout<<"Determination"<<std::endl;
    return emoyVec[getIndex(nbNeuronesVec,nbNeuronesChoose)];
}

int Demo::getIndex(std::vector<int> vec, int element) {
    auto it = std::find(vec.begin(),vec.end(),element);
    if(it != vec.end())
    {
        return it - vec.begin();
    }
    return -1;
}





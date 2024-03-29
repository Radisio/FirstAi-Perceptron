//
// Created by ericp on 11-04-22.
//

#include "SciplotHelper.h"

#include <utility>

Plot SciplotHelper::drawBoundariesDecisionLines(std::vector<double> x, std::vector<double> y, std::vector<std::vector<double>> outputs, Model * model, std::string title) {
    std::cout<<"Draw"<<std::endl;
    Plot plot;
    // Set the x and y labels
    plot.xlabel("x");
    plot.ylabel("y");
    int nbOutput = outputs[0].size();
    double maxX = Util::findMax(x);
    double minX = Util::findMin(x);
    double maxY = Util::findMax(y);
    double minY = Util::findMin(y);
    int nbEntries = x.size();
    std::vector<std::vector<double>> synapses = model->getSynapseLastLayer();
    int nbNeurones = synapses.size();
    std::vector<double> vtY;
    Vec tX = linspace(minX-1, maxX+1, 100);
    int sizeTx = tX.size();
    for (int i = 0; i < nbNeurones; i++) {
        vtY.clear();
        for (int j = 0; j < sizeTx; j++) {
            vtY.push_back((-synapses[i][0] - tX[j] * synapses[i][1]) / synapses[i][2]);
        }
        Vec tY(std::valarray<double>(vtY.data(), vtY.size()));
        plot.drawCurve(tX, tY).label("Boundary decision " + std::to_string(i));
    }

    ///Plot entries
    std::vector<std::vector<double>> xClassified, yClassified;
    for(int i = 0;i<2;i++)
    {
        xClassified.emplace_back();
        yClassified.emplace_back();
    }
    Seuil* seuil = model->getSeuilLastLayer();

    if(nbOutput>1) {
        for (int i = 2; i < nbOutput; i++) {
            xClassified.emplace_back();
            yClassified.emplace_back();
        }
        for (int i = 0; i < nbEntries; i++) {
            for (int j = 0; j < nbOutput; j++) {
                if (seuil->isActive(outputs[i][j])) {
                    xClassified[j].push_back(x[i]);
                    yClassified[j].push_back(y[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < nbOutput; i++) {
            Vec vX((std::valarray<double>(xClassified[i].data(), xClassified[i].size())));
            Vec vY(std::valarray<double>(yClassified[i].data(), yClassified[i].size()));
            plot.drawPoints(vX, vY).pointType(0).label("Inputs class : " + std::to_string(i));
        }
    }
    else{
        for(int i = 0;i<nbEntries;i++)
        {
            std::cout<<"Output ["<<i<<"][0] = " << outputs[i][0]<<std::endl;
            if(seuil->isActive(outputs[i][0])){
                xClassified[0].push_back(x[i]);
                yClassified[0].push_back(y[i]);
            }
            else{
                xClassified[1].push_back(x[i]);
                yClassified[1].push_back(y[i]);
            }
        }
        for(int i =0;i<2;i++) {
            Vec vX(std::valarray<double>(xClassified[i].data(), xClassified[i].size()));
            Vec vY(std::valarray<double>(yClassified[i].data(), yClassified[i].size()));
            plot.drawPoints(vX, vY).pointType(0).label("Inputs class : " + std::to_string(i));
        }
    }
    if(title.empty())
        plot.legend().hide();
    else
        plot.legend().title(title).titleCenter().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
    return plot;
}

Plot SciplotHelper::drawBoundariesDecisionZones(std::vector<double> x, std::vector<double> y, std::vector<std::vector<double>> outputs, Model * model,std::string title) {
    double maxX = Util::findMax(x);
    double maxY = Util::findMax(y);
    double minX = Util::findMin(x);
    double minY = Util::findMin(y);
    Vec vecX = linspace(minX-1, maxX+1,100);
    Vec vecY = linspace(minY-1,maxY+1,100);
    size_t sizeX, sizeY;
    sizeX = vecX.size();
    sizeY = vecY.size();
    int nbOutput = model->getSynapseLastLayer().size();
    std::vector<Data> output;
    std::vector<Data> entry;
    std::vector<std::vector<double>> vX;
    std::vector<std::vector<double>> vY;
    for(int i=0;i<nbOutput;i++)
    {
        vX.push_back({});
        vY.push_back({});
    }
    Seuil* seuil = model->getSeuilLastLayer();

    std::cout<<"X size : " << x.size()<<std::endl;
    if(nbOutput==1)
    {
        vX.push_back({});
        vY.push_back({});

        for(int i =0;i<sizeX;i++)
        {
            for(int j =0;j<sizeY;j++)
            {
                entry.clear();
                entry.push_back(Data(DATA_TYPE_NUMERIC,std::to_string(vecX[i])));
                entry.push_back(Data(DATA_TYPE_NUMERIC, std::to_string(vecY[j])));
                output = model->predict(entry);
                if(seuil->isActive(output[0].getNumericData())){
                    vX[0].push_back(vecX[i]);
                    vY[0].push_back(vecY[j]);
                }
                else
                {
                    vX[1].push_back(vecX[i]);
                    vY[1].push_back(vecY[j]);
                }
            }
        }
    }
    else {
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                entry.clear();
                entry.push_back(Data(DATA_TYPE_NUMERIC, std::to_string(vecX[i])));
                entry.push_back(Data(DATA_TYPE_NUMERIC, std::to_string(vecY[j])));
                output = model->predict(entry);

                for (int k = 0; k < nbOutput; k++) {
                    if (seuil->isActive(output[k].getNumericData())) {
                        vX[k].push_back(vecX[i]);
                        vY[k].push_back(vecY[j]);
                        break;
                    }
                }
            }
        }
    }
    /// Plotting entries
    /*Vec tmpX(std::valarray<double>(x.data(), x.size()));
    Vec tmpY(std::valarray<double>(y.data(), y.size()));
    plot.drawPoints(tmpX, tmpY).label("Entree");*/
    std::vector<std::vector<double>> xClassified, yClassified;
    int nbEntries = x.size();
    Plot plot;

    for(int i = 0;i<2;i++)
    {
        xClassified.emplace_back();
        yClassified.emplace_back();
    }

    ///Plotting area
    int nbOutputTmp = nbOutput==1?nbOutput+1:nbOutput;
    for(int i = 0;i<nbOutputTmp;i++)
    {
        Vec tmpX(std::valarray<double>(vX[i].data(), vX[i].size()));
        Vec tmpY(std::valarray<double>(vY[i].data(), vY[i].size()));
        plot.drawPoints(tmpX, tmpY).label("Zone : " + std::to_string(i));
    }
    if(nbOutput>1) {
        for (int i = 2; i < nbOutput; i++) {
            xClassified.emplace_back();
            yClassified.emplace_back();
        }
        for (int i = 0; i < nbEntries; i++) {
            for (int j = 0; j < nbOutput; j++) {
                if (seuil->isActive(outputs[i][j])) {
                    xClassified[j].push_back(x[i]);
                    yClassified[j].push_back(y[i]);
                    break;
                }
            }
        }
        for (int i = 0; i < nbOutput; i++) {
            Vec vX((std::valarray<double>(xClassified[i].data(), xClassified[i].size())));
            Vec vY(std::valarray<double>(yClassified[i].data(), yClassified[i].size()));
            plot.drawPoints(vX, vY).pointType(0).label("Inputs class : " + std::to_string(i));
        }
    }
    else{
        for(int i = 0;i<nbEntries;i++)
        {
            if(seuil->isActive(outputs[i][0])){
                xClassified[0].push_back(x[i]);
                yClassified[0].push_back(y[i]);
            }
            else{
                xClassified[1].push_back(x[i]);
                yClassified[1].push_back(y[i]);
            }
        }
        for(int i =0;i<2;i++) {
            Vec vX(std::valarray<double>(xClassified[i].data(), xClassified[i].size()));
            Vec vY(std::valarray<double>(yClassified[i].data(), yClassified[i].size()));
            plot.drawPoints(vX, vY).pointType(0).label("Inputs class : " + std::to_string(i));
        }
    }
    plot.xlabel("x");
    plot.ylabel("y");
    if(title.empty())
        plot.legend().hide();
    else
        plot.legend().title(title).titleCenter().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
    return plot;
}

Plot SciplotHelper::drawRegressionCurve(std::vector<double> x, std::vector<double> y, Model * model, std::string title) {
    double maxX = Util::findMax(x);
    double minX = Util::findMin(x);
    double minY = Util::findMin(y);
    double maxY = Util::findMax(y);
    Vec vecX = linspace(minX, maxX,100);
    Vec vecY = linspace(minY,maxY,100);
    std::cout<<"MinX = " <<minX << "MaxX = " << maxX;
    Seuil* seuil = model->getSeuilLastLayer();
    size_t size = vecX.size();
    std::vector<double> yPredict;
    std::vector<Data> output;
    std::vector<Data> entry;

    for(int i =0;i<size;i++)
    {
        entry.clear();
        entry.push_back(Data(DATA_TYPE_NUMERIC,std::to_string(vecX[i])));
        output = model->predict(entry);
        yPredict.push_back(output[0].getNumericData());
        std::cout<<"Pour X : " << vecX[i]<< " Y = " << output[0].getNumericData()<<std::endl;
    }
    Plot plot;
    /*plot.xrange(minX-1,maxX+1);
    plot.yrange(minY-1,maxY+1);*/

    Vec tmpX(std::valarray<double>(x.data(), x.size()));
    std::cout<<"X size : " << x.size()<< " Ypredict size : " << yPredict.size()<<std::endl;
    Vec yVecPredict(std::valarray<double>(yPredict.data(),yPredict.size()));
    plot.drawCurve(vecX,yVecPredict).label("Regression curve");
    plot.xlabel("x");
    plot.ylabel("y");
    Vec tmpY(std::valarray<double>(y.data(), y.size()));
    plot.drawPoints(tmpX, tmpY).label("Inputs");
    if(title.empty())
        plot.legend().hide();
    else
        plot.legend().title(title).titleCenter().atOutsideBottom().displayHorizontal().displayExpandWidthBy(2);
    return plot;
}

void SciplotHelper::putEntries(std::vector<double> x, std::vector<double> y, std::string color, std::string label) {

}

void SciplotHelper::putEntry(std::vector<double> x, std::vector<double> y, std::string color, std::string label) {

}

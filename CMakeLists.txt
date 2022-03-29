cmake_minimum_required(VERSION 3.0)
project(MyIALibrary)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyIALibrary main.cpp AILibrary/Dataset/Dataset.cpp AILibrary/Dataset/Dataset.h AILibrary/Dataset/Data.cpp AILibrary/Dataset/Data.h AILibrary/Dataset/DataFactory.cpp AILibrary/Dataset/DataFactory.h AILibrary/Dataset/Util.cpp AILibrary/Dataset/Util.h Perceptron/PerceptronV1Model.cpp Perceptron/PerceptronV1Model.h AILibrary/ModelBase/ModelBase.cpp AILibrary/ModelBase/ModelBase.h Perceptron/PerceptronV2Model.cpp Perceptron/PerceptronV2Model.h AILibrary/ModelBase/WGeneratorFunction.cpp AILibrary/ModelBase/WGeneratorFunction.h Perceptron/PerceptronV3Model.cpp Perceptron/PerceptronV3Model.h AILibrary/Model/Model.cpp AILibrary/Model/Model.h AILibrary/Model/Neurone.cpp AILibrary/Model/Neurone.h AILibrary/Model/Layer.cpp AILibrary/Model/Layer.h AILibrary/DerivedModel/PerceptronModel.cpp AILibrary/DerivedModel/PerceptronModel.h)

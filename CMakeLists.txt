cmake_minimum_required(VERSION 3.0)
project(MyIALibrary)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyIALibrary main.cpp AILibrary/Dataset/Dataset.cpp AILibrary/Dataset/Dataset.h AILibrary/Dataset/Data.cpp AILibrary/Dataset/Data.h AILibrary/Dataset/DataFactory.cpp AILibrary/Dataset/DataFactory.h AILibrary/Dataset/Util.cpp AILibrary/Dataset/Util.h Perceptron/Model.cpp Perceptron/Model.h AILibrary/ModelBase/ModelBase.cpp AILibrary/ModelBase/ModelBase.h)

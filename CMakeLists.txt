cmake_minimum_required(VERSION 3.0)
project(MyIALibrary)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyIALibrary main.cpp AILibrary/Dataset/Dataset.cpp AILibrary/Dataset/Dataset.h AILibrary/Dataset/Data.cpp AILibrary/Dataset/Data.h AILibrary/Dataset/DataFactory.cpp AILibrary/Dataset/DataFactory.h AILibrary/Dataset/Util.cpp AILibrary/Dataset/Util.h AILibrary/Model/Model.cpp AILibrary/Model/Model.h AILibrary/Model/Neurone.cpp AILibrary/Model/Neurone.h AILibrary/Model/Layer.cpp AILibrary/Model/Layer.h AILibrary/DerivedModel/PerceptronModel.cpp AILibrary/DerivedModel/PerceptronModel.h AILibrary/DerivedModel/DGModel.cpp AILibrary/DerivedModel/DGModel.h AILibrary/DerivedModel/AdalineModel.cpp AILibrary/DerivedModel/AdalineModel.h AILibrary/Seuil/SeuilIdentite.cpp AILibrary/Seuil/SeuilIdentite.h AILibrary/Seuil/Seuil.h AILibrary/Seuil/SeuilMarche.cpp AILibrary/Seuil/SeuilMarche.h AILibrary/Seuil/SeuilPReLu.cpp AILibrary/Seuil/SeuilPReLu.h AILibrary/Seuil/SeuilSigmoide.cpp AILibrary/Seuil/SeuilSigmoide.h AILibrary/Seuil/SeuilTangeanteHyperbolique.cpp AILibrary/Seuil/SeuilTangeanteHyperbolique.h AILibrary/Generator/Generator.h AILibrary/Generator/GeneratorOnly0.cpp AILibrary/Generator/GeneratorOnly0.h AILibrary/Generator/GeneratorNormalLaw.cpp AILibrary/Generator/GeneratorNormalLaw.h AILibrary/SciplotHelper/SciplotHelper.cpp AILibrary/SciplotHelper/SciplotHelper.h Demo.cpp Demo.h AILibrary/Seuil/SeuilUtil.cpp AILibrary/Seuil/SeuilUtil.h)
find_package(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_DIRS} )
link_directories( ${PYTHON_LIBRARIES})
target_link_libraries( MyIALibrary ${PYTHON_LIBRARY})
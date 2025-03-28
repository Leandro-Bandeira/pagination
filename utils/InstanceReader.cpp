#include "InstanceReader.hpp"

InstanceReader::InstanceReader(){}


void InstanceReader::readInstance(char *file_path){
    std::ifstream file(file_path);
    std::string line;
    if(!file){
        std::cout << "Erro ao abrir o arquivo\n";
        std::exit(-1);
    }

    std::getline(file, line);
    frames = std::stoi(line);
    
    while(std::getline(file, line)){
       referencies.push_back(std::stoi(line));
    }
}

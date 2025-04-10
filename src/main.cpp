#include <iostream>
#include <string>
#include <vector>
#include "../utils/InstanceReader.hpp"
#include "Fifo.hpp"
#include "LRU.hpp"
#include "OTM.hpp"


int main(int argc, char** argv){  
    InstanceReader reader; // Cria um objeto da classe InstanceReader para ler a instância  
    reader.readInstance(argv[1]); // Lê os dados da instância a partir do arquivo passado como argumento  


    std::vector<int> referencies = reader.getReferencies(); // Obtém a lista de processos lidos  
    int frames = reader.getFrames(); // Obtém o número de quadros lidos

    // for(int i = 0; i < referencies.size(); i++){
    //     std::cout << referencies[i] << "\n";
    // }
    
    /* Fifo algorithm */
    // Fifo fifo(referencies, frames);

    // int count_missed_pages = fifo.algorithm();
    //std::cout << "FIFO: " << count_missed_pages << "\n";

    /* LRU algorithm */
    // LRU lru(referencies, frames);

    // int count_missed_page = lru.algorithm();

    //-----------------testing optimal algorithm-----------------//
    Otm obj_otm(referencies, frames);     
    int missed_pages = obj_otm.algorithm();
    std::cout << "OTM " << missed_pages << std::endl;
}

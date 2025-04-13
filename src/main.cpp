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
    
    /* Fifo algorithm */
    Fifo fifo(referencies, frames);
    int count_missed_pages = fifo.algorithm();
    std::cout << "FIFO " << count_missed_pages << "\n";

     /*Optimal algorithm */
    Otm obj_otm(referencies, frames);     
    count_missed_pages = obj_otm.algorithm();
    std::cout << "OTM " << count_missed_pages << std::endl;

    /* LRU algorithm */
    LRU lru(referencies, frames);
    count_missed_pages = lru.algorithm();
    std::cout << "LRU " << count_missed_pages << "\n";
}

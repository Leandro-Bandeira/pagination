#include "OTM.hpp"


int Otm::algorithm(){

    int memory[frames];

    for (int i = 0; i < frames; ++i) {
        memory[i] = -1; 
    }

    for(int i = 0; i < references.size(); i++){

        int reference = references[i];

        bool finded = 0;
        int has_space = -1;
        for(int j = 0; j < frames; j++){
            
            if(reference == memory[j]){
                finded = 1;
                break;
            } 

            if(memory[j] == -1 && has_space == -1){
                has_space = j;
            }
        }

        if(finded){        //se a referencia solicitada já está na memoria entao vamos pra prox 
            continue;
        }

        fouls += 1;  //senão foi achado então houve falta:

        if (has_space != -1){   //tem espaco vazio
            memory[has_space] = reference;

        }else{  //nao tem espaco vazio, tem q substituir uma referencia já exisente

            int counter_references[frames] = {};  //inicalizando o vetor de contadores com 0
            for(int j : memory){
                for(int k = i+1; k < references.size(); k++){

                    if(memory[j] == references[k]){
                        counter_references[j] += 1;
                    }
                }
            }
            
            int size = sizeof(counter_references) / sizeof(counter_references[0]);
            int* maxPtr = std::min_element(counter_references, counter_references + size);  //encontra o menor numero no array
            int index = maxPtr - counter_references;  
            memory[index] = reference; //substituo a pagina que terá menos referencias no futuro pela a que precisa entrar agora    
        }
    }

    return fouls;
}



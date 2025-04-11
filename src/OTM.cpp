#include "OTM.hpp"
#include <iostream>
#include <algorithm>


int Otm::algorithm(){

    int memory[frames];

    for (int i = 0; i < frames; ++i) {
        memory[i] = -1; 
    }

    for(int i = 0; i < references.size(); i++){

        int reference = references[i];

        bool finded = 0;
        int has_space = -1;

        //debug
        // std::cout << "memoria: ";
        // for(int j = 0; j < frames; j++){
            
        //     std::cout << memory[j] << " ";
        // }
        // cout << " " << std::endl;

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
            int order_references[frames]; 

            for(int j = 0; j < frames; j++){
                order_references[j] = 9999999;         //pra ele ser escolhido se nao for chamado pq significa q ele nunca apareceu mais
            }

            for(int j = 0; j < frames; j++){
                int counter = 0;
                for(int k = i+1; k < references.size(); k++){  //começamos do ponto que estamos em frente (i+1)

                    if(memory[j] == references[k]){
                        order_references[j] = counter;
                        break;
                    }
                    counter++;
                }
            }
            
            int size = sizeof(order_references) / sizeof(order_references[0]);
            int* maxPtr = std::max_element(order_references, order_references + size);  //encontra o maior numero no array (o que demorará mais pra aparecer)
            int index = maxPtr - order_references;
            memory[index] = reference; //substituo a pagina que terá a referencia mais distante no futuro pela a que precisa entrar agora    
        }
    }

    return fouls;
}



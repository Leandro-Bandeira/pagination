#include "Fifo.hpp"
#include <algorithm>
#include <iostream>
int Fifo::algorithm(){
  /* Vector responsável por armazenar os elementos na fila */
  std::vector <int> fifo;
  fifo.clear();
  int max_value = *std::max_element(referencies.begin(), referencies.end());

  std::cout << "maxValue:" << max_value << "\n";
   /* Vector responsável por indicar se o valor está na página */
  std::vector<int> inPage(max_value + 1, 0);

  // Falta de pagina
  int count_missed_page = 0;
  // Indice que percorre o vetor FIFO
  int indice_to_remove = 0;
  
  std::cout << "---------------------" << "\n";
  for (int i = 0; i < referencies.size(); i++){
    std::cout << "referencie: " << referencies[i] << "\n";
    std::cout << "InPage: " << inPage[referencies[i]] << "\n";
    /* Se nao preenchemos todos os frames, temos todos em falta de pagina */
    if (count_missed_page < frames){
      if (!inPage[referencies[i]]) {
        fifo.push_back(referencies[i]);
        count_missed_page++;
        inPage[referencies[i]] = 1;
      }    
    }else{
      /* Se ocorrer uma referencia
      * que nao esta no frame removemos o valor da FIFO e atualizamos com o novo valor da  FIFO
      * Altera inPage do valor antigo  para zero e novo para 1, porque removemos um valor e conta falta de pagina
      */
      if(!inPage[referencies[i]]) {
        int value_removed = fifo[indice_to_remove];
        std::cout << "value removed: " << value_removed << "\n";
        std::cout << "value entrando: " << referencies[i] << "\n";
        fifo[indice_to_remove] = referencies[i];
        indice_to_remove = (indice_to_remove + 1) % frames;
        inPage[value_removed] = 0;
        inPage[referencies[i]] = 1;
        count_missed_page++;
      }
    }
    std::cout << "count_missed_page: " <<  count_missed_page << "\n";
       
  
  }

  return count_missed_page;
  
  
}

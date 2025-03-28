#include "Fifo.hpp"
#include <algorithm>

int Fifo::algorithm(){
  /* Vector responsável por armazenar os elementos na fila */
  std::vector <int> fifo(frames + 1, 0);
  fifo.clear();

  int max_value = *std::max(referencies.begin(), referencies.end());

  /* Vector responsável por indicar se o valor está na página */
  std::vector<int> inPage(max_value + 1, 0);

  // Falta de pagina
  int count_missed_page = 0;
  // Indice que percorre o vetor FIFO
  int indice_to_remove = 0;
  
  for (int i = 0; i < referencies.size(); i++){

    /* Se nao preenchemos todos os frames, temos todos em falta de pagina */
    if (count_missed_page < frames){
      fifo[count_missed_page] = referencies[i];    
      count_missed_page++;
      inPage[referencies[i]] = 1;
      
    }else{
      /* Se ocorrer uma referencia
      * que nao esta no frame "removemos" o valor da FIFO e continua na FIFO
      * Altera inPage para zero, porque removemos um valor e conta falta de pagina
      */
      if(!inPage[referencies[i]]) {
        int value_removed = fifo[indice_to_remove];
        indice_to_remove++;
        if (indice_to_remove == fifo.size()){
          indice_to_remove = 0;
        }
        inPage[value_removed] = 0;
        inPage[referencies[i]] = 1;
        count_missed_page++;
      }
    }
    
  
  }

  return count_missed_page;
  
  
}

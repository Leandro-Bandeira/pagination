#include "Fifo.hpp"
#include <algorithm>

void Fifo::algorithm(){
  /* Vector responsável por armazenar os elementos na fila */
  std::vector <int> fifo(frames + 1, 0);
  fifo.clear();

  int max_value = *std::max(referencies.begin(), referencies.end());

  /* Vector responsável por indicar se o valor está na página */
  std::vector<int> inPage(max_value + 1, 0);

  int count_missed_page = 0;

  for (int i = 0; i < referencies.size(); i++){
    
    if (count_missed_page <= frames){
      fifo[count_missed_page] = referencies[i];    
      count_missed_page++;
      inPage[referencies[i]] = 1;
      
    }else{
      if(!inPage[referencies[i]]) {
        int value_removed = fifo.front();
        fifo.remove(fifo.begin());
        inPage[value_removed] = 0;
      }
    }
    
  
  }
  
  
}

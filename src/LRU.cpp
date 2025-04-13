#include "LRU.hpp"
#include <iostream>
#include <algorithm>
#include <list>

typedef struct{
  int page_value;
  std::list<int>::iterator page_it;
}tPage;

int LRU::algorithm(){
  int count_missed_page = 0;

  /* Encontra o maior valor das paginas referenciadas */ 
  int max_value = *std::max_element(referencies.begin(), referencies.end());

  /* Cria um vetor indicando se a pagina foi referenciada */ 
  std::vector <tPage> inPage(max_value + 1);

  for(int i = 0; i < inPage.size(); i++){
    inPage[i].page_value = 0;
  }

  /* Pilha duplamente encadeada */ 
  std::list <int> stack;
  stack.clear();
  for(int i = 0; i < referencies.size(); i++){

    if (!inPage[referencies[i]].page_value){
        if (count_missed_page < frames){
          /* Quando n~ao esta referenciado, e nao preenchemos completamente o frame, so adicionamos no inicio */ 
          inPage[referencies[i]].page_it = stack.insert(stack.begin(), referencies[i]);
        }
        else{
          /* caso ele nao esteja referenciado
          * revemos o valor no final e colocamos o novo valor, como foi referenciado coloca no topo da pilha */ 
          int value_removed = stack.back();
          inPage[value_removed].page_value = 0;
          stack.pop_back();
          inPage[referencies[i]].page_it = stack.insert(stack.end(), referencies[i]);
          stack.splice(stack.begin(), stack, inPage[referencies[i]].page_it);
        }
    
        inPage[referencies[i]].page_value = 1;
        count_missed_page++;
    }
    else{
        /* Se ele ja estava na stack, vamos alterar sua posicao */
        stack.splice(stack.begin(), stack, inPage[referencies[i]].page_it);
    }
    
  }
  
  return count_missed_page;
}

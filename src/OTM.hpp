#ifndef OTM_H
#define OTM_H

#include <vector>

class Otm{
    public:
      Otm(std::vector <int>& referencies, int frames)
        :references(referencies), frames(frames) { fouls = 0;}    

      int algorithm();        
    private:
        std::vector<int> references;  //referencias às paginas
        const int frames;
        int fouls;  //qtd de vezes que a pagina faltou
      
};


#endif
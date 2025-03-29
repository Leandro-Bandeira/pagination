#ifndef LRU_H
#define LRU_H

#include <vector>


class LRU{
    public:
      LRU(std::vector <int>& referencies, int frames)
        :referencies(referencies), frames(frames) {}

      int algorithm();        
    private:
        std::vector <int> referencies;
        int frames;
      
};


#endif

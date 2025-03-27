#ifndef FIFO_H
#define FIFO_H

#include <cmath>
#include <vector>

class Fifo{
  public:
    Fifo(std::vector <int> &referencies)
      :referencies(referencies) {}
     void algorithm();   
  private:
      std::vector <int> referencies;
};
#endif FIFO_H

#ifndef FIFO_H
#define FIFO_H

#include <cmath>
#include <vector>

class Fifo{
  public:
    Fifo(std::vector <int> &referencies, int frames)
      :referencies(referencies), frames(frames) {}
     int algorithm();   
  private:
      std::vector <int> referencies;
      int frames;
};
#endif FIFO_H

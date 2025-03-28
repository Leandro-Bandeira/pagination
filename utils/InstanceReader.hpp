#ifndef INSTANCE_READER
#define INSTANCE_READER

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


class InstanceReader{
    public:
        InstanceReader();
        void readInstance(char* filePath);
        std::vector<int>& getReferencies() {return referencies;};
        int getFrames() {return frames;};
    private:
        std::vector<int> referencies;
        int frames;
};




#endif
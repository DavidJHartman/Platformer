#ifndef LAYER_HPP_INCLUDED
#define LAYER_HPP_INCLUDED
#include <vector>

class Layer {
public:
    std::string name;
    int width;
    int height;

    std::vector<int> Tiles;


};

#endif // LAYER_HPP_INCLUDED

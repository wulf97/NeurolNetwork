#ifndef NEURONLAYER_H
#define NEURONLAYER_H

#include "NeuralNetwork.h"

using namespace std;

namespace nn {
class NeuronLayer {
private:
    nn::NeuralNetwork *_parent = NULL;
    int _nNeurons;
    int _nin;
    vector<Neuron*> _neuron;
public:
    NeuronLayer(int nNeurons = 5, int nin = 0);
    ~NeuronLayer();

    nn::Neuron operator [] (int);

    void setParent(nn::NeuralNetwork*);
    void add(nn::Neuron&);
    void setNin(int);
    void initWeigh(void);
    int size(void);
    nn::Neuron get(int);
    void print(void);
};
}

#endif // NEURONLAYER_H

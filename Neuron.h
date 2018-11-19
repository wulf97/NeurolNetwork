#ifndef NEURON_H
#define NEURON_H

#include "NeuralNetwork.h"

using namespace std;

namespace nn {
class Neuron {
private:
    NeuronLayer *_parent = NULL;
    int _nin;
    vector<float> _weigh;
public:
    Neuron();
    Neuron(nn::Neuron&);
    ~Neuron();

    void operator = (Neuron&);
    float operator [] (int);

    void setParent(nn::NeuronLayer*);
    void setNin(int);
    void initWeigh(void);
    void setWeigh(void);
    float get(int);
    int size(void);
    void print(void);
};
}
#endif // NEURON_H

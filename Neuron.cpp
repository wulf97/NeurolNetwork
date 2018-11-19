#include "NeuralNetwork.h"

/*****************************************************/
/********************** Neuron ***********************/
/*****************************************************/

nn::Neuron::Neuron(int nin) {
    this->setNin(nin);
}

nn::Neuron::Neuron(nn::Neuron &neuron) {
    this->_nin = neuron._nin;
    for (int i = 0; i < neuron._weigh.size(); i++) {
        this->_weigh.push_back(neuron._weigh[i]);
    }
}
nn::Neuron::~Neuron() {

}

void nn::Neuron::operator = (Neuron &neuron)  {
    this->_nin = neuron._nin;
    for (int i = 0; i < neuron._weigh.size(); i++) {
        this->_weigh.push_back(neuron._weigh[i]);
    }
}

float nn::Neuron::operator [] (int i) {
    return this->_weigh[i];
}

void nn::Neuron::setParent(nn::NeuronLayer *p) {
    this->_parent = p;
}

void nn::Neuron::setNin(int nin) {
    this->_weigh.resize(nin);
    this->_nin = nin;
}

void nn::Neuron::initWeigh(void) {
    for (int i = 0; i < this->_weigh.size(); i++)
        this->_weigh[i] = (float)rand() / RAND_MAX;
}

float nn::Neuron::get(int i) {
    return this->_weigh[i];
}

void nn::Neuron::setInput(vector<float> &v) {
    this->_preWeightSum = this->_curWeightSum;
    this->_curWeightSum = 0;
    if (this->_weigh.size() == v.size()) {
        for (int i = 0; i < v.size(); i++) {
            this->_curWeightSum += this->_weigh[i] * v[i];
        }
        this->_preOut = this->_curOut;
        this->_curOut = this->_curWeightSum;
    } else {
        cout << "ERROR: this->_weigh.size != v.size" << endl;
    }
}

float nn::Neuron::getWeightSum(void) {
    return this->_curWeightSum;
}

float nn::Neuron::getOut() {
    return this->_curOut;
}

int nn::Neuron::size(void) {
    return this->_weigh.size();
}

void nn::Neuron::print(void) {
    cout << "Total: " << this->_nin << endl;
    cout << "[";
    for (int i = 0; i < this->_weigh.size(); i++)
        cout << this->_weigh[i] << " ";
    cout << "]" << endl << endl;
}

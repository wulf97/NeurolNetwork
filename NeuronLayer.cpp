#include "NeuralNetwork.h"

/*****************************************************/
/******************* NeuronLayer *********************/
/*****************************************************/

nn::NeuronLayer::NeuronLayer(int nNeurons, int nin) {
    this->_nNeurons = nNeurons;
    this->_nin = nin;
    for (int i = 0; i < nNeurons; i++)
        this->add(*(new nn::Neuron()));

    this->initWeigh();
}

nn::NeuronLayer::~NeuronLayer() {

}

nn::Neuron nn::NeuronLayer::operator [](int i) {
    return *this->_neuron[i];
}

void nn::NeuronLayer::setParent(nn::NeuralNetwork *p) {
    this->_parent = p;
}

void nn::NeuronLayer::add(nn::Neuron &neuron) {
    this->_neuron.push_back(&neuron);
    neuron.setNin(this->_nin);
    neuron.setParent(this);
    this->_nNeurons = this->_neuron.size();
}

void nn::NeuronLayer::setNin(int nin) {
    for (int i = 0; i < this->_nNeurons; i++) {
        this->_neuron[i]->setNin(nin);
    }
    this->_nin = nin;
}

void nn::NeuronLayer::initWeigh(void) {
    for (int i = 0; i < this->_nNeurons; i++) {
        this->_neuron[i]->initWeigh();
    }
}

nn::Neuron nn::NeuronLayer::get(int i) {
    return *this->_neuron[i];
}

vector<float> &nn::NeuronLayer::getWeightSum(void) {
    vector<float> v(0);

    for (int i = 0; i < this->_nNeurons; i++)
        v.push_back(this->_neuron[i]->getWeightSum());

    return v;
}

vector<float> *nn::NeuronLayer::getOut(void) {
    vector<float> *v = new vector<float>;

    for (int i = 0; i < this->_nNeurons; i++)
        v->push_back(this->_neuron[i]->getOut());

    return v;
}

void nn::NeuronLayer::setInput(vector<float> &v) {
    for (int i = 0; i < this->_nNeurons; i++)
        this->_neuron[i]->setInput(v);
}

int nn::NeuronLayer::size(void) {
    return  this->_nNeurons;
}

void nn::NeuronLayer::printWeightSum(void) {
    cout << "[";
    for (int i = 0; i < this->_nNeurons; i++) {
        cout << this->_neuron[i]->getWeightSum() << " ";
    }
    cout << "]" << endl << endl;
}

void nn::NeuronLayer::printOut(void) {
    cout << "[";
    for (int i = 0; i < this->_nNeurons; i++) {
        cout << this->_neuron[i]->getOut() << " ";
    }
    cout << "]" << endl << endl;
}

void nn::NeuronLayer::print(void) {
    for (int i = 0; i < this->_nNeurons; i++) {
        cout << "Neuron " << i << ":" << endl;
        this->_neuron[i]->print();
    }
}

#include "NeuralNetwork.h"

/*****************************************************/
/****************** NeuralNetwork ********************/
/*****************************************************/
nn::NeuralNetwork::NeuralNetwork(int nin, int nout) {
    this->_nin = nin;
    this->_nout = nout;
    this->_outLayer = new nn::NeuronLayer(nout);
    this->_outLayer->setNin(nin);
    this->_outLayer->setParent(this);
}

nn::NeuralNetwork::~NeuralNetwork() {

}

nn::NeuronLayer nn::NeuralNetwork::operator [] (int i) {
    return *(this->_layer[i]);
}

void nn::NeuralNetwork::add(nn::NeuronLayer &layer) {
    if (this->_layer.size() == 0)
        layer.setNin(this->_nin);
    else
        layer.setNin(this->_layer.back()->size());

    this->_layer.push_back(&layer);
    this->_outLayer->setNin(layer.size());
    layer.setParent(this);
}

nn::NeuronLayer nn::NeuralNetwork::get(int i) {
    return *(this->_layer[i]);
}

void nn::NeuralNetwork::initWeigh(void) {
    for (int i = 0; i < this->_layer.size(); i++) {
        this->_layer[i]->initWeigh();
    }

    this->_outLayer->initWeigh();
}

void nn::NeuralNetwork::setInput(vector<float> *v) {
    if (this->_layer.size() == 0) {
        this->_outLayer->setInput(*v);
    } else {
        this->_layer[0]->setInput(*v);
        for (int i = 1; i < this->_layer.size(); i++)
            this->_layer[i]->setInput(*this->_layer[i - 1]->getOut());
        this->_outLayer->setInput(*this->_layer[this->_layer.size() - 1]->getOut());
    }
}

int nn::NeuralNetwork::size(void) {
    return this->_layer.size();
}

void nn::NeuralNetwork::printWeightSum(void) {
    int i;

    for (i = 0; i < this->_layer.size(); i++) {
        cout << "*************************" << endl;
        cout << "* WeightSum of layer: " << i << " *" << endl;
        cout << "*************************" << endl;
        this->_layer[i]->printWeightSum();
    }
    cout << "*************************" << endl;
    cout << "* WeightSum of layer: " << i << " *" << endl;
    cout << "*************************" << endl;
    this->_outLayer->printWeightSum();
}

void nn::NeuralNetwork::printOut(void) {
    int i;

    for (i = 0; i < this->_layer.size(); i++) {
        cout << "*************************" << endl;
        cout << "* Out of layer: " << i << "       *" << endl;
        cout << "*************************" << endl;
        this->_layer[i]->printOut();
    }
    cout << "*************************" << endl;
    cout << "* Out of layer: " << i << "       *" << endl;
    cout << "*************************" << endl;
    this->_outLayer->printOut();
}

void nn::NeuralNetwork::print(void) {
    int i;
    for (i = 0; i < this->_layer.size(); i++) {
        cout << "***************" << endl;
        cout << "*  Layer: " << i << "   *" << endl;
        cout << "***************" << endl;
        this->_layer[i]->print();
    }

    cout << "***************" << endl;
    cout << "*  Layer: " << i + 1 << "   *" << endl;
    cout << "***************" << endl;
    this->_outLayer->print();

}

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <iostream>
#include <vector>

using namespace std;

namespace nn {
class NeuralNetwork;
class NeuronLayer;
class Neuron;

/**********************************/
class NeuralNetwork {
private:
    /* Количество входов НС */
    int _nin;
    /* Количество выходов НС */
    int _nout;
    /* Список слоев НС */
    vector<nn::NeuronLayer*> _layer;
    /* Выходной слой НС */
    nn::NeuronLayer* _outLayer;
public:
    NeuralNetwork(int nin = 1, int nout = 1);
    ~NeuralNetwork();

    nn::NeuronLayer operator [] (int);

    /* Добавить слой в НС */
    void add(nn::NeuronLayer&);
    /* Получить слой НС по индексу */
    nn::NeuronLayer get(int);
    /* Инициализировать синаптические веса НС*/
    void initWeigh(void);
    /* Установить входной сигнал НС */
    void setInput(vector<float>*);
    /* Получить количество слоев в НС */
    int size(void);
    /* Вывести взвешенные суммы выходных нейронов НС*/
    void printWeightSum(void);
    /* Вывести значения на выходе НС*/
    void printOut(void);
    /* Вывести структуру НС*/
    void print(void);
};

/**********************************/
class NeuronLayer {
private:
    /* Указатель на НС, в которой находится слой */
    nn::NeuralNetwork *_parent = NULL;
    /* Количество нейронов в слое НС*/
    int _nNeurons;
    /* Количество входов*/
    int _nin;
    /* Список нейронов в текущем слое */
    vector<Neuron*> _neuron;
public:
    NeuronLayer(int nNeurons = 5, int nin = 0);
    ~NeuronLayer();

    nn::Neuron operator [] (int);

    void setParent(nn::NeuralNetwork*);
    void add(nn::Neuron&);
    void setNin(int);
    void initWeigh(void);
    nn::Neuron get(int);
    vector<float> &getWeightSum(void);
    vector<float> *getOut(void);
    /* Установить входной сигнал слоя НС */
    void setInput(vector<float>&);
    int size(void);
    /* Вывести взвешенные суммы нейронов данного слоя*/
    void printWeightSum(void);
    /* Вывести значения на выходе слоя*/
    void printOut(void);
    /* Вывести структуру слоя*/
    void print(void);
};

/**********************************/
class Neuron {
private:
    /* Указатель на слой, в котором находится нейрон */
    NeuronLayer *_parent = NULL;
    /* Количество входных синапсов */
    int _nin;
    /* Синаптические веса */
    vector<float> _weigh;
    /* Взвешенная сумма на предыдущем шаге */
    float _preWeightSum;
    /* Взвешенная сумма на текущема шаге */
    float _curWeightSum;
    /* Выход функции активации на предыдущем шаге */
    float _preOut;
    /* Выход функции активации на текущем шаге */
    float _curOut;
public:
    Neuron(int nin = 0);
    Neuron(nn::Neuron&);
    ~Neuron();

    void operator = (Neuron&);
    float operator [] (int);

    /* Установить родительский слой НС */
    void setParent(nn::NeuronLayer*);
    /* Установить количество входов нейрона */
    void setNin(int);
    /* Инициализировать синаптические веса нейрона */
    void initWeigh(void);
    /* Получить синаптический вес по индексу */
    float get(int);
    /* Установить входной сигнал нейрона */
    void setInput(vector<float>&);
    /* Получить взвешенную сумму нейрона */
    float getWeightSum(void);
    /* Получить значение на выходе нейрона */
    float getOut(void);
    /* Получить количество входов нейрона */
    int size(void);
    /* Вывести структуру нейрона */
    void print(void);
};
}

#endif // NEURALNETWORK_H

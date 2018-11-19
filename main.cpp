#include <QCoreApplication>
#include <iostream>
#include "NeuralNetwork.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    vector<float> *in = new vector<float>;
    in->push_back(2.2);
    in->push_back(3.8);
    in->push_back(1.3);
    nn::NeuralNetwork net(3, 5);
    nn::NeuronLayer l1(3);
    nn::NeuronLayer l2(4);

    net.add(l1);
    net.add(l2);

    net.initWeigh();
    net.print();
    cout << "******************************************************************" << endl;
    net.setInput(in);

    net.printWeightSum();
     cout << "******************************************************************" << endl;
    net.printOut();

    return a.exec();
}

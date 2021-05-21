#ifndef MODEL_H_
#define MODEL_H_

#include "iostream"

class Model{
private:
    int type;
    int model;
    int grade=0;
    int numSold=0;
public:
    Model(int type, int model);
    void sold();
    void complaint(int numMonths);
    bool operator==(const Model& other);
    bool operator>(const Model& other);
    bool operator<(const Model& other);
};

#endif




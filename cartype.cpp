#include "cartype.h"
#include "iostream"

CarType::CarType(int type, int numOfModels):type(type)
{
    models = new AVLTree<Model>();
    //initializing a sorted array for insert into AVLTree
    int modelsarr[numOfModels]
    for(i=0; i<numOfModels; i++)
    {
        modelsarr[i]=i;
    }
    if(!arrToTree(modelsarr, 0, numOfModels-1))
    {
        delete models;
        // throw exception??
    }
    // the model with the highest value at initialization
    // is defined to be the model with the lowest model number
    // which is defined as the best selling model at initialization
    mostSold=models->highest;
}

//destructor for CarType, must delete models
CarType::~CarType()
{
    delete models;
}

// here we have two options,
// 1. make cartype inherit from AVLTree
// 2. make a method that returns a pointer to a node
// which can than be used to update the data of model
// right now im am implenting in the 2. way
bool CarType::sellModel(int model)
{
    // find the node which contains the model
    Node* sold = models->findNode(Model(type,model));
    if(sold != nullptr)
    {
        sold->data->sold();
        //check if we must update mostSold
        if(sold->data->numSold > mostSold->data->numSold)
            mostSold=sold;
        return true
    }
    return false;
}



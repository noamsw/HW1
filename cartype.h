#ifndef CAR_TYPE_H_
#define CAR_TYPE_H_

#include "AVL.h"
#include "model.h"

class CarType
{
    AVLTree<Model>* models;
    int type;
    Node* mostSold;
public:
    // constructor
    CarType(int type, int numOfModels);
    ~CarType();
    // method to sell a specific model in cartype
    bool sellModel(int model);
    // returns the model number of the best seller
    int getBestSeller();
    // comparing method between to cartypes
    // detertmined by typeid
    bool operator<(const CarType& cartype);
    bool operator>(const CarType& cartype);
private:
    // function used to initialize models tree
    // in O(n), by using a sorted array
    bool arrToTree(int arr[], int start, int end);

}

#endif
#include "model.h"

// constuctor for Model. grade is initialized to 0 
Model::Model(int type, int model):type(type),model(model){};

// updates grade when a model is sold
void Model::sold()
{
    grade = grade+10;
    sold = sold+1;
}

// updates grade when a model recieves a complaint
void Model::complaint(int numMonths)
{
    int lowered = 100/numMonths;
    grade = grade - lowered
}

// comparing operator, returns true if equal
// cars are equal to one another if
// both type and model are equal
bool Model::operator==(const Model& other)
{
    if(type == other.type && model == other.model)
        return true;
    return false;
}

// comparing operator, compares grades of cars
bool Model::operator<(const Model& other)
{
    // if the grade is smaller, return true
    if(grade < other.grade){
        return true;
    }
    // otherwise check if the grade is equal
    if(grade == other.grade)
    {
        // now, if the grade is equal, but the type is bigger
        // than it is still smaller, return true
        if(type > other.type)
            return true;
        // if the type is equal, check that the model is larger
        if(type == other.type)
            if(model > other.model)
                return true;
    }
    // the grade is either smaller
    // or the grade is equal but the type is smaller
    // or the grade and type are equal but the model is smaller
    // in all of these cases the car is a better model
    // return false
    return false; 
}

// comparing operator, compares grades of cars
bool Model::operator>(const Model& other)
{
    // check if the model is smaller
    // if not, it is larger as there are no two different models that are equal
    return !(this < other);
}
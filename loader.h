//
// Created by JHKim on 16/11/2017.
//
#ifndef LOADER_H
#define LOADER_H

#include "uncertainGraph.h"

template <class T>
class Loader {
private:
    T temp;
public:
    UncertainGraph<T>* load(char* fileName);
};
#endif

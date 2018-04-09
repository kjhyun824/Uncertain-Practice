//
// Created by JHKim on 16/11/2017.
//
#include <fstream>
#include <sstream>
#include "loader.h"

template <class T>
UncertainGraph<T>* Loader<T>::load(char* fileName) {
    UncertainGraph<T> *UG;

    std::fstream file;
    file.open(fileName);

    string line;

    UG = new UncertainGraph<T>();

    while(std::getline(file,line)) {
        std::istringstream iss(line);

        vid_t src, dst;
        weight_t weight = 1;
        prob_t prob;
        if(!(iss >> src >> dst >> prob)) break;

        if(src == dst) continue;
        UG->addEdge(src,dst,weight,prob);
    }

    int numVertex = UG->getNumVertices();
    Vertex<T>* allVertices = UG->getVertices();

    for(int i = 0; i < numVertex; i++) {
        allVertices[i].bitmapInit();
    }

    return UG;
}


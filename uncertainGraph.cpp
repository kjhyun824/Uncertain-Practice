//
// Created by JHKim on 16/11/2017.
//
#include "uncertainGraph.h"

template <class T>
UncertainGraph<T>::UncertainGraph() {
    numVertices = 0;
    numEdges = 0;
    maxVid = -1;
    vertices = NULL;
    capacity = 0;
}

template <class T>
bool UncertainGraph<T>::addEdge(vid_t src, vid_t dst, weight_t weight, prob_t prob) {
    createVertex(src,dst);

    Vertex<T> _src = vertices[src];
    Vertex<T> _dst = vertices[dst];

    bool isAdded = _src.addNeighborId(dst,weight,prob);

    if(isAdded) {
        _src.increaseOutDegree();
        _dst.increaseInDegree();
        numEdges++;
    }

    return isAdded;
}

template <class T>
void UncertainGraph<T>::createVertex(vid_t src, vid_t dst) {
    vid_t bigger = (src > dst) ? src : dst;
    if(bigger > maxVid) {
        setMaxVid(bigger);
    }
    ensureVertexCapacity(bigger+1);
    ensureVertexEntry(src);
    ensureVertexEntry(dst);
}

template <class T>
void UncertainGraph<T>::ensureVertexCapacity(int capacity) {
    if(this->capacity < capacity) {
        int doubled = this->capacity * 2;
        int newCapacity = (doubled > capacity) ? doubled : capacity;
        Vertex<T> *tmp = new Vertex<T>[newCapacity];
        for(int i = 0; i < this->capacity; i++) {
            tmp[i] = vertices[i];
        }
        delete [] vertices;
        vertices = tmp;
    }
}

template <class T>
void UncertainGraph<T>::ensureVertexEntry(int entry) {
    Vertex<T> v = vertices[entry];
    if(v.getVid() == -1) {
        v.setVid(entry);
        numVertices++;
    }
}

template <class T>
void UncertainGraph<T>::generatePWG(int numVertices) {
    for(int i = 0; i < numVertices; i++) {
        int vid = rand() % this->numVertices;
        vertices[vid].shuffleBitmap();
    }
}

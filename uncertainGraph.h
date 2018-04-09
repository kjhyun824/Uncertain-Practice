//
// Created by JHKim on 16/11/2017.
//
#ifndef UNCERTAINGRAPH_H
#define UNCERTAINGRAPH_H

#include "global.hpp"
#include "vertex.h"

template <class T>
class UncertainGraph {
private:
    int numVertices;
    int numEdges;
    vid_t maxVid;

    Vertex<T> *vertices;
    int capacity;

public:
    UncertainGraph();

    inline int getNumVertices() { return numVertices; }
    inline int getNumEdges() { return numEdges; }
    inline Vertex<T>* getVertices() { return vertices; }
    inline vid_t getMaxVid() { return maxVid; }
    Vertex<T> getVertex(vid_t vid) { return vertices[vid]; }

    void setMaxVid(vid_t vid) { this->maxVid= vid; }

    bool addEdge(vid_t src, vid_t dst, weight_t weight, prob_t prob);
    void createVertex(vid_t src, vid_t dst);
    void ensureVertexCapacity(int capacity);
    void ensureVertexEntry(int entry);

    void generatePWG(int numVertices);
};

#endif

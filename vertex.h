//
// Created by JHKim on 16/11/2017.
//
#ifndef VERTEX_H
#define VERTEX_H

#include <sstream>
#include "global.hpp"

template <class T>
class Vertex {
private:
    vid_t vid;
    int outDegree;
    int inDegree;
    int numActivated;

    vector<vid_t> neighbors;
    vector<weight_t> weights;
    vector<prob_t> probs;

    boost::dynamic_bitset<>* activated;

    T value;

public:
    Vertex();

    inline vid_t getVid() { return vid; }
    inline int getOutDegree() { return outDegree; }
    inline int getInDegree() { return inDegree; }
    inline int getNumActivated() { return numActivated; }
    inline vector<vid_t> &getNeighbors() { return neighbors; }
    inline vector<weight_t> &getWeights() { return weights; }
    inline vector<prob_t> &getProbs() { return probs; }
    inline vid_t getOutEdge(int idx) { return neighbors[idx]; }
    inline weight_t getWeight(vid_t nid) { return weights[getNeighborIdx(nid)]; }
    inline prob_t getProb(vid_t nid) { return probs[getNeighborIdx(nid)]; }
    inline T getValue() { return value; }

    inline void setVid(vid_t vid) { this->vid = vid; }
    inline void setOutDegree(int outDegree) { this->outDegree = outDegree; }
    inline void setInDegree(int inDegree) { this->inDegree = inDegree; }
    inline void setNumActivated(int numActivated) { this->numActivated = numActivated; }
    inline void setValue(T value) { this->value = value; }

    inline void increaseOutDegree() { this->outDegree++; }
    inline void increaseInDegree() { this->inDegree++; }

    inline void clearVector() {
            neighbors.clear();
            weights.clear();
            probs.clear();

            vector<vid_t>().swap(neighbors);
            vector<weight_t>().swap(weights);
            vector<prob_t>().swap(probs);

            outDegree = 0;
            inDegree = 0;
    }

    int binarySearch(vid_t dst);
    bool addNeighborId(vid_t dst, weight_t weight, prob_t prob);
    int getNeighborIdx(vid_t nid);

    void bitmapInit();
    void shuffleBitmap();

    string toString();
};

#endif

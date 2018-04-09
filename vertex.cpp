//
// Created by JHKim on 16/11/2017.
//
#include "vertex.h"

template <class T>
Vertex<T>::Vertex() {
    vid = -1;
    outDegree = 0;
    inDegree = 0;
}

template <class T>
int Vertex<T>::binarySearch(vid_t dst) {
    int low = 0;
    int high = neighbors.size() - 1;

    while(low <= high) {
        int mid = (low + high) >> 1;
        int midVal = neighbors[mid];
        if(midVal < dst) {
            low = mid + 1;
        } else {
            if(midVal == dst) {
                return mid;
            }

            high = mid - 1;
        }
    }

    return -(low + 1);
}

template <class T>
bool Vertex<T>::addNeighborId(vid_t dst, weight_t weight, prob_t prob) {
    int pos = binarySearch(dst);
    if(pos >= 0)
        return false;
    else {
        pos = -(pos + 1);
        neighbors.insert(neighbors.begin(),pos, dst);
        weights.insert(weights.begin(),pos, weight);
        probs.insert(probs.begin(),pos, prob);

        return true;
    }
}

template <class T>
int Vertex<T>::getNeighborIdx(vid_t nid) {
    return binarySearch(nid);
}

template <class T>
void Vertex<T>::bitmapInit() {
    activated = new boost::dynamic_bitset<> (outDegree);
}

template <class T>
void Vertex<T>::shuffleBitmap() {
    unsigned long long idx = rand() % activated->size(); // % operation may take long
    activated[idx].flip();
}

template <class T>
string Vertex<T>::toString() {
    std::stringstream output;

    output << endl << vid << " -> ";
    for (int i = 0; i < outDegree; i++) {
        output << "(" << neighbors[i] << ", " << weights[i] << ", " << probs[i] << ")";
    }

    return output.str();
}

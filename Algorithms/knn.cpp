#include <iostream>
#include "../vertex.cpp"
#include "../uncertainGraph.cpp"
#include "../loader.cpp"
using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cout << "[ERROR] 2 arguments required : graph file, source node" << endl;
        return -1;
    }

    char* graphFile = argv[1];
    int srcNode = atoi(argv[2]);

    Loader<int> loader;
    UncertainGraph<int>* uncertainGraph = loader.load(graphFile);

    return 0;
}

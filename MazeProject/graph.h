#include <iostream>
#include <vector>
#include <fstream>

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "graph.h"
/**
*   Author @ Alexander Robinson
*   graph.h
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/
using namespace std;
using std::vector;

class graph
{
    public:
        int index;
        vector<vertex>openPath;
        vector<vertex>mazeGraph;
        vector<vertex>path;
        graph();
        void depthFirstSearch();
        void addVertex(int x, int y);
        bool checkIfExist(vertex v);
        bool checkIfOpen(vertex v);
        void showOpenPath(ofstream &outputFile);
        void showGraph(ofstream &outputFile);
        void mazeMove(vertex v, ofstream &outputFile);
        virtual ~graph();
    private:
         void DFS(vertex v);
};

#endif // GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <conio.h>

#ifndef MAZE_H
#define MAZE_H

#include "graph.h"
#include "Print.h";
/**
*   Author @ Alexander Robinson
*   Maze.h
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/
using namespace std;

class Maze
{
    public:
        int startXCord;
        int startYCord;
        int endYCord;
        int endXCord;
        int mazeHeight;
        int MazeWidth;
        int **Mazearr;
        graph g;
        Maze();
        Maze(int startXCord, int startYCord, int endXCord, int endYCord, int mazeHeight, int MazeWidth, int **Mazearr);
        Maze createMaze(ifstream &myfile);
        void printMaze(ofstream &outputFile , Maze maze);
        void mazeSolveDFS(ofstream &outputFile , Maze maze);
        virtual ~Maze();
    private:
        int convertFromStringToInt(string s);
        bool pressEnterToContinue();
};

#endif // MAZE_H

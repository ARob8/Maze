#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


#include "Maze.h"
/**
*   Author @ Alexander Robinson
*   main.cpp
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/

using namespace std;
using std::vector;

int main()
{
    ifstream File;
    ofstream outputFile;
    outputFile.open("output_file.txt");
    File.open("input_file.txt");

    Maze m = m.createMaze(File);
    Maze print;
    print.mazeSolveDFS(outputFile,m);
}

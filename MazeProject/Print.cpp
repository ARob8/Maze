#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
/**
*   Author @ Alexander Robinson
*   Print.cpp
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/
#include "Print.h"

Print::Print()
{
    this->printArr[3] = printArr[3];
}
//Destructor that deletes blocks printed out 3x3
Print::~Print()
{
    delete printArr;
}

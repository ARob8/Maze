#include "graph.h"
/**
*   Author @ Alexander Robinson
*   graph.cpp
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/
graph::graph()
{
    index = 0;
}
void graph::addVertex(int x, int y)
{
    //Create temporary vertex and push it back to open path vector
    vertex temp(x,y,0);
    openPath.push_back(temp);
}
void graph::DFS(vertex v){
    //Used to push back 0,0 into graph as start spawn
    if(checkIfOpen(v) == true){
        if(checkIfExist(v) == false){
        mazeGraph.push_back(v);
        }
    }
    int x = v.x;
    int y = v.y;
    int num = v.num;
    //Adjacent vertexs
    vertex right(x+1,y,num);
    vertex left(x-1,y,num);
    vertex up(x,y+1,num);
    vertex down(x,y-1,num);
    //if its an open path and does not already exists within graph push
    if(checkIfOpen(up) == true){
        if(checkIfExist(up) == false){
            //if up num = 0 push
            if(up.num == 0){
                up.num = index++;
                mazeGraph.push_back(up);
            }
            //Recursive call on adjacent up
            DFS(up);
        }
    }
    if(checkIfOpen(right) == true){
       if(checkIfExist(right) == false){
            //if right num = 0 push
            if(right.num == 0){
                right.num = index++;
                mazeGraph.push_back(right);
            }
             //Recursive call on adjacent right
            DFS(right);
        }
    }
    if(checkIfOpen(down) == true){
        if(checkIfExist(down) == false){
            //if down num = 0 push
            if(down.num == 0){
                down.num = index++;
                mazeGraph.push_back(down);

            }
            //Recursive call on adjacent down
            DFS(down);
        }
    }
    if(checkIfOpen(left) == true){
        if(checkIfExist(left) == false){
                //if left num = 0 push
                if(left.num == 0){
                    left.num = index++;
                    mazeGraph.push_back(left);
                }
            //Recursive call on adjacent left
            DFS(left);
        }
    }
}
void graph::depthFirstSearch(){
    //set index to 1
    index = 1;
    // for all vertices in open path if num = 0 call DFS()
    for(int i = 0; i < openPath.size(); i++){
        if(openPath[i].num == 0){
            DFS(openPath[i]);
        }
    }
}
bool graph::checkIfOpen(vertex v){
    //Checks if the vertex exists within open path
    int x = v.x;
    int y = v.y;
    int in = 0;
    int length = openPath.size();

    for(int i = 0; i < openPath.size(); i++){
        if(openPath[i].x == x && openPath[i].y == y){
            return true;
        }else{
            in++;
        }
        if(in == length){
            return false;
        }
    }
}
bool graph::checkIfExist(vertex v){
      //Checks if the vertex exists within graph
    int x = v.x;
    int y = v.y;
    int in = 0;
    int length = mazeGraph.size();

    for(int i = 0; i < mazeGraph.size(); i++){
        if(mazeGraph[i].x == x && mazeGraph[i].y == y){
            return true;
        }else{
            in++;
        }
        if(in == length){
            return false;
        }
    }
}
void graph::showOpenPath(ofstream &outputFile){

    outputFile << "All Vertices: "<< endl;
    cout << "Vertices: "<< endl;

    for(int j = 0; j < openPath.size(); j++){
        cout <<"("<< openPath[j].x << "," << openPath[j].y <<")";
        outputFile <<"("<< openPath[j].x << "," << openPath[j].y <<")";
    }
 }

void graph::showGraph(ofstream &outputFile){
    //prints maze graph
    outputFile << "\n\n";
    cout << "\n\n";
    outputFile << "Graph DFS: "<< endl;
    cout << "Graph DFS: "<< endl;

    for(int j = 0; j < mazeGraph.size(); j++){
        cout  << "index " << mazeGraph[j].num
        <<"("<< mazeGraph[j].x << "," << mazeGraph[j].y <<")";
        outputFile <<  "index " << mazeGraph[j].num
        <<"("<< mazeGraph[j].x << "," << mazeGraph[j].y <<")";
    }
    outputFile << "\n\n";
    cout << "\n\n" << endl;
}

void graph::mazeMove(vertex v, ofstream &outputFile)
{
    //prints maze path
    path.push_back(v);

    outputFile << "Path: "<< endl;
    cout << "Path: "<< endl;

    for(int j = 0; j < path.size(); j++){
        cout <<"("<< path[j].x << "," << path[j].y <<")";
        outputFile <<"("<< path[j].x << "," << path[j].y <<")";
    }
    outputFile << "\n\n";
    cout << "\n\n" << endl;
}
graph::~graph()
{
    //swap to temp vector and clear
    vector<vertex>temp;
    temp.swap(path);
    temp.clear();
    temp.swap(mazeGraph);
    temp.clear();
    temp.swap(openPath);
    temp.clear();
}

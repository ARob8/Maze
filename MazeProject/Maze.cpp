#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
/**
*   Author @ Alexander Robinson
*   Maze.cpp
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/
using namespace std;

#include "Maze.h"

Maze::Maze()
{
    //ctor
}
//Constructor for maze
Maze::Maze(int startXCord, int startYCord, int endXCord,
           int endYCord, int mazeHeight, int MazeWidth, int **Mazearr)
{
    this->startXCord = startXCord;
    this->startYCord = startYCord;
    this->endXCord = endXCord;
    this->endYCord = endYCord;
    this->mazeHeight = mazeHeight;
    this->MazeWidth = MazeWidth;
    this->Mazearr = Mazearr;

}
//Function to create maze  from input file
Maze Maze::createMaze(ifstream &myfile)
{
    Maze maze;

    string str;
    string arr[15];
    int i = 0;
    //If the file is open store in string arr line by line
    if (myfile.is_open()) {
        while (getline(myfile, str)) {
            arr[i] = str;
            i++;
        }
        myfile.close();
    }
    //Get dimensions of maze
    //Finds length to comma on first line
    int widthOfNumber = arr[0].find_first_of(',');
    // Finds the substring at index 0 and length of widthOfNumber
    string widthOfString = arr[0].substr(0, widthOfNumber);
     //Finds the substring after the location of first comma + 2
    string restString = arr[0].substr(widthOfString.length() + 2);
     //Find the length to the . in restString
    int heightNumber = restString.find_first_of('.');
     //Uses restString and returns the string at index 0 and length of heightNumber
    string heightString = restString.substr(0, heightNumber);


    //convert from string to dimensions mazeWidth and mazeHeight
    int MazeWidth, mazeHeight;
    stringstream convertw(widthOfString);
    if (!(convertw >> MazeWidth))
        MazeWidth = 0;
    stringstream converth(heightString);
    if (!(converth >> mazeHeight))
        mazeHeight = 0;

    //Construct two dimensional maze using height and width
    // each i-th pointer points to int values
    int **Mazearr = new int *[mazeHeight];
    for (int i = 0; i < mazeHeight; ++i) {
        Mazearr[i] = new int[MazeWidth];
    }
     //Sets all values of Mazearr
    for (int height = 0; height < mazeHeight; height++) {
        for (int width = 0; width < MazeWidth; width++) {
            Mazearr[height][width] = 0;
        }
    }
    //Get starting x and y values
    //Finds length to first comma on second line
    int startXNumber = arr[1].find_first_of(',');
     //Gets start x
    string startXString = arr[1].substr(1, startXNumber  - 1);
       //Finds length to first right parenthesis on second line
    int endPos = arr[1].find_first_of(')');
     //Gets start y
    string startYString = arr[1].substr((startXNumber  + 2)
    ,(endPos - (startXNumber  + 2)));

      //convert from string to start x and start y coordinates
    int startXCord, startYCord;
    stringstream convertXcoord(startXString);
    if (!(convertXcoord >> startXCord))
        startXCord = 0;
    stringstream convertYcoord(startYString);
    if (!(convertYcoord >> startYCord))
        startYCord = 0;

    //Get value at end x and y values
    //Finds length to first comma on third line
    int endXNumber  = arr[2].find_first_of(',');
    //Gets end y
    string endXString  = arr[2].substr(1, endXNumber  - 1);
     //Finds length to first right parenthesis on third line
    int endYNumber = arr[2].find_first_of(')');
      //Gets end y
    string endYString = arr[2].substr((endXNumber  + 2)
    ,(endYNumber - (endXNumber  + 2)));

     //Convert from string to end x and end y coordinates
    int endXCord, endYCord;
    stringstream convertendXCord(endXString );
    if (!(convertendXCord >> endXCord))
        endXCord = 0;
    stringstream convertendYCord(endYString);
    if (!(convertendYCord >> endYCord))
        endYCord = 0;
    //Starts at index 3 get remaining lines in file
    int j = 3;
    for (j = 3; j < i; j++) {
        int index = 0;
        int length = arr[j].length();
        while (index < length) {
        //finds length to first comma on remaining lines
        int commaPos = arr[j].find_first_of(',');
        //finds length to first right parenthesis on remaining lines
        int rightParenthesis = arr[j].find_first_of(')');
        //Gets width and height
        int w = convertFromStringToInt(arr[j].substr(1, commaPos - 1));
        int h = convertFromStringToInt(arr[j].
        substr(commaPos + 2, rightParenthesis - (commaPos + 2)));
        //Set remaining values equal to walls
        Mazearr[h][w] = 1;
        index = index + rightParenthesis + 3;
        if (rightParenthesis <= arr[j].length() - 3) {
        arr[j] = arr[j].substr(rightParenthesis + 3);
        }
    }
}
    //Set values of maze object and returns maze object
    maze.startXCord = startXCord;
    maze.startYCord = startYCord;
    maze.endXCord = endXCord;
    maze.endYCord = endYCord;
    maze.mazeHeight = mazeHeight;
    maze.MazeWidth = MazeWidth;
    maze.Mazearr = Mazearr;
    return maze;

}
//Prints maze out into file
void Maze::printMaze(ofstream &outputFile , Maze maze) {
    //Set start and end cords as well as dimensions equal to Maze maze
    int startXCord = maze.startXCord;
    int startYCord = maze.startYCord;
    int endXCord = maze.endXCord;
    int endYCord = maze.endYCord;
    int mazeHeight = maze.mazeHeight;
    int MazeWidth = maze.MazeWidth;
    int **a = maze.Mazearr;

    //Define Print object that prints out mazes height and width
    Print arrPrint[mazeHeight][MazeWidth];
    cout << "   ";
    outputFile << "   ";
    //Loops over mazeWidth and prints it out
    for (int i = 0; i < MazeWidth; i++) {
        cout << " " << i << " ";
        outputFile << " " << i << " ";
    }
    cout << endl;
    outputFile << endl;

    for (int height = 0; height < mazeHeight; height++) {
        for (int width = 0; width < MazeWidth; width++) {
            for (int i = 0; i < 3; i++) {
                    //if a[height][width] = 0 or 2 ... openPath
              if (a[height][width] == 0) {
                arrPrint[height][width].printArr[i] = "...";
              } else if (a[height][width] == 1) {
                    //if a[height][width] = 1 XXX wall
              arrPrint[height][width].printArr[i] = "XXX";
              } else if (a[height][width] == -1) {
                    //if a[height][width] = -1 .P. path
              arrPrint[height][width].printArr[i] = ".P.";
            }
        }
    }
}
    //Start position equal to S
    arrPrint[startYCord][startXCord].printArr[1] = ".S.";
    arrPrint[startYCord][startXCord].printArr[0] = "...";
    arrPrint[startYCord][startXCord].printArr[2] = "...";
    //Finish position equal to F
    arrPrint[endYCord][endXCord].printArr[0] = "...";
    arrPrint[endYCord][endXCord].printArr[1] = ".F.";
    arrPrint[endYCord][endXCord].printArr[2] = "...";
    //print out the maze and prints out in file
    int lineCount = 0;
    //Loops over mazes height
    for (int h = 0; h < mazeHeight; h++) {
        for (int i = 0; i < 3; i++) {
            if (i == 1) {
                //Prints out line count and prints to file
            cout.width(2);
            cout.fill(' ');
            cout << lineCount;
            outputFile.width(2);
            outputFile.fill(' ');
            outputFile << lineCount;
            } else {
            cout << "  ";
            outputFile << "  ";
            }
            //Prints out maze blocks and prints to file
            cout << " ";
            outputFile << " ";
            for (int w = 0; w < MazeWidth; w++) {
                cout << arrPrint[h][w].printArr[i];
                outputFile << arrPrint[h][w].printArr[i];
            }
            cout << '\n';
            outputFile << std::endl;
        }
        lineCount++;
    }
    outputFile << std::endl;
    outputFile << std::endl;

}
void Maze::mazeSolveDFS(ofstream &outputFile , Maze maze) {
    //Set start and end cords as well as dimensions equal to Maze maze
    int startXCord = maze.startXCord;
    int startYCord = maze.startYCord;
    int endXCord = maze.endXCord;
    int endYCord = maze.endYCord;
    int mazeHeight = maze.mazeHeight;
    int MazeWidth = maze.MazeWidth;
    int **m = maze.Mazearr;
    int currentX, currentY;

    for (int height = 0; height < MazeWidth; height++) {
        for (int width = 0; width < mazeHeight; width++) {
            if(m[width][height] == 0 || m[width][height] == 2){

                g.addVertex(height,width);
            }
        }
    }
    g.showOpenPath(outputFile);
    cout << "\n\n" << endl;
    outputFile << "\n\n" << endl;
    g.depthFirstSearch();
    for(int i = 0; i < g.mazeGraph.size(); i++)
    {
        currentY = g.mazeGraph[i].x;
        currentX = g.mazeGraph[i].y;
        int num = g.mazeGraph[i].num;
        vertex temp(currentY,currentX,num);

       if(currentY == endXCord && currentX == endYCord){
        g.mazeMove(temp,outputFile);
        cout << "\n\n" << endl;
        outputFile << "\n\n" << endl;
        cout << "!!!!!!!!!!!!!!FINISH!!!!!!!!!!!!!" << endl;
        outputFile << "!!!!!!!!!!!!!!FINISH!!!!!!!!!!!!!"<<endl;
        cout << "\n\n" << endl;
        outputFile << "\n\n" << endl;
        outputFile << "\n\n";
        outputFile << "Finish spawn reached" << endl;
        cout << "Finish spawn reached" << endl;
        if(pressEnterToContinue() == true){
            continue;
        }else{
            g.showGraph(outputFile);
                return;
        }
        }else{
        g.mazeMove(temp,outputFile);
        m[currentX][currentY] = -1;
        cout << "\n\n" << endl;
        outputFile << "\n\n" << endl;
        printMaze(outputFile,maze);
        cout << "\n\n" << endl;
        outputFile << "\n\n" << endl;
        }
    }
   g.showGraph(outputFile);
}
bool Maze::pressEnterToContinue()
{
    cout << "Press ENTER to continue "
    << "through remaining unvisited maze paths...or 1 to exit"
    << endl;
    const char temp = cin.get();
    if(temp == '\n'){
       return true;
    }else if(temp == '1'){
        return false;
    }else {
       cin.sync();
       cin.clear();
       cout << "Invalid Try Again" << endl;
       pressEnterToContinue();
    }
}
//Convert from string to an integer
int Maze::convertFromStringToInt(string s) {
    int convert;
    stringstream convertI(s);
    if (!(convertI >> convert))
        convert = 0;
    return convert;
}
Maze::~Maze(){

}


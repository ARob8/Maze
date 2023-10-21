Author: Alexander Robinson  
File: README.txt
Assignment: Maze 6 Depth First Search
Date: 4/20/2017


CHANGES MADE FROM PREVIOUS DESIGN
 -Print class added for printing open paths,walls,and paths
 -vertex class added to model a vertex in a graph
 -graph class added to model a graph and do function alogrithm from book depthFirstSearch

DECRIPTION
-Program reads in 2d array from file
-Represent Maze as a graph and implement the algorithm in the book (pg 395/ pef 413) 
-Vertices are open paths, start and finish spawn
-Vertices and edges are objects 

DESIGN AND IMPLEMENTATION
-Read walls from file
-Mark all open paths, start, and finish spawn as vertices
-Give all vertices number or index 0 to start
-Generate adjacent open path or edges 
-if number or index of edge is 0 push to graph
-do this for all vertices
-post increment index everytime edge is pushed to graph 

TODO
-Display the output of maze path to file and console better

BUGS 
-When trying to delete mazeArr in maze deconstuctor sig fault

EXTRA FUNCTIONALITY 
-pressEnterToContinue();
-If graph solves from start to finish spawn without filling all of the open paths from the generated graph user is prompted to continue solving maze 
-ENTER continues solving maze from generated graph 
- (1) returns generated graph and exits program
-if ENTER was selected generated graph is printed out after all graph values have been passed to maze 
-Useful because DFS can easily fill all of the open paths(vertices) and if finish spawn is visted you know it solved the maze   

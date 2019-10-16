#ifndef VERTEX_H
#define VERTEX_H
/**
*   Author @ Alexander Robinson
*   vertex.h
*   Date 4/18/2017
*   Maze 6 Depth First Search
*/
class vertex
{
    public:
        int x;
        int y;
        int num;
        vertex();
        vertex(int x, int y, int num);
        virtual ~vertex();
    private:
};

#endif // VERTEX_H

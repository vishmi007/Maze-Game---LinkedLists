#ifndef ARRAY_H
#define ARRAY_H
void getSizes(char* pfileName,int*** metaDatatable, int* no_obstacles, int* no_rows, int* no_cols);
char*** createMap( char* getFile,int* passPlayerRow,int* passPlayerCol, int* passWinRow, int* passWinCol,int* passSnakeRow,int* passSnakeCol,int* passRows,int* passCols);
#define FALSE 0
#define TRUE !FALSE
#endif
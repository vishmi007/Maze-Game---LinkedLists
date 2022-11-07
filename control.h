#ifndef CONTROL_H
#define CONTROL_H

void controlPawn(char* fileName);
void displayMap(char*** displayMap,int* rows, int*cols,int plevel);
void chaseThePawn(char*** getMap, int* pawnRow,int* pawnCol, int* snakeRow, int* snakeCol);


#define FALSE 0
#define TRUE !FALSE

#endif
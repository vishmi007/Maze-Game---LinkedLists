/*********************************************************
 * Author: Vishmi Kalansooriya                               
 * Date:  10th October 2021                                    
 * Purpose: To create the map by creating a 2D  array by reading in the text file provided.               
 *********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*************************************************************
 * Name : getSizes
 * Import : metaDatTable (int 2d array),no_obstacles,no_rows,no_cols.
 * Export : None
 * Purpose : To get the dimensions of the map.(No rows and cols)
 * *********************************************************/
void getSizes(char* pFileName,int*** metaDatatable, int* no_obstacles, int* no_rows, int* no_cols)
{
   
   
        int i;
        int rows = 0;
        int cols = 0;
        int obstacles = 0;
        int** table;
       
    /* Creating a file pointer */
     FILE * fp = fopen(pFileName,"r");
     /* To check whether there is an error in reading the file even though the file exists.*/ 
     if(fp == NULL)
        {
            perror("Error opening input.txt"); /* an error message for the user if there is an error */

        }
        else     
        {
            
            int done = FALSE;
            int nRead;

            while(!done) /* while done is true */
            {
                nRead = fscanf(fp,"%d %d %d",&obstacles,&rows,&cols);
            
            /* to check if the the data was read properly */
                if(nRead != 3)
                {
                    done = TRUE; /* to stop reading if the reading is false */
                }
                else      
                {
                    /* testing */
                    /*printf("%d %d %d\n \t \n",obstacles,rows,cols); */
                }
                /* assuming that the number of rows and cols are in the first line as said */
                done = TRUE; /* to read only the first line of the text file since it contains the number of objects
                                rows in the map and columns in the map. */
            }

            if(ferror(fp))
            {
                perror("error reading from input.txt");
                
            }
            fclose(fp); /* closing the file after reading */
            fp = NULL;
            
        }

        /* malloc a 2D array to store the object codes, row codes and column codes. */
        
        table = (int **) malloc(sizeof(int *) * (obstacles)); /* the rows */

        for(i = 0 ; i < (obstacles) ; i++)
        {
            table[i] = (int *) malloc(sizeof(int) * 3); /* the columns */
        }
        /* To pass on the data */

        *metaDatatable = table;
        *no_obstacles = obstacles;
        *no_rows = rows;
        *no_cols = cols;
}
/*************************************************************
 * Name : createMap
 * Import : None
 * Export : None
 * Purpose : To create the map for the game play.
 * *********************************************************/

char*** createMap( char* getFile,int* passPlayerRow,int* passPlayerCol, int* passWinRow, int* passWinCol,int* passSnakeRow,int* passSnakeCol,int* passRows,int* passCols)
{
    
    int r = 0;
    int c = 0;
    int ref = 0;
    int* pointerOne = &ref;
    int** table;
    table  = &pointerOne;
    int no_rows = 0;
    int noOfObstacles = 0;
    int no_cols = 0;
    int obstacle_code = 0;
    int row = 0;
    int col = 0;
    int obstacle_row = 0;
    int obstacle_col = 0;
    int playerRow = 0;
    int playerCol = 0;
    int winRow = 0;
    int winCol = 0;
    int snakeRow = 0;
    int snakeCol = 0;
    char* fileName = "s";


    /* calling the method getSizes to get the dimensions of the map */

    getSizes(getFile,&table,&noOfObstacles,&no_rows,&no_cols);
   
   /* reading the text file again to get the object code and their relevant row index and col index */
    FILE * fp = fopen(getFile,"r");
    /* to check if there is an error in reading the file */
    if(fp == NULL)
    {
        perror("Error opening input.txt"); /* an error message for the user */

    }
    else     
    {
        int done = FALSE;
        int nRead;

        while(!done)
        {
            nRead = fscanf(fp,"%d %d %d",&row,&col,&obstacle_code);
           
            if(nRead != 3)
            {
                done = TRUE;
            }
            else      
            {
                /* store the data in the above created 2D array */
                   for(r = 0; r < noOfObstacles; r++)
                     {
                        for(c = 0; c < 3; c++)
                        {
                          fscanf(fp,"%d",&table[r][c]);
                            
                        }
                        
                    }
               
            }
           
        }

        if(ferror(fp))
        {
            perror("error reading from input.txt");
            
        }
        fclose(fp); /* close the file */
        fp = NULL;
        
    }
   /*  for(r = 0; r < noOfObstacles; r++)
     {
        for(c = 0; c < 3; c++)
        {
           printf("%d ",table[r][c]);
                            
        }
        printf("\n"); 
                        
    } */

    /* malloc the 2D array to create the map */
    char*** thisArray = (char***)malloc(sizeof(char**)*no_rows); /* the rows */

    for(r = 0; r < no_rows; r++)
    {
        thisArray[r] = (char**)malloc(sizeof(char*)*no_cols); /* The columns */
 
    }

    /* Filling the array with empty spaces */

      for(r = 0; r < no_rows; r++)
     {
        for(c = 0; c < no_cols; c++)
        {
           thisArray[r][c] = " ";
                            
        }
    
                        
    }

    /* inserting # to the coners of the array  */
    thisArray[0][0] = "#";
    thisArray[no_rows-1][0] = "#";
    thisArray[0][no_cols-1] = "#";
    thisArray[no_rows-1][no_cols -1] = "#";


    /* setting up the boundry boarders with " = " vertically ang "|" horizontally" */
    for( c = 1; c <no_cols-1; c++)
    {
        thisArray[0][c] = "=";
    }
     for( r = 1; r < no_rows -1; r++)
    {
        thisArray[r][0] = "|";
    }
       for( c = 1; c < no_cols -1; c++)
    {
        thisArray[no_rows-1][c] = "=";
    }
       for( r = 1; r < no_rows -1; r++)
    {
        thisArray[r][no_cols-1] = "|";
    }


    /*placing the obstacles in the map */
    for(r = 0; r < noOfObstacles; r++)
    {
        
            if(table[r][2] == 3)
            {
                 obstacle_row = table[r][0];
                 obstacle_col = table[r][1];
                 thisArray[obstacle_row][obstacle_col] = "0";
            }

    } 

    /* finding the player start position */
      for(r = 0; r < noOfObstacles; r++)
    {
        
            if(table[r][2] == 0)
            {
                 playerRow = table[r][0];
                 playerCol = table[r][1];
                /* thisArray[playerRow][playerCol] = "^"; */
            }

    } 
    /* finding the player win position */

      for(r = 0; r < noOfObstacles; r++)
    {
        
            if(table[r][2] == 2)
            {

                 winRow = table[r][0];
                 winCol = table[r][1];
               /*  thisArray[winRow][winCol] = "X"; */
            }

    } 

    /* finding the initial snake position */
     for(r = 0; r < noOfObstacles; r++)
    {
        
            if(table[r][2] == 1)
            {

                 snakeRow = table[r][0];
                 snakeCol = table[r][1];
                /* thisArray[snakeRow][snakeCol] = "~"; */
            }

    } 

    /* for(r = 0; r < no_rows; r++)
     {
        for(c = 0; c < no_cols; c++)
        {
           printf("%s",thisArray[r][c]);
                            
        }
        printf("\n ");
    
    } */


  

    *passPlayerRow = playerRow;
    *passPlayerCol = playerCol;
    *passSnakeRow = snakeRow;
    *passSnakeCol = snakeCol;
    *passWinRow = winRow;
    *passWinCol = winCol; 
    *passRows = no_rows;
    *passCols = no_cols;


    return thisArray;
   
}

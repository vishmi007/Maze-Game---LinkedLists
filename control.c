/* *****************************************************************************************************
 * Author: Vishmi Kalansooriya                               
 * Date:  09th September 2021                                    
 * Purpose: To implement a program to control the game.                   
 *********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "control.h"
#include <string.h>
#include "terminal.h"
#include "LinkedList.h"
/*********************************************************
 * Name   : controlPawn                           
 * Import : level (int)                                
 * Export : None
 * Purpose:  to let the piece move according to the user input.                
 *********************************************************************************************************/


void controlPawn(char* fileName)
{
    

    int cols = 0;
    int rows = 0;
    int pawnRowIndex = 0 ;
    int pawnColIndex = 0;
    int snakeRowIndex = 0;
    int snakeColIndex = 0;
    int winRow = 0;
    int winCol = 0;
    int r,c;
    char move; /* to store the user input and act accordingly */
  /*  int getPawnRow;
    int getPawnCol;
    int getSnakeRow;
    int getSnakeCol; */

     /* calling the createmap method to get the created 2D array , piece's intial position , win piece position,
     the number of rows and column of the array */

     
    char*** map = createMap(fileName,&pawnRowIndex,&pawnColIndex,&winRow,&winCol,&snakeRowIndex,&snakeColIndex,&rows,&cols);

  /* setting the pawn piece at the initial position ( The place where it should be when the game starts) */
    map[pawnRowIndex][pawnColIndex] = "^";
   /* setting the win piece at the initial position ( The place where it should be when the game starts) */   
     map[winRow][winCol] = "X";

  /* Setting the snake piece at the initial position (The place where it should be when the game starts) */
      map[snakeRowIndex][snakeColIndex] = "~";

     /* clearing the screen before displaying the map ( 2D array ) */
    system("clear"); 
     /* calling the display map method to display the 2D array while passing the level ( 0, 1, 2 ,3) entered 
      as arguments by the user */

      /* Using the display of assignment one along with 0-for the whole map because levels does not matter in assignment 2 */
     displayMap(map,&rows,&cols,0);

    /*LinkedList* pawnRowList = NULL;
    pawnRowList = createLinkedList();

    LinkedList* pawnColList = NULL;
    pawnColList = createLinkedList();
    
    
    LinkedList* snakeRowList = NULL;
    snakeRowList = createLinkedList();

    LinkedList* snakeColList = NULL;
    snakeColList = createLinkedList();
    

    LinkedList* shape = NULL;
    shape = createLinkedList();

    char* data;
    char input[100]; */

for( r = 0; r < rows; r++)
     {
     
         for( c = 0; c < cols; c++)
         {
              /* to move the pawn until it meets the win piece ( X) or the snake piece */
             while(strcmp(map[winRow][winCol],"X") == 0 && strcmp(map[snakeRowIndex][snakeColIndex],"~") == 0 
                     && (!strcmp(map[pawnRowIndex][pawnColIndex],"~") == 0 ))
             {

                  /* calling the disable buffer method to not let the user press enter */

                 disableBuffer();
                /* taking the user input */
                 scanf("%c",&move);
                 
                /* To perform actions according to the user input */ 
                 switch(move)
                 {
                     case 'w' :
                        system("clear"); /* clear the screen before displaying the map again with the changes done
                        according to the user input */
                        if(strcmp(map[pawnRowIndex-1][pawnColIndex]," ") == 0) /* check whether the pawn can be moved front */
                        {
                            /* set the pawn to the initial row position - 1 position */
                             map[pawnRowIndex-1][pawnColIndex] = "^";
                            /* strcpy(input,"^");
                             insertStart(shape,input); */
                             map[pawnRowIndex][pawnColIndex] = " "; /* make the initial position that the pawn was into empty space*/
                             pawnRowIndex = pawnRowIndex -1;   /* now set the moved position as the initial positin */
                             chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex); /* calling the chaseThePawn function 
                             to chase the pawn */
                             /* commenting the last lines because the undo method does not work */
                           /*  insertStart(pawnRowList,pawnRowIndex);
                             insertStart(pawnColList,pawnColIndex);
                             insertStart(snakeRowList,snakeRowIndex);
                             insertStart(snakeColList,snakeColIndex); */

                             displayMap(map,&rows,&cols,0); /* display the map with the changes */
                             
                           


                        }else if((strcmp(map[pawnRowIndex-1][pawnColIndex],"X") == 0)) /* check if the pawn piece has reached the target */
                        { 
                          
                             
                                   map[pawnRowIndex-1][pawnColIndex] = "^"; /* move the pawn */
                                   printf(" You win ! \n "); /* Display the fancy message */
                            
                            
                        }else
                        {
                             /* if the move that is requested to be done by the user has an obstacle or a boarder just print the 
                             map as it is */
                             chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);
                             /* insertStart(snakeRowList,snakeRowIndex);
                              insertStart(snakeColList,snakeColIndex); */
                              displayMap(map,&rows,&cols,0); 


                        }
                        break;
                        
                        case 's' :
                        system("clear");
                       if(strcmp(map[pawnRowIndex+1][pawnColIndex]," ") == 0)
                       {
                             map[pawnRowIndex+1][pawnColIndex] = "v";
                            /* strcpy(input,"v");
                            insertStart(shape,input); */
                             map[pawnRowIndex][pawnColIndex] = " ";
                             pawnRowIndex = pawnRowIndex +1;
                             chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);

                             /* insertStart(pawnRowList,pawnRowIndex);
                             insertStart(pawnColList,pawnColIndex);
                             insertStart(snakeRowList,snakeRowIndex);
                             insertStart(snakeColList,snakeColIndex); */

                             
                             displayMap(map,&rows,&cols,0);
                        }else if((strcmp(map[pawnRowIndex +1][pawnColIndex],"X") == 0))
                        {
                             
                                   map[pawnRowIndex+1][pawnColIndex] = "v"; /* move the pawn */
                                   printf(" You win ! \n "); /* Display the fancy message */
                             
                        }else
                       {
                           chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);

                              /* insertStart(snakeRowList,snakeRowIndex);
                               insertStart(snakeColList,snakeColIndex); */

                            
                              displayMap(map,&rows,&cols,0); 
                          

                       }
                       break;
                      
                        
                    case 'a' :
                         system("clear");
                         if(strcmp(map[pawnRowIndex][pawnColIndex-1]," ") == 0)
                         {
                              map[pawnRowIndex][pawnColIndex-1] = "<";
                              /* strcpy(input,"<");
                             insertStart(shape,input); */
                              map[pawnRowIndex][pawnColIndex] = " ";
                              pawnColIndex = pawnColIndex-1;
                              chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);

                               /*insertStart(pawnRowList,pawnRowIndex);
                               insertStart(pawnColList,pawnColIndex);
                               insertStart(snakeRowList,snakeRowIndex);
                               insertStart(snakeColList,snakeColIndex); */

                              displayMap(map,&rows,&cols,0);
                             
                         
                         }else if((strcmp(map[pawnRowIndex][pawnColIndex-1],"X") == 0))
                        { 
                              
                                   map[pawnRowIndex][pawnColIndex-1] = "<"; /* move the pawn */
                                   printf(" You win ! \n "); /* Display the fancy message */
                             

                         }else
                         {
                               chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);

                              /* insertStart(snakeRowList,snakeRowIndex);
                               insertStart(snakeColList,snakeColIndex); */
                              
                               displayMap(map,&rows,&cols,0); 
                            

                         }

                         
                         break;
                        
                         

                    case 'd':
                         system("clear");
                         if(strcmp(map[pawnRowIndex][pawnColIndex+1]," ") == 0)
                         {
                               map[pawnRowIndex][pawnColIndex+1] = ">";
                               /* strcpy(input,">");
                               insertStart(shape,input); */
                               map[pawnRowIndex][pawnColIndex] = " ";
                               pawnColIndex = pawnColIndex+1;
                               chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);

                              /* insertStart(pawnRowList,pawnRowIndex);
                               insertStart(pawnColList,pawnColIndex);
                               insertStart(snakeRowList,snakeRowIndex);
                               insertStart(snakeColList,snakeColIndex); */
                             
                               displayMap(map,&rows,&cols,0);
                         }else if((strcmp(map[pawnRowIndex][pawnColIndex +1],"X") == 0)) 
                        { 
                                  map[pawnRowIndex][pawnColIndex+1] = ">"; /* move the pawn */
                                  printf(" You win ! \n "); /* Display the fancy message */
                             

                         }else
                         {
                              chaseThePawn(map,&pawnRowIndex,&pawnColIndex,&snakeRowIndex,&snakeColIndex);

                              /* insertStart(snakeRowList,snakeRowIndex);
                               insertStart(snakeColList,snakeColIndex); */
                              
                              displayMap(map,&rows,&cols,0); 
                            
                         }
                         break;
                         /*********************************************
                          * 
                          *  The undo method does not work.
                          * 
                          * ***************************************************/
                    /* case 'u' :
                          system("clear");
                          {
                                data = (char *)removeStart(shape); 
                                getPawnRow = removeStart(pawnRowList);
                                getPawnCol = removeStart(pawnColList);
                                getSnakeRow = removeStart(snakeRowList);
                                getSnakeCol = removeStart(snakeColList);


                              map[pawnRowIndex][pawnColIndex] = " ";
                              map[snakeRowIndex][snakeColIndex] = " ";  
                              

                              map[getPawnRow][getPawnCol] = "^";
                              map[getSnakeRow][getSnakeCol] = "~";
                              
                              
                              displayMap(map,&rows,&cols,0); 

                          } */
                         

                          break;
                         }
                    /* To check if the snake has eaten the pawn to end the game */
                    if((strcmp(map[pawnRowIndex][pawnColIndex],"~") == 0)) /* move the snake to the pawn position to show that it ate*/
                    {
                         system("clear"); /* clear the screen before displaying the sorry message to the user */
                         printf("You loose ! Please try again \n" );
                             } 
             }
    } 

    }
    /* freeing the manually allocated spaces */
     for(r = 0; r < rows; r ++)
    {
       free(map[r]);
    }
   
    free(map);
    map = NULL;



    enableBuffer();

    
}
/*********************************************************
 * Name   : displayMap                            
 * Import : displayMap( char 2D array), rows ( integer pointer), cols (integer pointer), plevel ( integer)                              
 * Export : None
 * Purpose:  to display the map ( 2D array).               
 *********************************************************************************************************/

/** Using the display method used in the assignment one itself but displaying the whole map at all times. */

void displayMap(char*** displayMap,int* rows, int* cols,int plevel)
{
    int r = 0;
    int c = 0;
    int i = 0;
    int j = 0 ;
   

    
    for(r = 0; r < *rows; r++)
    {
        for(c = 0; c < *cols; c++)
        { 
            if(plevel != 0) /* check if the level entered by the user is 0 to display the whole map */
            {
                 if((strcmp(displayMap[r][c],"^") == 0) || (strcmp(displayMap[r][c],"<")== 0) || 
                 (strcmp(displayMap[r][c],"v")== 0) || (strcmp(displayMap[r][c],">") == 0))
                {
                     
                        for(i = r - plevel; i <= (r + plevel); i++) /* to display according to the neccesay level */
                        {
                             for(j = c - plevel; j <= (c + plevel); j++)
                                {
                                   /* print only the characters inside the bound ( To not let this go out of bound) */
                                   if(( (i >= 0) && (i <= (*rows - 1)) && (j >= 0) && ( j <= (*cols -1))) )
                                    {
                                        printf("%s",displayMap[i][j]);

                                    }
                                }
                           printf("\n");
                        }
                   

                }

            }else 
            printf("%s",displayMap[r][c]); /* print the whole map if it is 0 */
        }
        printf("\n");
    }

   
    
}
/*********************************************************
 * Name   : chase the pawn .                           
 * Import : getMap( char 2D array), pawnRow ( integer pointer), pawnCol (integer pointer), snakeRow( integer pointer) , snakeCol(interger p)                             
 * Export : None
 * Purpose:  to make the movement of the snake according to the movement of the pawn piece.               
 *********************************************************************************************************/

 void chaseThePawn(char*** getMap, int* pawnRow,int* pawnCol, int* snakeRow, int* snakeCol)
{ 
     /* The snake will move one row downwards if the pawn is below its position */
    if(*pawnCol > *snakeCol && *pawnRow > *snakeRow) /* Check the position of the pawn and the snake */
     {
          if( (strcmp(getMap[*snakeRow+1][*snakeCol]," ") == 0) ) /* if the movement is eligible */
          {
                getMap[*snakeRow+1][*snakeCol] = "~"; /* place the snake one row front */
                getMap[*snakeRow][*snakeCol] = " "; /* place the initial position of the snake to empty space */
                *snakeRow = *snakeRow+1; /* set the new row index of the snake after the movement */
               
          }
          /* since the snake is able to eat the pawn */
          else if( (strcmp(getMap[*snakeRow+1][*snakeCol],"^") == 0) || 
          (strcmp(getMap[*snakeRow+1][*snakeCol],"v") == 0) || (strcmp(getMap[*snakeRow+1][*snakeCol],"<") == 0) 
          || (strcmp(getMap[*snakeRow+1][*snakeCol],">") == 0))
          {
         
                getMap[*snakeRow+1][*snakeCol] = "~"; /* to eat the pawn */
               /* printf("You loose, try again !"); */
          }
         
     /* The snake will move one row upwards if the pawn is above its position */
     }else if(*pawnCol < *snakeCol && *pawnRow < *snakeCol)
     {
          if(strcmp(getMap[*snakeRow-1][*snakeCol]," ")== 0)
          {
                getMap[*snakeRow-1][*snakeCol] = "~"; 
                getMap[*snakeRow-1][*snakeCol] = " ";
                *snakeRow = *snakeRow-1;
                
          }
          else if ((strcmp(getMap[*snakeRow-1][*snakeCol],"^")== 0) || 
          (strcmp(getMap[*snakeRow-1][*snakeCol],"v")== 0) || (strcmp(getMap[*snakeRow-1][*snakeCol],"<")== 0)
          || (strcmp(getMap[*snakeRow-1][*snakeCol],">")== 0))
          {
                getMap[*snakeRow-1][*snakeCol] = "~"; 
              /* printf("You loose! try again "); */
          }
       /* The snake will move one row downwards towards the same column of pawn piece (if the pawn is below the snake) */   
     }else if(*pawnCol == *snakeCol && *pawnRow < *snakeCol)
     {
           if((strcmp(getMap[*snakeRow-1][*snakeCol]," ") == 0)) 
           {
                 getMap[*snakeRow -1 ][*snakeCol] = "~"; 
                 getMap[*snakeRow][*snakeCol] = " ";
                 *snakeRow = *snakeRow-1;

           }else if((strcmp(getMap[*snakeRow-1][*snakeCol],"^")== 0) || (strcmp(getMap[*snakeRow-1][*snakeCol],"v")== 0) ||
            (strcmp(getMap[*snakeRow-1][*snakeCol],"<")== 0)|| (strcmp(getMap[*snakeRow-1][*snakeCol],">")== 0))
          {
                
                getMap[*snakeRow-1][*snakeCol] = "~"; 
               /* printf("You loose! try again "); */
          }
     /* The snake will move one row upwards towards the same column of pawn piece (if the pawn is above the snake) */   
     }else if(*pawnCol == *snakeCol && *pawnRow > *snakeRow)
     {

           if((strcmp(getMap[*snakeRow+1][*snakeCol]," ") == 0) )
           {
                getMap[*snakeRow +1 ][*snakeCol] = "~";
                getMap[*snakeRow][*snakeCol] = " "; 
                *snakeRow = *snakeRow+1;

           }
           else if( (strcmp(getMap[*snakeRow+1][*snakeCol],"^") == 0) || 
          (strcmp(getMap[*snakeRow+1][*snakeCol],"v")== 0) || (strcmp(getMap[*snakeRow+1][*snakeCol],"<")== 0)
           || (strcmp(getMap[*snakeRow+1][*snakeCol],">")== 0))
           
          {
                getMap[*snakeRow +1 ][*snakeCol] = "~";
                /*printf("You loose! try again "); */
                
          }
     /* The snake will move one column towards the right in the same column of the pawn (if the pawn is to the right of the snake) */  
     }else if(*pawnCol > *snakeCol && *pawnRow == *snakeRow)
     {
          
           if((strcmp(getMap[*snakeRow][*snakeCol+1]," ")== 0) )
           {
                 getMap[*snakeRow][*snakeCol+1] = "~"; 
                 getMap[*snakeRow][*snakeCol] = " ";
                *snakeCol = *snakeCol+1;

           }
          else if((strcmp(getMap[*snakeRow][*snakeCol+1],"^")== 0) || 
          (strcmp(getMap[*snakeRow][*snakeCol+1],"v") == 0) || (strcmp(getMap[*snakeRow][*snakeCol+1],"<")== 0)
          || (strcmp(getMap[*snakeRow][*snakeCol+1],">") == 0))
           
          {
                getMap[*snakeRow][*snakeCol+1] = "~"; 
                /* printf("You loose! try again "); */
                
          }
       /* The snake will move one column towards the left in the same column of the pawn (if the pawn is to the left of the snake) */
     }else if(*pawnCol < *snakeCol && *pawnRow == *snakeRow)
     {
             
           if((strcmp(getMap[*snakeRow][*snakeCol-1]," ") == 0) ) 
           {
                 getMap[*snakeRow][*snakeCol-1] = "~"; 
                 getMap[*snakeRow][*snakeCol] = " ";
                 *snakeCol = *snakeCol-1;
           }
           else if((strcmp(getMap[*snakeRow][*snakeCol-1],"^")== 0) || 
          (strcmp(getMap[*snakeRow][*snakeCol-1],"v") == 0) || (strcmp(getMap[*snakeRow][*snakeCol-1],"<")== 0)
          || (strcmp(getMap[*snakeRow][*snakeCol-1],">")== 0))
          {
                getMap[*snakeRow][*snakeCol-1] = "~"; 
                /* printf("You loose! try again "); */
          }
       /* The snake will move one row downwards(in the same column because the snake cannot move diagonally) 
       if the pawn is below the snake  */
     }else if(*pawnCol < *snakeCol && *pawnRow > *snakeRow)
     {
           if((strcmp(getMap[*snakeRow+1][*snakeCol]," ")== 0))
           {
                getMap[*snakeRow+1][*snakeCol] = "~"; 
                getMap[*snakeRow][*snakeCol] = " ";
                *snakeRow = *snakeRow+1;
           }
           
           else if((strcmp(getMap[*snakeRow+1][*snakeCol],"^")== 0) || 
          (strcmp(getMap[*snakeRow+1][*snakeCol],"v")== 0) || (strcmp(getMap[*snakeRow+1][*snakeCol],"<")== 0)
           || (strcmp(getMap[*snakeRow+1][*snakeCol],">")== 0))
          {
                getMap[*snakeRow+1][*snakeCol] = "~"; 
               /*  printf("You loose! try again "); */
                
          }
       /* The snake will move one row upwards(in the same column because the snake cannot move diagonally) 
       if the pawn is above the snake  */
     }else if(*pawnCol > *snakeCol && *pawnRow < *snakeRow)
     {
            if((strcmp(getMap[*snakeRow-1][*snakeCol]," ") == 0)) 
            {
                getMap[*snakeRow-1][*snakeCol] = "~"; 
                getMap[*snakeRow][*snakeCol] = " ";
                *snakeRow = *snakeRow-1;

            }
            
          else if((strcmp(getMap[*snakeRow-1][*snakeCol],"^")== 0) || 
          (strcmp(getMap[*snakeRow-1][*snakeCol],"v")== 0) || (strcmp(getMap[*snakeRow-1][*snakeCol],">")== 0)
           || (strcmp(getMap[*snakeRow-1][*snakeCol],"<")== 0))
          {
                getMap[*snakeRow-1][*snakeCol] = "~"; 
               /* printf("You loose! try again "); */
                
          }


     }
         

}


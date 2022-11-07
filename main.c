#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "control.h"
#include "terminal.h"

int main(int argc, char* argv[])
{
     /* to check if the user HAS given a level to play the game */

     printf("%s",argv[1]);

  if( argc != 2)
  {
    printf(" Sorry ! please enter the necessary meta data containing file . \n "); /* a message to the user if he/ she not entered the level */
  }else 
  {
    #ifdef DARK 
        controlPawn(argv[1]);
    #endif 
  } 

  return 0;
}
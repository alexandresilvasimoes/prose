
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */

#include <stdio.h>     //used in printf
#include <stdlib.h>    //used in itoa()
#include <string.h>    //used to memcpy
#include "Search.h"
#include "Main.h"


int ProblemData::returnFirstofPin(int pin_number)
{
     int output;
    
    //check if there is at least one disk in the pin
    if (pin[pin_number][0] == 0) return(0);
    
     for (int i=1; i<=NUM_DISKS-1; i++) {
         if (pin[pin_number][i] == 0) {
               return(pin[pin_number][i-1]);
         }
     }
     return( pin[pin_number][NUM_DISKS-1]);
};

int ProblemData::removeFirstofPin(int pin_number)
{
    int output;
    
    //check if there is at least one disk in the pin
    if (pin[pin_number][0] == 0) return(0);
    
     for (int i=1; i<=NUM_DISKS-1; i++) {
         if (pin[pin_number][i] == 0) {
               output = pin[pin_number][i-1];
               pin[pin_number][i-1] = 0;
               return(output);
         }
     }
     output = pin[pin_number][NUM_DISKS-1];
     pin[pin_number][NUM_DISKS-1] = 0;
     return(output);
};


int ProblemData::insertFirstofPin(int pin_number, int disk)
{
     for (int i=0; i<=NUM_DISKS-1; i++) {
         if (pin[pin_number][i] == 0) {
            pin[pin_number][i] = disk;
            return(pin[pin_number][i]);
         }
     }
     return(0);
};



char* ProblemData::print()
{
     char* buffer; 
     char aux[20];
     buffer = (char*) malloc (sizeof(char[MAX_TEXT_WINDOW_SIZE]));
     strcpy(buffer, "<[");
     for (int pin_number=0; pin_number<=2; pin_number++) {
         for (int i=0; i<=NUM_DISKS-1; i++){
             itoa (pin[pin_number][i], aux, 10);
             strcat(buffer, aux);
         }
         if (pin_number!=2) strcat(buffer, "][");
     }
     strcat(buffer, "]>");
     return(buffer);
};



int ProblemData::getNumberofDisks(int pin_number) 
{
     int number_of_disks = 0;
     
     for (int i=0; i<=NUM_DISKS-1; i++) {
         if (pin[pin_number][i] !=0) {
            number_of_disks = number_of_disks+1;
         }
     }     
//                                    char aux[20];
//               itoa(number_of_disks, aux, 10);
//               printDepthBox(aux);
//               printGoalMessage();
     return(number_of_disks);          
};


int ProblemData::getPinPosition(int pin_number, int position){
    

    return(pin[pin_number][position]);
};

              
int ProblemData::isGoal(ProblemData* pdptr)
{
    int num_pins_with_disk = 0;   //Store the number of pins that has at least one disk
    int pin_with_disks = 0;       //Store the number 0-2 of this disk
    int number_of_correct = 0;    //Store the number of correct disks in a pin

    
    for (int pin_number=0; pin_number<=2; pin_number++){
        number_of_correct = 0;
        
        for (int position=0; position<=NUM_DISKS-1; position++) {
            if  (pdptr->getPinPosition(pin_number, position) ==  (NUM_DISKS-position)) {
                 number_of_correct = number_of_correct + 1;
                 //printErrorMessage(number_of_correct);
            }
        }
        
        if (number_of_correct == NUM_DISKS) {
        //Disks are in correct order in a pin.
        //Now we must check if current state is different of initial state...
              if (pin[0][0] == NUM_DISKS) {
                 return(0);
              } else return(1);
        }
    }
    return(0);
};




ProblemData::ProblemData(int pin1[3], int pin2[3], int pin3[3])
{
     memcpy (&pin[0][0], &pin1[0], sizeof(int[NUM_DISKS]));
     memcpy (&pin[1][0], &pin2[0], sizeof(int[NUM_DISKS]));
     memcpy (&pin[2][0], &pin3[0], sizeof(int[NUM_DISKS]));
};



ProblemData::ProblemData(void){
     for (int i=0; i<=NUM_DISKS-1; i++) {
         pin[0][i] = NUM_DISKS-i;
         pin[1][i] = 0;
         pin[2][i] = 0;
     }
};


int ProblemData::cost(void)
{
     return(0);  
};


int ProblemData::heuristic(void)
{
   return(0);
};    

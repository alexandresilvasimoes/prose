
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2016.

   ========================================================================= */

#include <stdio.h>     //used in printf
#include <stdlib.h>    //used in itoa()
#include <string.h>    //used to memcpy
#include <windows.h>   //used in MessageBox
#include "Search.h"
#include "Main.h"

int ProblemData::cost(void)
{
     return(1);  
};


int ProblemData::heuristic(void){

    
    // Heuristic 1
    // Basic idea: colors should be grouped, anywhere.
    // Look at a cube face. Get the first color and sum 1 point to each other cell of the same color 
    // that is not in contact with the first horizontally and vertically.

    int h=0;        //Heuristic value
    char cell_color;
    
    for (int face=0; face<=5; face++) {
        for (int cell=0; cell<=8; cell++) {
            cell_color = *(getColor(face, cell));
            for (int aux_cell=0; aux_cell<=8; aux_cell++) {
                if (aux_cell != cell) {
                   if (cell_color != *(getColor(face, aux_cell))) h = h+1;
                }   
            }    
        }
    }
    


    // Heuristic 2
    // In heuristic 1, it is frequent that only 1 cube of a different color 
    // occupe the center of a face.
    // Basic idea: cells of the same colors should be grouped in groups of 3
    
//    int h = 0;
//    char cell_color1, cell_color2, cell_color3;
//    
//    for (int face=0; face<=5; face++) {    
//        for (int base_cell=0; base_cell<=6; base_cell++) {
//                cell_color1 = *(getColor(face, base_cell));
//                cell_color2 = *(getColor(face, base_cell+1));
//                cell_color3 = *(getColor(face, base_cell+2));
//                if ( !((cell_color1==cell_color2) && (cell_color2==cell_color3))) h=h+1;
//                base_cell = base_cell+2;
//        }
//        for (int base_cell=0; base_cell<=2; base_cell++) {
//                cell_color1 = *(getColor(face, base_cell));
//                cell_color2 = *(getColor(face, base_cell+3));
//                cell_color3 = *(getColor(face, base_cell+6));
//                if ( !((cell_color1==cell_color2) && (cell_color2==cell_color3))) h=h+1;
//        }
//    }


    return(h);
};


char* ProblemData::getState(void){
   return(&cube[0][0]);                     
};


void ProblemData::setState(char * mypointer){
   memcpy(&(cube[0][0]), mypointer, sizeof(cube));              
};


ProblemData::ProblemData(void){
                               
	//Here you can find some initial state examples in different depths

	//Initial state after R0 (goal in depth=1)
	char mycube[6][9] = {  'O','O','O','W','W','W','W','W','W',
	                      'Y','Y','Y','O','O','O','O','O','O',
	                      'W','W','W','R','R','R','R','R','R',
	                      'G','G','G','G','G','G','G','G','G',
	                      'B','B','B','B','B','B','B','B','B',
	                      'R','R','R','Y','Y','Y','Y','Y','Y'};

	//Initial state after R0 -> R11 (goal in depth=2)
	//char mycube[6][9] = {  'O','O','G','W','W','G','W','W','G', 
	//                       'Y','Y','Y','O','O','O','O','O','O', 
	//                       'W','R','R','W','R','R','W','R','R', 
	//                       'G','G','Y','G','G','Y','G','G','R',
	//                       'B','B','O','B','B','W','B','B','W',
	//                       'B','R','R','B','Y','Y','B','Y','Y'};


	//Initial state after R0 -> R11 -> R16 (goal in depth=3)
	//char mycube[6][9] = {  'O','O','G','W','W','G','W','W','G', 
	//                       'B','Y','Y','B','O','O','W','O','O', 
	//                       'W','R','G','W','R','G','W','R','Y', 
	//                       'O','O','Y','G','G','Y','G','G','R',
	//                       'B','B','O','B','B','W','R','R','R',
	//                       'R','Y','Y','R','Y','Y','B','B','B'};


	//Initial state after R0 -> R11 -> R16 -> R4 (goal in depth=4)
	// char mycube[6][9] = {  'O','O','G','W','W','G','W','O','O',
	//                        'B','Y','Y','B','O','O','B','B','B',
	//                        'W','R','G','W','R','G','W','W','G',
	//                        'O','O','Y','G','G','Y','G','G','R',
	//                        'R','B','B','R','B','B','R','W','O',
	//                        'R','Y','Y','R','Y','Y','W','R','Y'};


	//Initial state after R0 -> R11 -> R16 -> R4 -> R12 (goal in depth=5)
	//char mycube[6][9] = {  'W','W','O','O','W','O','O','G','G', 
	//                       'B','Y','R','B','O','B','B','B','B', 
	//                       'G','R','G','G','R','G','R','W','G', 
	//                       'O','O','Y','G','G','Y','B','O','Y',
	//                       'W','W','W','R','B','B','R','W','O',
	//                       'R','Y','Y','R','Y','Y','W','R','Y'};

setState(&mycube[0][0]);

                               
};


ProblemData::ProblemData(char* mypointer) {                               

      int num_red = 0;
      int num_green = 0;
      int num_blue = 0;
      int num_orange = 0;
      int num_yellow = 0;
      int num_white = 0;

      memcpy(&(cube[0][0]), mypointer, sizeof(cube));
     
     //Check if there are 9 of each cell color
      for (int face=0; face<=5; face++) {
          for (int cell=0; cell<=8; cell++) {
              if (cube[face][cell] == 'R') num_red = num_red+1;
              if (cube[face][cell] == 'G') num_green = num_green+1;
              if (cube[face][cell] == 'B') num_blue = num_blue+1;
              if (cube[face][cell] == 'O') num_orange = num_orange+1;
              if (cube[face][cell] == 'Y') num_yellow = num_yellow+1;
              if (cube[face][cell] == 'W') num_white = num_white+1;
          }
      }
      if ( (num_red!=9) || (num_green!=9) || (num_blue!=9) || (num_orange!=9) || (num_white!=9) || (num_yellow!=9) ) {
         printErrorMessage(ERROR_USER_INITIALIZATION);
         if (num_red!=9) MessageBox(NULL, "Incorrect number of Red squares!", NULL, NULL);
         if (num_green!=9) MessageBox(NULL, "Incorrect number of squares!", NULL, NULL);
         if (num_blue!=9) MessageBox(NULL, "Incorrect number of Blue squares!", NULL, NULL);
         if (num_orange!=9) MessageBox(NULL, "Incorrect number of Orange squares!", NULL, NULL);
         if (num_yellow!=9) MessageBox(NULL, "Incorrect number of Yellow squares!", NULL, NULL);
         if (num_white!=9) MessageBox(NULL, "Incorrect number of White squares!", NULL, NULL);
         exit(-1);
      }
};


char* ProblemData::getColor(int face, int cell)
{
     return(&(cube[face][cell]));
};


void ProblemData::setColor(int face, int position, char* color)
{
     cube[face][position] = *color;
};


char* ProblemData::print()
{
     char* buffer; 
     char aux;
     buffer = (char*) malloc (sizeof(char[MAX_TEXT_SIZE]));
     
     strcpy(buffer, "<[");
     for (int face=0; face<=5; face++) {
         for (int cell=0; cell<=8; cell++){
             strncat(buffer, getColor(face, cell), 1);
         }
         if (face!=5) strcat(buffer, "][");
     }
     strcat(buffer, "]>");
     return(buffer);
};



              
int ProblemData::isGoal(ProblemData* pdptr)
{
    char test;              //used to test the color condition
    int faces_closed = 0;   //stores the number of faces with cells of the same color
    
    for (int face=0; face<=5; face++) {
        test = cube[face][0];
        if ((cube[face][1]==test) && (cube[face][2]==test) && (cube[face][3]==test) && (cube[face][4]==test) && (cube[face][5] == test) && (cube[face][6] == test) && (cube[face][7] == test) && (cube[face][8] == test)) {
           faces_closed = faces_closed + 1;
        }
    }    
    if (faces_closed==6) return(1); else return(0);
};




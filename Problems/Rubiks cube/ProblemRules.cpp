
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2016.

   ========================================================================= */
   

#include <stdio.h>     //used to define NULL
#include "Search.h"
#include "Main.h"


typedef Node* (ProblemRules::*ptrProblemRulesMethod)(Node*);

ProblemRules::ProblemRules (void) 
{
   setRulesNumber(18);
};


void ProblemRules::setRulesNumber (int number)
{
     rules_number = number;    
};


int ProblemRules::getRulesNumber (void)
{
    return(rules_number);
};


ptrProblemRulesMethod ProblemRules::getRule(int rule)
{
    ptrProblemRulesMethod p[getRulesNumber()];
    p[0] =&ProblemRules::R0;
    p[1] =&ProblemRules::R1;
    p[2] =&ProblemRules::R2;
    p[3] =&ProblemRules::R3;
    p[4] =&ProblemRules::R4;
    p[5] =&ProblemRules::R5;
    p[6] =&ProblemRules::R6;
    p[7] =&ProblemRules::R7;
    p[8] =&ProblemRules::R8;
    p[9] =&ProblemRules::R9;
    p[10]=&ProblemRules::R10;
    p[11]=&ProblemRules::R11;
    p[12]=&ProblemRules::R12;
    p[13]=&ProblemRules::R13;
    p[14]=&ProblemRules::R14;
    p[15]=&ProblemRules::R15;
    p[16]=&ProblemRules::R16;
    p[17]=&ProblemRules::R17;
    return(p[rule]);
};


//FRONTAL LEFT-RIGHT MOVEMENTS

Node* ProblemRules::R0(Node* state)
{
      // > > > 
      // x x x
      // x x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,0);
      charbuffer[1] = *(state->getData())->getColor(0,1);
      charbuffer[2] = *(state->getData())->getColor(0,2);
      charbuffer[3] = *(state->getData())->getColor(2,0);
      charbuffer[4] = *(state->getData())->getColor(2,1);
      charbuffer[5] = *(state->getData())->getColor(2,2);
      charbuffer[6] = *(state->getData())->getColor(5,0);
      charbuffer[7] = *(state->getData())->getColor(5,1);
      charbuffer[8] = *(state->getData())->getColor(5,2);
      charbuffer[9] = *(state->getData())->getColor(1,0);
      charbuffer[10]= *(state->getData())->getColor(1,1);
      charbuffer[11]= *(state->getData())->getColor(1,2);
      //Put these colors in the new order
      (state->getData())->setColor(2, 0, &charbuffer[0]);
      (state->getData())->setColor(2, 1, &charbuffer[1]);
      (state->getData())->setColor(2, 2, &charbuffer[2]);
      (state->getData())->setColor(5, 0, &charbuffer[3]);
      (state->getData())->setColor(5, 1, &charbuffer[4]);
      (state->getData())->setColor(5, 2, &charbuffer[5]);
      (state->getData())->setColor(1, 0, &charbuffer[6]);
      (state->getData())->setColor(1, 1, &charbuffer[7]);
      (state->getData())->setColor(1, 2, &charbuffer[8]);
      (state->getData())->setColor(0, 0, &charbuffer[9]);
      (state->getData())->setColor(0, 1, &charbuffer[10]);
      (state->getData())->setColor(0, 2, &charbuffer[11]);
      //Get color values of the superior face to rotate counter-clockwise
      charbuffer[0] = *(state->getData())->getColor(3,0);
      charbuffer[1] = *(state->getData())->getColor(3,1);
      charbuffer[2] = *(state->getData())->getColor(3,2);
      charbuffer[3] = *(state->getData())->getColor(3,3);
      charbuffer[4] = *(state->getData())->getColor(3,4);
      charbuffer[5] = *(state->getData())->getColor(3,5);
      charbuffer[6] = *(state->getData())->getColor(3,6);
      charbuffer[7] = *(state->getData())->getColor(3,7);
      charbuffer[8] = *(state->getData())->getColor(3,8);
      //Put these colors in the new order
      (state->getData())->setColor(3, 6, &charbuffer[0]);
      (state->getData())->setColor(3, 3, &charbuffer[1]);
      (state->getData())->setColor(3, 0, &charbuffer[2]);
      (state->getData())->setColor(3, 7, &charbuffer[3]);
      (state->getData())->setColor(3, 4, &charbuffer[4]);
      (state->getData())->setColor(3, 1, &charbuffer[5]);
      (state->getData())->setColor(3, 8, &charbuffer[6]);
      (state->getData())->setColor(3, 5, &charbuffer[7]);
      (state->getData())->setColor(3, 2, &charbuffer[8]);
      return(state);
};



Node* ProblemRules::R1(Node* state)
{
      // < < <
      // x x x
      // x x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,0);
      charbuffer[1] = *(state->getData())->getColor(0,1);
      charbuffer[2] = *(state->getData())->getColor(0,2);
      charbuffer[3] = *(state->getData())->getColor(2,0);
      charbuffer[4] = *(state->getData())->getColor(2,1);
      charbuffer[5] = *(state->getData())->getColor(2,2);
      charbuffer[6] = *(state->getData())->getColor(5,0);
      charbuffer[7] = *(state->getData())->getColor(5,1);
      charbuffer[8] = *(state->getData())->getColor(5,2);
      charbuffer[9] = *(state->getData())->getColor(1,0);
      charbuffer[10]= *(state->getData())->getColor(1,1);
      charbuffer[11]= *(state->getData())->getColor(1,2);
      //Put these colors in the new order
      (state->getData())->setColor(1, 0, &charbuffer[0]);
      (state->getData())->setColor(1, 1, &charbuffer[1]);
      (state->getData())->setColor(1, 2, &charbuffer[2]);
      (state->getData())->setColor(0, 0, &charbuffer[3]);
      (state->getData())->setColor(0, 1, &charbuffer[4]);
      (state->getData())->setColor(0, 2, &charbuffer[5]);
      (state->getData())->setColor(2, 0, &charbuffer[6]);
      (state->getData())->setColor(2, 1, &charbuffer[7]);
      (state->getData())->setColor(2, 2, &charbuffer[8]);
      (state->getData())->setColor(5, 0, &charbuffer[9]);
      (state->getData())->setColor(5, 1, &charbuffer[10]);
      (state->getData())->setColor(5, 2, &charbuffer[11]);
      //Get color values of the superior face to rotate clockwise
      charbuffer[0] = *(state->getData())->getColor(3,0);
      charbuffer[1] = *(state->getData())->getColor(3,1);
      charbuffer[2] = *(state->getData())->getColor(3,2);
      charbuffer[3] = *(state->getData())->getColor(3,3);
      charbuffer[4] = *(state->getData())->getColor(3,4);
      charbuffer[5] = *(state->getData())->getColor(3,5);
      charbuffer[6] = *(state->getData())->getColor(3,6);
      charbuffer[7] = *(state->getData())->getColor(3,7);
      charbuffer[8] = *(state->getData())->getColor(3,8);
      //Put these colors in the new order
      (state->getData())->setColor(3, 2, &charbuffer[0]);
      (state->getData())->setColor(3, 5, &charbuffer[1]);
      (state->getData())->setColor(3, 8, &charbuffer[2]);
      (state->getData())->setColor(3, 1, &charbuffer[3]);
      (state->getData())->setColor(3, 4, &charbuffer[4]);
      (state->getData())->setColor(3, 7, &charbuffer[5]);
      (state->getData())->setColor(3, 0, &charbuffer[6]);
      (state->getData())->setColor(3, 3, &charbuffer[7]);
      (state->getData())->setColor(3, 6, &charbuffer[8]);
      return(state);
};


Node* ProblemRules::R2(Node* state)
{
      // x x x
      // > > >
      // x x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,3);
      charbuffer[1] = *(state->getData())->getColor(0,4);
      charbuffer[2] = *(state->getData())->getColor(0,5);
      charbuffer[3] = *(state->getData())->getColor(2,3);
      charbuffer[4] = *(state->getData())->getColor(2,4);
      charbuffer[5] = *(state->getData())->getColor(2,5);
      charbuffer[6] = *(state->getData())->getColor(5,3);
      charbuffer[7] = *(state->getData())->getColor(5,4);
      charbuffer[8] = *(state->getData())->getColor(5,5);
      charbuffer[9] = *(state->getData())->getColor(1,3);
      charbuffer[10]= *(state->getData())->getColor(1,4);
      charbuffer[11]= *(state->getData())->getColor(1,5);
      //Put these colors in the new order
      (state->getData())->setColor(2, 3, &charbuffer[0]);
      (state->getData())->setColor(2, 4, &charbuffer[1]);
      (state->getData())->setColor(2, 5, &charbuffer[2]);
      (state->getData())->setColor(5, 3, &charbuffer[3]);
      (state->getData())->setColor(5, 4, &charbuffer[4]);
      (state->getData())->setColor(5, 5, &charbuffer[5]);
      (state->getData())->setColor(1, 3, &charbuffer[6]);
      (state->getData())->setColor(1, 4, &charbuffer[7]);
      (state->getData())->setColor(1, 5, &charbuffer[8]);
      (state->getData())->setColor(0, 3, &charbuffer[9]);
      (state->getData())->setColor(0, 4, &charbuffer[10]);
      (state->getData())->setColor(0, 5, &charbuffer[11]);

      return(state);
};


Node* ProblemRules::R3(Node* state)
{
      // x x x
      // < < <
      // x x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,3);
      charbuffer[1] = *(state->getData())->getColor(0,4);
      charbuffer[2] = *(state->getData())->getColor(0,5);
      charbuffer[3] = *(state->getData())->getColor(2,3);
      charbuffer[4] = *(state->getData())->getColor(2,4);
      charbuffer[5] = *(state->getData())->getColor(2,5);
      charbuffer[6] = *(state->getData())->getColor(5,3);
      charbuffer[7] = *(state->getData())->getColor(5,4);
      charbuffer[8] = *(state->getData())->getColor(5,5);
      charbuffer[9] = *(state->getData())->getColor(1,3);
      charbuffer[10]= *(state->getData())->getColor(1,4);
      charbuffer[11]= *(state->getData())->getColor(1,5);
      //Put these colors in the new order
      (state->getData())->setColor(1, 3, &charbuffer[0]);
      (state->getData())->setColor(1, 4, &charbuffer[1]);
      (state->getData())->setColor(1, 5, &charbuffer[2]);
      (state->getData())->setColor(0, 3, &charbuffer[3]);
      (state->getData())->setColor(0, 4, &charbuffer[4]);
      (state->getData())->setColor(0, 5, &charbuffer[5]);
      (state->getData())->setColor(2, 3, &charbuffer[6]);
      (state->getData())->setColor(2, 4, &charbuffer[7]);
      (state->getData())->setColor(2, 5, &charbuffer[8]);
      (state->getData())->setColor(5, 3, &charbuffer[9]);
      (state->getData())->setColor(5, 4, &charbuffer[10]);
      (state->getData())->setColor(5, 5, &charbuffer[11]);

      return(state);
};


Node* ProblemRules::R4(Node* state)
{
      // x x x
      // x x x
      // > > >
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,6);
      charbuffer[1] = *(state->getData())->getColor(0,7);
      charbuffer[2] = *(state->getData())->getColor(0,8);
      charbuffer[3] = *(state->getData())->getColor(2,6);
      charbuffer[4] = *(state->getData())->getColor(2,7);
      charbuffer[5] = *(state->getData())->getColor(2,8);
      charbuffer[6] = *(state->getData())->getColor(5,6);
      charbuffer[7] = *(state->getData())->getColor(5,7);
      charbuffer[8] = *(state->getData())->getColor(5,8);
      charbuffer[9] = *(state->getData())->getColor(1,6);
      charbuffer[10]= *(state->getData())->getColor(1,7);
      charbuffer[11]= *(state->getData())->getColor(1,8);
      //Put these colors in the new order
      (state->getData())->setColor(2, 6, &charbuffer[0]);
      (state->getData())->setColor(2, 7, &charbuffer[1]);
      (state->getData())->setColor(2, 8, &charbuffer[2]);
      (state->getData())->setColor(5, 6, &charbuffer[3]);
      (state->getData())->setColor(5, 7, &charbuffer[4]);
      (state->getData())->setColor(5, 8, &charbuffer[5]);
      (state->getData())->setColor(1, 6, &charbuffer[6]);
      (state->getData())->setColor(1, 7, &charbuffer[7]);
      (state->getData())->setColor(1, 8, &charbuffer[8]);
      (state->getData())->setColor(0, 6, &charbuffer[9]);
      (state->getData())->setColor(0, 7, &charbuffer[10]);
      (state->getData())->setColor(0, 8, &charbuffer[11]);
      //Get color values of the superior face to rotate clockwise
      charbuffer[0] = *(state->getData())->getColor(4,0);
      charbuffer[1] = *(state->getData())->getColor(4,1);
      charbuffer[2] = *(state->getData())->getColor(4,2);
      charbuffer[3] = *(state->getData())->getColor(4,3);
      charbuffer[4] = *(state->getData())->getColor(4,4);
      charbuffer[5] = *(state->getData())->getColor(4,5);
      charbuffer[6] = *(state->getData())->getColor(4,6);
      charbuffer[7] = *(state->getData())->getColor(4,7);
      charbuffer[8] = *(state->getData())->getColor(4,8);
      //Put these colors in the new order
      (state->getData())->setColor(4, 2, &charbuffer[0]);
      (state->getData())->setColor(4, 5, &charbuffer[1]);
      (state->getData())->setColor(4, 8, &charbuffer[2]);
      (state->getData())->setColor(4, 1, &charbuffer[3]);
      (state->getData())->setColor(4, 4, &charbuffer[4]);
      (state->getData())->setColor(4, 7, &charbuffer[5]);
      (state->getData())->setColor(4, 0, &charbuffer[6]);
      (state->getData())->setColor(4, 3, &charbuffer[7]);
      (state->getData())->setColor(4, 6, &charbuffer[8]);
      return(state);
};


Node* ProblemRules::R5(Node* state)
{
      // x x x
      // x x x
      // < < <
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,6);
      charbuffer[1] = *(state->getData())->getColor(0,7);
      charbuffer[2] = *(state->getData())->getColor(0,8);
      charbuffer[3] = *(state->getData())->getColor(2,6);
      charbuffer[4] = *(state->getData())->getColor(2,7);
      charbuffer[5] = *(state->getData())->getColor(2,8);
      charbuffer[6] = *(state->getData())->getColor(5,6);
      charbuffer[7] = *(state->getData())->getColor(5,7);
      charbuffer[8] = *(state->getData())->getColor(5,8);
      charbuffer[9] = *(state->getData())->getColor(1,6);
      charbuffer[10]= *(state->getData())->getColor(1,7);
      charbuffer[11]= *(state->getData())->getColor(1,8);
      //Put these colors in the new order
      (state->getData())->setColor(1, 6, &charbuffer[0]);
      (state->getData())->setColor(1, 7, &charbuffer[1]);
      (state->getData())->setColor(1, 8, &charbuffer[2]);
      (state->getData())->setColor(0, 6, &charbuffer[3]);
      (state->getData())->setColor(0, 7, &charbuffer[4]);
      (state->getData())->setColor(0, 8, &charbuffer[5]);
      (state->getData())->setColor(2, 6, &charbuffer[6]);
      (state->getData())->setColor(2, 7, &charbuffer[7]);
      (state->getData())->setColor(2, 8, &charbuffer[8]);
      (state->getData())->setColor(5, 6, &charbuffer[9]);
      (state->getData())->setColor(5, 7, &charbuffer[10]);
      (state->getData())->setColor(5, 8, &charbuffer[11]);
      //Get color values of the superior face to rotate counter-clockwise
      charbuffer[0] = *(state->getData())->getColor(4,0);
      charbuffer[1] = *(state->getData())->getColor(4,1);
      charbuffer[2] = *(state->getData())->getColor(4,2);
      charbuffer[3] = *(state->getData())->getColor(4,3);
      charbuffer[4] = *(state->getData())->getColor(4,4);
      charbuffer[5] = *(state->getData())->getColor(4,5);
      charbuffer[6] = *(state->getData())->getColor(4,6);
      charbuffer[7] = *(state->getData())->getColor(4,7);
      charbuffer[8] = *(state->getData())->getColor(4,8);
      //Put these colors in the new order
      (state->getData())->setColor(4, 6, &charbuffer[0]);
      (state->getData())->setColor(4, 3, &charbuffer[1]);
      (state->getData())->setColor(4, 0, &charbuffer[2]);
      (state->getData())->setColor(4, 7, &charbuffer[3]);
      (state->getData())->setColor(4, 4, &charbuffer[4]);
      (state->getData())->setColor(4, 1, &charbuffer[5]);
      (state->getData())->setColor(4, 8, &charbuffer[6]);
      (state->getData())->setColor(4, 5, &charbuffer[7]);
      (state->getData())->setColor(4, 2, &charbuffer[8]);
      return(state);
};



//FRONTAL UP-DOWN MOVEMENTS

Node* ProblemRules::R6(Node* state)
{
      // ^ x x
      // ^ x x
      // ^ x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,0);
      charbuffer[1] = *(state->getData())->getColor(0,3);
      charbuffer[2] = *(state->getData())->getColor(0,6);
      charbuffer[3] = *(state->getData())->getColor(4,0);
      charbuffer[4] = *(state->getData())->getColor(4,3);
      charbuffer[5] = *(state->getData())->getColor(4,6);
      charbuffer[6] = *(state->getData())->getColor(5,8);
      charbuffer[7] = *(state->getData())->getColor(5,5);
      charbuffer[8] = *(state->getData())->getColor(5,2);
      charbuffer[9] = *(state->getData())->getColor(3,0);
      charbuffer[10]= *(state->getData())->getColor(3,3);
      charbuffer[11]= *(state->getData())->getColor(3,6);
      //Put these colors in the new order
      (state->getData())->setColor(3, 0, &charbuffer[0]);
      (state->getData())->setColor(3, 3, &charbuffer[1]);
      (state->getData())->setColor(3, 6, &charbuffer[2]);
      (state->getData())->setColor(0, 0, &charbuffer[3]);
      (state->getData())->setColor(0, 3, &charbuffer[4]);
      (state->getData())->setColor(0, 6, &charbuffer[5]);
      (state->getData())->setColor(4, 0, &charbuffer[6]);
      (state->getData())->setColor(4, 3, &charbuffer[7]);
      (state->getData())->setColor(4, 6, &charbuffer[8]);
      (state->getData())->setColor(5, 8, &charbuffer[9]);
      (state->getData())->setColor(5, 5, &charbuffer[10]);
      (state->getData())->setColor(5, 2, &charbuffer[11]);
      //Get color values of the superior face to rotate counter-clockwise
      charbuffer[0] = *(state->getData())->getColor(1,0);
      charbuffer[1] = *(state->getData())->getColor(1,1);
      charbuffer[2] = *(state->getData())->getColor(1,2);
      charbuffer[3] = *(state->getData())->getColor(1,3);
      charbuffer[4] = *(state->getData())->getColor(1,4);
      charbuffer[5] = *(state->getData())->getColor(1,5);
      charbuffer[6] = *(state->getData())->getColor(1,6);
      charbuffer[7] = *(state->getData())->getColor(1,7);
      charbuffer[8] = *(state->getData())->getColor(1,8);
      //Put these colors in the new order
      (state->getData())->setColor(1, 6, &charbuffer[0]);
      (state->getData())->setColor(1, 3, &charbuffer[1]);
      (state->getData())->setColor(1, 0, &charbuffer[2]);
      (state->getData())->setColor(1, 7, &charbuffer[3]);
      (state->getData())->setColor(1, 4, &charbuffer[4]);
      (state->getData())->setColor(1, 1, &charbuffer[5]);
      (state->getData())->setColor(1, 8, &charbuffer[6]);
      (state->getData())->setColor(1, 5, &charbuffer[7]);
      (state->getData())->setColor(1, 2, &charbuffer[8]);
      return(state);
};


Node* ProblemRules::R7(Node* state)
{
      // v x x
      // v x x
      // v x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,0);
      charbuffer[1] = *(state->getData())->getColor(0,3);
      charbuffer[2] = *(state->getData())->getColor(0,6);
      charbuffer[3] = *(state->getData())->getColor(4,0);
      charbuffer[4] = *(state->getData())->getColor(4,3);
      charbuffer[5] = *(state->getData())->getColor(4,6);
      charbuffer[6] = *(state->getData())->getColor(5,8);
      charbuffer[7] = *(state->getData())->getColor(5,5);
      charbuffer[8] = *(state->getData())->getColor(5,2);
      charbuffer[9] = *(state->getData())->getColor(3,0);
      charbuffer[10]= *(state->getData())->getColor(3,3);
      charbuffer[11]= *(state->getData())->getColor(3,6);
      //Put these colors in the new order
      (state->getData())->setColor(4, 0, &charbuffer[0]);
      (state->getData())->setColor(4, 3, &charbuffer[1]);
      (state->getData())->setColor(4, 6, &charbuffer[2]);
      (state->getData())->setColor(5, 8, &charbuffer[3]);
      (state->getData())->setColor(5, 5, &charbuffer[4]);
      (state->getData())->setColor(5, 2, &charbuffer[5]);
      (state->getData())->setColor(3, 0, &charbuffer[6]);
      (state->getData())->setColor(3, 3, &charbuffer[7]);
      (state->getData())->setColor(3, 6, &charbuffer[8]);
	  (state->getData())->setColor(0, 0, &charbuffer[9]);  //Bug corrected (state->getData())->setColor(0, 8, &charbuffer[9]);
	  (state->getData())->setColor(0, 3, &charbuffer[10]); //Bug corrected (state->getData())->setColor(0, 5, &charbuffer[10]);
	  (state->getData())->setColor(0, 6, &charbuffer[11]); //Bug corrected  (state->getData())->setColor(0, 2, &charbuffer[11]);
      //Get color values of the superior face to rotate counter-clockwise
      charbuffer[0] = *(state->getData())->getColor(1,0);
      charbuffer[1] = *(state->getData())->getColor(1,1);
      charbuffer[2] = *(state->getData())->getColor(1,2);
      charbuffer[3] = *(state->getData())->getColor(1,3);
      charbuffer[4] = *(state->getData())->getColor(1,4);
      charbuffer[5] = *(state->getData())->getColor(1,5);
      charbuffer[6] = *(state->getData())->getColor(1,6);
      charbuffer[7] = *(state->getData())->getColor(1,7);
      charbuffer[8] = *(state->getData())->getColor(1,8);
      //Put these colors in the new order
      (state->getData())->setColor(1, 2, &charbuffer[0]);
      (state->getData())->setColor(1, 5, &charbuffer[1]);
      (state->getData())->setColor(1, 8, &charbuffer[2]);
      (state->getData())->setColor(1, 1, &charbuffer[3]);
      (state->getData())->setColor(1, 4, &charbuffer[4]);
      (state->getData())->setColor(1, 7, &charbuffer[5]);
      (state->getData())->setColor(1, 0, &charbuffer[6]);
      (state->getData())->setColor(1, 3, &charbuffer[7]);
      (state->getData())->setColor(1, 6, &charbuffer[8]);
      return(state);
};



Node* ProblemRules::R8(Node* state)
{
      // x ^ x
      // x ^ x
      // x ^ x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,1);
      charbuffer[1] = *(state->getData())->getColor(0,4);
      charbuffer[2] = *(state->getData())->getColor(0,7);
      charbuffer[3] = *(state->getData())->getColor(4,1);
      charbuffer[4] = *(state->getData())->getColor(4,4);
      charbuffer[5] = *(state->getData())->getColor(4,7);
      charbuffer[6] = *(state->getData())->getColor(5,7);
      charbuffer[7] = *(state->getData())->getColor(5,4);
      charbuffer[8] = *(state->getData())->getColor(5,1);
      charbuffer[9] = *(state->getData())->getColor(3,1);
      charbuffer[10]= *(state->getData())->getColor(3,4);
      charbuffer[11]= *(state->getData())->getColor(3,7);
      //Put these colors in the new order
      (state->getData())->setColor(3, 1, &charbuffer[0]);
      (state->getData())->setColor(3, 4, &charbuffer[1]);
      (state->getData())->setColor(3, 7, &charbuffer[2]);
      (state->getData())->setColor(0, 1, &charbuffer[3]);
      (state->getData())->setColor(0, 4, &charbuffer[4]);
      (state->getData())->setColor(0, 7, &charbuffer[5]);
      (state->getData())->setColor(4, 1, &charbuffer[6]);
      (state->getData())->setColor(4, 4, &charbuffer[7]);
      (state->getData())->setColor(4, 7, &charbuffer[8]);
      (state->getData())->setColor(5, 7, &charbuffer[9]);
      (state->getData())->setColor(5, 4, &charbuffer[10]);
      (state->getData())->setColor(5, 1, &charbuffer[11]);
      return(state);
};



Node* ProblemRules::R9(Node* state)
{
      // x v x
      // x v x
      // x v x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,1);
      charbuffer[1] = *(state->getData())->getColor(0,4);
      charbuffer[2] = *(state->getData())->getColor(0,7);
      charbuffer[3] = *(state->getData())->getColor(4,1);
      charbuffer[4] = *(state->getData())->getColor(4,4);
      charbuffer[5] = *(state->getData())->getColor(4,7);
      charbuffer[6] = *(state->getData())->getColor(5,7);
      charbuffer[7] = *(state->getData())->getColor(5,4);
      charbuffer[8] = *(state->getData())->getColor(5,1);
      charbuffer[9] = *(state->getData())->getColor(3,1);
      charbuffer[10]= *(state->getData())->getColor(3,4);
      charbuffer[11]= *(state->getData())->getColor(3,7);
      //Put these colors in the new order
      (state->getData())->setColor(4, 1, &charbuffer[0]);
      (state->getData())->setColor(4, 4, &charbuffer[1]);
      (state->getData())->setColor(4, 7, &charbuffer[2]);
      (state->getData())->setColor(5, 7, &charbuffer[3]);
      (state->getData())->setColor(5, 4, &charbuffer[4]);
      (state->getData())->setColor(5, 1, &charbuffer[5]);
      (state->getData())->setColor(3, 1, &charbuffer[6]);
      (state->getData())->setColor(3, 4, &charbuffer[7]);
      (state->getData())->setColor(3, 7, &charbuffer[8]);
      (state->getData())->setColor(0, 1, &charbuffer[9]);
      (state->getData())->setColor(0, 4, &charbuffer[10]);
      (state->getData())->setColor(0, 7, &charbuffer[11]);
      return(state);
};


Node* ProblemRules::R10(Node* state)
{
      // x x ^
      // x x ^
      // x x ^
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,2);
      charbuffer[1] = *(state->getData())->getColor(0,5);
      charbuffer[2] = *(state->getData())->getColor(0,8);
      charbuffer[3] = *(state->getData())->getColor(4,2);
      charbuffer[4] = *(state->getData())->getColor(4,5);
      charbuffer[5] = *(state->getData())->getColor(4,8);
      charbuffer[6] = *(state->getData())->getColor(5,6);
      charbuffer[7] = *(state->getData())->getColor(5,3);
      charbuffer[8] = *(state->getData())->getColor(5,0);
      charbuffer[9] = *(state->getData())->getColor(3,2);
      charbuffer[10]= *(state->getData())->getColor(3,5);
      charbuffer[11]= *(state->getData())->getColor(3,8);
      //Put these colors in the new order
      (state->getData())->setColor(3, 2, &charbuffer[0]);
      (state->getData())->setColor(3, 5, &charbuffer[1]);
      (state->getData())->setColor(3, 8, &charbuffer[2]);
      (state->getData())->setColor(0, 2, &charbuffer[3]);
      (state->getData())->setColor(0, 5, &charbuffer[4]);
      (state->getData())->setColor(0, 8, &charbuffer[5]);
      (state->getData())->setColor(4, 2, &charbuffer[6]);
      (state->getData())->setColor(4, 5, &charbuffer[7]);
      (state->getData())->setColor(4, 8, &charbuffer[8]);
      (state->getData())->setColor(5, 6, &charbuffer[9]);
      (state->getData())->setColor(5, 3, &charbuffer[10]);
      (state->getData())->setColor(5, 0, &charbuffer[11]);
      //Rotate right face clockwise
      charbuffer[0] = *(state->getData())->getColor(2,0);
      charbuffer[1] = *(state->getData())->getColor(2,1);
      charbuffer[2] = *(state->getData())->getColor(2,2);
      charbuffer[3] = *(state->getData())->getColor(2,3);
      charbuffer[4] = *(state->getData())->getColor(2,4);
      charbuffer[5] = *(state->getData())->getColor(2,5);
      charbuffer[6] = *(state->getData())->getColor(2,6);
      charbuffer[7] = *(state->getData())->getColor(2,7);
      charbuffer[8] = *(state->getData())->getColor(2,8);
      //
      (state->getData())->setColor(2, 2, &charbuffer[0]);
      (state->getData())->setColor(2, 5, &charbuffer[1]);
      (state->getData())->setColor(2, 8, &charbuffer[2]);
      (state->getData())->setColor(2, 1, &charbuffer[3]);
      (state->getData())->setColor(2, 4, &charbuffer[4]);
      (state->getData())->setColor(2, 7, &charbuffer[5]);
      (state->getData())->setColor(2, 0, &charbuffer[6]);
      (state->getData())->setColor(2, 3, &charbuffer[7]);
      (state->getData())->setColor(2, 6, &charbuffer[8]);
      
      return(state);
};



Node* ProblemRules::R11(Node* state)
{
      // x x v
      // x x v
      // x x v
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(0,2);
      charbuffer[1] = *(state->getData())->getColor(0,5);
      charbuffer[2] = *(state->getData())->getColor(0,8);
      charbuffer[3] = *(state->getData())->getColor(4,2);
      charbuffer[4] = *(state->getData())->getColor(4,5);
      charbuffer[5] = *(state->getData())->getColor(4,8);
      charbuffer[6] = *(state->getData())->getColor(5,6);
      charbuffer[7] = *(state->getData())->getColor(5,3);
      charbuffer[8] = *(state->getData())->getColor(5,0);
      charbuffer[9] = *(state->getData())->getColor(3,2);
      charbuffer[10]= *(state->getData())->getColor(3,5);
      charbuffer[11]= *(state->getData())->getColor(3,8);
      //Put these colors in the new order
      (state->getData())->setColor(4, 2, &charbuffer[0]);
      (state->getData())->setColor(4, 5, &charbuffer[1]);
      (state->getData())->setColor(4, 8, &charbuffer[2]);
      (state->getData())->setColor(5, 6, &charbuffer[3]);
      (state->getData())->setColor(5, 3, &charbuffer[4]);
      (state->getData())->setColor(5, 0, &charbuffer[5]);
      (state->getData())->setColor(3, 2, &charbuffer[6]);
      (state->getData())->setColor(3, 5, &charbuffer[7]);
      (state->getData())->setColor(3, 8, &charbuffer[8]);
      (state->getData())->setColor(0, 2, &charbuffer[9]);
      (state->getData())->setColor(0, 5, &charbuffer[10]);
      (state->getData())->setColor(0, 8, &charbuffer[11]);
      //Rotate right face clockwise
      charbuffer[0] = *(state->getData())->getColor(2,0);
      charbuffer[1] = *(state->getData())->getColor(2,1);
      charbuffer[2] = *(state->getData())->getColor(2,2);
      charbuffer[3] = *(state->getData())->getColor(2,3);
      charbuffer[4] = *(state->getData())->getColor(2,4);
      charbuffer[5] = *(state->getData())->getColor(2,5);
      charbuffer[6] = *(state->getData())->getColor(2,6);
      charbuffer[7] = *(state->getData())->getColor(2,7);
      charbuffer[8] = *(state->getData())->getColor(2,8);
      //
      (state->getData())->setColor(2, 6, &charbuffer[0]);
      (state->getData())->setColor(2, 3, &charbuffer[1]);
      (state->getData())->setColor(2, 0, &charbuffer[2]);
      (state->getData())->setColor(2, 7, &charbuffer[3]);
      (state->getData())->setColor(2, 4, &charbuffer[4]);
      (state->getData())->setColor(2, 1, &charbuffer[5]);
      (state->getData())->setColor(2, 8, &charbuffer[6]);
      (state->getData())->setColor(2, 5, &charbuffer[7]);
      (state->getData())->setColor(2, 2, &charbuffer[8]);
      
      return(state);
};



//LONGITUDINAL MOVEMENTS

Node* ProblemRules::R12(Node* state)
{
      //     x x x
      //   x x x x
      // > > > x x
      // ^ . v x
      // < < <
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(2,0);
      charbuffer[1] = *(state->getData())->getColor(2,3);
      charbuffer[2] = *(state->getData())->getColor(2,6);
      charbuffer[3] = *(state->getData())->getColor(4,2);
      charbuffer[4] = *(state->getData())->getColor(4,1);
      charbuffer[5] = *(state->getData())->getColor(4,0);
      charbuffer[6] = *(state->getData())->getColor(1,8);
      charbuffer[7] = *(state->getData())->getColor(1,5);
      charbuffer[8] = *(state->getData())->getColor(1,2);
      charbuffer[9] = *(state->getData())->getColor(3,6);
      charbuffer[10]= *(state->getData())->getColor(3,7);
      charbuffer[11]= *(state->getData())->getColor(3,8);
      //Put these colors in the new order
      (state->getData())->setColor(4, 2, &charbuffer[0]);
      (state->getData())->setColor(4, 1, &charbuffer[1]);
      (state->getData())->setColor(4, 0, &charbuffer[2]);
      (state->getData())->setColor(1, 8, &charbuffer[3]);
      (state->getData())->setColor(1, 5, &charbuffer[4]);
      (state->getData())->setColor(1, 2, &charbuffer[5]);
      (state->getData())->setColor(3, 6, &charbuffer[6]);
      (state->getData())->setColor(3, 7, &charbuffer[7]);
      (state->getData())->setColor(3, 8, &charbuffer[8]);
      (state->getData())->setColor(2, 0, &charbuffer[9]);
      (state->getData())->setColor(2, 3, &charbuffer[10]);
      (state->getData())->setColor(2, 6, &charbuffer[11]);
      //Rotate right face clockwise
      charbuffer[0] = *(state->getData())->getColor(0,0);
      charbuffer[1] = *(state->getData())->getColor(0,1);
      charbuffer[2] = *(state->getData())->getColor(0,2);
      charbuffer[3] = *(state->getData())->getColor(0,3);
      charbuffer[4] = *(state->getData())->getColor(0,4);
      charbuffer[5] = *(state->getData())->getColor(0,5);
      charbuffer[6] = *(state->getData())->getColor(0,6);
      charbuffer[7] = *(state->getData())->getColor(0,7);
      charbuffer[8] = *(state->getData())->getColor(0,8);
      //
      (state->getData())->setColor(0, 2, &charbuffer[0]);
      (state->getData())->setColor(0, 5, &charbuffer[1]);
      (state->getData())->setColor(0, 8, &charbuffer[2]);
      (state->getData())->setColor(0, 1, &charbuffer[3]);
      (state->getData())->setColor(0, 4, &charbuffer[4]);
      (state->getData())->setColor(0, 7, &charbuffer[5]);
      (state->getData())->setColor(0, 0, &charbuffer[6]);
      (state->getData())->setColor(0, 3, &charbuffer[7]);
      (state->getData())->setColor(0, 6, &charbuffer[8]);
      return(state);
};



Node* ProblemRules::R13(Node* state)
{
      //     x x x
      //   x x x x
      // < < < x x
      // v . ^ x
      // > > >
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(2,0);
      charbuffer[1] = *(state->getData())->getColor(2,3);
      charbuffer[2] = *(state->getData())->getColor(2,6);
      charbuffer[3] = *(state->getData())->getColor(4,2);
      charbuffer[4] = *(state->getData())->getColor(4,1);
      charbuffer[5] = *(state->getData())->getColor(4,0);
      charbuffer[6] = *(state->getData())->getColor(1,8);
      charbuffer[7] = *(state->getData())->getColor(1,5);
      charbuffer[8] = *(state->getData())->getColor(1,2);
      charbuffer[9] = *(state->getData())->getColor(3,6);
      charbuffer[10]= *(state->getData())->getColor(3,7);
      charbuffer[11]= *(state->getData())->getColor(3,8);
      //Put these colors in the new order
      (state->getData())->setColor(3, 6, &charbuffer[0]);
      (state->getData())->setColor(3, 7, &charbuffer[1]);
      (state->getData())->setColor(3, 8, &charbuffer[2]);
      (state->getData())->setColor(2, 0, &charbuffer[3]);
      (state->getData())->setColor(2, 3, &charbuffer[4]);
      (state->getData())->setColor(2, 6, &charbuffer[5]);
      (state->getData())->setColor(4, 2, &charbuffer[6]);
      (state->getData())->setColor(4, 1, &charbuffer[7]);
      (state->getData())->setColor(4, 0, &charbuffer[8]);
      (state->getData())->setColor(1, 8, &charbuffer[9]);
      (state->getData())->setColor(1, 5, &charbuffer[10]);
      (state->getData())->setColor(1, 2, &charbuffer[11]);
      //Rotate right face counter-clockwise
      charbuffer[0] = *(state->getData())->getColor(0,0);
      charbuffer[1] = *(state->getData())->getColor(0,1);
      charbuffer[2] = *(state->getData())->getColor(0,2);
      charbuffer[3] = *(state->getData())->getColor(0,3);
      charbuffer[4] = *(state->getData())->getColor(0,4);
      charbuffer[5] = *(state->getData())->getColor(0,5);
      charbuffer[6] = *(state->getData())->getColor(0,6);
      charbuffer[7] = *(state->getData())->getColor(0,7);
      charbuffer[8] = *(state->getData())->getColor(0,8);
      //
      (state->getData())->setColor(0, 6, &charbuffer[0]);
      (state->getData())->setColor(0, 3, &charbuffer[1]);
      (state->getData())->setColor(0, 0, &charbuffer[2]);
      (state->getData())->setColor(0, 7, &charbuffer[3]);
      (state->getData())->setColor(0, 4, &charbuffer[4]);
      (state->getData())->setColor(0, 1, &charbuffer[5]);
      (state->getData())->setColor(0, 8, &charbuffer[6]);
      (state->getData())->setColor(0, 5, &charbuffer[7]);
      (state->getData())->setColor(0, 2, &charbuffer[8]);
      return(state);
};


Node* ProblemRules::R14(Node* state)
{
      //     x x x
      //   > > > x
      // x x x v x
      // x x x v
      // x x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(2,1);
      charbuffer[1] = *(state->getData())->getColor(2,4);
      charbuffer[2] = *(state->getData())->getColor(2,7);
      charbuffer[3] = *(state->getData())->getColor(4,5);
      charbuffer[4] = *(state->getData())->getColor(4,4);
      charbuffer[5] = *(state->getData())->getColor(4,3);
      charbuffer[6] = *(state->getData())->getColor(1,7);
      charbuffer[7] = *(state->getData())->getColor(1,4);
      charbuffer[8] = *(state->getData())->getColor(1,1);
      charbuffer[9] = *(state->getData())->getColor(3,3);
      charbuffer[10]= *(state->getData())->getColor(3,4);
      charbuffer[11]= *(state->getData())->getColor(3,5);
      //Put these colors in the new order
      (state->getData())->setColor(4, 5, &charbuffer[0]);
      (state->getData())->setColor(4, 4, &charbuffer[1]);
      (state->getData())->setColor(4, 3, &charbuffer[2]);
      (state->getData())->setColor(1, 7, &charbuffer[3]);
      (state->getData())->setColor(1, 4, &charbuffer[4]);
      (state->getData())->setColor(1, 1, &charbuffer[5]);
      (state->getData())->setColor(3, 3, &charbuffer[6]);
      (state->getData())->setColor(3, 4, &charbuffer[7]);
      (state->getData())->setColor(3, 5, &charbuffer[8]);
      (state->getData())->setColor(2, 1, &charbuffer[9]);
      (state->getData())->setColor(2, 4, &charbuffer[10]);
      (state->getData())->setColor(2, 7, &charbuffer[11]);

      return(state);
};



Node* ProblemRules::R15(Node* state)
{
      //     x x x
      //   < < < x
      // x x x ^ x
      // x x x ^
      // x x x
      
      char charbuffer[12];
      
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(2,1);
      charbuffer[1] = *(state->getData())->getColor(2,4);
      charbuffer[2] = *(state->getData())->getColor(2,7);
      charbuffer[3] = *(state->getData())->getColor(4,5);
      charbuffer[4] = *(state->getData())->getColor(4,4);
      charbuffer[5] = *(state->getData())->getColor(4,3);
      charbuffer[6] = *(state->getData())->getColor(1,7);
      charbuffer[7] = *(state->getData())->getColor(1,4);
      charbuffer[8] = *(state->getData())->getColor(1,1);
      charbuffer[9] = *(state->getData())->getColor(3,3);
      charbuffer[10]= *(state->getData())->getColor(3,4);
      charbuffer[11]= *(state->getData())->getColor(3,5);
      //Put these colors in the new order
      (state->getData())->setColor(3, 3, &charbuffer[0]);
      (state->getData())->setColor(3, 4, &charbuffer[1]);
      (state->getData())->setColor(3, 5, &charbuffer[2]);
      (state->getData())->setColor(2, 1, &charbuffer[3]);
      (state->getData())->setColor(2, 4, &charbuffer[4]);
      (state->getData())->setColor(2, 7, &charbuffer[5]);
      (state->getData())->setColor(4, 5, &charbuffer[6]);
      (state->getData())->setColor(4, 4, &charbuffer[7]);
      (state->getData())->setColor(4, 3, &charbuffer[8]);
      (state->getData())->setColor(1, 7, &charbuffer[9]);
      (state->getData())->setColor(1, 4, &charbuffer[10]);
      (state->getData())->setColor(1, 1, &charbuffer[11]);

      return(state);
};


Node* ProblemRules::R16(Node* state)
{
      //     > > >
      //   x x x v
      // x x x x v
      // x x x x
      // x x x
      
      char charbuffer[12];
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(2,2);
      charbuffer[1] = *(state->getData())->getColor(2,5);
      charbuffer[2] = *(state->getData())->getColor(2,8);
      charbuffer[3] = *(state->getData())->getColor(4,8);
      charbuffer[4] = *(state->getData())->getColor(4,7);
      charbuffer[5] = *(state->getData())->getColor(4,6);
      charbuffer[6] = *(state->getData())->getColor(1,6);
      charbuffer[7] = *(state->getData())->getColor(1,3);
      charbuffer[8] = *(state->getData())->getColor(1,0);
      charbuffer[9] = *(state->getData())->getColor(3,0);
      charbuffer[10]= *(state->getData())->getColor(3,1);
      charbuffer[11]= *(state->getData())->getColor(3,2);
      //Put these colors in the new order
      (state->getData())->setColor(4, 8, &charbuffer[0]);
      (state->getData())->setColor(4, 7, &charbuffer[1]);
      (state->getData())->setColor(4, 6, &charbuffer[2]);
      (state->getData())->setColor(1, 6, &charbuffer[3]);
      (state->getData())->setColor(1, 3, &charbuffer[4]);
      (state->getData())->setColor(1, 0, &charbuffer[5]);
      (state->getData())->setColor(3, 0, &charbuffer[6]);
      (state->getData())->setColor(3, 1, &charbuffer[7]);
      (state->getData())->setColor(3, 2, &charbuffer[8]);
      (state->getData())->setColor(2, 2, &charbuffer[9]);
      (state->getData())->setColor(2, 5, &charbuffer[10]);
      (state->getData())->setColor(2, 8, &charbuffer[11]);
      //Rotating back plane
      charbuffer[0] = *(state->getData())->getColor(5,0);
      charbuffer[1] = *(state->getData())->getColor(5,1);
      charbuffer[2] = *(state->getData())->getColor(5,2);
      charbuffer[3] = *(state->getData())->getColor(5,3);
      charbuffer[4] = *(state->getData())->getColor(5,4);
      charbuffer[5] = *(state->getData())->getColor(5,5);
      charbuffer[6] = *(state->getData())->getColor(5,6);
      charbuffer[7] = *(state->getData())->getColor(5,7);
      charbuffer[8] = *(state->getData())->getColor(5,8);
      //
      (state->getData())->setColor(5, 6, &charbuffer[0]);
      (state->getData())->setColor(5, 3, &charbuffer[1]);
      (state->getData())->setColor(5, 0, &charbuffer[2]);
      (state->getData())->setColor(5, 7, &charbuffer[3]);
      (state->getData())->setColor(5, 4, &charbuffer[4]);
      (state->getData())->setColor(5, 1, &charbuffer[5]);
      (state->getData())->setColor(5, 8, &charbuffer[6]);
      (state->getData())->setColor(5, 5, &charbuffer[7]);
      (state->getData())->setColor(5, 2, &charbuffer[8]);
      return(state);
};


Node* ProblemRules::R17(Node* state)
{
      //     < < <
      //   x x x ^
      // x x x x ^
      // x x x x
      // x x x
      
      char charbuffer[12];
      //Get curent color values
      charbuffer[0] = *(state->getData())->getColor(2,2);
      charbuffer[1] = *(state->getData())->getColor(2,5);
      charbuffer[2] = *(state->getData())->getColor(2,8);
      charbuffer[3] = *(state->getData())->getColor(4,8);
      charbuffer[4] = *(state->getData())->getColor(4,7);
      charbuffer[5] = *(state->getData())->getColor(4,6);
      charbuffer[6] = *(state->getData())->getColor(1,6);
      charbuffer[7] = *(state->getData())->getColor(1,3);
      charbuffer[8] = *(state->getData())->getColor(1,0);
      charbuffer[9] = *(state->getData())->getColor(3,0);
      charbuffer[10]= *(state->getData())->getColor(3,1);
      charbuffer[11]= *(state->getData())->getColor(3,2);
      //Put these colors in the new order
      (state->getData())->setColor(3, 0, &charbuffer[0]);
      (state->getData())->setColor(3, 1, &charbuffer[1]);
      (state->getData())->setColor(3, 2, &charbuffer[2]);
      (state->getData())->setColor(2, 2, &charbuffer[3]);
      (state->getData())->setColor(2, 5, &charbuffer[4]);
      (state->getData())->setColor(2, 8, &charbuffer[5]);
      (state->getData())->setColor(4, 8, &charbuffer[6]);
      (state->getData())->setColor(4, 7, &charbuffer[7]);
      (state->getData())->setColor(4, 6, &charbuffer[8]);
      (state->getData())->setColor(1, 6, &charbuffer[9]);
      (state->getData())->setColor(1, 3, &charbuffer[10]);
      (state->getData())->setColor(1, 0, &charbuffer[11]);
      //Rotating back plane
      charbuffer[0] = *(state->getData())->getColor(5,0);
      charbuffer[1] = *(state->getData())->getColor(5,1);
      charbuffer[2] = *(state->getData())->getColor(5,2);
      charbuffer[3] = *(state->getData())->getColor(5,3);
      charbuffer[4] = *(state->getData())->getColor(5,4);
      charbuffer[5] = *(state->getData())->getColor(5,5);
      charbuffer[6] = *(state->getData())->getColor(5,6);
      charbuffer[7] = *(state->getData())->getColor(5,7);
      charbuffer[8] = *(state->getData())->getColor(5,8);
      //
      (state->getData())->setColor(5, 2, &charbuffer[0]);
      (state->getData())->setColor(5, 5, &charbuffer[1]);
      (state->getData())->setColor(5, 8, &charbuffer[2]);
      (state->getData())->setColor(5, 1, &charbuffer[3]);
      (state->getData())->setColor(5, 4, &charbuffer[4]);
      (state->getData())->setColor(5, 7, &charbuffer[5]);
      (state->getData())->setColor(5, 0, &charbuffer[6]);
      (state->getData())->setColor(5, 3, &charbuffer[7]);
      (state->getData())->setColor(5, 6, &charbuffer[8]);
      return(state);
};

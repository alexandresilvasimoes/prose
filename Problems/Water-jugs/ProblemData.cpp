
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     First version: August, 2006.
     Last update: September, 2012.

   ========================================================================= */

#include <stdio.h>     //used in printf
#include <stdlib.h>    //used in itoa()
#include "Search.h"
#include "Main.h"

ProblemData::ProblemData(int a, int b)
{
     jar1 = a;
     jar2 = b;
};

ProblemData::ProblemData(void){
     jar1 = 0;
     jar2 = 0;
};

int ProblemData::getJar1()
{
     return(jar1);
};

int ProblemData::getJar2()
{
     return(jar2);
};

void ProblemData::setJar1(int j)
{
     jar1 = j;
};

void ProblemData::setJar2(int j)
{
     jar2 = j;
};

char* ProblemData::print()
{
     char* buffer; 
     buffer = (char*) malloc (sizeof(char[20]));
     sprintf(buffer, "<%d,%d>", jar1, jar2);
     return(buffer);
     //Original code was:
     //printf("<%d,%d>",jar1,jar2);
};
              
              
int ProblemData::isGoal(ProblemData* pdptr)
{
     if ((pdptr->getJar1()==2) || (pdptr->getJar2()==2)) return(1); else return(0);
    
};

int ProblemData::cost(void)
{
     return(0);  
};


int ProblemData::heuristic(void)
{
   return(0);
};    

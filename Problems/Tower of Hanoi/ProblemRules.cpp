
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */

#include <stdio.h>     //used to define NULL
#include "Search.h"
#include "Main.h"


typedef Node* (ProblemRules::*ptrProblemRulesMethod)(Node*);

ProblemRules::ProblemRules (void) 
{
   setRulesNumber(6);
};


ptrProblemRulesMethod ProblemRules::getRule(int rule)
{
    ptrProblemRulesMethod p[getRulesNumber()];
    p[0]=&ProblemRules::R0;
    p[1]=&ProblemRules::R1;
    p[2]=&ProblemRules::R2;
    p[3]=&ProblemRules::R3;
    p[4]=&ProblemRules::R4;
    p[5]=&ProblemRules::R5;
    return(p[rule]);
};


Node* ChangePin(int pin_origin, int pin_dest, Node* father)
{
     int disk_size;
     int fp1, fp2;
     
     fp1 = (father->getData())->returnFirstofPin(pin_origin);
     //printErrorMessage(fp1);
     fp2 = (father->getData())->returnFirstofPin(pin_dest);
     
     //Check basic conditions
     if (fp1 == 0) return(NULL);  //There is no disk in origin
     if ((fp1 > fp2) && (fp2>0)) return(NULL);  //A disk cant go above a smaller disk
     
     disk_size = (father->getData())->removeFirstofPin(pin_origin);   
     (father->getData())->insertFirstofPin(pin_dest, disk_size);
     
     return(father);
};


Node* ProblemRules::R0(Node* father)   //Transfer first disk from pin 0 to 1
{
   return(ChangePin(0,1, father));
};


Node* ProblemRules::R1(Node * father)   //Transfer first disk from pin 0 to 2
{
   return(ChangePin(0,2, father));
};


Node* ProblemRules::R2(Node * father)   //Transfer first disk from pin 1 to 0
{
   return(ChangePin(1,0, father));
};


Node* ProblemRules::R3(Node * father)   //Transfer first disk from pin 1 to 2
{   
   return(ChangePin(1,2, father));
};


Node* ProblemRules::R4(Node * father)   //Transfer first disk from pin 2 to 0
{
   return(ChangePin(2,0, father));
};


Node* ProblemRules::R5(Node * father)   //Transfer first disk from pin 2 to 1
{
   return(ChangePin(2,1, father));
};



void ProblemRules::setRulesNumber (int number)
{
     rules_number = number;    
};

int ProblemRules::getRulesNumber (void)
{
    return(rules_number);
};

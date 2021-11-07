
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     First version: August, 2006.
     Last update: September, 2012.

   ========================================================================= */

#include <stdio.h>     //used to define NULL
#include "Search.h"


typedef Node* (ProblemRules::*ptrProblemRulesMethod)(Node*);

ProblemRules::ProblemRules (void) 
{
   setRulesNumber(8);
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
    p[6]=&ProblemRules::R6;
    p[7]=&ProblemRules::R7;
    return(p[rule]);
};


Node* ProblemRules::R0(Node* father)   //Fill jar 1
{
     //printf ("no recebido: "); father->print(); printf("\n");
     (father->getData())->setJar1(4);
     return(father);
};


Node* ProblemRules::R1(Node * father)   //Fill jar 2
{
     (father->getData())->setJar2(3);
     return(father);
};


Node* ProblemRules::R2(Node * father)   //Empty jar 1
{
     (father->getData())->setJar1(0);
     return(father);
};


Node* ProblemRules::R3(Node * father)   //Empty jar 2
{   
     (father->getData())->setJar2(0);
     return(father);
};


Node* ProblemRules::R4(Node * father)   //Complete jar 2 with jar 1
{
     int max_water_to_transfer;    //Stores the amount of watter than can be transfered
     int water_in_jar1;            //4L jug
     int water_in_jar2;            //3L jug
          
     water_in_jar1 = (father->getData())->getJar1();
     water_in_jar2 = (father->getData())->getJar2();
     
     if ((water_in_jar2<3) && (water_in_jar1>0)){
        //Jar2 is not full and there is water in Jar1.
        //It is possible to transfer some water.
        max_water_to_transfer = 3 - water_in_jar2;
        if (water_in_jar1 >= max_water_to_transfer) {
           //Only a part of the amount of water in jar1 will be transfered
           (father->getData())->setJar2(3);
           (father->getData())->setJar1(water_in_jar1-max_water_to_transfer);
           } else {
             //Jar1 will be fully transfered to jar2
             (father->getData())->setJar2(water_in_jar2+water_in_jar1);
             (father->getData())->setJar1(0);
           }
     }
     return(father);
};


Node* ProblemRules::R5(Node * father)   //Complete jar1 with jar2
{
     int max_water_to_transfer;    //Stores the amount of watter than can be transfered
     int water_in_jar1;
     int water_in_jar2;
     
     water_in_jar1 = (father->getData())->getJar1();
     water_in_jar2 = (father->getData())->getJar2();
     
     if ((water_in_jar1<4) && (water_in_jar2>0)){
        //Jar1 is not full and there is water in Jar2.
        //It is possible to transfer some water.
        max_water_to_transfer = 4 - water_in_jar1;
        if (water_in_jar2 >= max_water_to_transfer) {
           //Only a part of the amount of water in jar2 will be transfered
           (father->getData())->setJar1(4);
           (father->getData())->setJar2(water_in_jar2-max_water_to_transfer);
           } else {
             //Jar2 will be fully transfered to jar1
             (father->getData())->setJar1(water_in_jar1+water_in_jar2);
             (father->getData())->setJar2(0);
           }
     }
     return(father);
};




Node* ProblemRules::R6(Node * father)   //Dump jar2 into jar1
{
     int max_water_to_transfer;    //Stores the amount of watter than can be transfered
     int water_in_jar1;
     int water_in_jar2;
          
     water_in_jar1 = (father->getData())->getJar1();
     water_in_jar2 = (father->getData())->getJar2();
     
     if ( (water_in_jar1 + water_in_jar2) <=4) {
        (father->getData())->setJar1(water_in_jar1+water_in_jar2);
     } else {
        (father->getData())->setJar1(4);
     }
     (father->getData())->setJar2(0);
     return(father);
};


Node* ProblemRules::R7(Node * father)   //Dump jar1 into jar2
{
     int max_water_to_transfer;    //Stores the amount of watter than can be transfered
     int water_in_jar1;
     int water_in_jar2;
          
     water_in_jar1 = (father->getData())->getJar1();
     water_in_jar2 = (father->getData())->getJar2();
     
     if ( (water_in_jar1 + water_in_jar2) <=3)
     {
        (father->getData())->setJar2(water_in_jar1+water_in_jar2);
     } else {
        (father->getData())->setJar2(3);
     }
     (father->getData())->setJar1(0);
     return(father);
};


void ProblemRules::setRulesNumber (int number)
{
     rules_number = number;    
};

int ProblemRules::getRulesNumber (void)
{
    return(rules_number);
};

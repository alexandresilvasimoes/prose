
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */

#include <stdio.h>     //used to define NULL
#include <string.h>    //used to memcpy
#include "Search.h"
#include "Main.h"      //used by printNodeBox and printFatherBox


int Node::getDepth(void)
{
      return(depth);
};

void Node::setDepth(int newdepth)
{
     depth = newdepth;
};

float Node::getf(void)
{
      return(f);
};

float Node::getg(void)
{
      return(g);
};

float Node::geth(void)
{
      return(h);      
};

void Node::setf(float newf)
{
     f = newf;     
};

void Node::setg(float newg)
{
     g = newg;     
};

void Node::seth(float newh)
{
     h = newh;     
};

Node::Node(ProblemData *dptr) {
   problemdata = dptr;
   next = NULL;
   father = NULL;
};



void Node::setRule(int a)
{
     rule = a;
};


int Node::getRule(void)
{
     return(rule);    
};

ProblemData* Node::getData()
{
     return (problemdata);
};

Node* Node::getNext()
{
     return(next);
};

void Node::setNext(Node *n)
{
     next = n;
};

void Node::setData(ProblemData *dptr)
{
     memcpy (problemdata, dptr, sizeof(ProblemData) ); 
};



void Node::setPrevious(Node *n)
{
     previous = n;
};


Node* Node::getPrevious(void)
{
     return(previous);
};


char* Node::print()
{
    return(problemdata->print());
};


int Node::isGoal(void)
{
    if (father == NULL) return(0); else return(problemdata->isGoal(getData()));
};


Node* Node::getFather(void)
{
     return(father);
};


void Node::setFather(Node* node)
{
     father = node;
};


void Node::printNode(void)
{
     printNodeBox(problemdata->print());
     if (getFather()==NULL) {
        printFatherBox("-");
        } else {
        printFatherBox((getFather())->problemdata->print());
     }
};     

void Node::printGoal(void)
{
     printGoalBox(problemdata->print());
};     








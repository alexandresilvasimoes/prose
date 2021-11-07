
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
#include <stdlib.h>    //used to malloc()
#include <string.h>    //used by memcmp()
#include "Search.h"
#include "Main.h"      //used by printListBox()


List::List() {
   start = NULL;
   end = NULL;    
   numberofremovednodes = 0;                     
};


int List::isEmpty()
{
    if (start==NULL) 
       return (1); 
    else return(0);
};


int List::getNumberofNodes(void)
{
     return(numberofnodes);   
};


void List::setNumberofNodes(int num)
{
     numberofnodes = num;     
};

int List::getNumberofRemovedNodes(void)
{
     return(numberofremovednodes);   
};


void List::setNumberofRemovedNodes(int num)
{
     numberofremovednodes = num;     
};

void List::insertinOrder(Node* newnode)
{
     // Used by algorithms based on Best First Search
     // nodes must have cost value
     
     Node* n(NULL);
     Node* tmpnode(NULL);
     int inserted = 0;
     
     n=getStart();
     if (n==NULL) {
        //This is the first node of the list
        setStart(newnode);
        newnode->setPrevious(NULL);
        newnode->setNext(NULL);
        setEnd(newnode);
     } else {
        while ((n!=NULL) && (inserted==0)) {
            if ((n->getf()) > (newnode->getf())) {
               //node must be inserted before this node
               tmpnode = (n->getPrevious());
               if (tmpnode!=NULL) tmpnode->setNext(newnode);  //This can be he second node in queue
               n->setPrevious(newnode);
               newnode->setNext(n);
               newnode->setPrevious(tmpnode);
               tmpnode=getStart();
               if (tmpnode==n) setStart(newnode);
               if (tmpnode==n) setStart(newnode);
               inserted = 1;
            } else {
               n = n->getNext();
            }
        }
        if (inserted ==0) {  //The queue finished, and the newnode must be inserted in the last position
           n = getEnd();
           n->setNext(newnode);
           newnode->setPrevious(n);
           newnode->setNext(NULL);
           setEnd(newnode);
        }
     }
   setNumberofNodes(getNumberofNodes()+1);
   printinBox();
};



void List::insert(Node* newnode)
{
   Node* n(NULL);   //The last node in stack
   
   n = getEnd();
   if (n==NULL) {
      //This is the first node of the stack
      setStart(newnode);
      newnode->setPrevious(NULL);
   } else {
      //The new node will be placed in the end of the stack
      n->setNext(newnode);
      newnode->setPrevious(n);
   }
   setEnd(newnode);
   newnode->setNext(NULL);
   setNumberofNodes(getNumberofNodes()+1);
   printinBox();
};



Node* List::remove(Node*)
{
    //This method will be different in each type of list
};



Node* List::getStart(void)
{
     return(start);
};

Node* List::getEnd(void)
{
     return(end);
};

void List::setEnd(Node* n)
{
     end = n;     
};

void List::setStart(Node *n)
{
     start = n;   
};

void List::print()
{
     //This method will be different in each type of list
};

void List::clearList()
{
   start = NULL;
   end = NULL;     
   numberofnodes=0; 
   printinBox();
   numberofremovednodes = 0;
};


Node* List::getNext(Node* n)
{
    return(n->getNext());
};


Node* List::getPrevious(Node* n)
{
    return(n->getPrevious());
};


int List::isEqual(Node* n1, Node* n2)
{
      //Compare the memory of the ProblemData structures of both nodes
      int i;
      ProblemData * ptr1;
      ProblemData * ptr2;
      ptr1 = n1->getData();
      ptr2 = n2->getData();
      i = memcmp (ptr1, ptr2, sizeof(ProblemData));
      if (i== 0) return(1); else return(0);
};

int List::isIn(Node* n)
{
    Node* pointer;
    pointer = start;
    while (pointer!=NULL) {
          if (isEqual(pointer, n)) {
             //n->print(); printf(" already in list.\n");
             return(1);
          }
          pointer = getNext(pointer);
    }
    return(0);
};

void List::printinBox(void)
{
//      This method will be different in each type of list
};

void List::printOrder(void)
{
//      This method will be different in each type of list
};


void List::setID(int a)
{
     ID = a;
};

int List::getID(void)
{
    return(ID);
};

Node* List::copyNode(Node* org)
{
      Node* dest;
      dest = (Node*) malloc(sizeof(Node));
      memcpy(dest, org, sizeof(Node));
      return(dest);
};


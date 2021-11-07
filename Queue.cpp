
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */
   
   
#include <cstdlib>   //Used in system("PAUSE");
#include <stdio.h>   //Necessary to declare the NULL pointer
#include <string.h>  //used by strcat() and strcpy()
#include "Search.h"
#include "Main.h"    //used by printListBox()


Node* Queue::remove(void)
{
   Node* n1(NULL);   //The node to be removed (first in queue)
   Node* n2(NULL);   //The sucessor of n1
   
   n1 = getStart();
   if (n1==NULL) {
      printErrorMessage(ERROR_QUEUE_REMOVE);
      exit(-1);
      } else {
         
         n2 = n1->getNext();
         if (n2==NULL) {
            //There is only one node in queue, and it will be removed
            setStart(NULL);
            setEnd(NULL);
         } else {
             //The node to be removed (n1) has a previous node (n2)
             n2->setPrevious(NULL);
             setStart(n2);
         }
         setNumberofNodes(getNumberofNodes()-1);
         if (getID()==1) setNumberofRemovedNodes(getNumberofRemovedNodes()+1);
         printinBox();
         return(n1);
      }
};
       

void Queue::print(void)
{
     Node* n(NULL);
     n = getStart();
     printf("Queue:");
     if (n==NULL) {
        printf("  Empty.");
     } else {
          printf(" <Start> ");
          while(n!=NULL) {
             n->print();
             printf(" ");
             n = n->getNext();
          }
          printf("<End>");
     }
     printf("\n");
};


void Queue::printOrder(void)
{
     char aux[20];
     itoa ((int) getNumberofRemovedNodes(), aux, 10);
     printOrderBox(aux);                      //This is the opening order box  
};


void Queue::printinBox(void)
{

   if (useDisplay()==1) {
      char* buffer;
      char aux[20];
      buffer = (char*) malloc(sizeof(char[MAX_TEXT_WINDOW_SIZE]));
      Node* pointer;
    
      pointer = getStart();
      strcpy(buffer, "");
      if (getID()!=3) strcpy(buffer,"<Queue begin>\r\n");
      if (isEmpty()) {
         strcpy(buffer, "Empty Queue.");
         } else {
              while (pointer!=NULL) {
                    strcat (buffer, "(");
                    //int t;
                    //t = (int) pointer->getf();
                    //printErrorMessage(t);
                    itoa ((int) pointer->getf(), aux, 10);
                    strcat (buffer, aux);
                    strcat (buffer, ")");
                    strcat (buffer, pointer->print());
                    //Only should print rule in sucessors box
                    if (getID()==3) {    
                       strcat (buffer, "(R");
                       itoa ((int) pointer->getRule(), aux, 10);
                       strcat (buffer, aux);
                       strcat (buffer, ")");
                    }
                    if (getID()!=3) strcat(buffer, "\r\n");//other lists are printed vertically 
                    if (getID()==3) strcat(buffer,"  ");   //sucessors list is printed horizontly
                    pointer = getNext(pointer);
              }
         if (getID()!=3) strcat (buffer,"<Queue end>");
      }
      
      if (getID()==1) printListBox(buffer);       //This is the main queue
      if (getID()==2) printVisitedBox(buffer);    //This is the visited nodes
      if (getID()==3) printSucessorsBox(buffer);  //This is the sucessors
      if (getID()==1) {
         itoa ((int) getNumberofRemovedNodes(), aux, 10);
         printOrderBox(aux);                      //This is the opening order box
      }   
      free(buffer);
    }
};





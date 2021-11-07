
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


Node* Stack::remove(void)
{
   Node* n1(NULL);   //The node to be removed (last in stack)
   Node* n2(NULL);   //The node previous to n1
   
   n1 = getEnd();
   if (n1==NULL) {
      printErrorMessage(ERROR_STACK_REMOVE);
      exit(-1);
      } else {
         n2 = n1->getPrevious();
         if (n2==NULL) {
            //There is only one node in stack, and it will be removed
            setStart(NULL);
            setEnd(NULL);
         } else {
             //The node to be removed (n1) has a previous node (n2)
             n2->setNext(NULL);
             setEnd(n2);
         }
         setNumberofNodes(getNumberofNodes()-1);
         if (getID()==1) setNumberofRemovedNodes(getNumberofRemovedNodes()+1);
         printinBox();
         return(n1);
      }
};
       
       

void Stack::print(void)
{
     Node* n(NULL);
     n = getStart();
     printf("Stack:");
     if (n==NULL) {
        printf("  Empty.");
     } else {
          printf("  <Start> ");
          while(n!=NULL) {
             n->print();
             printf(" ");
             n = n->getNext();
          }
          printf("<End>");
     }
     printf("\n");
};


void Stack::printOrder(void)
{
     char aux[20];
     itoa ((int) getNumberofRemovedNodes(), aux, 10);
     printOrderBox(aux);                      //This is the opening order box  
};


void Stack::printinBox(void)
{
  if (useDisplay()==1) {
      char* buffer;
      char aux[20];
      buffer = (char*) malloc(sizeof(char[MAX_TEXT_WINDOW_SIZE]));
      Node* pointer;
    
      pointer = getStart();
      strcpy(buffer,"<Stack begin>\r\n");
      if (isEmpty()) {
         strcpy(buffer, "Empty Stack.");
         } else {
              while (pointer!=NULL) {
                    strcat (buffer, pointer->print());
                    strcat (buffer, "\r\n");
                    pointer = getNext(pointer);
              }
         strcat (buffer,"<Stack end>");
      }
      
      if (getID()==1) printListBox(buffer);       //This is the main stack
      if (getID()==2) printVisitedBox(buffer);    //This is the visited nodes
      if (getID()==3) printSucessorsBox(buffer);  //This is the sucessors
      if (getID()==1) {
         itoa ((int) getNumberofRemovedNodes(), aux, 10);
         printOrderBox(aux);                      //This is the opening order box
      }
      free(buffer);
  }
};


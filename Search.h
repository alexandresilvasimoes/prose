
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */
   
   
const int MAX_RULES = 50;                  //The maximum number of rules to be declared by user
const int MAX_TEXT_WINDOW_SIZE = 100000;   //Maximum size of the texts exported to a text window
const int MAX_TEXT_SIZE = 5000;            //Maximul size of a text line

#include "ProblemData.h"
#include "Node.h"
#include "List.h"
#include "Queue.h"
#include "Stack.h"
#include "ProblemRules.h"



class Search {
      private:
         typedef Node* (ProblemRules::*ptrProblemRulesMethod)(Node*);
         ProblemRules pr;
         int rulesnumber;
         ptrProblemRulesMethod p[MAX_RULES];
         Queue queue;         //Main search queue
         Stack stack;         //Main search stack
         Queue visited;       //Visited nodes search queue
         Queue sucessors;     //Sucessors of a node
         Stack fathers;        //Will sotore the tracked nodes
         
         public:
         Search(void);
         void startNewSearch(void);
         int getQueueSize(void);
         int getStackSize(void);
         int getVisitedSize(void);
         int getNodeSize(void);
         void expandNode(Node*);
         void trackFathers(Node*);
         void trackRules(Node*);
         void breadthFirst(Node *);           //The breadth frist search algorithm
         void depthFirst(Node *);             //The depth first search algorithm
         void astar(Node *);
};

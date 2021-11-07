
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */
   

#include <windows.h>   //Used by IDNO (ID of the NO button)
#include <stdlib.h>    //Used by malloc and exit functions
#include <string.h>    //used by strcat() and strcpy()
#include <stdio.h>     //Used by printf
#include "Search.h"
#include "Main.h"      //Used by printRouteBox() printDepthBox()


int Search::getVisitedSize(void)
{
    return(visited.getNumberofNodes());
};


int Search::getQueueSize(void)
{
    return(queue.getNumberofNodes());
};

int Search::getStackSize(void)
{
    return(stack.getNumberofNodes());
};


int Search::getNodeSize(void) {
    return(sizeof(ProblemData));    
}


Search::Search (void)
{
    startNewSearch();
    //First of all, observe the number of rules defined by user
    rulesnumber = pr.getRulesNumber();
    if (rulesnumber>MAX_RULES){
       //printf("ERROR: Too many rules. Increase MAX_RULES in <Search.h>. Exiting...\n");
       printErrorMessage(ERROR_RULES);
       //system("PAUSE");
       exit(-1);
    }
    //Load the pointers tho these rules
    for (int rule=0; rule<=rulesnumber-1; rule++) {
        p[rule]=pr.getRule(rule);
    }
             
};



void Search::trackFathers(Node * solution)
{
    
     fathers.setID(4);     //Just an ID for the fathers queue
     char* buffer1;        //Will store the text data to be sent do visual boxes
     buffer1 = (char*) malloc(sizeof(char[MAX_TEXT_WINDOW_SIZE]));
     char* buffer2;
     buffer2 = (char*) malloc(sizeof(char[MAX_TEXT_WINDOW_SIZE]));
     char aux[20];         //Will store chrs in itoa() conversion
     int number_nodes = 0; //will store the number of fathers readed
     ProblemData* pdptr;   //Used to start a new node
     Node* newnodeptr;     //Used to start a new node
     Node * pointer;
     pointer = solution;
     
    
     //Insert solution in stack, its father and so on...
     while (pointer!=NULL) {             //while the node has father
           pdptr = new ProblemData();   //Create new node
           newnodeptr = new Node(pdptr);          // ...
           if (!newnodeptr) {
              printErrorMessage(ERROR_MEMORY);
              //printf("Can't allocate memory. Exiting.\n");
              //system("PAUSE");
              exit(-1);
           }
           newnodeptr->setData(pointer->getData());     //And copy the pointer to it
           newnodeptr->setFather(pointer->getFather()); //...
           newnodeptr->setRule(pointer->getRule());
           fathers.insert(newnodeptr);
           number_nodes = number_nodes+1;
           pointer = newnodeptr->getFather();   
     };
     
     //Generate the string to be sent to Visual Box
     strcpy (buffer1,"");
     itoa (number_nodes-1, aux, 10);
     strcpy(buffer1, aux);
     printDepthBox(buffer1);


     //Need to take nodes in the reverse order.
     //So lets take it from stack
     pointer = fathers.getStart();
     pointer = fathers.remove();
     strcpy(buffer2,"");
     strcat(buffer2, pointer->print());
     strcat(buffer2,"\r\n");
     pointer = fathers.remove();

     //for(int i = 1; i<=4; i++) {
     while (pointer!=NULL) {
           strcat(buffer2," R");
           itoa(pointer->getRule(), aux, 10);
           strcat(buffer2, aux);
           strcat(buffer2, ": ");    
           strcat(buffer2, pointer->print());
           
           if (!fathers.isEmpty()) {
              pointer = fathers.remove(); 
              strcat(buffer2,"\r\n");
           } else {
               pointer = NULL;
               strcat(buffer2, "  <- Goal!");
           }
     };
     printRouteBox(buffer2);
};


void Search::trackRules(Node * n)
{
     Stack fathers;
     
     while (n!=NULL) {
           fathers.insert(n);
           n=n->getFather();
     };
     
     n = fathers.getStart();
     n = fathers.remove();
     while (!fathers.isEmpty()) {
           n = fathers.remove();
           printf(" R%d ", n->getRule()); 
     };
};


int breakpoint1(int a, int b)
{
    if (a==2*b) return(1); else return(0);   
};


int breakpoint2(int a, int b)
{

    if (a==2*b+1) return(1); else return(0);
};


void Search::startNewSearch(void)
{
     queue.clearList();
     stack.clearList();
     visited.clearList();
     sucessors.clearList();

};


void Search::expandNode(Node* father)
{
    sucessors.clearList();                                              //Removes all nodes from the sucessors list
    
    father->printNode();
    
    for (int rule=0; rule<=rulesnumber-1; rule++) {                      //Execute, one by one, all rules
        ProblemData* pdptr = new ProblemData();
        Node* nptr = new Node(pdptr);                                    //Creates the node pointer
        if (!nptr) {
           printErrorMessage(ERROR_MEMORY);
           exit(-1);
        }
        nptr->setData(father->getData());                                //Copy the data from father node
        nptr = ((pr.*p[rule])(nptr));                                    //Execute one rule and returns the new node
        //int a;
        //a = nptr->getRule();
        //printErrorMessage(rule);
        if (nptr!=NULL) {
            //Prepare data to insert node
            nptr->setFather(father);              //Set the father of this node
            nptr->setRule(rule);
            (nptr->seth( (nptr->getData())->heuristic() ));               //Set heuristic h(n) value
            (nptr->setDepth((nptr->getFather())->getDepth() +1));         //Set node depth value
            (nptr->setg( (nptr->getData())->cost() * nptr->getDepth() )); //Set cost g(n) value
            (nptr->setf( (nptr->getg()) + (nptr->geth() ) ));             //Set total cost f(n) = g(n) + h(n)
            //Insert node            
            sucessors.insert(nptr);              //If node is not in sucessors list, add it
        } 
       // else {
       //      printErrorMessage(ERROR_NULL_NODE);
       //      exit(-1);
       // }     
    }
};



void Search::breadthFirst(Node * seed){

    //Queue queue;
    //Queue visited;
    Node* nq;            //Node in the main search queue
    Node* ns;            //Node in the sucessors queue
    Node* solution;      //The goal node
    char* aux;
    int inputs=-1;       //Number of analised nodes
    long order = 0;
    
    queue.setID(1);      //Defines that queue prints goes to window ListBox
    visited.setID(2);    //Defines that visited prints goes to window VisitedBox
    sucessors.setID(3);  //Defines that sucessors prints goes to window SucessorBox
    startNewSearch();    //Clear lists
    queue.insert(seed);  //Insert the start node in queue

    //int a;

    while (!queue.isEmpty()) {
          printRouteBox("");  //Clear RouteBox
          printGoalBox("");   //Clear GoalBox
          printDepthBox("");  //Clear DepthBox
          
          inputs = inputs +1;
          nq = queue.remove();                      //Get the first node in queue
          if (useVisit()) visited.insert(nq);       //Insert in the visited queue
          nq->print();    
          //-----
          //a = (nq->getData())->heuristic();
          //itoa (a, aux, 10);
          //printNodeValueBox(aux);
          // -------
                                         
          if (nq->isGoal()) {                                    //Check if this node is the goal
             trackFathers(nq);
             nq->printGoal();
             nq->printNode();
             queue.printOrder();
             sucessors.clearList();
             if (search_mode == SM_CONTINOUS) {
                int a;
                a = printGoalMessage();
                if (a==IDNO) return;
                }
             if ((search_mode==SM_BREAKPOINT)&&(breakpoint1(state_machine, inputs))){
                  state_machine = state_machine+2;
                  break;
             }   
          } else {
                 visited.printinBox();
               
               expandNode(nq);        //Update sucessors list with nq sucessors
               if ((search_mode==SM_BREAKPOINT)&&(breakpoint1(state_machine, inputs))){
                  state_machine = state_machine+1;
                  break;
               }
               visited.printinBox();
                
               while (!sucessors.isEmpty()) {        
                                     
                     ns = sucessors.remove();                         //Check a sucessor
                     visited.printinBox();
                     
                     if (!queue.isIn(ns)) {
                        if (useVisit()==0) queue.insert(ns);     //If the sucessor is not in queue or visited, insert it
                        else if(!visited.isIn(ns)) queue.insert(ns);     //If the sucessor is not in queue or visited, insert it   
                     };
                     ns = sucessors.getNext(ns);                      //Take next sucessor
               }
               if ((search_mode==SM_BREAKPOINT)&&(breakpoint2(state_machine, inputs))) {
                  state_machine = state_machine+1;
                  break;
               }
          }
    }
    if (search_mode!=SM_BREAKPOINT) printEndMessage();
}; 






void Search::depthFirst(Node * seed){
     

     Node * nst;          //A node in stack
     Node * nsc;          //A node in sucessor
     Node * solution;     //A goal node

     stack.setID(1);      //Defines that stack prints will be sent to window ListBox
     visited.setID(2);    //Defines that visited prints will be sent to window VisitedBox
     sucessors.setID(3);  //Defines that sucessors prints will be sent to window SucessorBox
     
     int inputs = -1;

     startNewSearch();
     
     stack.insert(seed);
     
     while(!stack.isEmpty()) {
     
          printRouteBox("");
          printGoalBox("");
          printDepthBox("");
          
          inputs = inputs +1;
          nst = stack.remove();
          if (useVisit()) visited.insert(nst);
          nst->print();

          if (nst->isGoal()) {
             trackFathers(nst);
             nst->printGoal();
             nst->printNode();
             stack.printOrder();
             sucessors.clearList();
                 if (search_mode == SM_CONTINOUS) {
                    int a;
                    a = printGoalMessage();
                    if (a==IDNO) return;
                    }
                 
                 if ((search_mode==SM_BREAKPOINT)&&(breakpoint1(state_machine, inputs))){
                     state_machine = state_machine+2;
                     break;
                 }   
          } else {
               expandNode(nst);
               if ((search_mode==SM_BREAKPOINT)&&(breakpoint1(state_machine, inputs))){
                  state_machine = state_machine+1;
                  break;
               }
               while (!sucessors.isEmpty()) {                         
                     nsc = sucessors.remove();                         //Check a sucessor
                     if (!stack.isIn(nsc)){
                        if (!useVisit()) stack.insert(nsc);                             //If the sucessor is not in queue or visited, insert it
                        else {
                            if (!visited.isIn(nsc)) stack.insert(nsc);    
                        }
                     };
                     nsc = sucessors.getNext(nsc);                      //Take next sucessor
               }
               if ((search_mode==SM_BREAKPOINT)&&(breakpoint2(state_machine, inputs))) {
                  state_machine = state_machine+1;
                  break;
               }
          }
   }
    if (search_mode!=SM_BREAKPOINT) printEndMessage();
}; 

void Search::astar(Node* seed){
     
     
     Node * nst;          //A node in queue
     Node * nsc;          //A node in sucessor
     Node * solution;     //A goal node

     queue.setID(1);      //Defines that queue prints will be sent to window ListBox
     visited.setID(2);    //Defines that visited prints will be sent to window VisitedBox
     sucessors.setID(3);  //Defines that sucessors prints will be sent to window SucessorBox

     char aux [20];       //Temporarily stores string that will be sent to a text box
     int inputs = -1;

     startNewSearch();

     seed->setDepth(0);
     queue.insert(seed);
     
     itoa( (seed->getData())->heuristic(), aux, 10);
     printStartValueBox(aux);
     
     seed->setf((seed->getData())->heuristic());
     
     while(!queue.isEmpty()) {
     
          //Clear list boxes
          printRouteBox("");
          printGoalBox("");
          printDepthBox("");
          
          //Choose next node to evaluate
          inputs = inputs +1;
          nst = queue.remove();
          if (useVisit()) visited.insert(nst);
          nst->print();
          itoa( (int) nst->getf(), aux, 10);
          printNodeValueBox(aux);

          //Check for goal node
          if (nst->isGoal()) {
             trackFathers(nst);
             nst->printGoal();
             nst->printNode();
             queue.printOrder();
             sucessors.clearList();
                 if (search_mode == SM_CONTINOUS) {
                    int a;
                    a = printGoalMessage();
                    if (a==IDNO) return;
                    }
                 
                 if ((search_mode==SM_BREAKPOINT)&&(breakpoint1(state_machine, inputs))){
                     state_machine = state_machine+2;
                     break;
                 }   
          } else {
               expandNode(nst);
               if ((search_mode==SM_BREAKPOINT)&&(breakpoint1(state_machine, inputs))){
                  state_machine = state_machine+1;
                  break;
               }
               while (!sucessors.isEmpty()) {                         
                     nsc = sucessors.remove();                         //Check a sucessor
                     if (!queue.isIn(nsc)){
                        if (!useVisit()) queue.insertinOrder(nsc);     //If the sucessor is not in queue or visited, insert it
                        else {
                            if (!visited.isIn(nsc)) queue.insertinOrder(nsc);    
                        }
                     };
                     nsc = sucessors.getNext(nsc);                      //Take next sucessor
               }
               if ((search_mode==SM_BREAKPOINT)&&(breakpoint2(state_machine, inputs))) {
                  state_machine = state_machine+1;
                  break;
               }
          }
   }
    if (search_mode!=SM_BREAKPOINT) printEndMessage();
}; 



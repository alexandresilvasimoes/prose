
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */


class Node {
      private:
         Node* next;                  //Stores the next node in the list
         Node* previous;              //Stores the previous node in the list
         Node* father;                //Stores the node whos expantion generate current node
         int rule;                    //Stores the rule whos application over the father node generated current node
         ProblemData* problemdata;    //Stores the data of the problem, defined by user
         float f;                     //Stores the node cost
         float g;                     //Stores the effective path coast from start node to current node
         float h;                     //Stores the estimated path coast from node to solution
         int depth;                   //Stores node depth
      public:
         float getf(void);
         void setf(float);
         float getg(void);
         void setg(float);
         float geth(void);
         void seth(float);
         void setDepth(int);
         int getDepth(void);
         Node(ProblemData*);          //Constructor
         ProblemData* getData(void);  //Returns the ProblemData of the node
         void setData(ProblemData*);  //Sets the ProblemData of the node
         Node* getNext(void);         //Returns the next node in the list
         void setNext(Node*);         //Sets the next node in the list
         Node* getPrevious(void);     //Returns the previous node in the list
         void setPrevious(Node*);     //Sets the previous node in the list
         Node* getFather(void);
         void setFather(Node*);
         void setRule(int);
         int getRule(void);
         int isGoal(void);            //Return 1 if the node is a goal
         char* print(void);           //Prints the node
         void printNode(void);
         void printGoal(void);
};

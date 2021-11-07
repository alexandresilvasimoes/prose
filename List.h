
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */

class List {
      protected:
         Node *start;                   //Stores the start node of the list
         Node *end;                     //Stores the end node of the list
         int numberofnodes;             //Stores the number of nodes in list
         int ID;                        //Many lists can be created simultaneously. Here one can assign an id to this list.
         int numberofremovednodes;     //Number of nodes already removed from this list
      public:
         List(void);                    //Constructor
         int isEmpty();                 //Retorns 1 if the list is empty
         int getNumberofNodes(void);    //Returns the number of nodes in list
         int getNumberofRemovedNodes(void);    //Returns the number of nodes already removed from list
         void setNumberofNodes(int);    //Set the number of nodes currently in list
         void setNumberofRemovedNodes(int);    //Set the number of nodes already removed from list
         void insert(Node*);            //Inserts a node in list
         void insertinOrder(Node*);     //Insert a node in a position based on its cost
         virtual Node *remove(Node*);   //Remove a node from the list
         Node *getStart(void);          //Returns the start node of the list
         Node *getEnd(void);            //Returns the end node of the list
         void setStart(Node*);          //Sets the start node of the queue
         void setEnd(Node*);            //Sets the end node of the queue
         Node *getNext(Node*);          //Returns the next node in list
         Node *getPrevious(Node*);      //Returns the previous node in list
         void clearList();              //Remove all nodes from list
         int isEqual(Node*, Node*);     //Returns 1 if both nodes have the same data
         int isIn(Node *);              //Check if a node is in list
         void setID(int);               //Allows identification of each created list 
         int getID(void);               //Return the list ID
         Node* copyNode(Node*);         //Copy a node to a new memory postion
         virtual void print();          //Prints the whole list
         virtual void printinBox(void); //Send the whole list to a ListBox
         virtual void printOrder(void); //Print number of opened nodes in OrderBox
};

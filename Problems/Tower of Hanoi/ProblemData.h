
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */

const int NUM_DISKS = 5;

class ProblemData {
      private:
         int numdiscs;             //Stores the amount of disks in the problem
         int pin[3][NUM_DISKS];    //Stores the disks presents in the three pins
                                   // in the form pin[0] = {3,2,1,0,0,0,...}, etc.
      public:
         //Setting and Getting variables
         int returnFirstofPin(int);      //Returns the first disk of a pin
         int removeFirstofPin(int);      //Returns the first disc present in a pin
         int insertFirstofPin(int, int); //Set the first disc present in a pin
         int getPinPosition(int, int);   //Return the size of a disk in a pin
         int getNumberofDisks(int);      //Returns the number of disks in pin x
         int heuristic(void);            //Returns the estimated path coast from node to the goal (DISABLED FOR THIS PROBLEM)
         int cost(void);                 //Retuns the path cost from node to the initial node (DISABLED FOR THIS PROBLEM)
         //Check if a solution is a goal
         int isGoal(ProblemData *); 
         //print a state
         char* print(void);              //How to print the state?
         //Constructors
         ProblemData(int[3], int[3], int[3]);     
         ProblemData(void);        
};

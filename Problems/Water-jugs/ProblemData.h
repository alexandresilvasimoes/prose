
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     First version: August, 2006.
     Last update: September, 2012.

   ========================================================================= */


class ProblemData {
      private:
         int jar1;   //Store the amount of water in jar 1
         int jar2;   //Store the amount of water in jar 2
      public:
         ProblemData(int, int);     //Constructor
         ProblemData(void);         //Constructor
         int getJar1(void);         //Returns the amount of water in jar 1
         int getJar2(void);         //Returns the amount of water in jar 2
         void setJar1(int);         //Sets the amount of water in jar 1
         void setJar2(int);         //Sets the amount of water in jar 2
         int isGoal(ProblemData *); //Check when the node is a goal
         char* print(void);         //How to print the state?
         int heuristic(void);       //Returns the estimated path coast from node to the goal (DISABLED FOR THIS PROBLEM)
         int cost(void);            //Retuns the path cost from node to the initial node (DISABLED FOR THIS PROBLEM)
};

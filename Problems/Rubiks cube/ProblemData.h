
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */


class ProblemData {
      private:
         char cube[6][9];                    //Store the state currently under evaluation
         //char init_cube[6][9];               //Store initial state
      public:
         char* getState(void);               //Returns current state
         void  setState(char*);              //Set current state
         char* getColor(int, int);           //Returns the color of the cube(face, position)
         void setColor(int, int, char*);     //Set the color of the cube(face, position, color)
         int isGoal(ProblemData *);          //Returns 1 when the node is a goal
         int heuristic(void);                //Returns the estimated path coast from node to the goal
         int cost(void);                     //Retuns the path cost from node to the initial node
         char* print(void);                  //How to print the state?
         ProblemData(char*);                 //Constructor
         ProblemData();                      //Constructor without initialization
};

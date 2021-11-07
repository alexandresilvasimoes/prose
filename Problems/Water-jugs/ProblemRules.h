
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     First version: August, 2006.
     Last update: September, 2012.

   ========================================================================= */

class ProblemRules
{
      private:
         typedef Node* (*ptrMethodType)(Node*);
         typedef Node* (ProblemRules::*ptrProblemRulesMethod)(Node*);
         int rules_number;                    //Stores the number of rules. Must be setted by user.
      public:
         ProblemRules(void);                  //Constructor
         void setRulesNumber (int);           //Set the number of rules (must be setted by user)
         int getRulesNumber (void);           //Return the number of rules
         ptrProblemRulesMethod getRule(int);  //Returns the pointer to one method (rule of the problem)
         Node* R0(Node*);                     //Rule 0: Fill jar 1
         Node* R1(Node*);                     //Rule 1: Fill jar 2
         Node* R2(Node*);                     //Rule 2: Empty jar 1
         Node* R3(Node*);                     //Rule 3: Empty jar 2
         Node* R4(Node*);                     //Rule 4: Complete jar 2 with jar 1
         Node* R5(Node*);                     //Rule 5: Compete jar 1 with jar 2
         Node* R6(Node*);                     //Rule 6: Dump jar 2 into jar 1
         Node* R7(Node*);                     //Rule 7: Dump jar 1 into jar 2
};

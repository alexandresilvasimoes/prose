
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
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
         Node* R0(Node*);                     //Rule 0: Put first of pin0 in pin1
         Node* R1(Node*);                     //Rule 1: Put first of pin0 in pin2
         Node* R2(Node*);                     //Rule 2: Put first of pin1 in pin0
         Node* R3(Node*);                     //Rule 3: Put first of pin1 in pin2
         Node* R4(Node*);                     //Rule 4: Put first of pin2 in pin0
         Node* R5(Node*);                     //Rule 5: Put first of pin2 in pin1
};

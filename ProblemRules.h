
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
         int rules_number;                     //Stores the number of rules. Must be setted by user.
      public:
         ProblemRules(void);                   //Constructor
         void setRulesNumber (int);            //Set the number of rules (must be setted by user)
         int getRulesNumber (void);            //Return the number of rules
         ptrProblemRulesMethod getRule(int);   //Returns the pointer to one method (rule of the problem)
         Node* R0 (Node*);                     //Rule 0 : move frontal superior cells horizontally to right
         Node* R1 (Node*);                     //Rule 1 : move frontal superior cells horizontally to left
         Node* R2 (Node*);                     //Rule 2 : move frontal central cells horizontally to right
         Node* R3 (Node*);                     //Rule 3 : move frontal central cells horizontally to left
         Node* R4 (Node*);                     //Rule 4 : move frontal bellow cells horizontally to right
         Node* R5 (Node*);                     //Rule 5 : move frontal bellow cells horizontally to left
         Node* R6 (Node*);                     //Rule 6 : move frontal left cells vertically up
         Node* R7 (Node*);                     //Rule 7 : move frontal left cells vertically down
         Node* R8 (Node*);                     //Rule 8 : move frontal central cells vertically up
         Node* R9 (Node*);                     //Rule 9 : move frontal central cells vertically down
         Node* R10(Node*);                     //Rule 10: move frontal right cells vertically up
         Node* R11(Node*);                     //Rule 11: move frontal right cells vertically down
         Node* R12(Node*);                     //Rule 12: move back cells in the first level clockwise
         Node* R13(Node*);                     //Rule 13: move back cells in the first level anticlockwise
         Node* R14(Node*);                     //Rule 14: move back cells in the second level clockwise
         Node* R15(Node*);                     //Rule 15: move back cells in the second level anticlockwise
         Node* R16(Node*);                     //Rule 16: move back cells in the third level clockwise
         Node* R17(Node*);                     //Rule 17: move back cells in the third level anticlockwise
};

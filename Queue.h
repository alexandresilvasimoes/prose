
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */


class Queue : public List
{
    private:
    public:
       virtual Node *remove(void);
       virtual void print(void);
       virtual void printinBox(void);
       virtual void printOrder(void);
};

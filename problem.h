
/* =========================================================================

     Alexandre da Silva Simoes
     <assimoes@sorocaba.unesp.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This class implements the user node to be used with search algorithms
     Based on RUSSELL and NORVIG - Artificial Intelligence: Modern Approach
     All knowledge should be free. Use this freely.
     Last update: august, 2006.

   ========================================================================= */
   
   
#include<stdio.h>

//Structure of the node ---------------------------
class node{
      private:
        int jar1;
        int jar2;
      public:
        void node::print_node (node node);
};


//How shoud the node be printed? ------------------
void node::print_node () {
     printf("<%d %d>", jar1, jar2);
};


//Goal --------------------------------------------
int node::goal () {
    if ((jar1 == 2)||(jar2==2))
       return(1);
       else return(0);
};
    
//Rules -------------------------------------------

//R1: Fill jar 1
//R2: Fill jar 2
//R3: Empty jar 1
//R4: Empty jar 2
//R5: Complete jar 1 with jar 2
//R6: Complete jar 2 with jar 1
//R7: Dump jar 1 in jar 2
//R8: Dump jar 2 in jar 1

node node::R1() {
    jar1=4;
    return(mynode);
};

node R2(node mynode) {
     mynode.jar2 = 3;
     return(mynode);
};

node R3(node mynode) {
     mynode.jar1=0;
     return(mynode);
};

node R4(node mynode) {
     mynode.jar2=0;
     return(mynode);
};

node R5(node mynode) {
     int support; //How many watter does jar 1 supports to receive?
     if ((mynode.jar1<4) && (mynode.jar2>0)) {
        support = 4-mynode.jar1;
        if (mynode.jar2<=support) {
           mynode.jar1=mynode.jar1+mynode.jar2;
           mynode.jar2=0;
        } else {
           mynode.jar1 = 4;
           mynode.jar2 = mynode.jar2-support;
           }
     }
     return(mynode);
};

node R6(node mynode) {
     int support; //How many watter does jar 2 supports to receive?
     if ((mynode.jar2<3) && (mynode.jar1>0)) {
        support = 3-mynode.jar2;
        if (mynode.jar1<=support) {
           mynode.jar2=mynode.jar2+mynode.jar1;
           mynode.jar1=0;
        } else {
           mynode.jar2 = 3;
           mynode.jar1 = mynode.jar1-support;
           }
     }
     return(mynode);
};

node R7(node mynode) {
     mynode.jar1 = mynode.jar1 + mynode.jar2;
     mynode.jar2 = 0;
     if (mynode.jar1 > 4) mynode.jar1=4;
     return(mynode);
};

node R8(node mynode) {
     mynode.jar2 = mynode.jar2 + mynode.jar1;
     mynode.jar1 = 0;
     if (mynode.jar2 > 3) mynode.jar2 = 3;
     return(mynode);
};

void initialize_rules (void) {
    node (*funcptr1)(node);
    node (*funcptr2)(node);
    node (*funcptr3)(node);
    node (*funcptr4)(node);
    node (*funcptr5)(node);
    node (*funcptr6)(node);
    node (*funcptr7)(node);
    funcptr1 = R1;

};


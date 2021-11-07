
/* =========================================================================

     Alexandre da Silva Simoes and Esther Luna Colombini
     <assimoes@sorocaba.unesp.br> <esther@ita.br>
     http://www.sorocaba.unesp.br/professor/assimoes
     This code is part of ProSE - Problem Search Environment
     Software under GNU General Public License V.3
     Last update: September, 2012.

   ========================================================================= */


#include <windows.h>
#include <stdio.h>     //used to input-output facilities like printf and NULL
#include "Main.h"
#include "Search.h"    

// ---------------------------------
// Problems initialization
// ---------------------------------

ProblemData state;
ProblemRules pr;
Node n(&state);

// Vars ---------------------------------

char  auxchar[20];
char* auxcharptr;
int state_machine = 0;
int search_mode = 0;
int visit_mode = 0;
int visual_mode = 1;
Search search;

// Handles -------------------------------

HWND hwnd;               /* This is the handle for our window */
HDC hdc;
RECT r;
LPSTR szMessage = "";
PAINTSTRUCT ps;
HWND hStartNodeBox;
HWND hRulesBox;
HWND hVisitedBox;
HWND hListBox;
HWND hNodeBox;
HWND hFatherBox;
HWND hOrderBox;
HWND hSucessorsBox;
HWND hDepthBox;
HWND hGoalBox;
HWND hRouteBox;
HWND hButton1;
HWND hButton2;
HWND hButton3;
HWND hButton4;
HWND hButton5;
HWND hGroupBox1;
HWND hGroupBox2;
HWND hGroupBox3;
HWND hGroupBox4;
HWND hAlgorithmBox;
HWND hCheckBox;
HWND hCheckBox2;
HWND hStartValueBox;
HWND hNodeValueBox;
    

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM); /*  Declare Windows procedure  */

char szClassName[ ] = "WindowsApp"; /*  Make the class name into a global variable  */


void AppendTextToEditCtrl(HWND hWndEdit, LPCTSTR pszText)
{
   int nLength = GetWindowTextLength(hWndEdit); 
   SendMessage(hWndEdit, EM_SETSEL, (WPARAM)nLength, (LPARAM)nLength);
   SendMessage(hWndEdit,EM_REPLACESEL, (WPARAM)FALSE, (LPARAM)pszText);
}



int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nFunsterStil)
{
    
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    wincl.hInstance = hThisInstance;                   /* The Window structure */
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;               /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                          /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);    /* Use default icon and mouse-pointer */
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                         /* No menu */
    wincl.cbClsExtra = 0;                              /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                              /* structure or the window instance */
    wincl.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);  
    
    if (!RegisterClassEx (&wincl)) return 0;/* Register the window class, and if it fails quit the program */
        
    hwnd = CreateWindowEx (     /* The class is registered, let's create the program*/
           1,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "ProSE - Problem Search Environment",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           900,                 /* The programs width */
           720,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
    
    ShowWindow (hwnd, nFunsterStil); /* Make the window visible on the screen */
    
    while (GetMessage (&messages, NULL, 0, 0))  /* Run the message loop. It will run until GetMessage() returns 0 */
    {
        TranslateMessage(&messages);            /* Translate virtual-key messages into character messages */
        DispatchMessage(&messages);             /* Send message to WindowProcedure */
    }
    return messages.wParam;    /* The program return-value is 0 - The value that PostQuitMessage() gave */
}




            
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)  /*  This function is called by the Windows function DispatchMessage()  */
{
    const char *ComboBoxItems[] = { "Depth First Search", "Breadeth First Search", "A* Search"};
    int value;
    
    RECT problembox;
    problembox.top = 10;
    problembox.left = 20;
             
    RECT searchbox;
    searchbox.top = 310;
    searchbox.left = 20;

    RECT currentbox;
    currentbox.top = 125;
    currentbox.left = 20;

    RECT goalbox;
    goalbox.top = 310;
    goalbox.left = 487;
             
    RECT buttonbox;
    buttonbox.top = 610;
    buttonbox.left = 515;
             
    RECT algorithmbox;
    algorithmbox.top = 10;
    algorithmbox.left = 327;
    
    switch (message)         /* handle the messages */
    {
        case WM_COMMAND:
             switch(LOWORD(wParam))
             {
                  case CHK_VISUAL:
                       if (visual_mode == 0) visual_mode=1; else visual_mode=0;
                  break;
                  case BTN_INFO_VISIT:
                       value = SendMessage(hAlgorithmBox, CB_GETCURSEL, 0, 0 ) ;
                       if (value != CB_ERR) {
                          char buffer[50];
                          int mem_size;
                          strcpy(buffer, "Nodes in List: ");
                          mem_size = search.getVisitedSize();
                          itoa (mem_size, auxchar, 10);
                          strcat(buffer, auxchar);
                          strcat(buffer,"\nNode size: ");
                          itoa(search.getNodeSize(), auxchar, 10);
                          strcat(buffer, auxchar);
                          strcat(buffer, ".\nTotal memory size: ");
                          itoa(mem_size*search.getNodeSize(), auxchar, 10);
                          strcat(buffer, auxchar);
                          strcat(buffer, " bytes.");
                          MessageBox(hwnd, buffer, "Visited List Information", MB_OK | MB_ICONINFORMATION);
                       }
                  break;
                  case BTN_INFO_LIST:
                       value = SendMessage(hAlgorithmBox, CB_GETCURSEL, 0, 0 ) ;
                       if (value != CB_ERR) {
                          char buffer[50];
                          int mem_size;
                          strcpy(buffer, "Nodes in memory: ");
                          if (value == 0) mem_size = search.getStackSize();
                          if (value == 1) mem_size = search.getQueueSize();
                          if (value == 2) mem_size = search.getQueueSize();
                          itoa (mem_size, auxchar, 10);
                          strcat(buffer, auxchar);
                          strcat(buffer,"\nNode size: ");
                          itoa(search.getNodeSize(), auxchar, 10);
                          strcat(buffer, auxchar);
                          strcat(buffer, ".\nTotal memory size: ");
                          itoa(mem_size*search.getNodeSize(), auxchar, 10);
                          strcat(buffer, auxchar);
                          strcat(buffer, " bytes.");
                          MessageBox(hwnd, buffer, "Main List Information", MB_OK | MB_ICONINFORMATION);
                       }
                  break;
                  case CHK_VISITED:
                       if (visit_mode==0) {
                          visit_mode = 1; 
                          SendMessage(hVisitedBox, WM_ENABLE , TRUE, 0);
                          SendMessage(hButton5, WM_ENABLE , TRUE, 0);
                       }
                       else {
                          visit_mode = 0;
                          SendMessage(hVisitedBox, WM_ENABLE , FALSE, 0);
                          SendMessage(hButton5, WM_ENABLE , FALSE, 0);
                       }
                  break;
                  case BTN_STEP:
                       search_mode = SM_BREAKPOINT;
                       value = SendMessage(hAlgorithmBox, CB_GETCURSEL, 0, 0 ) ;
                       if (value != CB_ERR) {
                          if (value == 0) search.depthFirst(&n);
                          if (value == 1) search.breadthFirst(&n);
                          if (value == 2) search.astar(&n);
                       }
                  break;
                  case BTN_EXIT:
                       exit(0);
                  break;
                  case BTN_RUN:
                       state_machine = 0;
                       search_mode = SM_CONTINOUS;     
                       value = SendMessage(hAlgorithmBox, CB_GETCURSEL, 0, 0 ) ;
                       if (value != CB_ERR) {
                          if (value == 0) search.depthFirst(&n);
                          if (value == 1) search.breadthFirst(&n);
                          if (value == 2) search.astar(&n);
                       }
                  break;
             }     
             break;
        case WM_CREATE:

             //Combo Box
             hAlgorithmBox = CreateWindowEx(WS_EX_CLIENTEDGE, "COMBOBOX", "" , WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL , algorithmbox.left+80, algorithmbox.top+60, 230, 200, hwnd, (HMENU)COMBO_ALG ,  GetModuleHandle(NULL), NULL);
             SendMessage(hAlgorithmBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR) ComboBoxItems[0]));
             SendMessage(hAlgorithmBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR) ComboBoxItems[1]));
             SendMessage(hAlgorithmBox, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR) ComboBoxItems[2]));

             //Text boxes
             hStartNodeBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , problembox.left+80,  problembox.top+30, 758, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hRulesBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , problembox.left+235,  problembox.top+60, 50, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hStartValueBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , problembox.left+80,  problembox.top+60, 90, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hVisitedBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL | ES_AUTOHSCROLL , problembox.left,  searchbox.top+33+25, 187, 285, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hListBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL | ES_AUTOHSCROLL , problembox.left+212,  searchbox.top+33+25, 187, 285, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hNodeBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , currentbox.left+80,  currentbox.top+30, 758, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hNodeValueBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , currentbox.left+80,  currentbox.top+60, 90, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hFatherBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , currentbox.left+410,  currentbox.top+60, 428, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hOrderBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , currentbox.left+240,  currentbox.top+60, 100, 30, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hSucessorsBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",  WS_CHILD | WS_VISIBLE | ES_MULTILINE  | WS_VSCROLL, currentbox.left+80,  currentbox.top+90, 758, 75, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hDepthBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , goalbox.left+220+50,  goalbox.top+30, 100, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hGoalBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL , goalbox.left+50,  goalbox.top+30, 150, 25, hwnd, NULL, GetModuleHandle(NULL), NULL);
             hRouteBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL | ES_AUTOHSCROLL | ES_AUTOVSCROLL , goalbox.left+50,  goalbox.top+60, 320, 180, hwnd, NULL, GetModuleHandle(NULL), NULL);


             //CheckBox
             hCheckBox = CreateWindowEx(WS_EX_TRANSPARENT, "BUTTON", "", BS_AUTOCHECKBOX | WS_CHILD | WS_VISIBLE , searchbox.left+100,  searchbox.top+30, 20, 25, hwnd, (HMENU) CHK_VISITED, GetModuleHandle(NULL), NULL);
             SendMessage(hVisitedBox, WM_ENABLE , FALSE, 0);
             hCheckBox2 = CreateWindowEx(WS_EX_TRANSPARENT, "BUTTON", "", BS_AUTOCHECKBOX | WS_CHILD | WS_VISIBLE , problembox.left+824,  problembox.top+62, 20, 25, hwnd, (HMENU) CHK_VISUAL, GetModuleHandle(NULL), NULL);
             
             //Buttons
             //WS_DISABLED
             hButton1 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "Step", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, buttonbox.left, buttonbox.top, 100, 40, hwnd, (HMENU)BTN_STEP, NULL, NULL);
             hButton2 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "Run",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON , buttonbox.left+110, buttonbox.top, 100, 40, hwnd, (HMENU)BTN_RUN, NULL, NULL);
             hButton3 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "Exit", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON , buttonbox.left+220, buttonbox.top, 100, 40, hwnd, (HMENU)BTN_EXIT, NULL, NULL);
             hButton4 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "Info", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON , searchbox.left+339, searchbox.top+30, 60, 25, hwnd, (HMENU)BTN_INFO_LIST, NULL, NULL);
             hButton5 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "Info",  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON , searchbox.left+127, searchbox.top+30, 60, 25, hwnd, (HMENU)BTN_INFO_VISIT, NULL, NULL);
             //SendMessage(hButton5, , TRUE, 0);

             //Group Boxs
             hGroupBox1 = CreateWindowEx(WS_EX_TRANSPARENT, "BUTTON", "Problem definition:",  WS_EX_TRANSPARENT | WS_CHILD | WS_VISIBLE | BS_GROUPBOX, problembox.left-10, problembox.top, 870, 100, hwnd, NULL, NULL, NULL);    
             hGroupBox2 = CreateWindowEx(WS_EX_TRANSPARENT , "BUTTON", "Current node:",  WS_EX_TRANSPARENT | WS_CHILD | WS_VISIBLE | BS_GROUPBOX, currentbox.left-10, currentbox.top, 870, 170, hwnd, NULL, NULL, NULL);
             hGroupBox3 = CreateWindowEx(WS_EX_TRANSPARENT , "BUTTON", "Search evaluation:",  WS_EX_TRANSPARENT | WS_CHILD | WS_VISIBLE | BS_GROUPBOX, searchbox.left-10, searchbox.top, 430, 358, hwnd, NULL, NULL, NULL);
             hGroupBox4 = CreateWindowEx(WS_EX_TRANSPARENT , "BUTTON", "Goal information:",  WS_EX_TRANSPARENT | WS_CHILD | WS_VISIBLE | BS_GROUPBOX, goalbox.left-10, goalbox.top, 403, 255, hwnd, NULL, NULL, NULL);
                         
             break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_PAINT:
             HINSTANCE hQueue;       
             
             
             //TEXTS:
             hdc = BeginPaint(hwnd, &ps);
             SetBkColor(hdc, 2);
             SetBkMode(hdc, TRANSPARENT);
             
             //Problem definition box
             TextOut(hdc,problembox.left,problembox.top+33, "Start node:", 11);
             TextOut(hdc,problembox.left,problembox.top+66, "Value:", 6);
             TextOut(hdc,problembox.left+183,problembox.top+66, "Rules:", 6);
             TextOut(hdc,problembox.left+640,problembox.top+66, "Disable Lists Visualization:", 28);
             
             //Search box
             TextOut(hdc,searchbox.left,searchbox.top+33, "Visited nodes:", 14);
             TextOut(hdc,searchbox.left+212,searchbox.top+33, "Nodes list:", 11);

             //Current node box
             TextOut(hdc,currentbox.left,currentbox.top+33, "Node:", 5);
             TextOut(hdc,currentbox.left,currentbox.top+66, "Value:", 6);
             TextOut(hdc,currentbox.left+180,currentbox.top+63, "Opening:", 8);
             TextOut(hdc,currentbox.left+350,currentbox.top+63, "Father:", 7);
             TextOut(hdc,currentbox.left,currentbox.top+106, "Sucessors:", 10);
             
             //Goal
             TextOut(hdc, goalbox.left, goalbox.top+33, "Goal:", 5);
             TextOut(hdc, goalbox.left+220, goalbox.top+33, "Depth:", 6);
             TextOut(hdc, goalbox.left, goalbox.top+66, "Route:", 6);
             
             //Algorithm
             TextOut(hdc, algorithmbox.left, algorithmbox.top+66, "Algorithm:", 10);
             
             EndPath(hdc); 
             //Set the StartNodeBox
             SendMessage(hStartNodeBox, WM_SETTEXT, 0, (LPARAM) state.print());
             //Set the RulesBox
             
             itoa(pr.getRulesNumber(), auxchar, 10);
             SendMessage(hRulesBox, WM_SETTEXT, 0, (LPARAM) auxchar);

             
             break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}


void printListBox(char *n)
{
       SendMessage(hListBox, WM_SETTEXT, 0, (LPARAM) n);
}

void printVisitedBox(char *n)
{
       SendMessage(hVisitedBox, WM_SETTEXT, 0, (LPARAM) n);
}

void printSucessorsBox(char *n)
{
       SendMessage(hSucessorsBox, WM_SETTEXT, 0, (LPARAM) n); 
}

void printNodeBox(char* n)
{
     SendMessage(hNodeBox, WM_SETTEXT, 0, (LPARAM) n);
};

void printNodeValueBox(char* n)
{
     SendMessage(hNodeValueBox, WM_SETTEXT, 0, (LPARAM) n);
};

void printFatherBox(char* n)
{
     SendMessage(hFatherBox, WM_SETTEXT, 0, (LPARAM) n);
};

void printOrderBox(char* n)
{
     SendMessage(hOrderBox, WM_SETTEXT, 0, (LPARAM) n);
};

void printRouteBox(char* n)
{
     SendMessage(hRouteBox, WM_SETTEXT, 0, (LPARAM) n);
};

void printDepthBox(char* n)
{
     SendMessage(hDepthBox, WM_SETTEXT, 0, (LPARAM) n);
};

void printGoalBox(char* n)
{
     SendMessage(hGoalBox, WM_SETTEXT, 0, (LPARAM) n);
};


void printStartValueBox(char* n)
{
     SendMessage(hStartValueBox, WM_SETTEXT, 0, (LPARAM) n);
};


int printGoalMessage(void)
{
     MessageBox(hwnd, "Goal finded. Continue search?", "Search Problem Environment", MB_YESNO | MB_ICONINFORMATION);
};


void printErrorMessage(int error)
{
     char auxchar2[14];
     strcpy(auxchar2,"Error number ");
     itoa(error, auxchar, 10);
     strcat(auxchar2, auxchar);
     MessageBox(hwnd, auxchar2, "Search Problem Environment", MB_OK | MB_ICONINFORMATION);
};


int useVisit(void)
{
    return(visit_mode);    
};


int useDisplay(void)
{
    return(visual_mode);
};

void printEndMessage(void)
{
     
};

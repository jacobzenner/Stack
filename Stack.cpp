/****************************************************************************
*** NAME : Jacob Zenner                                                   ***
*** CLASS : CSc 300                                                       ***
*** ASSIGNMENT : 3                                                        ***
*** DUE DATE : 10/5/2022                                                  ***
*** INSTRUCTOR : GAMRADT                                                  ***
*** DESCRIPTION : This program defines a stack class which has the member *** 
*** functions pop, push, view, and peek                                   ***
****************************************************************************/
#include "Stack.h"
#include <string>
#include <iostream>

using namespace std;

/****************************************************************************
*** FUNCTION Stack                                                        ***
*****************************************************************************
*** DESCRIPTION : This function is the constructor for the class          ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
Stack::Stack() : top(nullptr){}

/****************************************************************************
*** FUNCTION Stack                                                        ***
*****************************************************************************
*** DESCRIPTION : This function is the copy constructor for the class     ***
*** INPUT ARGS  : Stack &                                                 ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
Stack::Stack(Stack & old) : top(nullptr)
{
    Stack temp;
    SElement str;

    while(old.top)
    {
        old.pop(str);
        temp.push(str);
    }
    while(temp.top)
    {
        temp.pop(str);
        old.push(str);
        push(str);
    }
}

/****************************************************************************
*** FUNCTION ~Stack                                                       ***
*****************************************************************************
*** DESCRIPTION : This function is the destructor for the class which     ***
***  deletes every element in the stack                                   ***
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
Stack::~Stack()
{
    SElement temp;

    while(top)
        pop(temp);
}

/****************************************************************************
*** FUNCTION push                                                         ***
*****************************************************************************
*** DESCRIPTION : This function pushes an element onto the stack          ***                                
*** INPUT ARGS  : const SElement str                                      ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Stack::push(const SElement str)
{
    SNodePtr newNode = new SNode;
    if(!new(std::nothrow)SNode)
    {
        cout << "Memory could not be allocated for push function." << endl;
        exit(102);
    }
    else
    {
        newNode->element = str;
        newNode->next = nullptr;

        if(top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
}

/****************************************************************************
*** FUNCTION pop                                                          ***
*****************************************************************************
*** DESCRIPTION : This function removes an element from the stack         ***                                
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : SElement & str                                          ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Stack::pop(SElement & str)
{
    if(top == nullptr)
    {
        cout << "Stack Underflow- No element in the stack to remove" << endl;
    }
    else
    {
        str = top->element;
        delete top;
        top = top->next;
    }
}

/****************************************************************************
*** FUNCTION peek                                                         ***
*****************************************************************************
*** DESCRIPTION : This function returns the top element                   *** 
***               of the stack but does not change the stack              ***                 
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : SElement & str                                          ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Stack::peek(SElement & str)
{
    pop(str);
    push(str);
}

/****************************************************************************
*** FUNCTION view                                                         ***
*****************************************************************************
*** DESCRIPTION : This function displays all the elements in the stack    ***                            
*** INPUT ARGS  : None                                                    ***
*** OUTPUT ARGS : None                                                    ***
*** IN/OUT ARGS : None                                                    ***
*** RETURN      : None                                                    *** 
****************************************************************************/
void Stack::view()
{
    Stack temp;
    SElement str = "";
    temp.top = nullptr;
    
    cout << "TOP -> ";
    
    while(top != nullptr)
    {
        pop(str);
        cout << str << " -> ";
        temp.push(str);
    }
    cout << "BOTTOM" << endl;

    while(temp.top != nullptr)
    {
        temp.pop(str);
        push(str);
    }
}
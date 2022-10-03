/****************************************************************************
*** NAME : Jacob Zenner                                                   ***
*** CLASS : CSc 300                                                       ***
*** ASSIGNMENT : 3                                                        ***
*** DUE DATE : 10/5/2022                                                  ***
*** INSTRUCTOR : GAMRADT                                                  ***
*** DESCRIPTION : This program defines a stack class which has the member *** 
*** functions pop, push, view, and peek                                   ***
****************************************************************************/
#ifndef _STACK_H
#define _STACK_H

#include <string>

typedef std::string SElement;

class Stack{
    public:
        /****************************************************************************
        *** FUNCTION Stack                                                        ***
        *****************************************************************************
        *** DESCRIPTION : This function is the constructor for the class          ***
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        Stack();

        /****************************************************************************
        *** FUNCTION Stack                                                        ***
        *****************************************************************************
        *** DESCRIPTION : This function is the copy constructor for the class     ***
        *** INPUT ARGS  : Stack &                                                 ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        Stack(Stack &);
        
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
        ~Stack();

        /****************************************************************************
        *** FUNCTION push                                                         ***
        *****************************************************************************
        *** DESCRIPTION : This function pushes an element onto the stack          ***                                
        *** INPUT ARGS  : const SElement str                                      ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        void push(const SElement);

        /****************************************************************************
        *** FUNCTION pop                                                          ***
        *****************************************************************************
        *** DESCRIPTION : This function removes an element from the stack         ***                                
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : SElement & str                                          ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        void pop(SElement &);

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
        void peek(SElement &);

        /****************************************************************************
        *** FUNCTION view                                                         ***
        *****************************************************************************
        *** DESCRIPTION : This function displays all the elements in the stack    ***                            
        *** INPUT ARGS  : None                                                    ***
        *** OUTPUT ARGS : None                                                    ***
        *** IN/OUT ARGS : None                                                    ***
        *** RETURN      : None                                                    *** 
        ****************************************************************************/
        void view();

    private:
        struct SNode;
        typedef SNode *SNodePtr;
        struct SNode{
            SElement element;
            SNodePtr next;
        };
        SNodePtr top;
};


#endif

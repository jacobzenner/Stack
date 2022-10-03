/*****************************************************************************
*** NAME : Jacob Zenner                                                    ***
*** CLASS : CSc 300                                                        ***
*** ASSIGNMENT : 3                                                         ***
*** DUE DATE : 10/5/2022                                                   ***
*** INSTRUCTOR : GAMRADT                                                   ***
******************************************************************************
*** DESCRIPTION : This program implements a stack which has the member     ***
*** functions push, pop, peek, and view                                    ***
*****************************************************************************/
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Hello";
    string copy1 = "copy";
    string temp = "";
    Stack myStack;
    myStack.push(str);
    cout << "Pushing string Hello" << endl;
    myStack.push("New String");
    myStack.push("Newer String");
    myStack.view();
    cout << "Popping top from stack" << endl;
    myStack.pop(temp);
    cout << "Viewing stack..." << endl;
    myStack.view();
    
    cout << "----------------------------------" << endl;

    cout << "Creating copy constructor" << endl;
    Stack copy(myStack);
    copy.push(copy1);
    myStack.push(str);
    cout << "Printing stack copy- Copy" << endl;
    copy.view();
    cout << "Printing regular stack - Hello" << endl;
    myStack.view();
    cout << "Popping 2 items off of copy stack which should cause stack underflow" << endl;
    copy.pop(str);
    copy.pop(str);

    cout << "----------------------------------" << endl;
    cout << "Pushing Hello2 to stack" << endl;
    myStack.push("Hello2");
    cout << "Viewing Stack with view function" << endl;
    myStack.view();
    cout << "Peeking from stack" << endl;
    myStack.peek(str);
    cout << "Printing item from stack peek: " << str << endl;
    cout << "Viewing Stack with view function" << endl;
    myStack.view();
    cout << "Popping from stack" << endl;
    myStack.pop(str);
    myStack.pop(str);
    myStack.pop(str);
    myStack.pop(str);
    myStack.pop(str);
    myStack.view();

    return;
}
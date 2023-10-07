#include <iostream>
#include <string.h>

using namespace std;

#define MAX 100


class Stack{

	public:
	int top;
	char string[MAX];

	Stack()
	{
		top = -1;
	}


bool isFull()
{
    if(top >= MAX-1)
        return true;
    else
        return false;
}


bool isEmpty()
{
	 if(top == -1)
	     return true;
	 else
	     return false;
}


void push(int num)
{
    if (isFull())
        cout << "Stack Overflow";
    else
	{
		top++;
        string[top] = num;

    }
}

int pop()
{
    if (isEmpty())
        cout << "Stack Underflow";

    else
	{
     top--;
        return string[top+1];
    }
}
};

int main()
{
    char inStr[100], c;
    int i, length;
    class Stack stack;

    cout << "Enter a string: ";
	cin.getline(inStr,100);

    length = strlen(inStr);

    for(i = 0; i < length; i++)
	{
        stack.push(inStr[i]);
    }

    for(i = 0; i < length; i++)
	{
        if(stack.pop() != inStr[i])
		{
            cout << "Not Palindrome";
            return 0;
        }
    }

    cout << "Palindrome";
    return 0;
}



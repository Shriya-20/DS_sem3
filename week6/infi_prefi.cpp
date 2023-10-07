#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
void Reverse (char *arr)
{   //reverse function for expression

  int size = strlen (arr);
  int j = size, i = 0;
  char temp[size];

  temp[j] = '\0';
  j--;
  while (arr[i] != '\0')
    {
      temp[j] = arr[i];
      j--;
      i++;
    }
    strcpy (arr, temp);
}
//////// STACK /////////
class Stack{
    char arr[30];
    int top;

    public:
    Stack(){
    top=-1;
    }


    bool isempty(){

        if(top<= -1)
            return true;
        else
            return false;
    }

    void push(char ele){
        if(top>= 29)
            cout<<"Stack Overflow";
        else{
            top++;
            arr[top]=ele;
        }


    }



    int peek(){
        if(isempty())
        {   cout<<"Stack underflow";
            return -1;
        }
        else
            return arr[top];
    }

    int pop(){
        if(isempty()){
            cout<<"Stack underflow";
            return -1;

        }


        else{
            char topvalue=arr[top];
            top--;
            //cout<<topvalue<<" is popped\n"<<endl;
            return topvalue;
            }


    }

    void display(){

    for(int i=top;i>=0;i--)
        cout<<arr[i]<<"\n";
    }




};


int main()
{

  	char infix[30], prefix[30];
  	cout<<"Enter a Infix Expression :"<<endl;
  	cin>>infix;
  	Stack s;

	cout<<"INFIX EXPRESSION: "<<infix<<endl;

  	int j=0;


    Reverse(infix);
    //cout<<infix<<"\n";

    ///
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    ///



	for(int i=0;i<strlen(infix);i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			prefix[j]=infix[i];
			j++;

		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.peek()!='(') && (!s.isempty()))
			{
				char temp=s.peek();
				prefix[j]=temp;
				j++;
				s.pop();
			}
			if(s.peek()=='(')
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))
		{
			if(s.isempty())
			{
				s.push(infix[i]);
			}
			else{

                if (precedence(infix[i]) > precedence(s.peek())) {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.peek()))&& (infix[i] == '^')) {
                    while ((precedence(infix[i]) == precedence(s.peek()))&& (infix[i] == '^')) {
                        prefix[j] = s.peek();
                        j++;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.peek())) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.isempty()) && (precedence(infix[i]) < precedence(s.peek()))) {
                        prefix[j] = s.peek();
                        j++;
                        s.pop();
                    }
                    s.push(infix[i]);
            }
        }
    }

    }



	while(!s.isempty())
	{
		prefix[j]=s.peek();
		j++;
		s.pop();
	}

  	cout<<endl<<"PREFIX EXPRESSION: ";

	Reverse(prefix);


	for(int k=0;k<j;k++)
       cout<<prefix[k];
    cout<<" \n ";


	return 0;
}


#include<iostream>
#include <cmath>
#include<string.h>
using namespace std;

class Stack{s
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



int main(){

char postfix[30];
  	cout<<"Enter a Postfix Expression : ";
  	cin>>postfix;
  	Stack s;


	int i;

	for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            s.push(postfix[i]-'0');
        }
        else{

            int op2=s.peek();
            s.pop();
            int op1=s.peek();
            s.pop();

            switch(postfix[i]){

            case '+':
                s.push(op1+op2);
                break;
            case '-':
                s.push(op1-op2);
                break;
            case '*':
                s.push(op1*op2);
                break;
            case '/':
                s.push(op1/op2);
                break;
            case '^':
                s.push(pow(op1,op2));
                break;
            default:
                break;


            }

        }
    }
cout<<"The postfix epxression evaluates to: ";
cout<<s.peek()<<endl;



return 0;
}



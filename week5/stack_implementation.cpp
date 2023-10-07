#include<iostream>
using namespace std;

class Stack{
    int arr[30];
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

    void push(int ele){
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
            int topvalue=arr[top];
            top--;
            cout<<topvalue<<" is popped\n"<<endl;
            return topvalue;
            }


    }

    void display(){

    for(int i=top;i>=0;i--)
        cout<<arr[i]<<"\n";
    }
    cout<<"\n";



};

int main(){

    int ch,ele;
    Stack s;

    do{
    cout<<"\n 0. stop\n 1. push \n 2. pop \n 3.peek \n 4.isempty \n 5.display \nEnter your choice:";

    cin>>ch;

    switch(ch){
    case 0:
        break;
    case 1:
        cout<<"Enter element to push: "<<endl;
        cin>>ele;
        s.push(ele);
        break;
    case 2:
        cout<<s.pop();
        break;
    case 3:
        cout<<s.peek();
        break;
    case 4:
        if(s.isempty())
            cout<<"Stack empty\n";
        else
            cout<<"Stack not empty\n";
        break;
    case 5:
        s.display();
        break;

    default:
        break;
        }

    }while(ch!=0);



return 0;
}

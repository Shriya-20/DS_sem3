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

            return topvalue;
            }


    }

    void display(){

    for(int i=top;i>=0;i--)
        cout<<arr[i]<<"\n";
    }



};

int main(){

    Stack st;
    char s[20];
    int j,count=0;
    bool flag=true;
    cout<<"Enter epression: "<<endl;
    cin>>s;

    for(int j=0;s[j]!='\0';j++)
        count++;


    for(int i=0;i<count;i++){

        if(s[i]=='(')
            st.push(s[i]);
        else
        {
            if(s[i]==')' && (!st.isempty()))
            {   if(st.peek()=='(')
                    st.pop();
                else
                    flag=false;

            }
            else if(s[i]==')' && st.isempty())
                flag=false;

        }
        ////

        if(s[i]=='[')
            st.push(s[i]);
        else
        {
            if(s[i]==']' && (!st.isempty()))
            {   if(st.peek()=='[')
                    st.pop();
                else
                    flag=false;

            }
            else if(s[i]==']' && st.isempty())
                flag=false;

        }
        ////
        if(s[i]=='{')
            st.push(s[i]);
        else
        {
            if(s[i]=='}' && (!st.isempty()))
            {   if(st.peek()=='{')
                    st.pop();
                else
                    flag=false;

            }
            else if(s[i]=='}' && st.isempty())
                flag=false;

        }
    }

    if( st.isempty() && (flag!=false) )
        flag=true;
    else
        flag=false;

    if(flag)
        cout<<"Valid paranthesis expression";
    else
        cout<<"Invalid parathesis expression";


return 0;
}

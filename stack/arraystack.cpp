#include<iostream>
using namespace std;
class stack{
    int top;
    public: 
    int a[100];
    stack(){ top=-1; }
    bool push(int x);
    int pop();
    int peek();
    bool isempty();
};
bool stack::isempty(){
    return top<0;
}
bool stack::push(int x){
    int max=100;
    if(top>max-1){
        cout<<"stack overflow.\n";
        return false;
    }
    a[top++]=x;
    return true;
}
int stack::pop(){
    if(top<0){
        cout<<"stack underflow.\n";
        return -1;
    }
    return a[--top];
}
int stack::peek(){
    if(top<0){
        cout<<"stack underflow.\n";
        return -1;
    }
    int x=a[top];
    return x;
}
bool stack::isempty(){
    return top<0;
}
int precedence(char op){
    if(op=='+'||op=='-'){
        return 1;
    }
    if(op=='*'||op=='/'){
        return 2;
    }
    else return 0;
}
bool isOperator(char ch){
    return ch=='+'||ch=='-'||ch=='/'||ch=='*';
}
string infixtopostfix(const string& infix){
    stack s;
    string posfix;
    for(char ch: infix){
        if(isalnum(ch)){
            posfix+=ch;
        }
        else if(ch=='('){
            s.push(ch);
        }
        else if(ch==')'){
            while(!s.isempty()&&s.peek()!='('){
                posfix+=s.pop();
            }
            s.pop();
        }
        else if(isOperator(ch)){
            while(!s.isempty()&&precedence(s.peek())>=precedence(ch)){
                posfix+=s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.isempty()){
        posfix+=s.pop();
    }
    return posfix;
}
int evaluateposfix(const string& posfix){
    stack s;
    for(char ch: posfix){
        if(isdigit(ch)){
            s.push(ch-'0');
        }
        else{
            int val2=s.peek();s.pop();
            int val1=s.peek();s.pop();
            switch(ch){
                case '+': s.push(val1+val2);break;
                case '*':s.push(val1*val2);break;
                case '-':s.push(val1-val2);break;
                case '/':s.push(val1/val2);break;
                default: cout<<" operand doesnot exist.";break;
            }
        }
    }
    return s.peek();
}
int main(){
    class stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"elements present in the stack: ";
    while(!s.isempty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
    string infix="1+2*(3-4)";
    cout<<"postfix expression: "<<infixtopostfix(infix)<<endl;
    string postfix="123*+9-";
    cout<<"postfix evaluation result: "<<evaluateposfix(postfix)<<endl;
    return 0;
}
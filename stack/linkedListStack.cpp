#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
    Node(int v){
        value=v;
        next=nullptr;
    }
};
class stack{
    Node* head;
    public:
    stack(){this->head=nullptr;}
    bool isempty(){
        return head==nullptr;
    }
    void push(int x){
        Node* newNode=new Node(x);
        if(!newNode){
            cout<<"stack overflow.\n";
        }
        newNode->next=head;
        head=newNode;
    }
    void pop(){
        if(isempty()){
            cout<<"stack underflow.\n";
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    int peek(){
        if(!isempty()){
            return head->value;
        }
        else{
            cout<<"stack is empty.\n";
            return 0;
        }
    }
    void decimaltobinary(int decimal){
       while(decimal>0){
        push(decimal%2);
        decimal/=2;
       }
       while(!isempty()){
        cout<<peek();
        pop();
       }
       cout<<endl;
    }
    bool ispalindrome(string& str){
        for(char ch:str){
            push(ch);
        }
        for(char ch:str){
            if(ch!=peek()){
                return false;
                break;
            }
            else{
                pop();
            }
        }
        return true;
    }
    int evaluatePostfix(const string& postfix){
        for(char ch:postfix){
            if(isdigit(ch)){
                push(ch-'0');
            }
            else{
                int val2=peek();pop();
                int val1=peek();pop();
                switch(ch){
                    case '+':push(val1+val2);break;
                    case '-':push(val1-val2); break; 
                    case '*':push(val1*val2); break; 
                    case '/':push(val1/val2); break;
                    default: cout<<"the operation does not exist.\n";break;
                }
            }
        }
        return peek();
    }
};
int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"the elements of the satck: ";
    while(!st.isempty()){
        cout<<st.peek()<<" ";
        st.pop();
    }
     cout<<endl;
     int x=7;
     cout<<"the binary form of: "<<x<<" is:";st.decimaltobinary(x);
     string postfix = "231*+9-"; 
     cout << "Postfix evaluation result: " <<st.evaluatePostfix(postfix) << endl;
     string s="racecar";
     cout<<"the value of palindrome evaluation of "<<s<<" is: "<<st.ispalindrome(s)<<endl;
    return 0;
}
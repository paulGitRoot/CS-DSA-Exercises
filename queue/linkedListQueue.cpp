#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
    Node(int v){
        value=v;
        next=nullptr;
    }
};
class Queue{
    Node *front, *rear;
public:
    Queue(){front=rear=nullptr;}
    bool isempty(){
        return front==nullptr;
    }
    void enqueue(int x){
        Node* newNode=new Node(x);
        if(this->isempty()){
            front=rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }
    void dequeue(){
        if(this->isempty()){
            cout<<"Queue underflow.\n";
            return;
        }
        Node* temp=front;
        front=front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
    }
    int getfront(){
        if(this->isempty()){
            cout<<"Queue underflow.\n";
            return -1;
        }
        return front->value;
    }
    int getrear(){
        if(this->isempty()){
            cout<<"Queue underflow.\n";
            return -1;
        }
        return rear->value;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Queue Front: " << q.getfront() << endl;
    cout << "Queue Rear: " << q.getrear() << endl;
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front: " << q.getfront() << endl;
    cout << "Queue Rear: " << q.getrear() << endl << endl;
    return 0;
}
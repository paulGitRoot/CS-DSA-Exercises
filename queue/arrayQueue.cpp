#include <iostream>
# include <bits/stdc++.h>
using namespace std;
class Queue{
public:
    vector<int> arr;
    int size;
    int front;
    int capacity;
    Queue(int qsize){
        front=0;
        size=0;
        capacity=qsize;
        arr.resize(qsize);
    }
    void enqueue(int x){
        if(size==capacity){
            cout<<"Queue overflow.\n";
            return;
        }
        arr[size]=x;
        size++;
    }
    void dequeue(){
        if(size==0){
           cout<<"Queue underflow.\n";
            return;
        }
        for(int i=1;i<size;i++){
            arr[i-1]=arr[i];
        }
        size--;
    }
    int getfront(){
        if(size==0){
            cout<<"Queue underflow.\n";
            return -1;
        }
        return arr[front];
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue* q=new Queue(4);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    cout<<"the front element is: "<<q->getfront()<<endl;
    q->display();
    q->dequeue();
    q->enqueue(4);
    q->display();
    return 0;
}
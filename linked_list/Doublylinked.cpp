#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* prev,*next;
    Node(int v){
        value=v;
        prev=next=nullptr;
    }
};
class Doubly{
    public:
    Node* insertfront(Node* head,int newValue);
    Node* insertlast(Node* head,int newValue);
    Node* insertpos(Node* head,int pos,int newValue);
    Node* delhead(Node* head);
    Node* dellast(Node* head);
    Node* delpos(Node* head,int pos);
    void search(Node* head,int x);
    int getsize(Node* head);
    void printlist(Node* head);
    void printback(Node* last);
};
Node* Doubly::insertfront(Node* head,int newValue){
    Node* newNode=new Node(newValue);
    newNode->next=head;
    if(head!=nullptr){
        head->prev=newNode;
        head=newNode;
    }
    return head;
}
Node* Doubly::insertlast(Node* head,int newValue){
    Node* newNode=new Node(newValue);
    if(head==nullptr){
        head=newNode;
    }
    Node* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    newNode->prev=curr;
    curr->next=newNode;
    return head;
}
Node* Doubly::insertpos(Node* head,int pos,int newValue){
    Node* newNode=new Node(newValue);
    if(head==nullptr){
        if(pos!=1){
            cout<<"no such node.";
            delete newNode;
            return NULL;
        }
        head=newNode;
    }
    Node* curr=head;
    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<"no such node.";
    }
    newNode->prev=curr;
    newNode->next=curr->next;
    curr->next=newNode;
    return head;
}
Node* Doubly::delhead(Node* head){
   if(head==nullptr){
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    } 
    delete temp;
    return head;
}
Node* Doubly::dellast(Node* head){
    if(head->next==nullptr){
        delete head;
        return NULL;
    }
   Node* curr=head->next;
   Node* prev=head;
   while(curr->next!=nullptr){
    prev=curr;
    curr=curr->next;
   }
   prev->next=curr->next;
   delete curr;
   return head;
}
Node* Doubly::delpos(Node* head,int pos){
  if(head->next==nullptr){
    delete head;
    return NULL;
  }
  Node* curr=head->next;
  Node* prev=head;
  for(int i=0;i<pos-1;i++){
    prev=curr;
    curr=curr->next;
  }
  prev->next=curr->next;
  delete curr;
  return head;
}
void Doubly::search(Node* head,int x){
    Node* curr=head;
    while(curr->next!=nullptr&&curr->value!=x){
        curr=curr->next;
    }
    if(curr->value==x){
        cout<<"found it: "<<curr->value<<endl;
    }
    else{
        cout<<"node not found."<<endl;
    }
}
int Doubly::getsize(Node*head){
    int count;
    for(Node* curr=head;curr!=nullptr;curr=curr->next){
        count++;
    }
    return count;
}
void Doubly::printback(Node* last){
    Node* curr=last;
    while(curr!=nullptr){
        cout<<curr->value<<" ";
        curr=curr->prev;
    }
    cout<<endl;
}
void Doubly::printlist(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->value<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    Doubly* d=new Doubly();
    Node* head=new Node(2);
    Node* second=new Node(3);
    Node* third=new Node(4);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    cout<<"the original list: ";d->printlist(head);
    cout<<"backward: ";d->printback(third);
    cout<<"number of elements: "<<d->getsize(head)<<endl;
    head=d->insertfront(head,1);
    head=d->insertpos(head,2,1);
    head=d->insertlast(head,5);
    //the next 3 lines are delete operattions
    head=d->delhead(head);
    head=d->dellast(head);
    head=d->delpos(head,3);
    cout<<"the modified list: ";d->printlist(head);
    cout<<"number of elements: "<<d->getsize(head)<<endl;
    cout<<"what element are you looking for: ";
    int x;
    cin>>x;
    d->search(head,x);
    return 0;
}
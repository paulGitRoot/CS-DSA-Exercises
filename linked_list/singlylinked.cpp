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
class single{
    public: 
    Node* insertfront(Node* head,int newValue);
    Node* insertlast(Node* head,int newValue);
    Node* insertpos(Node* head,int pos,int newValue);
    Node* delhead(Node* head);
    Node* dellast(Node* head);
    Node* delpos(Node* head,int pos);
    Node* reverselist(Node* head);
    void search(Node* head,int key);
    int getsize(Node* head);
    void printlist(Node* head);
};
Node* single::insertfront(Node* head,int newValue){
    Node* newNode=new Node(newValue);
    newNode->next=head;
    head=newNode;
    return head;
}
Node* single::insertlast(Node* head,int newValue){
    Node* newNode=new Node(newValue);
    if(head==nullptr){
        head=newNode;
    }
    Node* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=newNode;
    return head;
}
Node* single::insertpos(Node* head,int pos,int newValue){
    Node* newNode=new Node(newValue);
    if(head==nullptr){
        if(pos!=1){
            cout<<"no such node.\n";
            return NULL;
        }
        head=newNode;
    }
    Node* curr=head;
    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<"no such node.\n";
        delete newNode;
    }
    newNode->next=curr->next;
    curr->next=newNode;
    return head;
}
Node* single::delhead(Node* head){
    if(head==nullptr){
        return NULL;
    }
    Node* curr=head;
    head=head->next;
    delete curr;
    return head;
}
Node* single::dellast(Node* head){
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
Node* single::delpos(Node* head,int pos){
    if(head->next==nullptr){
        delete head;
        return NULL;
    }
    Node* curr=head->next;
    Node* prev=head;
    for(int i=1;i<pos-1;i++){
        prev=prev->next;
        curr=curr->next;
    }
    if(curr==nullptr){
        cout<<"no such node to delete.\n";
    }
    prev->next=curr->next;
    delete curr;
    return head;
}
Node* single::reverselist(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next=nullptr;
    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void single::search(Node* head,int key){
    Node* curr=head;
    while(curr->next!=nullptr&&curr->value!=key){
        curr=curr->next;
    }
    if(curr->value==key){
        cout<<"found it! "<<curr->value<<endl;
    }
    else{
        cout<<"node not found.\n";
    }
}
int single::getsize(Node* head){
    int count;
    for(Node* curr=head;curr!=nullptr;curr=curr->next){
        count++;
    }
    return count;
}
void single::printlist(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->value<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    single* s=new single();
    Node* head=new Node(2);
    Node* second =new Node(3);
    head->next=second;
    cout<<"the original list: ";s->printlist(head);
    cout<<"the number of elements: "<<s->getsize(head)<<endl;
    head=s->insertfront(head,1);
    head=s->insertlast(head,4);
    head=s->insertpos(head,2,1);
    //the next 3 lines are delete operations
    head=s->delhead(head);
    head=s->dellast(head);
    head=s->delpos(head,3);
    cout<<"the modified list: ";s->printlist(head);
    cout<<"the number of elements: "<<s->getsize(head)<<endl;
    int key;
    cout<<"search something or you are gay: ";cin>>key;
    s->search(head,key);
    return 0;
}
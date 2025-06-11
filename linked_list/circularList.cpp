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
class circular{
    public:
    Node* insertempty(Node* last,int newValue);
    Node* insertfront(Node* last,int newValue);
    Node* insertlast(Node* last,int newValue);
    Node* insertpos(Node* last,int pos,int newValue);
    Node* delhead(Node* last);
    Node* dellast(Node* last);
    Node* delNode(Node* last,int key);
    void search(Node* last,int x);
    int getsize(Node* last);
    void printlist(Node* last);
};
Node* circular::insertempty(Node* last,int newValue){
   if(last!=nullptr){
    cout<<"use another method this method is for empty lists.\n";
    return last;
   }
   Node* newNode=new Node(newValue);
   newNode->next=newNode;
   last=newNode;
   return last;
}
Node* circular::insertfront(Node* last,int newValue){
    Node* newNode=new Node(newValue);
    if(last==nullptr){
        newNode->next=newNode;
        last=newNode;
    }
    last->next=newNode->next;
    last->next=newNode;
    return last;
}
Node* circular::insertlast(Node* last,int newValue){
    Node* newNode=new Node(newValue);
    if(last==nullptr){
        newNode->next=newNode;
        last=newNode;
    }
    newNode->next=last->next;
    last->next=newNode;
    last=newNode;
    return last;
}
Node* circular::insertpos(Node* last,int pos,int newValue){
    Node* newNode=new Node(newValue);
    if(last==nullptr){
        if(pos!=1){
        cout<<"the node does not exist.\n";
        delete newNode;
        return NULL;
        }
       circular::insertempty(last,newValue); 
    }
    Node* curr=last->next;
    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }
    newNode->next=curr->next;
    curr->next=newNode;
    return last;
}
Node* circular::delhead(Node* last){
    if(last==nullptr){
        cout<<"the list is already empty.\n";
        return NULL;
    }
    Node* head=last->next;
    if(head==last){
        delete head;
        last=nullptr;
        return NULL;
    }
    last->next=head->next;
    delete head;
    return last;
}
Node* circular::dellast(Node* last){
     if(last==nullptr){
        cout<<"the list is already empty.\n";
        return NULL;
    }
    Node* head=last->next;
    if(head==last){
        delete head;
        last=nullptr;
        return NULL;
    }
    Node* curr=head;
    while(curr->next!=last){
        curr=curr->next;
    }
    curr->next=last->next;
    delete last;
    last=curr;
    return last;
}
Node* circular::delNode(Node* last,int key){
     if(last==nullptr){
        cout<<"the list is already empty.\n";
        return NULL;
     }
     Node* prev=last;
     Node* curr=last->next;
     if(curr==last&&curr->value==key){
        last=nullptr;
        delete curr;
        return NULL;
     }
     if(curr->value==key){
        last->next=curr->next;
        delete curr;
        return last;
     }
     while(curr!=last&&curr->value!=key){
        prev=curr;
        curr=curr->next;
     }
     if(curr->value==key){
        prev->next=curr->next;
        if(curr==last){
            last=prev;
        }
        delete curr;
     }
     else{
        cout<<"the node is not found.\n";
     }
     return last;
}
void circular::search(Node* last,int x){
    Node* curr=last->next;
    while(curr!=last&&curr->value!=x){
        curr=curr->next;
    }
    if(curr->value==x){
        cout<<"found it! "<<curr->value<<endl;
    }
    else{
        cout<<"sorry node not found.\n";
    }
}
int circular::getsize(Node* last){
    int count;
    Node* curr=last->next;
    while(true){
        count++;
        curr=curr->next;
        if(curr=last->next){
            break;
        }
    }
    return count;
}
void circular::printlist(Node* last){
    Node* curr=last->next;
    while(true){
        cout<<curr->value<<" ";
        curr=curr->next;
        if(curr==last->next){
            break;
        }
    }
    cout<<endl;
}
int main(){
    int arr[12];
    cin>>arr[0];
    circular* c=new circular();
    Node* first=new Node(2);
    first->next=new Node(3);
    first->next->next=new Node(4);
    Node* last=first->next->next;
    last->next=first;
    cout<<"the original list: ";c->printlist(last);
    cout<<"no of elements: "<<c->getsize(last)<<endl;
    last=c->insertfront(last,1);
    last=c->insertlast(last,5);
    last=c->insertpos(last,2,1);
    last=c->delhead(last);
    last=c->dellast(last);
    cout<<"the modified list: ";c->printlist(last);
    cout<<"no of elements: "<<c->getsize(last)<<endl;
    int x;
    cout<<"enter a node you want to delete: ";cin>>x;
    last=c->delNode(last,x);
    cout<<"the modified list: ";c->printlist(last);
    cout<<"no of elements: "<<c->getsize(last)<<endl;
    cout<<"what node are you looking for: ";cin>>x;
    c->search(last,x);
    return 0;
}
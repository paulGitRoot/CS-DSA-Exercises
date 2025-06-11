#include<iostream>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value=v;
        left=right=nullptr;
    }
};
Node* insert(Node* root,int x){
    if(root==nullptr){
        return new Node(x);
    }
    if(root->value==x){
        return root;
    }
    if(x<root->value){
        root->left=insert(root->left,x);
    }
    else if(x>root->value){
        root->right=insert(root->right,x);
    }
    return root;
}
Node* getSuccessor(Node* root){
    Node* curr=root->left;
    while(curr!=nullptr&&curr->right!=nullptr){
        curr=curr->right;
    }
    return curr;
}
Node* delNode(Node* root,int x){
    if(root==nullptr){
        return root;
    }
    if(root->value>x){
        root->left=delNode(root->left,x);
    }
    if(root->value<x){
        root->right=delNode(root->right,x);
    }
    else{
        if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* succ=getSuccessor(root);
        root->value=succ->value;
        root->left=delNode(root->left,succ->value);
    }
}
Node* search(Node* root,int key){
    if(root==nullptr||root->value==key){
        return root;
    }
    if(key<root->value){
        return search(root->left,key);
    }
    return search(root->right,key);
}
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}
void preOrder(Node* root){
    if(root!=nullptr){
        cout<<root->value<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void posOrder(Node* root){
    if(root!=nullptr){
        posOrder(root->left);
        posOrder(root->right);
        cout<<root->value<<" ";
    }
}
int main(){
    Node* root=new Node(50);
    root=insert(root,30);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,21);
    root=insert(root,60);
    root=insert(root,80);
    inorder(root);
    return 0;
}
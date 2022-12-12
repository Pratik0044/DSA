#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* creat_tree(node* root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    root=new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left: "<<data<<endl;
    root->left=creat_tree(root->left);
    cout<<"Enter data for inserting in right: "<<data<<endl;
    root->right=creat_tree(root->right);

    return root;

}

void inorder(node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    preorder(root->left);
    
    preorder(root->right);

}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);

    cout<<root->data<<" ";
}



void levelordertrasversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* temp=q.front();
        
        q.pop();

        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
            q.push(temp->left);
            }

            if(temp->right){
            q.push(temp->right);
            }

        }
       
    }
    
}

int main(){
    node* root=NULL;
    root=creat_tree(root);
    // 1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1 
    cout<<"Data of tree are: "<<endl;
    levelordertrasversal(root);


    cout<<"Inorder traversal  "<<endl;
    inorder(root);



    cout<<endl<<"Preorder Traversal "<<endl;
    preorder(root);

    cout<<endl<<"Postorder Treversal "<<endl;
    postorder(root);
    return 0;
}
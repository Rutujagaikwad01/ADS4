#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
class binaryTree
{
    public:
    int data;
    binaryTree* left;
    binaryTree* right;
    int flag;
    binaryTree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
        flag=0;
    }
};
void insert(binaryTree* &root,int val)
{
    if(root==NULL)
    {
        root=new binaryTree(val);
    }
    else
    {
        if(val<=root->data)
        {
            insert(root->left,val);
        }
        else
        {
            insert(root->right,val);
        }
    }
}
void create(binaryTree* &root)
{
    int val,no_node;
    cout<<"\nEnter root node: ";
    cin>>val;
    root=new binaryTree(val);
    cout<<"\nEnter no. of nodes to be insert: ";
    cin>>no_node;
    cout<<"\nEnter the valuse of nodes: ";
    for(int i=0;i<no_node;i++)
    {
        cin>>val;
        insert(root,val);
    }
}
void inorderTraversal(binaryTree* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(root->left);
        cout << root->data << " "; 
        inorderTraversal(root->right);
    }
}
void postorderTraversal(binaryTree* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}
void preorderTraversal(binaryTree* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void nonRecursivePreorder(binaryTree* root) 
{
    if (root == NULL) 
        return;

    stack<binaryTree*> s;
    s.push(root);

    while (!s.empty()) 
    {
        binaryTree* temp = s.top();
        s.pop();

        cout << temp->data << " "; 
        if (temp->right != NULL) {
            s.push(temp->right);
        }

        if (temp->left != NULL) {
            s.push(temp->left);
        }
    }
}
void nonRecursiveInorder(binaryTree* root)
{
    if(root==NULL)
        return;
    stack<binaryTree*>s;
    binaryTree* temp=root;
    do
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }while(!s.empty()||temp!=NULL);
}

int main()
{
    binaryTree* root=NULL;
    create(root);
    cout<<"\nInorder traversal: ";
    inorderTraversal(root);
    cout<<"\nPostorder traversal: ";
    postorderTraversal(root);
    cout<<"\nPreorder traversal: ";
    preorderTraversal(root);
    cout<<"\nnonRecursivePreorder: ";
    nonRecursivePreorder(root);
    cout<<"\nnonRecursiveInorder: ";
    nonRecursiveInorder(root);
}
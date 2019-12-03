#include<iostream>
using namespace std;
struct node
{
	int data;
    node *left;
    node *right;
    node *parent;
};

node *newNode(int data)
{
	struct node *n=new node;
	n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    return n;
}
node *search(node *root,int data)
{
	if(root==NULL)
		return NULL;
	if(root->data==data)
	   return root;
	node *l=search(root->left,data);
    if (l != NULL)
    {
        return l;
    }
	node *r=search(root->right,data);
    if(r !=NULL)
    {
        return r;
    }
    return NULL;
}
node *predecessor(node *root,int data)
{
    node *n=search(root,data);
    cout<<n->data;
    if(n!=NULL)
    {
        if(n->right)
            return n->right;    
        node *curr=n;
        node *par=curr->parent;
        while(par!=NULL and par->left==curr)
        {
            curr=curr->parent;
            par=par->parent;
        }
        if(par==NULL)
            return NULL;
        return par->left;
    }
   return NULL;
}
int main()
{
	node *root=newNode(1);
	root->parent=NULL;

	root->left=newNode(2);
	root->left->parent=root;

    root->right=newNode(3);
    root->right->parent=root;

    root->left->left=newNode(4);
    root->left->left->parent=root->left;

    root->left->right=newNode(5);
    root->left->right->parent=root->left;

    root->right->left=newNode(6);
    root->right->left->parent=root->right;
   
    node *pre_node=predecessor(root,5);
    if(pre_node!=NULL)
      cout<<pre_node->data<<endl;
    else
      cout<<"No data found"<<endl;

}
/*
                            (4)
                          /     \
                        (2)     (6)
                        / \     / \
                      (1) (3) (5) (7)
*/

#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *Right;
    Node *Left;
};

Node *ROOT = NULL;

void *insert(int data)
{
    Node *leaf = new Node;
    leaf->data = data;
    leaf->Right = NULL;
    leaf->Left = NULL;

    if(ROOT==NULL)
    {
        ROOT = leaf;  
        cout<<"Inserted root with data: "<<ROOT->data;  
    }
    else
    {
        Node *ptr = ROOT;
        while(true)
        {
            if(ptr->data > data) 
            {
                if(ptr->Left!=NULL)
                {
                    ptr = ptr->Left;
                }
                else
                {
                    ptr->Left = leaf;
                    cout<<"\nInserted with data: "<<ptr->Left->data;
                    break;
                }
            }
            else
            {
                if(ptr->Right!=NULL)
                {
                    ptr = ptr->Right;
                }
                else
                {
                    ptr->Right = leaf;
                    cout<<"\nInserted with data: "<<ptr->Right->data;
                    break;
                }
            }
            
        }
    }
    cout<<endl;
}

void inOrder(Node *root)
{
    if(root)
    {
        inOrder(root->Left);
        cout<<root->data;
        inOrder(root->Right);
    }
}

void postOrder(Node *root)
{
    if(root)
    {
        cout<<root->data;
        postOrder(root->Left);
        postOrder(root->Right);
    }
}

void preOrder(Node *root)
{
    if(root)
    {
        preOrder(root->Left);
        preOrder(root->Right);
        cout<<root->data;
    }
}

int main()
{
    insert(4);
    insert(2);
    insert(6);
    insert(1);
    insert(3);
    insert(5);
    insert(7);
    cout<<"In-Order: ";
    inOrder(ROOT);
    cout<<endl;
    cout<<"Pre-Order: ";
    preOrder(ROOT);
    cout<<endl;
    cout<<"Post-Order: ";
    postOrder(ROOT);
    cout<<endl;
    return 0;
}
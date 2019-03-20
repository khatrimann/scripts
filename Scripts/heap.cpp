#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *Left;
    Node *Right;
};

Node *ROOT = NULL;

bool insert(Node *root, int data)
{
    Node *node = new Node;
    node->data = data;
    node->Left = NULL;
    node->Right = NULL;

    if(root==NULL)
    {
        cout<<"Inserted at root\n";
        root = node;
        return true;
    }
    else
    {   
        while(1)
        {
            Node *ptr = root;
            
            if(ptr->data > data)
            {
                if(ptr->Left == NULL && ptr->Right == NULL)
                {
                    ptr->Left = node;
                    cout<<"Inserted\n";
                    return true;
                }
                else if(ptr->Left==NULL)
                {
                    ptr->Left = node;
                    cout<<"Inserted";
                    return true;
                }
                else if(ptr->Right == NULL)
                {
                    ptr->Right = node;
                    cout<<"Inserted";
                    return true;
                }
                else if(ptr->Left->data > data)
                {
                    insert(ptr->Left, data);
                }
                else if(ptr->Right->data > data)
                {
                    insert(ptr->Right, data);
                }
                
                
            }
            else
            {
                cout<<"Invalid";
                return false;
            }
            

        }
    }    
}

void inOrder(Node *root)
{
    if(root)
    {
        inOrder(root->Left);
        cout<<root->data;
        inOrder(root->Right);
    }
    cout<<"\n";
}

int main()
{
    if(insert(ROOT, 3))
        if(insert(ROOT, 2))
            if(insert(ROOT, 1))
            {
                cout<<"Everything was inserted successfully!!\n";
                inOrder(ROOT);
            }
    return 0;
}
#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *HEAD = NULL;

void *insert(int data)
{
    node *Node = new node;
    Node->data = data;
    Node->next = NULL;

    if(HEAD == NULL)
    {
        cout<<"Inserting at HEAD...\n";
        HEAD = Node;        
    }
    else
    {
        cout<<"\nInserting...\n";
        node *ptr = HEAD;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = Node;
    }
    cout<<"Inserted!!\n";
}

void *display()
{
    cout<<"\nExecuting function...\n";
    node *ptr = HEAD;
    //cout<<"\n*ptr->data = "<<ptr->data<<endl;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    } 
}

int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;

    for(int i=0;i<n;i++)
        insert(i);
    display();
    return 0;
}
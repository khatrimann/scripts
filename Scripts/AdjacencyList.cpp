#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *insert(node *head, int data)
{
    node *Node = new node;
    Node->data = data;
    Node->next = NULL;

    if(head == NULL)
    {
        cout<<"Inserting at head...\n";
        head = Node;        
    }
    else
    {
        cout<<"\nInserting...\n";
        node *ptr = head;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = Node;
    }
    cout<<"Inserted!!\n";
    return head;
}

void *display(node *head)
{
    cout<<"\nExecuting function...\n";
    node *ptr = head;
    //cout<<"\n*ptr->data = "<<ptr->data<<endl;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    } 
}

int main()
{
    int numNodes;
    
    cout<<"Number of nodes: ";
    cin>>numNodes;
    
    node *a[numNodes];

    for(int i=0;i<4;i++)
    {
        a[i] = NULL;
    }

    for(int i=0;i<4;i++)
    {
        int n=0;
        a[i] = insert(a[i], i);
        cout<<"\nInsert nodes(enter -1 to quit): ";
        cout<<"\nINFO: THE HEAD BELONGS TO THE i = "<<i<<" and head->data is = "<<a[i]->data;
        while(n!=-1)
        {
            cout<<"\nValue of i is: "<<i;
            cout<<"\nEnter here(-1 to quit): ";
            cin>>n;
            cout<<endl;
            if(n!=-1)
                a[i] = insert(a[i], n);
        }
    }

    for(int i=0;i<4;i++)
        display(a[i]);
    
    return 0;
}
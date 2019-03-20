/*
                            (4)
                          /     \
                        (2)     (6)
                        / \     / \
                      (1) (3) (5) (7)
*/

#include<iostream>
#include<stack>
#include<queue>
#include<sstream>

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

void topview()
{
    Node *ptr_to_left=ROOT, *ptr_to_right=ROOT;
    stack <int>s;
    queue <int>q;

    while(ptr_to_right != NULL)
    {
        //cout<<"\ndata->right = "<<ptr_to_right->data;
        q.push(ptr_to_right->data);
        ptr_to_right = ptr_to_right->Right;
    }
    
    //s.push(ROOT->data);
    
    while(ptr_to_left->Left != NULL)
    {
        //cout<<"\ndata->left = "<<ptr_to_left->data;
        ptr_to_left = ptr_to_left->Left;
        s.push(ptr_to_left->data);
    }
    
    while(!s.empty())
    {
        cout<<s.top()<<" "; 
        s.pop(); 
    }

    while(!q.empty())
    {
        cout << q.front()<<" "; 
        q.pop(); 
    }

}

int main()
{
    /*
    
    These are inputs according to the tree on top
    insert(4);
    insert(2);
    insert(6);
    insert(1);
    insert(3);
    insert(5);
    insert(7);

    */

    int pos=0;
    string token;
    string delimiter = " ";
    string s = "37 23 108 59 86 64 94 14 105 17 111 65 55 31 79 97 78 25 50 22 66 46 104 98 81 90 68 40 103 77 74 18 69 82 41 4 48 83 67 6 2 95 54 100 99 84 34 88 27 72 32 62 9 56 109 115 33 15 91 29 85 114 112 20 26 30 93 96 87 42 38 60 7 73 35 12 10 57 80 13 52 44 16 70 8 39 107 106 63 24 92 45 75 116 5 61 49 101 71 11 53 43 102 110 1 58 36 28 76 47 113 21 89 51 19 3 ";
    while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    stringstream mann(token);
    int i;
    mann>>i;
    insert(i);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}

    topview();
    return 0;
}
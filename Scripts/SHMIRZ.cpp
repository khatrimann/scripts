#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;

    int A[N], B[N];
    
    for(int i=0;i<N;i++)
    {
        cin>>A[i]>>B[i];
    }

    int Q, p;
    cout<<"Q: ";
    cin>>Q;

    p = Q;

    int q[Q][4];

    for(int i=0;i<Q;i++)
    {   
        for(int j=0;j<4;j++)
        {
            cin>>q[i][j];
        }
    }

    int shop_i = 0, shop_j = 0, L = 0, R = 0, x = 0;

    for(int i=0;i<Q;i++)
    {
        
        if(q[i][0]==1)
        {
            shop_i = q[i][1];
            shop_j = q[i][2];
        }
        else if(q[i][0]==2)
        {
            L = q[i][1];
            R = q[i][2];
            x = q[i][3];
        }

        if(L != 0 && R != 0 && x != 0)
        {
            int max=0;
            for(int l=L-1;l<R;l++)
            {
                int max=0;
                int ans = A[i] * x + B[i];
                if(ans > max) max = ans;
            }
            cout<<"\nmax: "<<max<<endl;
        }
    }
    
    return 0;
}
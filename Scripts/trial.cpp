    #include <bits/stdc++.h>
    using namespace std;
    int main()
    { 
      int t,n,ans,a, b, d, c, i,j; 
      cin>>t;
      while(t>0)
      { 
       c=0;
       cin>>n; 
       d = n;
       while(n!=0)
       {
         a = n; n=n/10; b = a % 10;
         if (d % b == 0)  c++; 
         else continue; 
       }
       cout<<c<<"\n";
       t--; 
      }
      return 0;
    }
#include<bits/stdc++.h>
using namespace std;
int  SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
       
        if (prime[p] == true) 
        { 
            
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
   int ctr=0;
    for (int p=2; p<=n; p++) 
      { if (prime[p]) 
       ctr++;}
       return ctr;
       
         
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    { int n;cin>>n;
        int ctr=SieveOfEratosthenes(n);
       // cout<<ctr<<endl;
     if(ctr==0)
          cout<<"Harshit"<<endl;
    else if(ctr%2!=0)
         cout<<"Aahad"<<endl;
     else
                 cout<<"Harshit"<<endl;

    }       
	return 0;
}

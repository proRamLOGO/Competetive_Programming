/*
 
 /-----------------------------------------------------------/
 |                                                           |
 |                                                           |
 |               AUTHOR: Achint Narang                       |                                   
 |                                                           |
 |                                                           |
 /------------------------------------------------------------/
 
 
*/
#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return 
 
 
using namespace std;
int  C(int n, int r) 
{
    if(r > n - r)
     r = n - r; 
    int  ans = 1;
    
 
    for(int i = 1; i <= r; i++) {
        ans *=( n - r + i);
        ans /= i;
    }
 
    return ans;
}
 
 
  int stringtointer(string a)
{
 
  return stoi(a);
}
int countdigit(int a)
  {
    
    int ans=0;
 
    while(a)
    {
      a/=10; 
      ans++;
    }
    
 
    return ans; 
  }
 
  
 int factorial(int n) 
{ 
   
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 
 int dayofweek(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}
int floorSqrt(int x)  
{     
    
    if (x == 0 || x == 1)  
       return x; 
  int start = 1, end = x, ans;    
    while (start <= end)  
    {         
        int mid = (start + end) / 2; 
    if (mid*mid == x) 
            return mid; 
  if (mid*mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else 
            end = mid-1;         
    } 
 
    return ans; 
} 
 


bool checkpallindrome(string s)
{


  string ans=s;

  reverse(ans.begin(),ans.end());

  if(ans==s)
     return true;


   return false;

}

int kadane(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 




 void solve(int tc)

{ 
     
 
 int n;cin>>n;
vector<int>index;


 int arr[n];
  //index.pb(-1);

for(int i=0;i<n;i++)
{
       cin>>arr[i];

        if(arr[i]!=0&&arr[i]%2==0)
      index.pb(i);



}

   
int ans=(n*(n+1))>>1;

if(index.size()==0)
{
  cout<<ans<<endl;
  R;
}
int indexsize=index.size();
//cout<<indexsize<<endl;
for(int i=0;i<index.size();i++)
{

     int x=index[i];
 
     if(arr[x]%4==2||arr[x]%4==-2)
     {

             
      int a=(i==0?x:x-index[i-1]-1 );
      int b=(i==indexsize-1?n-1-x :index[i+1]-x-1)  ;


          int temp=a;
      temp+=b;

      temp+=a*b;
      temp+=1;
//cout<<temp<<endl;
      ans-=temp;

     }

}

cout<<ans<<endl;

  

  }










      



int32_t main()
{
 
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
//   int f=-4;
//   cout<<f%4<<endl;
 
  int t=1;
cin>>t;
 int tc=1;
    while(t--)
    {


       solve(tc);
      tc++;


       
    }
return 0;
}
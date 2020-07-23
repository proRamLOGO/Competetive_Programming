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


class obj{

 public:
  int acount;
  int Acount;
  int ocount;
  int lcount;

  obj()
  {

    acount=1;
    Acount=1;
    ocount=1;
    lcount=1;
  }

};

int calc(int x,int y)
{
              int res = 1;    
  
    x = x % moduli; 
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
        
        if (y & 1)  
            res = (res*x) ;  
  
      
        y = y>>1; 
        x = (x*x);  
    }
    
    
    return res;  
              
}
  
  
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
  
// Function to find modulo inverse of a 
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    int res = (x%m + m) % m; 
       return  res; 
    
     
} 

 void solve(int tc)

{ 
     
 
 
  string s;
  cin>>s;
int ctr=0;

  stack<obj>op;
stack<char>op1;

  for(int i=0;i<s.size();i++)
{

  

  if(s[i]=='#')
  {
ctr++;
    obj temp;
     op.push(temp);
continue;

  }

if(s[i]=='^'||s[i]=='&'||s[i]=='|')
{

        op1.push(s[i]);
        continue;

}

if(s[i]==')')
{


  obj temp2=op.top();
op.pop();

  obj temp1=op.top();

  op.pop();


  char ch=op1.top();
  op1.pop();

  if(ch=='&')
  {

obj temp;
    int sum2=(temp2.ocount+temp2.lcount+temp2.acount+temp2.Acount)%moduli;

    int sum1=(temp1.ocount+temp1.lcount+temp1.acount+temp1.Acount)%moduli;


    int x=(temp2.ocount *sum1)%moduli;
    int y=(x+  (temp1.ocount)*(sum2) )%moduli;

    int z=(y-temp1.ocount*temp2.ocount)%moduli;

   
    x=(temp1.acount*temp2.Acount)%moduli;

    y=(temp1.Acount*temp2.acount)%moduli;


    z=(z+x+y)%moduli;

    z=(z+moduli)%moduli;

    temp.ocount=z;

    temp.lcount=(temp1.lcount*temp2.lcount)%moduli;

    x=(temp1.acount*temp2.acount)%moduli;

    y=(temp1.lcount*temp2.acount)%moduli;

    z=(temp1.acount*temp2.lcount)%moduli;

    temp.acount=(x+y+z)%moduli;

    x=(temp1.Acount*temp2.Acount)%moduli;

    y=(temp1.lcount*temp2.Acount)%moduli;

    z=(temp1.Acount*temp2.lcount)%moduli;


temp.Acount=(x+y+z)%moduli;
op.push(temp);
  }


else if(ch=='|')
{

obj temp;
    int sum2=(temp2.ocount+temp2.lcount+temp2.acount+temp2.Acount)%moduli;

    int sum1=(temp1.ocount+temp1.lcount+temp1.acount+temp1.Acount)%moduli;


    int x=((temp2.lcount) *(sum1))%moduli;
    int y=(x+ (temp1.lcount)*(sum2) )%moduli;

    int z=(y-temp1.lcount*temp2.lcount)%moduli;

   
    x=(temp1.acount*temp2.Acount)%moduli;

    y=(temp1.Acount*temp2.acount)%moduli;


    z=(z+x+y)%moduli;

    z=(z+moduli)%moduli;

    temp.lcount=z;

    temp.ocount=(temp1.ocount*temp2.ocount)%moduli;

    x=(temp1.acount*temp2.acount)%moduli;

    y=(temp1.ocount*temp2.acount)%moduli;

    z=(temp1.acount*temp2.ocount)%moduli;

    temp.acount=(x+y+z)%moduli;

    x=(temp1.Acount*temp2.Acount)%moduli;

    y=(temp1.ocount*temp2.Acount)%moduli;

    z=(temp1.Acount*temp2.ocount)%moduli;


temp.Acount=(x+y+z)%moduli;
op.push(temp);


}

else{

     
     obj temp;
           int x=(temp1.ocount*temp2.lcount)%moduli;
          int y=(temp1.lcount*temp2.ocount )%moduli;
          int z=(temp1.acount*temp2.Acount)%moduli;
          int w=(temp1.Acount*temp2.acount)%moduli;

          temp.lcount=(x+y+z+w)%moduli;

          x=(temp1.ocount*temp2.ocount)%moduli;

          y=(temp1.lcount*temp2.lcount)%moduli;

          z=(temp1.acount*temp2.acount)%moduli;

          w=(temp1.Acount*temp2.Acount)%moduli;

          temp.ocount=(x+y+z+w)%moduli;

            

             x=(temp1.ocount*temp2.acount)%moduli;
             y=(temp1.acount*temp2.ocount)%moduli;
             z=(temp1.lcount*temp2.Acount)%moduli;
             w=(temp1.Acount*temp2.lcount)%moduli;
 temp.acount=(x+y+z+w)%moduli;


x=(temp1.Acount*temp2.ocount)%moduli;
y=(temp1.ocount*temp2.Acount)%moduli;

z=(temp1.lcount*temp2.acount)%moduli;

 w=(temp1.acount*temp2.lcount)%moduli;
     
   
     temp.Acount=(x+y+z+w)%moduli;
      
     
     op.push(temp);
                    



}

}



  }
//748683265 748683265 748683265 748683265
//436731905 935854081 811073537 811073537


obj temp=op.top();
   
   // int lol=calc(4,ctr);
    int inv=modInverse(4,moduli);

    int x=temp.acount,y=temp.Acount,z=temp.ocount,w=temp.lcount;
//cout<<temp.acount<<" "<<temp.Acount<<" "<<temp.ocount<<" "<<temp.lcount<<endl;

    for(int i=0;i<ctr;i++)
 { 

  x=( x*inv )%moduli;

  y=( y*inv )%moduli;
    
   w=(w*inv )%moduli;

  z=( z*inv )%moduli;

}

cout<<z<<" "<<w<<" "<<x<<" "<<y<<endl;
  }










      



int32_t main()
{
 
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
  
 
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
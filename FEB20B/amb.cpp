/*
Just Another Source code by -
Ambuj              
*/
#include<bits/stdc++.h>
#define ll long long
#define MAX 1000003
#define pii pair<int,int>
#define VP vector< pii >
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define all(v) (v).begin(),(v).end()
#define S(x) scanf("%d",&(x))
#define S2(x,y) scanf("%d%d",&(x),&(y))
#define SL(x) scanf("%lld",&(x))
#define SL2(x) scanf("%lld%lld",&(x),&(y))
#define P(x) printf("%d\n",(x))
#define FF first
#define SS second
using namespace std;
int tellday(int date,int m,int y)
{
	int q=y%10,w=(y/10)%10,lcode=0;
	int ycode=w*10+q;
	ycode=(ycode+(ycode/4))%7;
    if((y%4==0&&y%100!=0)||(y%400==0))lcode=1;
	int c=(ycode+m-lcode+date)%7;
	return c;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen ("output.txt","w",stdout);
#endif
 int date,month,year,m[13]={0,3,3,6,1,4,6,2,5,0,3,5};
 cin>>date>>month>>year;
 int lcode=0;
if((year%4==0&&year%100!=0)||(year%400==0))lcode=1;
 int g=tellday(date,m[month-1],year);
 if((month==2||month==1)&&lcode==1)
{g--;
 if(g==-1)
 	cout<<6;
 else
 	cout<<g;
}
else
cout<<g;

return 0;
}

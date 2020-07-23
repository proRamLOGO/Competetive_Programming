#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100005;
const int MA = 1000006;
const int MAXM = 100005;
const int LN = 19;

#define MOD 1000000007
typedef long ll;
 int spf[MA]; 
int N, M, K, cur, LVL[MAXN], DP[LN][MAXN];
int BL[MAXN << 1], ID[MAXN << 1], ANS[MAXM];
int l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < int > adjList[MAXN];
vector<vector<pair<ll,ll>>> m(MAXN,vector<pair<ll,ll>>());
ll pc[1000005],pcmi[300005];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MA; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MA; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MA; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MA; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
void modularInverse(int n, ll prime=1000000007) 
{ 
    //int dp[n + 1]; 
    pcmi[0] = pcmi[1] = 1; 
    for (int i = 2; i <= n; i++)  
        pcmi[i] = pcmi[prime % i] *  
               (prime - prime / i) % prime;     
  
   
} 
struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];
//bool prime[100005];
 
// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 //unordered_map <ll,ll> m;
 // vector<ll> m,v;

 inline void rem(int x,ll &res)
 {
for(auto it=m[x].begin();it!=m[x].end();it++)
{//cout<<(*it).first<<" "<<(*it).second<<endl;

res-=((res*pcmi[pc[(*it).first]])%MOD*(*it).second)%MOD;
res=(res+MOD)%MOD;
pc[(*it).first]-=(*it).second;


}
 	
 }
 inline void add(int x,ll &res)
 {//cout<<"E"<<x;
 	
for(auto it=m[x].begin();it!=m[x].end();it++)
{//cout<<(*it).first<<" "<<(*it).second<<endl;

res+=((res*pcmi[pc[(*it).first]])%MOD*(*it).second)%MOD;
res%=MOD;
pc[(*it).first]+=(*it).second;


}

}

 
inline void check(int x,ll &res){
	// If (x) occurs twice, then don't consider it's value 
	//cout<<A[x]<<endl;
	if ( (VIS[x])  ) rem(x,res);
	else if ( (!VIS[x])  ) add(x,res);
	VIS[x] ^= 1;
}

 
void compute(){
	
	// Perform standard Mo's Algorithm
	ll curL = Q[0].l, curR = Q[0].l - 1, res = 1;
	
	for (int i = 0; i < M; i++){
		
		while (curL < Q[i].l) check(ID[curL++],res);
		while (curL > Q[i].l) check(ID[--curL],res);
		while (curR < Q[i].r) check(ID[++curR],res);
		while (curR > Q[i].r) check(ID[curR--],res);
		
		int u = ID[curL], v = ID[curR];
		
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc,res);
		
		ANS[Q[i].id] = res%MOD;
		
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc,res);
	}
 
	for (int i = 0; i < M; i++) cout<<ANS[i]<<"\n";
}
 
int main(){
	
 ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
	#ifndef ONLINE_JUDGE
 freopen("/home/ambuj/.config/sublime-text-3/Packages/User/input.txt","r",stdin);
 freopen("/home/ambuj/.config/sublime-text-3/Packages/User/output.txt","w",stdout);
 #endif
 sieve();
  	int u, v;
	int t;
	cin>>t;
	//for(int i=0;i<200005;i++){pcmi[i]=modInverse(i);}
	modularInverse(100005);
	while (t--){
		//m.clear();
   for(int i=0;i<1000005;i++){pc[i]=1;}
   
		cin>>N;
		
		// Cleanup
		cur = 0;
		memset(VIS, 0, sizeof(VIS));
		//memset(pc, 1, sizeof(pc));
		for (int i = 1; i <= N; i++) adjList[i].clear();
		//memcpy(d + 1, A + 1, sizeof(int) * N);
		// Inputting Tree
		for (int i = 1; i < N; i++){
			//scanf("%d %d", &u, &v);
			cin>>u>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		
		// Inputting Values
		//for(int i=1;i<=N;i++)cin>>A[i];
		
		 unordered_map<int,int> ret ;
       int tmp;
		for (int i = 1; i <= N; i++) {cin>>tmp;

			m[i].clear();
				
		ret.clear();		
    while (tmp != 1) 
    { 
        ret[spf[tmp]]++; 
        tmp = tmp / spf[tmp]; 
    } 
    for(auto it=ret.begin();it!=ret.end();it++)
    {
    	m[i].push_back(make_pair((*it).first,(*it).second));

    }
				

    }
		
		cin>>M;
		
		
		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int size = sqrt(cur);
		
		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;
		
		for (int i = 0; i < M; i++){
			//scanf("%d %d", &u, &v);
			cin>>u>>v;
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}
 
		sort(Q, Q + M);
		compute();
		
	}
 
}
 
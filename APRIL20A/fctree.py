import sys
sys.stdin = open('input.txt', 'r') 
sys.stdout = open('output.txt', 'w')
MAXN = 100005
MA = 1000006
MAXM = 100005
LN = 19

spf[MA]; 
# int N, M, K, cur, LVL[MAXN], DP[LN][MAXN];
LVL = [[0]]*MAXN
DP =  [ [[0]]*MAXN ] * LN

BL = [ [[0]]* (2**MAXN) ]
ID = [[0]]* (2**MAXN)
ANS = [[0]]* MAXM
l = [[0]]*MAXN
R = [[0]]*MAXN
VIS = [[False]]*MAXN

adjList = [[0]] * MAXN
m =  [ [ [0,0] ] ] * MAXN
# vector<vector<pair<ll,ll>>> m(MAXN,vector<pair<ll,ll>>());
pc = [ [0] ]* 1000005
pcmi = [ [0] ]* 300005

def init__spf() ;

    for i in range(2,int(1e7)) :
        if ( spf[i] == 1 ) :
            spf[i] = i 
            for  j in range( i*i, int(1e7) , i ) :
                if ( spf[j]==1 )
                    spf[j] = i 


# int smpf( ulli n ) {
#     for ( int i = 2 ; i*i <= n ; ++i )
#         if ( n%i == 0 )
#             return i ;
#     return n ;
# }

def init__modularInverse() :
    dp = [[0]] * 100006 
    pcmi[0] = pcmi[1] = 1; 
    for i in range(2,100006) :
        pcmi[i] = pcmi[prime % i] * (prime - prime // i) % prime 
  
   
} 
class query :
    def __init__(self) :
        self.id = 0
        self.c = 0
        self.r = 0
        self.l = 0

	def __lt__(self, rhs):
		if (BL[l] == BL[rhs.l]) :
            (r < rhs.r) 
        else : 
            (BL[l] < BL[rhs.l])
	
}

Q = [[query]]*MAXM
# //bool prime[100005];
 
# // Set up Stuff

def dfs(u,par) :
	l[u] = cur+1; 
    cur += 1
	ID[cur] = u
	for i in range(1,LN):
        DP[i][u] = DP[i - 1][DP[i - 1][u]]
	for i in range(len(adjList[u])) :
		v = adjList[u][i]
		if (v == par) :
            continue
		LVL[v] = LVL[u] + 1
		DP[0][v] = u
		dfs(v, u)
	}
	r[u] = 1+cur; 
    cur += 1
    ID[cur] = u

 
# // Function returns lca of (u) and (v)

def lca(u,v) :
	if ( LVL[u] > LVL[v]):
        swap(u, v)
	for i in range(LN - 1,-1,-1) :
		if (LVL[v] - (1 << i) >= LVL[u]) :
            v = DP[i][v]

	if (u == v) :
        return u
	for i in range(LN - 1,-1,-1) :
		if (DP[i][u] != DP[i][v]):
			u = DP[i][u]
			v = DP[i][v]
		
	}
	return DP[0][u]

#  //unordered_map <ll,ll> m;
#  // vector<ll> m,v;
res = 0
def rem( x ) :
    for i in m[x] :
        # //cout<<(*it).first<<" "<<(*it).second<<endl;
        res -= ((res*pcmi[pc[(i)[0]]])%MOD*(i)[1])%MOD
        res = ( res + MOD ) % MOD
        pc[(i)[0] ]-= i[1]
 	
 inline void add(int x,ll &res) :
 {//cout<<"E"<<x;
 	
for(auto it=m[x].begin();it!=m[x].end();it++)
{//cout<<(*it).first<<" "<<(*it).second<<endl;

res+=((res*pcmi[pc[(*it).first]])%MOD*(*it).second)%MOD;
res%=MOD;
pc[(*it).first]+=(*it).second;


}

}

 
inline void check(int x ){
	// If (x) occurs twice, then don't consider it's value 
	//cout<<A[x]<<endl;
	if ( (VIS[x])  ) rem(x);
	else if ( (!VIS[x])  ) add(x);
	VIS[x] ^= 1;
}

 
void compute(){
	
	// Perform standard Mo's Algorithm
	ll curL = Q[0].l, curR = Q[0].l - 1;
    global res 
    res = 1
	
	for (int i = 0; i < M; i++){
		
		while (curL < Q[i].l) check(ID[curL++]);
		while (curL > Q[i].l) check(ID[--curL]);
		while (curR < Q[i].r) check(ID[++curR]);
		while (curR > Q[i].r) check(ID[curR--]);
		
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
	init__modInverse(100005);
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
 
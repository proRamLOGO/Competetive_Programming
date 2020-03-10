#include <bits/stdc++.h>
#define llui long long unsigned int 

using namespace std ;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t ;
    cin>>t;
    while(t--)
    {
        int n,d; cin>>n>>d;
        if(d<=n)
            cout<<"YES"<<endl;
        else
        {
            //int dbyn = ceil(double((double)d/(double)n));
            ////cout<<"DBYN "<<dbyn<<endl;
            //int sum = dbyn + ceil((double)d/(double)(dbyn+1));
            ////cout<<"Sum "<<sum<<endl;
            //if(sum<=n)
            //    cout<<"YES"<<endl;
            //else
            //    cout<<"NO"<<endl;
            int low = 1, high = n-1;
            bool flag=false;
            while(low<high)
            {
                int x = (low+high)/2;
                int sum = x + ceil((double)d/(double)(x+1));
                if(sum <= n)
                {
                    flag = true;
                    break;
                }
                else
                {
                    low = x+1;
                }
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
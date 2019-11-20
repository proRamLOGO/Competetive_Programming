#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif 

	int t;
	cin >> t;
	while(t--) {
	    vector<int> op;
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    int sum=0;
	    for(int i=0;i<n;i++) {
            cin>>arr[i];
            if ( arr[i] >= k )
                op.push_back(arr[i]);
            else
                sum+=arr[i];
	    }
        cout << "hey" ;
	    sort(op.begin(),op.end());
	    for(int i=0;i<op.size()-1;i++)
	    {
	        if(min(op[i],op[i+1])>k)
	        {
	            //op[i]=k;
	            op[i+1]-=(op[i]-k);
	            op[i]=k;
	            
	        }
	        
	    }
	    for(int i=0;i<op.size();i++)
	    sum+=op[i];
	    
	    cout<<sum<<endl;
	}
	return 0;
}

    #include<iostream>
    using namespace std;
    int main()
    {
        long long int t,i,x,y,z,a,b,c;
        cin>>t;
        for(i=0;i<t;i++)
        {
            cin>>x>>y>>z;
            if(x==y)
            {
                if(x>=z)
                {
                    cout<<"YES\n";
                    cout<<x<<" "<<z<<" "<<z<<endl;
                    
                }
                else
                {
                    cout<<"NO\n";
                }
            }
            else if(y==z)
            {
                if(y>=x)
                {
                    cout<<"YES\n";
                    cout<<y<<" "<<x<<" "<<x<<endl;
                }
                else
                {
                    cout<<"NO\n";
                }
            }
            else if(x==z)
            {
                if(x>=y)
                {
                    cout<<"YES\n";
                    cout<<x<<" "<<y<<" "<<y<<endl;
                }
                else
                {
                    cout<<"NO\n";
                }
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
int main()
{
int n,k;
cin>>n>>k;
int x;
map<int,int> m;

for(int i=0;i<n;i++)
{
 cin>>x;
 m[x]++;
}ull a[1020]={0},b[1020]={0},prod[1020]={0},flg=0;
for(auto it=m.begin();it!=m.end();it++)
{
    if(flg==0)
    {
        flg++;
        a[0]=prod[0]=1;
        a[1]=prod[1]=it->second;

    }else
    {
        b[0]=1;
    b[1]=it->second;
    //cout<<b[1]<<endl;
        for(int i=0;;i++)
        {//cout<<"oh!yeah"<<endl;
            if(a[i]==0)
                break;

            for(int j=0;j<2;j++)
            { //cout<<"a"<<i<<": "<<a[i]<<"b"<<j<<":"<<b[j]<<endl;
                prod[i+j]=(prod[i+j]%mod+(a[i]%mod*b[j]%mod)%mod)%mod;
                //cout<<"prod "<<i+j<<" "<<prod[i+j]<<endl;
            }
        }
    }


for(int i=0;i<1010;i++)
{
a[i]=prod[i];    prod[i]=0;
}

}ull ans=0;

for(int i=0;i<=k;i++)
{
    ans=(ans%mod+a[i]%mod)%mod;
    if(a[i]==0)break;
}
cout<<ans<<endl;
    return 0;
}
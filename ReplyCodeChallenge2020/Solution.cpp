#include <bits/stdc++.h>

using namespace std ;

vector<string> ip_map;
vector < vector<int > > op_map;

int width,height,n_dev,n_man;

class dev{
    public:
        string c;
        int b;
        vector<string> s;
        dev(string _c, int _b, vector<string> _s) : s(_s),c(_c),b(_b){}
};

class man{
    public:
        string c;
        int b;
        man(string _c, int _b) : c(_c),b(_b){}
};

vector<dev*> vec_dev;
vector<man*> vec_man;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>width>>height;
    string temp_str;
    for(int i=0; i<height; ++i)
    {
        cin>>temp_str;
        ip_map.push_back(temp_str);
    }
    cin>>n_dev;
    for(int i=0; i<n_dev; ++i)
    {
        string c; int b,n_s; vector<string> ss;
        cin>>c;
        cin>>b;
        cin>>n_s;
        string temps;
        for(int j=0; j<n_s; ++j)
        {
            cin>>temps;
            ss.push_back(temps);
        }
        dev *tempd = new dev(c,b,ss);
        vec_dev.push_back(tempd);
    }
    cin>>n_man;
    for(int i=0; i<n_man; ++i)
    {
        string c; int b;
        cin>>c;
        cin>>b;
        man *temp = new man(c,b);
        vec_man.push_back(temp);
    }

    return 0;
}
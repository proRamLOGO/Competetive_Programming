#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

class library {

public:

    int signuptime, shipcapacity, no_of_books, idx, strength ;
    vector<int> books ;
    unordered_set<int> books_dis ;
    library(void) {
        this->signuptime = 0 ;
        this->shipcapacity = 0 ;
        this->no_of_books = 0 ;
        this->idx = -1 ;
        this->strength =01 ;
    }

    void input(void) {
        cin >> this->no_of_books >> this->signuptime >> this->shipcapacity ;
        for ( int i = 0 ; i < this->no_of_books ; ++i ) {
            int x ;
            cin >> x ;
            this->books.pb(x) ;
            books_dis.insert(x) ;
        }
    }

    void setstrength( vector<int> &scores ) {
        for ( auto i : books_dis ) {
            this->strength += scores[i] ;
        }
    }

    void output( vector<bool> &used, int distinctleft, bool mode, int &newscore, vector<int> &scores ) {
        if ( mode )
            cout << this->idx << ' ' << distinctleft << endl ;
        for ( auto i : this->books ) {
            if ( !used[i] ) {
                newscore += scores[i] ;
                used[i] = true ;
                if ( mode )
                    cout << i << ' ' ;
            }
        }
        if ( mode )
            cout << endl ;
    }

    int check( vector<bool> &used ) {
        int cnt = 0 ;
        for ( auto i : books ) {
            if ( !used[i] )
                ++cnt ;
        }
        return cnt ;
    }


};

class mySort {
    bool charr[4];
    void make_array(bool a, bool b, bool c, bool d, int order)
    {
        for(int i=0; i<4;++i) charr[i]=0; //CLEAR
        int alpha[4] = {0,1,2,3};
        for(int i=0; i<order; ++i)
            next_permutation(alpha, alpha+4);
        for(int i=0; i<4; ++i)
        {
            switch(alpha[i])
            {
                case 0 : charr[i] = a;
                         break;
                case 1 : charr[i] = b;
                         break;
                case 2 : charr[i] = c;
                         break;
                case 3 : charr[i] = d;
                         break;
            }
        }
    }
public:
    int order;  //0 to 23 (24 ways)
    mySort(int o=0){order = o; }
    void setOrder(int o){order = o; }
    bool operator()(const library &l1, const library &l2){
        
        bool chstr=0,chsign=0,chship=0,chno=0;
        if(l1.strength > l2.strength)
            chstr = 1;
        if(l1.signuptime < l2.signuptime)
            chsign = 1;
        if(l1.shipcapacity > l2.shipcapacity)
            chship = 1;
        if(l1.no_of_books > l2.no_of_books)
            chno = 1;
        make_array(chstr,chsign,chship,chno,order);
        for(int i=0; i<4; ++i)
        {
            if(charr[i])
                return true;
        }
        return false;
    }
}mySortObj;

int32_t main(void) {

    #ifndef ONLINE_JUDGE
        freopen("F.txt", "r", stdin) ;
        freopen("F_OUT.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int books, libs, scandays ;
    cin >> books >> libs >> scandays ;
    vector< int > scores(books) ;

    for ( int i = 0 ; i < books ; ++i )
        cin >> scores[i] ;
    
    vector< library > libraries ;

    for ( int i = 0 ; i < libs ; ++i ) {
        library newlib ;
        newlib.input() ;
        newlib.idx = i ;
        newlib.setstrength(scores) ;
        libraries.pb(newlib) ;
    }

    //Here run a loop kinda thing to go through every possible sorting style
    //----------------------------------------------------------------------------------------------------------------------
    
    int bestscore = INT_MIN ;
    int bsorder = -1 ;

    for(int i=0; i<24; ++i) {
        mySortObj.setOrder(i);
        sort(libraries.begin(), libraries.end(), mySortObj);

        vector<bool> book_used(books,false) ;
        int newscore = 0  ;
        for ( auto i : libraries ) {
            
            int distinctleft = i.check(book_used) ;
            if ( distinctleft != 0 ) {
                i.output(book_used, distinctleft, false, newscore, scores) ;
            }

        }
        if ( newscore > bestscore ) {
            bestscore = newscore ;
            bsorder = i ;
        }

    }//----------------------------------------------------------------------------------------------------------------------
    
    //Output

    mySortObj.setOrder(bsorder);
    sort(libraries.begin(), libraries.end(), mySortObj);

    vector<bool> book_used(books,false) ;
    int newscore = 0  ;
    int cnt = 0 ;
    for ( auto i : libraries ) {
        
        int distinctleft = i.check(book_used) ;
        if ( distinctleft != 0 ) {
            i.output(book_used, distinctleft, false, newscore, scores) ;
            ++cnt ;
        }

    }

    fill(book_used.begin(),book_used.end(), false) ;
    
    cout << cnt << endl ;
    for ( auto i : libraries ) {
        
        int distinctleft = i.check(book_used) ;
        if ( distinctleft != 0 ) {
            i.output(book_used, distinctleft, true, newscore, scores) ;
        }

    }

    return 0 ;
    
}


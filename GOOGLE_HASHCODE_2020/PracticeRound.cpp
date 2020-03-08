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

    void output( vector<bool> &used, int distinctleft, bool printallowed ) {
        if ( printallowed )
            cout << this->idx << ' ' << distinctleft << endl ;
        for ( auto i : this->books ) {
            if ( !used[i] ) {
                used[i] = true ;
                if ( printallowed )
                    cout << i << ' ' ;
            }
        }
        if ( printallowed )
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
public:
    bool operator()(const library &l1, const library &l2){
        if(l1.signuptime < l2.signuptime)
            return true;
        if(l1.shipcapacity > l2.shipcapacity)
            return true;
        if(l1.no_of_books > l2.no_of_books)
            return true;
        return false;
    }
}mySortObj;

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("C.txt", "r", stdin) ;
    freopen("C_OUT.txt", "w", stdout) ;
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

    sort(libraries.begin(), libraries.end(), mySortObj);
    
    //Output

    vector<bool> book_used(books,false) ;

    int cnt = 0 ;
    for ( auto i : libraries ) {
        
        int distinctleft = i.check(book_used) ;
        if ( distinctleft != 0 ) {
            i.output(book_used, distinctleft, false) ;
            ++cnt ;
        }

    }

    fill(book_used.begin(),book_used.end(), false) ;
    
    cout << cnt << endl ;
    for ( auto i : libraries ) {
        
        int distinctleft = i.check(book_used) ;
        if ( distinctleft != 0 ) {
            i.output(book_used, distinctleft, true) ;
        }

    }

    return 0 ;
    
}
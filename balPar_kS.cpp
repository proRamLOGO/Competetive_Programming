#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isBalancedParenthesis(string str)
{
    vector<char> stk;
    char s;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stk.push_back(str[i]);
        }

        else
        {
            if (stk.empty()) {
                cout << i << endl ;
                return false;
            }
            s = stk[stk.size()-1] ;
            cout << "s = " << s << endl ;
            switch (str[i])
            {
            case ')':
                if (s == '{' || s == '['){
                    cout << i << endl ;
                    return false;
                }
                stk.pop_back();
                break;
            
            case '}':
                if (s == '(' || s == '['){
                    cout << i << endl ;
                    return false;
                }
                stk.pop_back();
                break;

            case ']':
                if (s == '{' || s == '(') {
                    cout << i << endl ;
                    return false;
                }
                stk.pop_back();
                break;
            
            default:
                stk.pop_back();
                break;
            }
        }

        for ( auto i : stk ) 
            cout << i << " " ;
        cout << endl ;
    } 

    if (stk.empty())
    {
        return true;
    }
    else
    {
        cout << "hey" << endl ;
        return false;
    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string str = "{()}[]";
    string str = "(((((())))))";
    // cin >> str;
    cout <<  isBalancedParenthesis(str);
    return 0;
}

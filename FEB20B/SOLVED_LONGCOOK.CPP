#include <iostream>
#define int long long
using namespace std;
int ar[] = {25, 50, 75, 101};
int p[]={25,25,25,26};


int dow(int d, int m, int y)  
{  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}  

signed main() {    
    int t;
    cin>>t;
    while(t--){
        int m1,y1,m2,y2;
        cin>>m1>>y1>>m2>>y2;
        if(m2==1) y2--;
        if(m1==1 || m1==2) y1--;
            int ans1 = (y1 / 400) * 101;
            
            int ind = (y1 % 400) / 100;
            if (ind != 0) {
                ans1 += ar[ind - 1];
            }
            for (int i = ((y1/100)*100)+1;i<=y1; i++) {                    
                    if (dow(6, 2, i) == 5 && i % 4 != 0) {
                        ++ans1;
                    } else if (dow(7, 2, i) == 5) {
                        ++ans1;
                    }
                }

            
            
            
            int ans2 = (y2 / 400) * 101;
            ind = (y2 % 400) / 100;
            if (ind != 0) {
                ans2 += ar[ind - 1];
            }
            
            for (int i = ((y2/100)*100)+1;i<=y2; i++) {                    
                    if (dow(6, 2, i) == 5 && i % 4 != 0) {
                        ++ans2;
                    } else if (dow(7, 2, i) == 5) {
                        ++ans2;
                    }
                }

       // cout<<"\naaaa";
         cout<<(ans2-ans1)<<endl;
    }
}
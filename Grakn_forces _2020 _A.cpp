#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define moduli 1000000007
#define INF 1000000000000000000
#define int long long int
#define F first
#define S second
#define Pii pair<int,int>
#define Pdi pair<long double,int>

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define R return
#define ld long double

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int maxn = 1001;
int Co[maxn + 1][maxn + 1];
void precompute()
{


  Co[0][0] = 1;
  for (int n = 1; n <= maxn; ++n) {
    Co[n][0] = Co[n][n] = 1;
    for (int k = 1; k < n; ++k)
      Co[n][k] = (Co[n - 1][k - 1] + Co[n - 1][k]) % moduli;

  }

}




// int stringtointer(string a)
// {

//   return stoi(a);
// }
// int countdigit(int a)
// {

//   return log10(a) + 1;
// }


// int factorial(int n)
// {

//   return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
// }

// int floorSqrt(int x)
// {

//   if (x == 0 || x == 1)
//     return x;
//   int start = 1, end = x, ans;
//   while (start <= end)
//   {
//     int mid = (start + end) / 2;
//     if (mid * mid == x)
//       return mid;
//     if (mid * mid < x)
//     {
//       start = mid + 1;
//       ans = mid;
//     }
//     else
//       end = mid - 1;
//   }

//   return ans;
// }



// bool checkpallindrome(string s)
// {


//   string ans = s;

//   reverse(ans.begin(), ans.end());

//   if (ans == s)
//     return true;


//   return false;

// }

// int kadane(int a[], int size)
// {
//   int max_so_far = INT_MIN, max_ending_here = 0;

//   for (int i = 0; i < size; i++)
//   {
//     max_ending_here = max_ending_here + a[i];
//     if (max_so_far < max_ending_here)
//       max_so_far = max_ending_here;

//     if (max_ending_here < 0)
//       max_ending_here = 0;
//   }
//   return max_so_far;
// }



// int calc(int x, int y, int m)
// {
//   int res = 1;



//   if (x == 0) return 0;

//   while (y > 0)
//   {

//     if (y & 1)
//       res = (res * x % m ) % m ;


//     y = y >> 1;
//     x = (x % m * x % m) % m;
//   }


//   return res;

// }


// int gcdExtended(int a, int b, int *x, int *y)
// {
//   // Base Case
//   if (a == 0)
//   {
//     *x = 0, *y = 1;
//     return b;
//   }

//   int x1, y1;
//   int gcd = gcdExtended(b % a, a, &x1, &y1);


//   *x = y1 - (b / a) * x1;
//   *y = x1;

//   return gcd;
// }

// // Function to find modulo inverse of a
// int modInverse(int a, int m)
// {
//   int x, y;
//   int g = gcdExtended(a, m, &x, &y);
//   int res = (x % m + m) % m;
//   return  res;


// }

// vi divisor(int n)
// {

//   vi a;

//   for (int i = 1; i * i <= n; i++)
//   {
//     if (n % i == 0)
//     {
//       a.pb(i);

//       if (i * i != n)
//         a.pb(n / i);
//     }
//   }

//   return a;

// }


// int fenwick[1000001];
// void update(int index, int x, int n)
// {
//   while (index <= n)
//   {
//     fenwick[index] += x;
//     index += (index & (-index));
//   }

// }

// int query(int n, int index)
// {
//   int ans = 0;
//   while (index > 0)
//   {
//     ans += fenwick[index];
//     index -= (index & (-index));
//   }
//   return ans;
// }













// int find(string a, string b)
// {
//   int cnt = 0;
//   for (int i = 0; i < 6; i++)
//   {
//     if (a[i] != b[i])
//       cnt++;
//   }
//   return cnt;
// }

// int calc(vi arr, int i, int a, int b, int &c)
// {
//   int n = arr.size();

//   if (i >= n)
//   {
//     c = max(c, b);
//     return c;
//   }


//   int a1 = max(a, b - arr[i]);
//   int b1 = max(arr[i] + a, b);


//   int ans1 = 0;


//   ans1 = calc(arr, i + 1, a1, b, c);

//   if (b1 != b)
//   {
//     int ans2 = calc(arr, i + 2, a1, b1, c);
//     return max(ans1, ans2);
//   }
//   return  ans1;



// }




vi graph[10009];
vi graph2[10009];
vb visited(10009, false);
vi ans(10009, 0);
int dfs(int si )
{



  for (auto i : graph[si])
  {
    if (visited[i])
    {
      ans[si] += (ans[i] + 1);
      continue;
    }

    int x = dfs(i);
    ans[si] += x;
  }


  return ans[si] + 1 ;



}




void solve(int tc)
{



  int n; cin >> n;
  vi arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vi brr(n);
  for (int i = 0; i < n; i++)
    cin >> brr[i];
  vi c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];


  vi ans(n);

  ans[0] = arr[0];

  for (int i = 1; i < n - 1; i++)
  {
    if (arr[i] != ans[i - 1])
      ans[i] = arr[i];
    else if (brr[i] != ans[i - 1])
      ans[i] = brr[i];
    else
      ans[i] = c[i];
  }


  if (arr[n - 1] != ans[n - 2] && arr[n - 1] != ans[0])
    ans[n - 1] = arr[n - 1];
  else if (brr[n - 1] != ans[n - 2] && brr[n - 1] != ans[0])
    ans[n - 1] = brr[n - 1];
  else
    ans[n - 1] = c[n - 1];

  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;

















}











int32_t main()
{




#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);




  int t = 1;

  cin >> t;
  int tc = 1;


// precompute();
  while (t--)
  {

    solve(tc);


    tc++;
  }
  return 0;
}

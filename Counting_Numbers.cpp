#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define ll long long
#define int ll
#define ld long double
#define INF 1e18
#define nline '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define fo(i,a,b) for(int i = a; i < b ; i ++)
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vst;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int dp[20][10][2][2];

int mem(string s, int curr, int prev_digit,int leading_zero,int tight){
    if(curr==0)
        return 1;
    if(dp[curr][prev_digit][leading_zero][tight]!=-1){
        return dp[curr][prev_digit][leading_zero][tight];
    }
    int limit;
    if(tight==0)
        limit = 9;
    else{
        int sz = s.size();
        limit = s[sz - curr] - 48;
    }

    int countNumbers = 0;
     // Iterate through possible digits for the current position
    for (ll curr_digit = 0; curr_digit <= limit; curr_digit++)
    {
        // Check validity based on constraints
        if (leading_zero == 0 && (curr_digit == prev_digit))
        {
            continue;
        }

        // Update state parameters based on the current digit
        ll new_leading_zero = (leading_zero == 1 && curr_digit == 0) ? 1 : 0;
        ll new_tight = (curr_digit == limit && tight == 1) ? 1 : 0;

        // Recursively call the mem function for the next position
        countNumbers += mem(s, curr - 1, curr_digit, new_leading_zero, new_tight);
    }

    // Update the memoization table with the count of valid numbers for the current state
    dp[curr][prev_digit][leading_zero][tight] = countNumbers;
  
    return dp[curr][prev_digit][leading_zero][tight];
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int count1 = 0;
    memset(dp, -1, sizeof(dp));

    string str1 = to_string(a - 1);
    if(a!=0)
        count1 = mem(str1, str1.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    string str2 = to_string(b);
    int count2 = mem(str2, str2.size(), -1, 1, 1);

    cout << count2 - count1 << endl;
}

signed main() 
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int tc = 1;
    fo(i, 1, tc + 1)
    {
        solve();
    }
}
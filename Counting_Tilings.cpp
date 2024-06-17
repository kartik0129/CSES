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
int dp[1050][2050];
void generateNextMask(int n, int curr_mask, int new_mask, int j, vector<int> &nextMask){
    if(j==n){
        nextMask.push_back(new_mask);
        return;
    }

      if (j + 1 < n && (((1 << j) & (curr_mask)) == 0) && (((1 << (j + 1)) & (curr_mask)) == 0))
    {
        generateNextMask(n, curr_mask, new_mask, j + 2, nextMask);
    }
    // Place a 1x2 tile if the cell is empty
    if ((((1 << j) & (curr_mask)) == 0))
    {
        generateNextMask(n, curr_mask, new_mask + (1 << j), j + 1, nextMask);
    }
    // Move to the next cell if the current cell is already filled
    if ((((1 << j) & (curr_mask)) != 0))
    {
        generateNextMask(n, curr_mask, new_mask, j + 1, nextMask);
    }
}

int countWays(int n, int m, int i, int mask){
    if(i==m){
        if(mask==0)
            return 1;
        return 0;
    }

    if(dp[i][mask]!=-1)
        return dp[i][mask];

    vector<int> nextMask;
    generateNextMask(n, mask, 0, 0,nextMask);

    int ans = 0;
    for(auto x:nextMask){
        ans = (ans % MOD + countWays(n, m, i + 1, x) % MOD) % MOD;
    }

    dp[i][mask] = ans;
    return dp[i][mask];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    cout << countWays(n, m, 0, 0) << endl;
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
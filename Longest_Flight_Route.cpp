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

void mark_dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            mark_dfs(it, vis, adj);
        }
    }
}
int dfs(int node, vector<int> &dp, vector<int> &child, vector<vector<int>> &adj,int n){
    if(node==n)
        return dp[node] = 1;
    if(dp[node]!=-1)
        return dp[node];
    int len = 0;
    for(auto it:adj[node]){
        int tmp = dfs(it, dp, child, adj, n);
        int tmp_len = tmp == 0 ? 0 : 1 + tmp;
        if(tmp_len>len){
            child[node] = it;
            len = tmp_len;
        }
    }
    return dp[node] = len;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    fo(i,0,m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> dp(n + 1, -1);
    vector<int> child(n + 1, 0);
    vector<int> vis(n + 1, 0);
    mark_dfs(1, vis, adj);
    if(!vis[n])
      {  cout << "IMPOSSIBLE" << endl;
          return;
      }
    int ans = dfs(1, dp, child, adj, n);
    vector<int> anss;
    int start = 1;
    while(start){
        anss.push_back(start);
        start = child[start];
    }
    cout << anss.size() << endl;
    fo(i, 0, anss.size()) cout << anss[i] << ' ';
    cout << endl;
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
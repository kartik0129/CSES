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

int start, finish;
void dfs(int node, vector<int> &parent, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            parent[it] = node;
            dfs(it, parent, vis, adj);
            if(start)
                return;
        }
        else if(vis[it]==1){
            finish = node;
            start = it;
            return;
        }
    }
    vis[node] = 2;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    start = 0, finish = 0;
    vector<vector<int>> adj(n + 5);
    fo(i,0,m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> parent(n + 5, -1);
    vector<int> vis(n + 5, 0);
    for (int i = 1; i <= n && !start; i++)
    {
        if(vis[i]==0)
            dfs(i, parent, vis, adj);
        
    }
    if(!start)
        cout << "IMPOSSIBLE" << endl;
    else{
        vector<int> ans;
        ans.push_back(start);
        for (int i = finish; i !=start;i = parent[i]){
            ans.push_back(i);
        }
        ans.push_back(start);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        fo(i, 0, ans.size()) cout << ans[i] << ' ';
        cout << endl;
    }
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
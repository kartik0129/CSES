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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    fo(i,0,n){
        fo(j, 0, m) cin >> graph[i][j];
    }
    int x = -1, y = -1;
    queue<pair<int, int>> q;
    fo(i,0,n){
        fo(j,0,m){
            if(graph[i][j]=='M')
                q.push({i, j});
            else if (graph[i][j]=='A'){
                x = i, y = j;
            }
        }
    }
    q.push({x, y});
    int nex[1005][1005];
    nex[x][y] = -1;
    int fx[4] = {-1, 1, 0, 0};
    int fy[4] = {0, 0, 1, -1};
    char go[4] = {'U', 'D', 'R', 'L'};
    while(q.size()){
        auto [x, y] = q.front();
        q.pop();
        if(graph[x][y]=='A' && (x==0 || y==0 || x==n-1 || y==m-1)){
            cout << "YES" << endl;
            string ans;
            int d = nex[x][y];
            while(d!=-1){
                ans += go[d];
                x -= fx[d];
                y -= fy[d];
                d=nex[x][y];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            cout << ans << endl;
            return;
        }
        for (int k = 0; k < 4;k++){
            int xx = x + fx[k];
            int yy = y + fy[k];
            if(xx<0 || yy<0 || xx>=n || yy>=m || graph[xx][yy]!='.')
                continue;
            graph[xx][yy] = graph[x][y];
            if(graph[xx][yy]=='A')
                nex[xx][yy] = k;
            q.push({xx, yy});
        }
    }
    cout << "NO" << endl;
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
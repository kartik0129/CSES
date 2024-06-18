#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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
#define fo(i, a, b) for (int i = a; i < b; i++)
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
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isValid(int i,int j,vector<vector<char>> &graph, vector<vector<int>> &visited){
    if (i < 0 || j < 0 || i >= graph.size() || j >= graph[0].size() || visited[i][j] || graph[i][j]=='#')
        return 0;
    return 1;
}
void dfs(int i, int j, vector<vector<char>> &graph, vector<vector<int>> &visited)
{
    visited[i][j] = 1;
    fo(k,0,4){
        int newX = i + dx[k];
        int newY = j + dy[k];
        if(isValid(newX,newY,graph,visited)){
            dfs(newX, newY, graph, visited);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    fo(i, 0, n)
    {
        fo(j, 0, m) cin >> graph[i][j];
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (graph[i][j] == '.' && visited[i][j] == 0)
            {
                dfs(i, j, graph, visited);
                count++;
            }
        }
    }
    cout << count << endl;
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
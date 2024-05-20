#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// function to find the number of subarrays with sum = X
ll solve(vector<ll>& arr, ll X, ll N)
{
    // Map to store the frequency of prefix sums
    map<ll, ll> prefSums;

    prefSums[0] = 1;
    ll pref = 0;
    ll cnt = 0;

    // Calculate the prefix sum at every index, and find the
    // count of subarrays with sum = pref - X
    for (int i = 0; i < N; ++i) {
        pref += arr[i];
        cnt += (prefSums[pref - X]);
        prefSums[pref] += 1;
    }
    return cnt;
}

int main()
{
    // Sample Input
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n;i++)
        cin >> arr[i];

    cout << solve(arr, x, n);
    return 0;
}

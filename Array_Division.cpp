#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Function to check if we can divide the array arr[] into K
// subarrays such that each subarray has sum <= mid
bool isValid(ll* arr, ll N, ll K, ll mid)
{
    ll partitions = 1, runningSum = 0;
    // find the number of subarrays such that each subarray
    // has sum <= mid
    for (int i = 0; i < N; i++) {
        runningSum += arr[i];
        if (runningSum > mid) {
            runningSum = arr[i];
            partitions += 1;
        }
    }
    // if the number of subarrays is less than or equal to
    // K, then it means that it is possible to divide arr[]
    // into K subarrays with sum of each subarray <= mid
    return partitions <= K;
}

// function to minimize the maximum sum among all subarrays
ll solve(ll* arr, ll N, ll K)
{
    // Define the lower and upper limit of our answer
    ll low = *max_element(arr, arr + N),
    high = accumulate(arr, arr + N, 0LL);
    ll ans = 0;
    // Binary Search to minimize the maximum sum
    while (low <= high) {
        ll mid = (low + high) / 2;
        // If it is possible to divide the array arr[] into
        // K subarrays such that each subarray has sum <=
        // mid, then we update ans and move high to mid-1
        if (isValid(arr, N, K, mid)) {
            ans = mid;
            high = mid - 1;
        }
        // If it is impossible to divide the array arr[]
        // into K subarrays such that each subarray has sum
        // <= mid, move low to mid+1
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // Sample Input
    ll N = 5, K = 3;
    cin>>N>>K;
    
    ll arr[N] ;
    for(int i=0;i<N;i++)cin>>arr[i];

    cout << solve(arr, N, K);
}

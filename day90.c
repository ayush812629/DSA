// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

// Determine the minimum time required to paint all boards.

// Input Format
// n k
// n space-separated integers representing board lengths

// Output Format
// Print the minimum time required to paint all boards.

// Sample Input
// 4 2
// 10 20 30 40

// Sample Output
// 60

// Explanation
// One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.

#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) return 0;

        if (currTime + arr[i] <= maxTime) {
            currTime += arr[i];
        } else {
            painters++;
            currTime = arr[i];
        }
    }

    return painters <= k;
}

int minTime(int arr[], int n, int k) {
    int low = 0, high = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));
    return 0;
}
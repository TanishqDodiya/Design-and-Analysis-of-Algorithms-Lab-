#include <stdio.h>

int knapsack(int N, int W, int val[], int wt[]) {

    int dp[W + 1];
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < N; i++) {

        for (int w = W; w >= wt[i]; w--) {
            dp[w] = (dp[w] > dp[w - wt[i]] + val[i]) ? dp[w] : dp[w - wt[i]] + val[i];
        }
    }

    return dp[W];
}

int main() {
    int N, W;

    scanf("%d", &N);
    
    int val[N], wt[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &val[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &wt[i]);
    }

    scanf("%d", &W);

    printf("%d\n", knapsack(N, W, val, wt));
    
    return 0;
}


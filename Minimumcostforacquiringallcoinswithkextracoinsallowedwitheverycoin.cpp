void preprocess(int coin[], int n) 
{ 
    sort(coin, coin + n); 
    for (int i = 1; i <= n - 1; i++) 
        coin[i] += coin[i - 1]; 
}  
int minCost(int coin[], int n, int k) 
{ 
    int coins_needed = ceil(1.0 * n / (k + 1)); 
    return coin[coins_needed - 1]; 
} 

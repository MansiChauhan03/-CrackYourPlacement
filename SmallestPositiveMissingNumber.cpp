class Solution
{
    public:
    int partition(int arr[], int n)
    {
    int pind = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) // pivot is 0
        {
            swap(arr[i], arr[pind]);
            pind++;
        }
    }
    return pind;
}

int missingNumber(int arr[], int n)
{
    int k = partition(arr, n);

    for (int i = 0; i < k; i++) {
        int val = abs(arr[i]);

        if (val - 1 < k && arr[val - 1] > 0) {
            arr[val - 1] = -arr[val - 1];
        }
    }

    for (int i = 0; i < k; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return k + 1;
}

};

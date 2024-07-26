class Solution{
public:
long long findPages(int n, int arr[], int m) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if (m > n) {
        return -1;
    }

    long long low = *max_element(arr, arr + n);
    long long high = sum;

    long long ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;

        int students = 1;
        long long curr_sum = 0;

        for (int i = 0; i < n; i++) {
            curr_sum += arr[i];

            if (curr_sum > mid) {
                students++;
                curr_sum = arr[i];
            }
        }

        if (students <= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
 }
};

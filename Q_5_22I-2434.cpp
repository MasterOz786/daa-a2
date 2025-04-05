
#include <iostream>

bool isValid(int* phones, long long n, long long k, long long maxTime) {
    long long shopsUsed = 1;
    long long currentSum = 0;

    for (long long i = 0; i < n; i++) {
        if (phones[i] > maxTime) {
            return false;
        }
        if (currentSum + phones[i] <= maxTime) {
            currentSum += phones[i];
        } else {
            shopsUsed++;
            currentSum = phones[i];
    if (shopsUsed > k) {
        return false;
    }
        
        }
    }   
    
    return true;
}


// findmax
long long maxdhundo(int *arr, long long n) {
    int m = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > m) {
            m = arr[i];
        }
    }

    return m;
    
}

long long sumcalc(int* arr, long long n) {
    long long s = 0;
    for (long long i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}

long long findKumseKumMurammatKaWaqt(int *phones, long long n, long long k) {
    if (n == 0) return 0;
    if (k >= n) {
        return maxdhundo(phones, n);
    }
    long long l = maxdhundo(phones, n);
    long long r = sumcalc(phones, n);
    long long res = r;

    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (isValid(phones, n, k, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        int p[n];
        for (long long i = 0; i < n; i++)
        {
            std::cin >> p[i];
        }
        std::cout << findKumseKumMurammatKaWaqt(p, n, k) << '\n';
    }

    return 0;
}
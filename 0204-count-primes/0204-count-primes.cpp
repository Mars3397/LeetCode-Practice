/*
Brute force approach
1. for number between [2...n] find whether a number in [2...n-1] can divide it
2. if can find -> non prime number, if can't -> prime number
3. time complexity: O(n^2)

Better Approach
1. declare a isPrime boolean vector (all init to true)
2. for every idx i: multiple all numbers in [2...i] -> and set the vector[result] to false
3. only perform this when vector[i] is true
4. time complexity: O(nlogn)?
5. space complexity: O(n)
*/



class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);

        for (int p = 2; p * p < n; ++p) {
            // skip non-prime
            if (isPrime[p] == false) continue;

            for (int m = p*p; m < n; m += p) {
                isPrime[m] = false;
            }
        }

        // count prime
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++count;
        }

        return count;
    }
};
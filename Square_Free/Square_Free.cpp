#include <cstdio>   // For getchar() and printf()
#include <cmath>    // For sqrt()
#include <vector>   // For std::vector
#include <array>    // For std::array

using namespace std;  // Use the standard namespace

constexpr int ML = 31623;  // Maximum limit for generating primes (sqrt(1e9) ~ 31623)
constexpr int MP = 3500;   // Estimated maximum number of primes up to the limit

int main() {
    vector<char> p(ML + 1, true);  // Vector to mark if a number is prime
    p[0] = p[1] = false;  // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes to mark non-prime numbers
    for (int i = 2; i <= ML; ++i) {
        if (p[i]) {
            for (int j = i * i; j <= ML; j += i) {
                p[j] = false;  // Mark multiples of i as non-prime
            }
        }
    }

    array<int, MP> ps;  // Array to store prime numbers
    int pc = 0;  // Count of primes found
    if (ML >= 2) {
        ps.at(pc++) = 2;  // Add 2 as the only even prime number
    }
    for (int i = 3; i <= ML; i += 2) {  // Only check odd numbers starting from 3
        if ((i % 3 == 0 && i != 3) || (i % 5 == 0 && i != 5) || (i % 7 == 0 && i != 7)) {
            continue;
        }
        if (p[i]) {
            ps.at(pc++) = i;
        }
    }

    int N = 0;  // Input number
    char c;     // Variable to store each character read from input

    // Read characters one by one until a non-digit character is encountered
    while ((c = getchar()) != EOF && c != '\n') {
        if (c >= '0' && c <= '9') {
            N = N * 10 + (c - '0');  // Convert character to an integer and build the number
        }
    }

    int lim = static_cast<int>(sqrt(N));
    if (lim > ML) lim = ML;  // Ensure the limit does not exceed ML

    int k = 0;  // Count of distinct prime factors
    int n = N;  // Copy of N to perform factorization

    for (int i = 0; i < pc && ps.at(i) * ps[i] <= n; ++i) {
        if (n % ps[i] == 0) {
            k++;  // Increment distinct prime factor count
            while (n % ps[i] == 0) {
                n /= ps[i];  // Divide n by the prime factor until it is no longer divisible
            }
        }
    }

    if (n > 1) {
        k++;  // Count remaining prime factor
    }

    int res = (1 << k) - 1;  // Calculate number of square-free divisors

    printf("%d\n", res);  // Print the result

    return 0;  // Return zero to indicate successful execution
}
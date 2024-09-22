class Solution
{
public:
#define M 1000000007
    vector<bool> Sieve(long long int n)
    {
        // create a sieve array telling isPrime till 'n'
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;

        /*for (long long int i = 2; i <= n; i++)*/
        for (long long int i = 2; i * i <= n; i++) // Optimisation 2: (Outer loop):
                                                   // if i becomes > sqrt(N), then the
                                                   // inner loop does not work.
        {
            if (sieve[i] == true)
            {
                // means, sieve[i] is Prime and mark its multiples
                //  as non-prime.
                /*long long long long int j = i * 2;*/
                long long int j = i * i; // Optimisation 1 (inner loop):
                                         // first unmarked number would be i*i
                                         // as, other have been marked by 2 to (i - 1).
                while (j <= n)
                {
                    sieve[j] = false;
                    j += i;
                }
            }
        }
        return sieve;
    }

    vector<bool> segmentedSeive(long long int L, long long int R)
    {
        // Get me prime marking array.
        // to be used to mark primes in segmented sieve.
        vector<bool> sieve = Sieve(sqrt(R));
        vector<long long int> basePrimes;
        for (long long int i = 0; i < sieve.size(); i++)
        {
            if (sieve[i])
                basePrimes.push_back(i);
        }

        vector<bool> segSieve(R - L + 1, true);
        if (L == 1)
        {
            segSieve[0] = false;
        }

        for (auto prime : basePrimes)
        {
            long long int first_mul = (L / prime) * prime;
            first_mul = first_mul < L ? first_mul + prime : first_mul;
            long long int j = max(first_mul, prime * prime);
            while (j <= R)
            {
                segSieve[j - L] = false;
                j += prime;
            }
        }
        return segSieve;
    }

    long long primeProduct(long long L, long long R)
    {
        vector<bool> segSieve = segmentedSeive(L, R);
        long long int ans = 1;
        for (long long int i = 0; i < segSieve.size(); i++)
        {
            if (segSieve[i])
            {
                long long int actualPrime = (L + i) % M;
                ans = (ans * actualPrime) % M;
            }
        }
        return ans;
    }
};
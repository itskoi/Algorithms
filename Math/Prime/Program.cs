using System;
using System.Collections.Generic;

namespace Prime
{
    class PrimeNumber {
        // Variables:
        
        // Functions:
        public static void Eratosthenes(int N) {
            // Initialize
            bool[] isPrime = new bool[N + 2];
            for (int i = 2; i <= N; i++) {
                isPrime[i] = true;
            }

            // Sieving
            for (int i = 2; i * i <= N; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= N; j += i) {
                        isPrime[j] = false;
                    }
                }
            }

            // Print result
            for (int i = 2; i <= N; i++) {
                if (isPrime[i]) {
                    Console.WriteLine(i + " ");
                }
            }
        }

        public static int[] minPrime(int N) {
            int[] tmp = new int[N + 2];
            for (int i = 2; i <= N; i++) {
                tmp[i] = -1;
            }
            for (int i = 2; i * i <= N; i++) {
                if (tmp[i] == -1) {
                    for (int j = i * i; j <= N; j += i) {
                        tmp[j] = i;
                    }
                }
            }
            for (int i = 2; i <= N; i++) {
                if (tmp[i] == -1) {
                    tmp[i] = i;
                }
            }
            return tmp;
        }

        public static void EratosthenesRange(long L, long R) {
            bool[] isPrime = new bool[R - L + 1];
            for (long i = 0; i < R - L + 1; i++) {
                isPrime[i] = true;
            }
            for (long i = 2; i * i <= R; i++) {
                for (long j = Math.Max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
                    isPrime[j - L] = false;
                }
            }
            for (long i = Math.Max(2, L); i <= R; i++) {
                if (isPrime[i - L] == true) {
                    Console.WriteLine(i + " is prime");
                } else {
                    Console.WriteLine(i + " isnt prime");
                }
            }
        }

        public static void Factorize(int N) {
            int[] _minPrime = minPrime(N);
            while(N != 1) {
                Console.WriteLine(_minPrime[N]);
                N /= _minPrime[N];
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            PrimeNumber.EratosthenesRange(15, 59);
        }
    }
}

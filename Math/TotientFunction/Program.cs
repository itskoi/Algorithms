using System;

namespace TotientFunction {
    class Totient {
        public static void TotientFunction(int N) {
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
            int result = N;
            // Print result
            for (int i = 2; i <= N; i++) {
                if (isPrime[i] && N % i == 0) {
                    result -= (result / i);
                    while(N % i == 0) {
                        N /= i;
                    }
                }
            }
            Console.WriteLine(result);
        }
    }
    class Program {
        static void Main(string[] agrs) {
            int N = Convert.ToInt32(Console.ReadLine());
            Totient.TotientFunction(N);
        }
    }
}
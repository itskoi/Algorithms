using System;

/* Calculations with Modulo <> Hackerearth
 * (a + b) % c = ((a % c) + (b % c)) % c
 * (a * b) % c = ((a % c) * (b % c)) % c
 * (a - b) % c = ((a % c) - (b % c) + c) % c
 * (a / b) % c = ((a % c) * (b ^ (-1) % c)) % c
 * ----------------------------------------------
 * A.B = 1 (Mod M) |
 * Here B is the modular multiplicative inverse of A under modulo M
 * >>> B = A^ (-1) (Mod M) => B in [1, M - 1]
 * >>> if A and M are coprime: Ax + My = 1 => Extended Euclid to find x (B = x)
 * >>> if M is prime => Fermat's Little Theorem
 *  >> A ^ (M) = A (Mod M) >> A ^ (M - 1) = 1 (Mod M) 
 *  >> A ^ (M - 2) = A ^ (-1) (Mod M)
 */

namespace Modulo
{
    class Modulo {
        // Variables:
        static int x;
        static int y;
        static int gcd;
        // Functions:
        public static long pow(int a, int n, int MOD) {
            if (n == 0) return (1 % MOD);
            long tmp = pow(a, n / 2, MOD) % MOD;
            if ((n & 1) == 1) {
                return ((a % MOD) * ((tmp * tmp) % MOD)) % MOD;
            } else {
                return (tmp * tmp) % MOD;
            }
        }

        public static void extendedEuclid(int A, int B) {
            if (B == 0) {
                gcd = A;
                x = 1;
                y = 0;
            } else {
                extendedEuclid(B, A % B);
                int tmp = x;
                x = y;
                y = tmp - (A / B) * y;
            }
        }

        public static int findInverse(int A, int MOD) {
            extendedEuclid(A, MOD);
            return (x + MOD) % MOD;
        }

        public static void run() {
            int A, B, C, M;
            string input = Console.ReadLine();
            A = Convert.ToInt32(input.Split(' ')[0]);
            B = Convert.ToInt32(input.Split(' ')[1]);
            C = Convert.ToInt32(input.Split(' ')[2]);
            M = Convert.ToInt32(input.Split(' ')[3]);
            long result = (pow(A, B, M) * findInverse(C, M)) % M;
            Console.WriteLine(result);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Modulo.run();
        }
    }
}

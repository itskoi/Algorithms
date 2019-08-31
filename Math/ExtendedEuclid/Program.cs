using System;

namespace ExtendedEuclid {
    class ExtendedEuclid {
        // Variables:
        static int x;
        static int y;
        static int gcd;

        // Functions:
        public static void extendedEuclid(int A, int B) {
            findGCD(A, B);
            printResult(A, B);
        }
        public static void findGCD(int A, int B) {
            if (B == 0) {
                gcd = A;
                x = 1;
                y = 0;
            } else {
                findGCD(B, A % B);
                int tmp = x;
                x = y;
                y = tmp - (A / B) * y;
            }
        }
        public static void printResult(int A, int B) {
            Console.WriteLine("GCD of {0} and {1}: {2}", A, B, gcd);
            Console.WriteLine("Coefficents x and y are: {0} and {1}", x, y);
        }

    }
    class Program {
        static void Main(string[] args) {
            ExtendedEuclid.extendedEuclid(16, 10);
            Console.ReadLine();
        }
    }
}

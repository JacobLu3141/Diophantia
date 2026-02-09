#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include "class.h"
using namespace std;

int euler(int m) {
    int n = m, phi = m;
    vector<int> primes = {};

    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            primes.push_back(i);
        }

        while (n % i == 0) n /= i;
    }

    for (int i = 2; i <= m; i++) phi *= (1 - 1.0 / primes[i]);
    
    return phi;
}

int modPower(int a, int b, int m) {
    int c = b, e = a, n = 1;
    vector<int> sum = {}, powers = {};

    if (b == 0) {
        cout << endl << a << "^" << b << " == 1 (mod " << m << ")";
        return 1; 
    }
    else {
        cout << endl << b << " = ";

        while (c > 0) {
            int d = pow(2, floor(log(c) / log(2)));

            cout << d;
            c -= d;
            sum.push_back(d);

            if (c > 0) cout << " + ";
        }

        cout << endl << endl;

        for (int i = 0; i < floor(log(b) / log(2)) + 1; i++) {
            powers.push_back(e % m);

            cout << a << "^" << pow(2, i) << " == ";
            
            if (i > 0) cout << round(pow(e, 0.5)) << "^2 = " << e << " == ";
            
            cout << e % m << " (mod " << m << ")\n";

            e %= m;
            e *= e;
        }

        cout << "\n" << a << "^" << b << " = ";

        for (int i = 0; i < sum.size(); i++) {
            cout << a << "^" << sum[i];

            if (i < sum.size() - 1) cout << " * ";
        }

        cout << "\n\n" << a << "^" << b << " == ";

        for (int i = 0; i < sum.size(); i++) {
            cout << powers[log(sum[i]) / log(2)];
            n *= powers[log(sum[i]) / log(2)];

            if (i < sum.size() - 1) cout << " * ";
        }

        cout << " = " << n << " == " << n % m << " (mod " << m << ")";
        return n % m;
    }
}

int diyModPower(int a, int b, int m) {
    int c = b, d, e = a, n = 1;
    string text;
    vector<int> sum = {}, powers = {};

    if (b == 0) {
        cout << a << "^" << b << " == 1 (mod " << m << ")";
        return 1; 
    }
    else {
        cout << "Question: what is " << a << "^" << b << " (mod " << m << ")?\n\n";

        while (c > 0) {
            d = pow(2, floor(log(c) / log(2)));

            text = "What is the largest binary number less than or equal to " + to_string(c) + "? ";
            question(text, d);

            cout << c << " - " << d << " = " << c - d << endl;
            c -= d;
            sum.push_back(d);
        }

        cout << endl << b << " = ";

        for (int i = 0; i < sum.size(); i++) {
            cout << sum[i];
            if (i < sum.size() - 1) cout << " + ";
        }

        cout << endl << endl;

        for (int i = 0; i < floor(log(b) / log(2)) + 1; i++) {
            text = to_string(a) + "^" + to_string(int(pow(2, i))) + " == ";
            
            if (i > 0) text += to_string(int(pow(e, 0.5))) + "^2 == ";

            text += "? (mod " + to_string(m) + "): ";

            powers.push_back(e % m);
            question(text, e % m);

            e %= m;
            e *= e;
        }

        cout << "\n" << a << "^" << b << " = ";

        for (int i = 0; i < sum.size(); i++) {
            cout << a << "^" << sum[i];

            if (i < sum.size() - 1) cout << " * ";
        }

        cout << "\n\n" << a << "^" << b << " == ";

        for (int i = 0; i < sum.size(); i++) {
            cout << powers[log(sum[i]) / log(2)];
            n *= powers[log(sum[i]) / log(2)];

            if (i < sum.size() - 1) cout << " * ";
        }

        cout << " = " << n << " == " << n % m << " (mod " << m << ")";
        return n % m;
    }
}

void eulerExp(int a, int b, int m) {
    int n = m, phi = m, p;
    vector<int> primes = {};

    cout << "\nPrime factors of " << m << ": ";
    
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            cout << i << " ";
        }

        while (n % i == 0) n /= i;
    }

    cout << endl << "phi(" << m << ") = " << m;

    for (int i = 0; i < primes.size(); i++) {
        cout << "(" << primes[i] - 1 << "/" << primes[i] << ")";
        phi *= (1 - 1.0 / primes[i]);
    }

    cout << " = " << phi << "\n\n" << a << "^" << b << " == " << a << "^(" << b << " % " << phi << ") = " << a << "^"
    << b % phi << " (mod " << m << ")\n" << miniFresh;

    p = modPower(a, b % phi, m);

    cout << endl << miniFresh << "\nTherefore, " << a << "^" << b << " == " << p << " (mod " << m << ").";
}

void diyEulerExp(int a, int b, int m) {
    int n = m, phi = m, p;
    vector<int> primes = {};

    cout << "Question: what is " << a << "^" << b << " (mod " << m << ")?\n\n";

    cout << "Prime factors of " << m << ": ";
    
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            cout << i << " ";
        }

        while (n % i == 0) n /= i;
    }

    cout << endl << "phi(" << m << ") = " << m;

    for (int i = 0; i < primes.size(); i++) {
        cout << "(" << primes[i] - 1 << "/" << primes[i] << ")";
        phi *= (1 - 1.0 / primes[i]);
    }

    question(" = ", phi);

    cout << endl << a << "^" << b << " == " << a << "^(" << b << " % " << phi << ") = " << a << "^? (mod " << m;
    question(") ", b % phi);
    cout << miniFresh << endl;

    p = diyModPower(a, b % phi, m);
    cout << endl << miniFresh << "\nTherefore, " << a << "^" << b << " == " << p << " (mod " << m << ").";
}

class Arithmetic : public Lesson {
    public:
        void print() override {
            cout << "Modular addition, subtraction, multiplication, and division are very basic ideas in modular arithmetic; "
                 << "the only step that is different from first grade arithmetic is finding the result modulo m for any "
                 << "given value of m. For example, 4 * 7 == 3 (mod 5), since 4 * 7 = 28, and 28 divided by 5 yields a "
                 << "remainder of 3.\n\nSome important rules to know are: if a is congruent b (mod m) or a == b (mod m); that "
                 << "is to say a / m and b / m yield the same remainder, then for any integer value of k: a + k == b + k "
                 << "(mod m), a - k == b - k (mod m), ak == bk (mod m), and a^k == b^k (mod m). Additionally, if c == d "
                 << "(mod m), then a + b == c + d (mod m), a - b == c - d (mod m), ab = cd (mod m).\n" << fresh;
        }

        void dem() override {
            int a, b, m;

            cout << fresh << "Enter three non-zero integers for a, b, and m, separated by spaces (it is recommended that "
                 << "m be smaller than both a and b): ";
            cin >> a >> b >> m;

            if (a == 0 || b == 0 || m == 0) cout << "\nSorry, at least one of your values is zero.";
            else
                cout << endl << a << " * " << b << " (mod " << m << ") = " << a % m << " * " << b % m << " (mod " << m 
                << ") = " << a % m * (b % m) << " (mod " << m << ") = " << a * b % m << " (mod " << m << ").";

            cout << endl << fresh;
        }
        
        void ex() override {
            int a, b, m = rand() % 6 + 5;

            do {
                a = rand() % 91 + 10;
            } while (a % m == 0);

            do {
                b = rand() % 91 + 10;
            } while (b % m == 0);
            
            cout << fresh << "Question: what is " << a << " * " << b << " (mod " << m << ")?\n\n";

            string aModM = "What is " + to_string(a) + " (mod " + to_string(m) + ")? ";
            string bModM = "What is " + to_string(b) + " (mod " + to_string(m) + ")? ";
            string axb = "What is " + to_string(a % m) + " * " + to_string(b % m) + "? ";
            string cModM = "What is " + to_string(a % m * (b % m)) + " (mod " + to_string(m) + ")? ";

            question(aModM, a % m);
            question(bModM, b % m);
            question(axb, a % m * (b % m));
            question(cModM, a % m * (b % m) % m);

            cout << "\nTherefore, " << a << " * " << b << " == " << a % m * (b % m) % m << " (mod " << m << ").\n" << fresh;
        }
};

class Exponentiation : public Lesson {
    public:
        void print() override {
            cout << "Modular exponentiation is a slightly more advanced version of multiplication; it involves writing the "
                 << "exponent as a sum of squares and rewriting the power as a product of powers with binary exponents. "
                 << "This idea is known as exponentiation by squaring, and you will see in the exploration activity why it "
                 << "works so well.\n" << fresh;
        }

        void dem() override {
            int a, b, m, n;

            cout << fresh << "Enter three non-zero integers for a, b, and m (b must be positive), separated by spaces (try "
                 << "to keep m under 100): ";
            cin >> a >> b >> m;

            if (a == 0 || b <= 0 || m == 0) cout << "\nSorry, at least one of your values is invalid.";
            else n = modPower(a, b, m);

            cout << endl << fresh;
        }
        
        void ex() override {
            int a = rand() % 6 + 5, b = rand() % 240 + 16, m, n;

            do {
                m = rand() % 6 + 5;
            } while (__gcd(a, m) != 1);

            cout << fresh;
            n = diyModPower(a, b, m);
            cout << endl << fresh;
        }
};

class Euler : public Lesson {
    public:
        void print() override {
            cout << "Fermat's little theorem states that for all prime numbers p, a^(p - 1) == 1 (mod p). The generalized " 
                 << "version of this theorem is the Euler's theorem, which requires one to know Euler's totient function: "
                 << "phi(m), which returns the number of positive integers below m that are coprime to m. This can be "
                 << "calculated by finding every prime factor of m, taking (1 - 1/p) for every prime factor p, multiplying "
                 << "the results, and multiplying the final product by m.\n\nEuler's theorem states that for any coprime "
                 << "values of a and m, a^phi(m) == 1 (mod m). This idea can be used to greatly reduce the b value when "
                 << "solving a^b (mod m), knowing that a^b == a^(b % phi(m)) (mod m). By doing this, the entire process "
                 << "of modular exponentiation becomes easier in terms of computation.\n\nVERY IMPORTANT: a and m MUST be "
                 << "coprime for this to work. Otherwise, the exponentiation by squaring technique must be used WITHOUT "
                 << "the help of Euler's theorem." << fresh;
        }

        void dem() override {
            int a, b, m;

            cout << fresh << "Enter three positive integers for a, b, and m (a and m must be coprime), separated by spaces "
                 << "(try to keep m under 100): ";
            cin >> a >> b >> m;

            if (a <= 0 || b <= 0 || m <= 0) cout << "\nSorry, at least one of your values is invalid.";
            else if (__gcd(a, m) != 1) cout << "\nSorry, " << a << " and " << m << " are not coprime.";
            else eulerExp(a, b, m);

            cout << endl << fresh;
        }
        
        void ex() override {
            int a = rand() % 6 + 10, b = rand() % 240 + 16, m;

            do {
                m = rand() % 6 + 5;
            } while (__gcd(a, m) != 1 || b % euler(m) == 0);

            cout << fresh;
            diyEulerExp(a, b, m);
            cout << endl << fresh;
        }
};

void modExp() {
    int number;
    ofstream fout;
    
    fout.open("questions.txt", fstream::app);

    Arithmetic arithmetic;
    Exponentiation exponentiation;
    Euler euler;

    arithmetic.miniLesson();
    exponentiation.miniLesson();
    euler.miniLesson();

    cout << "How many questions (0 to 10) would you like to add to your question bank? ";
    cin >> number;

    for (int i = 0; i < max(0, min(number, 10)); i++) {
        fout << "What is " << rand() % 16 + 5 << "^" << rand() % 240 + 16 << " (mod " << rand() % 16 + 5 << ")?";
        fout << endl;
    }

    system("clear");
    fout.close();
}

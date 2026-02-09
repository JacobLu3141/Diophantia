#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "class.h"
using namespace std;

void gcf(int a, int b) {
    cout << a << " % " << b << " = " << a % b << endl;

    if (a % b == 0)
        cout << "\nThe GCF is " << b << ".";
    else
        return gcf(b, a % b);
}

void diyGcf(int a, int b) {
    string text = to_string(a) + " % " + to_string(b) + " = ";

    question(text, a % b);

    if (a % b == 0) {
        question("\nThe GCF is ", b);
    }
    else
        diyGcf(b, a % b);
}

void extGcf(int a, int b, int c, int *x, int *y, bool first) {
    string input;

    if (first) {
        c = a;
        gcf(max(a, b), min(a, b));
        cout << "\n\nPress enter to continue: ";
        getline(cin, input);
        getline(cin, input);
        cout << miniFresh << endl;
    }

    if (a == 0) {
        *x = 0;
        *y = 1;
    }
    else {
        int x1, y1;

        extGcf(b % a, a, c, &x1, &y1, false);

        *x = y1 - (b / a) * x1; 
        *y = x1; 
    
        cout << b << " % " << a << " = " << b % a << "\n\na = " << a << ", b = " << b << "\nx = " << x1 << ", y = " << y1
             << "\n\nNew x = y - [b/a] * x = " << *x << "\nNew y = x = " << *y << "\n\nPress enter to continue: ";
        getline(cin, input);
        cout << miniFresh << endl;

        if (a == c)
            cout << "Conclusion:\n\nThe integer solutions of the equation " << a << "x + " << b << "y = " << __gcd(a, b)
                 << " are (" << *x << ((*x > 0) ? " - " : " + ") << a << "k, " << *y << ((*x > 0) ? " + " : " - ") << b
                 << "k), for all integers k.";
    }
}

void diyExtGcf(int a, int b, int c, int *x, int *y, bool first) {
    string input;

    if (first) {
        c = a;
        diyGcf(max(a, b), min(a, b));
        cout << miniFresh << endl;
    }

    if (a == 0) {
        *x = 0;
        *y = 1;
    }
    else {
        int x1, y1;

        diyExtGcf(b % a, a, c, &x1, &y1, false);

        *x = y1 - (b / a) * x1;
        *y = x1; 

        cout << b << " % " << a << " = " << b % a << "\n\na = " << a << ", b = " << b << "\nx = " << x1 << ", y = " << y1;
        question("\n\nNew x = y - [b/a] * x = ", *x);
        question("New y = x = ", *y);
        cout << miniFresh << endl;

        if (a == c)
            cout << "Conclusion:\n\nThe integer solutions of the equation " << a << "x + " << b << "y = " << __gcd(a, b)
                 << " are (" << *x << ((*x > 0) ? " - " : " + ") << a << "k, " << *y << ((*x > 0) ? " + " : " - ") << b
                 << "k), for all integers k.";
    }
}

class Bezout : public Lesson {
    public:
        void print() override {
            cout << "A Diophantine equation consists of more than one variable (in this module we will only be looking at "
                 << "two-variable equations) with the intention of finding all integer solutions. Linear Diophantine "
                 << "equations are usually modeled as ax + by = c (or ax + by + c = 0), where a, b, and c are constant "
                 << "non-zero integers.\n\nBézout's identity states that ax + by = c has integer solutions for (x, y), where "
                 << "a, b, and c are non-zero integers, if and only if c is divisible by the GCF of a and b.\n" << fresh;
        }

        void dem() override {
            int a, b, c, d;

            cout << fresh << "Enter three non-zero integers for a, b, and c, separated by spaces: ";
            cin >> a >> b >> c;
            d = __gcd(a, b);
            cout << endl;

            if (a == 0 || b == 0 || c == 0) {
                cout << "Sorry, at least one of your values is zero.\n" << fresh;
            }
            else {
                cout << "The GCF of " << a << " and " << b << " is " << d << ". Since " << c << " is "
                     << ((c % d == 0) ? "" : "not ") << "divisible by " << d << ", " << a << "x + " << b << "y = " << c
                     << ((c % d == 0) ? " has " : " does not have ") << "integer solutions for (x, y).\n" << fresh;
            }
        }
        
        void ex() override {
            int a = rand() % 91 + 10, b = rand() % 91 + 10, c = rand() % 10 + 1, d = __gcd(a, b);
            string gcf = "What is the GCF of " + to_string(a) + " and " + to_string(b) + "? ";
            string div = "Is " + to_string(c) + " divisible by " + to_string(d) + "? (enter 1 for yes or 0 for no) ";

            cout << fresh << "Question: does " << a << "x + " << b << "y = " << c << " have integer solutions for (x, y)?\n\n";
            question(gcf, d);
            cout << endl;
            question(div, (c % d == 0));
            cout << "\nTherefore, " << a << "x + " << b << "y = " << c << ((c % d == 0) ? " has " : " does not have ")
                 << "integer solutions for (x, y).\n" << fresh;
        }
};

class EuclidAlg : public Lesson {
    public:
        void print() override {
            cout << "Sometimes, especially with large numbers, it can be difficult to find the GCF of two numbers, even with "
                 << "the help of a calculator. Fortunately, there is a very efficient algorithm used both by computers and "
                 << "by humans to find GCF, known as the Euclidean algorithm. Here is how it works: \n\nIf either number is "
                 << "negative, its absolute value is taken. If the two numbers are equal, the GCF is equal to the two "
                 << "numbers. Otherwise, the larger number is divided by the smaller, and the remainder is taken (this is "
                 << "known as the modulo operation, or %). Then the smaller number is divided by the remainder, and once "
                 << "again the remainder is taken. This repeats until the remainder reaches zero, and the divisor is the GCF "
                 << "we are looking for.\n" << fresh;
        }

        void dem() override {
            int a, b;

            cout << fresh << "Enter two non-zero integers for a and b, separated by a space: ";
            cin >> a >> b;
            cout << endl;

            if (a == 0 || b == 0) cout << "Sorry, at least one of your values is zero.";
            else gcf(max(a, b), min(a, b));

            cout << endl << fresh;
        }
        
        void ex() override {
            int a = rand() % 91 + 10, b = rand() % 91 + 10;
            
            cout << fresh << "Question: what is the GCF of " << a << " and " << b << "?\n\n";
            diyGcf(max(a, b), min(a, b));
        }
};

class ExtEuclidAlg : public Lesson {
    public:
        void print() override {
            cout << "Being able to find GCF with the Euclidean algorithm is pretty cool, but it's not the only thing that "
                 << "it's used for! Remember the first lesson about Bézout's identity, which states the conditions of "
                 << "a, b, and c for ax + by = c to have integer (x, y) solutions (just to review, c must be divisible by "
                 << "GCF(a, b))? Well you can find said solutions through what's called the extended Euclidean algorithm. "
                 << "This idea is often used to find modular inverses and apply the Chinese remainder theorem.\n\n"
                 << "The extended version starts with the original Euclidean algorithm, and initially x = 0 and y = 1. The "
                 << "x and y values are modified using every equation in the original Euclidean algorithm, and the final "
                 << "values one of the solutions for (x, y). From there, solutions can be generated by adding ak to x and "
                 << "subtracting bk from y for any integer k.\n\nA proper explanation of the extended Euclidean algorithm "
                 << "would be practically impossible to understand without a demonstration, so it is highly recommended to "
                 << "learn it through experimenting with the given exploration activity, which can find all integer "
                 << "solutions of the equation ax + by = GCF(a, b) for any values of a and b.\n" << fresh;
        }

        void dem() override {
            int x, y, a, b;

            cout << fresh << "Enter two non-zero integers for a and b, separated by a space: ";
            cin >> a >> b;
            cout << endl;

            if (a == 0 || b == 0) {
                cout << "Sorry, at least one of your values is zero.";
            }
            else {
                extGcf(a, b, a, &x, &y, true);
            }

            cout << endl << fresh;
        }
        
        void ex() override {
            int a = rand() % 91 + 10, b = rand() % 91 + 10, x, y;
            
            cout << fresh << "Question: what is the GCF of " << a << " and " << b << "?\n\n";
            diyExtGcf(a, b, a, &x, &y, true);
            cout << endl << fresh;
        }
};

void linearDioEq() {
    int number, a, b;
    ofstream fout;
    
    fout.open("questions.txt", fstream::app);

    Bezout bezout;
    EuclidAlg euclidAlg;
    ExtEuclidAlg extEuclidAlg;
    bezout.miniLesson();
    euclidAlg.miniLesson();
    extEuclidAlg.miniLesson();

    cout << "How many questions (0 to 10) would you like to add to your question bank? ";
    cin >> number;

    for (int i = 0; i < max(0, min(number, 10)); i++) {
        a = rand() % 91 + 10;
        b = rand() % 91 + 10;

        fout << "What are the solutions to " << a << "x + " << b << "y = " << __gcd(a, b) << "?";
        fout << endl;
    }

    system("clear");
    fout.close();
}

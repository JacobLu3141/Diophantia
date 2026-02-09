#include <iostream>
#include <fstream>
#include "linear.h"
#include "modExp.h"
using namespace std;

int main() {
    srand(time(0));

    string option, question, clear;
    ifstream bank;

    do {
        cout << "IMPORTANT: you will only ever have to enter integer values throughout this program. NEVER enter "
             << "non-integer values where integer input is required.\n\n"
             << "Welcome to Diophantia! Learn number theory through an assortment of lessons, demonstrations, and exercises. "
             << "Here is Diophantia's syllabus: \n\nUnit 1: Linear Diophantine Equations\n- Bézout's Identity\n- Euclidean "
             << "Algorithm\n- Extended Euclidean Algorithm\n\nUnit 2: Modular Exponentiation\n- Introduction to Modular "
             << "Arithmetic\n- Exponentiation by Squaring\n- Euler's Theorem\n\nEnter:\n\n1 - Unit 1\n2 - Unit 2\n3 - Open "
             << "your question bank\nAny other key - Exit the program\n\n";
        
        cin >> option;
        system("clear");
    
        if (option == "1") {
            linearDioEq();
        }
        else if (option == "2") {
            modExp();
        }
        else if (option == "3") {
            bank.open("questions.txt");

            while (getline(bank, question)) cout << question << endl;

            bank.close();

            cout << fresh << "Press 0 to empty your question bank, or press any other key to return to the main "
                 << "menu. ";
            cin >> clear;

            if (clear == "0") bank.open("questions.txt", ios::out | ios::trunc);
            
            bank.close();
            system("clear");
        }
    } while (option == "1" || option == "2" || option == "3");

    bank.open("questions.txt", ios::out | ios::trunc);
    bank.close();
}

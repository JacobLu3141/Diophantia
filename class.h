#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <stdlib.h>
using namespace std;

string options = "Enter 1 to explore this idea, enter 2 to try an exercise, or enter any other key to move forward. ";
string fresh = "\n--------------------------------------------------\n\n";
string miniFresh = "------------------------------";

void question(string text, int answer) {
    int input;

    cout << text;
    cin >> input;

    if (input != answer)
        cout << "Incorrect. The answer is " << answer << ".\n";
}

class Lesson {
    public:
        virtual void print() = 0, dem() = 0, ex() = 0;

        void miniLesson() {
            string response;

            print();

            do {
                cout << options;
                cin >> response;

                if (response == "1") {
                    dem();
                }
                else if (response == "2") {
                    ex();
                }
            } while (response == "1" || response == "2");
            
            system("clear");
        }
};

#endif

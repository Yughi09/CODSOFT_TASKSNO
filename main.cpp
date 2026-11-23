// CODSOFT C++ Internship - Task 1: Number Guessing Game
#include <iostream>
#include <random>
#include <limits>
using namespace std;

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout << "Invalid input. Please enter a whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    const int MIN = 1, MAX = 100;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(MIN, MAX);

    char again;
    do {
        int secret = dist(gen);
        int attempts = 0;
        int guess;

        cout << "\n=== Number Guessing Game ===\n";
        cout << "I'm thinking of a number between " << MIN << " and " << MAX << ".\n";

        do {
            guess = readInt("Enter your guess: ");
            attempts++;
            if (guess < secret)
                cout << "Too low! Try again.\n";
            else if (guess > secret)
                cout << "Too high! Try again.\n";
            else
                cout << "Correct! You guessed it in " << attempts << " attempt(s).\n";
        } while (guess != secret);

        cout << "Play again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
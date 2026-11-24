#include <iostream>
using namespace std;
char b[9];
void show() {
    for (int i = 0; i < 9; i++)
        cout << ' ' << b[i] << (i % 3 == 2 ? (i < 8 ? "\n---+---+---\n" : "\n") : " |");
}
bool win(char p) {
    int w[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (auto& l : w) if (b[l[0]] == p && b[l[1]] == p && b[l[2]] == p) return true;
    return false;
}
int main() {
    char again;
    do {
        for (int i = 0; i < 9; i++) b[i] = '1' + i;
        char p = 'X'; int moves = 0;
        while (true) {
            show();
            int m = 0;
            cout << "Player " << p << ", enter move (1-9): ";
            if (!(cin >> m)) { cin.clear(); cin.ignore(1000, '\n'); }
            if (m < 1 || m > 9 || b[m-1] == 'X' || b[m-1] == 'O') { cout << "Invalid move!\n"; continue; }
            b[m-1] = p; moves++;
            if (win(p)) { show(); cout << "Player " << p << " wins!\n"; break; }
            if (moves == 9) { show(); cout << "It's a draw!\n"; break; }
            p = (p == 'X') ? 'O' : 'X';
        }
        cout << "Play again? (y/n): "; cin >> again;
    } while (again == 'y' || again == 'Y');
}

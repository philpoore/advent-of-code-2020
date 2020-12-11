/*
https://adventofcode.com/2020/day/5
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pos {
    int row;
    int col;
};

Pos ticket_to_pos(string ticket) {
    int a = 1;
    Pos pos = {0, 0};
    for (int i = 6; i >= 0; i--) {
        if (ticket[i] == 'B') {
            pos.row += a;
        }
        a *= 2;
    }
    a = 1;
    for (int i = 9; i >= 7; i--) {
        if (ticket[i] == 'R') {
            pos.col += a;
        }
        a *= 2;
    }
    return pos;
}

int main() {
    string line;
    int maxSeatID = -1;
    while (!cin.eof()) {
        cin >> line;
        Pos pos = ticket_to_pos(line);
        int seatID = (pos.row * 8) + pos.col;
        cout << "ticket: " << line 
            << " pos: row=" << pos.row 
            << " col=" << pos.col 
            << " seatID:" << seatID << "\n";
        if (seatID > maxSeatID) {
            cout << "ticket: " << line << "\n";
            maxSeatID = seatID;
        }
    }
    cout << "max seat id: " << maxSeatID << "\n";
    return 0;
}
/*
https://adventofcode.com/2020/day/5
*/
#include "../common.hpp"

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
    map<int, bool> seats;
    while (!cin.eof()) {
        cin >> line;
        Pos pos = ticket_to_pos(line);
        int seatID = (pos.row * 8) + pos.col;
        seats[seatID] = true;
    }
    int last = -1;
    for (auto& seat : seats) {
        if (last != -1 && seat.first - last > 1) {
            int missing = last + 1;
            debug(missing);
        }
        last = seat.first;
    }
    return 0;
}
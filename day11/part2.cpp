/*
https://adventofcode.com/2020/day/11
*/
#include "../common.hpp"

enum { FLOOR, SEAT, PERSON };

int num_visible_occupied(vector<vector<int>> &layout, int height, int width, int x, int y) {
    int occupied = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= width) continue;
            if (ny < 0 || ny >= height) continue;
            while (layout[ny][nx] == FLOOR) {
                nx += dx;
                ny += dy;
                if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                    break;
                }
            }
            if (nx < 0 || nx >= width) continue;
            if (ny < 0 || ny >= height) continue;
            if (layout[ny][nx] == PERSON) occupied++;
        }
    }
    return occupied;
}

void display_layout(vector<vector<int>> layout) {
    cout << "------- display -------\n";
    for (auto& row : layout) {
        string line = "";
        for (auto& a : row) {
            if (a == FLOOR) {
                line += '.';
            } else if (a == SEAT) {
                line += 'L';
            } else if (a == PERSON) {
                line += '#';
            } else {
                line += '?';
            }
        }
        cout << line << "\n";
    }
    cout << "-----------------------\n";
}

int main() {
    vector<vector<int>> layout;

    // Parse input layout.
    while(!cin.eof()) {
        string line;
        cin >> line;
        vector<int> row;
        for (char c : line) {
            if (c == '.') {
                row.push_back(FLOOR);
            } else if (c == 'L') {
                row.push_back(SEAT);
            } else if (c == '#') {
                // Shouldn't be needed, layout given with no people.
                row.push_back(PERSON);
            } else {
                cout << "Unknown char in layout: " << c << "\n";
                exit(1);
            }
        }
        layout.push_back(row);
    }
    int height = layout.size();
    int width = layout[0].size();
    debug(height);
    debug(width);
    display_layout(layout);

    // Simulate rules of layout.
    bool somethingChanged = false;
    int total_occupied = 0;
    do {
        vector<vector<int>> layout_copy = layout;
        somethingChanged = false;
        total_occupied = 0;
        // display_layout(layout);
        for (int y = 0; y < layout.size(); y++) {
            for (int x = 0; x < layout[0].size(); x++) {
                int curr = layout[y][x];
                if (curr == FLOOR) continue;

                int num = num_visible_occupied(layout, height, width, x, y);
                if (curr == PERSON) total_occupied++;
                if (curr == PERSON && num >= 5) {
                    somethingChanged = true;
                    layout_copy[y][x] = SEAT;
                } else if (curr == SEAT && num == 0) {
                    somethingChanged = true;
                    layout_copy[y][x] = PERSON;
                }
            }
        }

        layout = layout_copy;
    } while(somethingChanged);

    // display final layout
    display_layout(layout);
    debug(total_occupied);
}
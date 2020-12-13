/*

*/
#include "../common.hpp"

struct Pos {
    int x;
    int y;
};

int main() {
    Pos waypoint = {10, 1};
    Pos ship = {0, 0};
    while(!cin.eof()) {
        char c;
        int value;
        cin >> c;
        if (cin.eof()) break;
        debug(c);
        if (c == 'N') { cin >> value; waypoint.y += value;}
        if (c == 'S') { cin >> value; waypoint.y -= value;}
        if (c == 'E') { cin >> value; waypoint.x += value;}
        if (c == 'W') { cin >> value; waypoint.x -= value;}
        if (c == 'R') {
            cin >> value;
            value /= 90;
            if (value == 1) { waypoint = {waypoint.y, -waypoint.x}; }
            if (value == 2) { waypoint = {-waypoint.x, -waypoint.y}; }
            if (value == 3) { waypoint = {-waypoint.y, waypoint.x}; }
        }
        if (c == 'L') {
            cin >> value;
            value /= 90;
            if (value == 1) { waypoint = {-waypoint.y, waypoint.x}; }
            if (value == 2) { waypoint = {-waypoint.x, -waypoint.y}; }
            if (value == 3) { waypoint = {waypoint.y, -waypoint.x}; }
        }
        if (c == 'F') {
            cin >> value;
            ship.x += waypoint.x * value;
            ship.y += waypoint.y * value;
        }
    }
    
    debug(waypoint.x);
    debug(waypoint.y);
    debug(ship.x);
    debug(ship.y);

    int answer = abs(ship.x) + abs(ship.y);
    debug(answer);
}

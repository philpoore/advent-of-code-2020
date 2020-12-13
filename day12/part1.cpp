/*

*/
#include "../common.hpp"

struct PosDir {
    int x;
    int y;
    int dir;
};

int main() {
    PosDir pos = {0, 0, 1};
    while(!cin.eof()) {
        char c;
        int value;
        cin >> c;
        if (cin.eof()) break;
        debug(c);
        if (c == 'N') { cin >> value; pos.y += value;}
        if (c == 'S') { cin >> value; pos.y -= value;}
        if (c == 'E') { cin >> value; pos.x += value;}
        if (c == 'W') { cin >> value; pos.x -= value;}
        if (c == 'R') { cin >> value; pos.dir += value / 90;}
        if (c == 'L') { cin >> value; pos.dir -= value / 90;}
        if (c == 'F') {
            cin >> value;
            if (pos.dir == 0) pos.y += value;
            if (pos.dir == 1) pos.x += value;
            if (pos.dir == 2) pos.y -= value;
            if (pos.dir == 3) pos.x -= value;
        }

        if (pos.dir < 0) pos.dir += 4;
        if (pos.dir > 3) pos.dir -= 4;
    }
    
    debug(pos.x);
    debug(pos.y);
    debug(pos.dir);

    int answer = abs(pos.x) + abs(pos.y);
    debug(answer);
}
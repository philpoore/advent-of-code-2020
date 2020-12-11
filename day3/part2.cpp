/*
--- Part Two ---
Time to check the rest of the slopes - you need to minimize the probability 
of a sudden arboreal stop, after all.

Determine the number of trees you would encounter if, for each of the following
 slopes, you start at the top-left corner and traverse the map all the way to
  the bottom:

Right 1, down 1.
Right 3, down 1. (This is the slope you already checked.)
Right 5, down 1.
Right 7, down 1.
Right 1, down 2.
In the above example, these slopes would find 2, 7, 3, 4, and 2 tree(s) 
respectively; multiplied together, these produce the answer 336.

What do you get if you multiply together the number of trees encountered on 
each of the listed slopes?
*/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<bool>> Map;

int treesHit(Map &map, int width, int height, int dx, int dy) {
    int x = 0;
    int y = 0;
    int countTrees = 0;
    while(y < height) {
        x += dx;
        y += dy;

        if (y >= height) break;
        if (x >= width) x -= width;

        if (map[y][x]) {
            countTrees++;
        }
    }
    return countTrees;
}

int main() {
    Map map;
    cin >> noskipws;
    while(!cin.eof() && cin.peek() != -1) {
        vector<bool> line;
        while(cin.peek() != '\n') {
            char c = cin.get();
            line.push_back(c == '#');
        }
        cin.ignore(1);
        
        map.push_back(line);
    }

    cout << "Read map...\n";

    int height = map.size();
    int width = map[0].size();
    cout << "map width : " << width << "\n";
    cout << "map height: " << height << "\n";
    
    int a = treesHit(map, width, height, 1, 1);
    int b = treesHit(map, width, height, 3, 1);
    int c = treesHit(map, width, height, 5, 1);
    int d = treesHit(map, width, height, 7, 1);
    int e = treesHit(map, width, height, 1, 2);
    cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
    long long answer = (long long)a * b * c * d * e;
    cout << answer << "\n";
}
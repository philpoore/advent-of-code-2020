/*
https://adventofcode.com/2020/day/10
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> input;
    while(!cin.eof()) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    sort(input.begin(), input.end());

    for (auto a : input) {
        cout << a << " ";
    }
    cout << "\n";
    int curr = 0;
    int diff1 = 0;
    int diff3 = 1; // End connection is always 3 higher than last adapter.
    for (auto a : input) {
        int diff = a - curr;
        if (diff == 1) diff1++;
        else if (diff == 3) diff3++;
        else {
            cout << curr << "\n";
            cout << a << "\n";
            cout << diff << "\n";
            cout << "shouldn't have diff other than 1 and 3\n";
            exit(1);
        }
        curr = a;
    }
    int answer = diff1 * diff3;
    cout << "diff1: " << diff1 << "\n";
    cout << "diff3: " << diff3 << "\n";
    cout << "answer: " << answer << "\n";
}
/*
https://adventofcode.com/2020/day/10
*/
#include "../common.hpp"

int main() {
    vector<int> input = get_input<int>();

    sort(input.begin(), input.end());

#if 0
    // Display sorted list.
    for (auto a : input) cout << a << " "; cout << "\n";
#endif

    int curr = 0;
    int diff1 = 0;
    int diff3 = 1; // End connection is always 3 higher than last adapter.
    for (auto num : input) {
        int diff = num - curr;
        if (diff == 1) diff1++;
        else if (diff == 3) diff3++;
        else {
            debug(curr);
            debug(num);
            debug(diff);
            cout << "shouldn't have diff other than 1 and 3\n";
            exit(1);
        }
        curr = num;
    }
    int answer = diff1 * diff3;

    debug(diff1);
    debug(diff3);
    debug(answer);
}
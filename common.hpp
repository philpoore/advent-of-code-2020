#pragma once

#include <iostream>
#include <algorithm>
#include <regex>

// Data structures
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

#define debug(a) std::cout << #a << ": " << a << "\n";
#define debugv(a) for (auto& it: a) std::cout << ": " << it << "\n";
#define foreach(arr) for (auto& it : arr)

#define FOR(a, b, c) for (int a = b; a <= c; a++)
#define FORI(a, b, c) for (int a = c; a >= b; a--)

template <class T>
vector<T> get_input() {
    vector<T> input;
    while(!cin.eof()) {
        T line;
        cin >> line;
        input.push_back(line);
    }
    return input;
}

vector<string> split(string input, char delim) {
    vector<string> output;
    string curr;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == delim) {
            output.push_back(curr);
            curr = "";
        } else {
            curr += input[i];
        }
    }
    if (curr != "") output.push_back(curr);
    return output;
}
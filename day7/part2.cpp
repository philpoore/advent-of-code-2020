/*
https://adventofcode.com/2020/day/7
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>

using namespace std;

map<string, bool> nodes;
vector<pair<string, string>> edges;

map<string, vector<pair<int, string>>> rules;

void parse_line(string line) {
    cout << "line: " << line << "\n";
    const std::regex base_regex("([a-z ]+) bags contain ");
    std::smatch base_match;
    string color;
    if (regex_search(line, base_match, base_regex)) {
        color = base_match[1].str();
        cout << "Color: " << color << "\n";
    } else {
        return;
    }

    if (line.find("no other bags") != string::npos) {
        return;
    }

    const std::regex base_regex2("([0-9]+) ([a-z ]+) bags?");
    std::smatch base_match2;
    while (std::regex_search(line, base_match2, base_regex2)) {
        std::cout << base_match2[2] << std::endl;
        edges.push_back(make_pair(color, base_match2[2]));

        rules[color].push_back(make_pair(stoi(base_match2[1]), base_match2[2]));

        line = base_match2.suffix().str();
    }
    cout << "\n";
}

int main() {
    // parse input line by line
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        parse_line(line);
    }

    cout << "number of edges: " << edges.size() << "\n";

    // bfs to find all downstream nodes, count as we go
    stack<pair<int, string>> s;
    // set<string> visited;

    s.push(make_pair(1, "shiny gold"));
    int count = 0;
    while(s.size()) {
        string current = s.top().second;
        int num = s.top().first;
        s.pop();

        if (current != "shiny gold") {
            count += num;
        }

        for (auto& rule : rules[current]) {
            s.push(make_pair(rule.first * num, rule.second));
        }
    }
    cout << "count: " << count << "\n";
    return 0;
}

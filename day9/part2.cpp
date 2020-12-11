/*

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll target = 3199139634;

// ll target = 127;

int main() {
    vector<ll> input;
    while(!cin.eof()) {
        string line;
        getline(cin, line);
        if (line == "") break;
        input.push_back(stoll(line));
    }

    vector<ll> prefix_sum(input.size());
    ll sum = 0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
        prefix_sum[i] = sum;
    }

    bool pass = false;
    int i;
    int j;

    for (i = 0; i < prefix_sum.size(); i++) {
        for (j = i + 2; j < prefix_sum.size(); j++) {
            ll diff = prefix_sum[j] - prefix_sum[i];
            if (diff == target) {
                i++;
                cout << "Found sum:\n";
                cout << "i=" << i << " ," << input[i] << "\n";
                cout << "i=" << j << " ," << input[j] << "\n";
                pass = true;
                break;
            }
        }
        if (pass) break;
    }

    if (!pass) {
        cout << "Couldn't find match\n";
        return 1;
    }
    
    ll min = INT64_MAX;
    ll max = INT64_MIN;
    {
        for (int k = i; k <= j; k++) {
            cout << "input[" << k << "] = " << input[k] << "\n";

            if (input[k] > max) max = input[k];
            if (input[k] < min) min = input[k];
        }
        cout << "min: " << min << "\n";
        cout << "max: " << max << "\n";
    }
    
    {
        ll sum = max + min;
        cout << "sum: " << sum << "\n";
    }
    
}
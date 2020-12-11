/*
--- Part Two ---
The Elves in accounting are thankful for your help; one of them even 
offers you a starfish coin they had left over from a past vacation.
They offer you a second one if you can find three numbers in your 
expense report that meet the same criteria.

Using the above example again, the three entries that sum to 2020 
are 979, 366, and 675. Multiplying them together produces the 
answer, 241861950.

In your expense report, what is the product of the three entries 
that sum to 2020?
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
    vector<int> numbers;
    while (true) {
        int num;
        cin >> num;
        if (cin.eof()) break;
        numbers.push_back(num);
    }

    set<int> s;
    // Insert all numbers into set
    for (auto& num : numbers) {
        s.insert(num);
    }
    
    // For each pair, check if other is in set
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int other = 2020 - numbers[i] - numbers[j];
            if (s.count(other)) {
                cout << other << " " << numbers[i] << " " << numbers[j] << "\n";
                cout << other * numbers[i] * numbers[j] << "\n";
                return 0;
            }
        }
    }
    cout << "No match found\n";
    return 0;
}
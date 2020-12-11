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

#include "../common.hpp"

int main() {
    vector<int> numbers = get_input<int>();
    set<int> s;

    foreach (numbers)
        s.insert(it);
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int a = numbers[i];
            int b = numbers[j];
            int c = 2020 - a - b;
            if (s.count(c)) {
                int answer = a * b * c;
                cout << a << " " << b << " " << c << "\n";
                debug(answer);
                return 0;
            }
        }
    }
    cout << "No match found\n";
    return 0;
}
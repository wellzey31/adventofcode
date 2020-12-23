//Solution by /u/-WorstWizard-
//Dec. 11 - Advent of Code

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//This function is predicated on the observation that there are no differences of 2 in the input, only 1 and 3,
// and additionally that there are never more than 3 values between 2 unskippable values
//(values that cannot be removed while fulfulling the puzzle condition).
//Thus, using the differences of 3 to mark unskippable values the following is a simple table of valid combinations
//given a certain amount of values in-between the unskippable values.
int valid_combinations(int sublist_length) {
    int valid{1};
    //Leftmost and rightmost must be unskippable
    switch (sublist_length) {
        case 2:
            break;
        case 3:
            valid += 1;
            break;
        case 4:
            valid += 3;
            break;
        case 5:
            valid += 6;
            break;
    }
    return valid;
}

int main() {

    //Open file
    std::ifstream input{"data10.txt"};
    if (!input) {
        std::cout << "Could not open input file 'input_10.txt'!";
        return 1;
    }

    int num;
    std::vector<int> adapters{};

    //Parse the input
    std::string line;
    while (input) {
        std::getline(input, line);
        if (line.empty()) {
            break;
        }
        num = std::stoi(line);
        adapters.push_back(num);
	}

    adapters.push_back(0);
    std::sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters.back() + 3);

    int difference_before;
    int difference_after;
    int differences[] = {0,0,0};

    std::vector<int> unskippables{};
    unskippables.push_back(0); //First value is unskippable too
    for (int i=1; i < adapters.size()-1; i++) {
        difference_before = adapters[i] - adapters[i-1];
        ++differences[difference_before - 1];
        difference_after = adapters[i+1] - adapters[i];

        //For part 2
        if (difference_before == 3 || difference_after == 3) {
            unskippables.push_back(i);
        } else if (difference_before == 2 && difference_after == 2) {
            unskippables.push_back(i);
        }
    }
    ++differences[2]; //From largest adaptor to the device, the difference is guaranteed to be 3
    unskippables.push_back(adapters.size()-1); //Last value is unskippable too

    unsigned long answer_2{1};
    //This loop takes two unskippable values, and measures the length of the sublist that spans between (and including) them
    for (int i=0; i<unskippables.size()-1; i++) {
        int a = unskippables[i];
        int b = unskippables[i+1];
        int sublist_length = b-a+1;
        //The total number of combinations is given by the amount of valid ways to arrange the values between unskippable values, multiplied together
        answer_2 *= valid_combinations(sublist_length);
    }
    std::cout << "dif1: " << differences[0] << " dif3: " << differences[2] << std::endl;
    std::cout << "Answer 1: " << differences[0] * differences[2] << "\n";
    std::cout << "Answer 2: " << answer_2 << "\n";

    return 0;
}

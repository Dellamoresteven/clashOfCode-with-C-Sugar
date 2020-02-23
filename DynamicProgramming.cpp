/* This file is auto generated by C-Sugar @author Steven Dellamore 
URL = https://github.com/Dellamoresteven/C-Sugar */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <list>
#include <sys/stat.h>
#include <unistd.h>
#include <functional>
#include <map>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
template <typename T >
int maxSubsetSum( T arr ) {
    // Printing out the entire arr vector with delim: "\n"
    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        std::cout << *i << "\n";
    }
    // [1,2,3,4]
    // [1,-2,3,4]
    // biggestLength @TODO
    int biggestLength = 0;
    for( // i @TODO
    int i = 0; i < arr.size(); i++ ) {
        if( arr.at(i) > 0 ){
            // if( arr.at( i + 1 ) <= arr.at(i) && ( i + 1 ) > arr.size()-1 ) {
            //     biggestLength += arr.at( i++ );
            // }
        }
    }
    return biggestLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool is_word_part(char character) {
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9')) {
        return true;
    }
    return false;
}

int int_cmp(const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int percentage(int freq, int total) {
    double result = freq / (double) total;
    return result * 100;
}

int main(int argc, char* argv[]) {
    ifstream fin;
    ofstream fout;

    string file_in_name = argv[1];
    string file_out_name = argv[2];

    fin.open(file_in_name);

    map <string, int> words_data;

    // Reading strings
    int words_total = 0;
    string current_string;
    while (!fin.eof()) {
        getline(fin, current_string,'\n');

        string new_word = "";
        for (long unsigned int i = 0; i < current_string.length(); i++) {
            if ((i == current_string.length() - 1) && is_word_part(current_string[i])) {
                new_word += current_string[i];
                words_data[new_word]++;
                words_total++;
                new_word = "";
                continue;
            }
            if (is_word_part(current_string[i])) {
                new_word += current_string[i];
            }
            else if (is_word_part(current_string[i - 1])) {
                words_data[new_word]++;
                words_total++;
                new_word = "";
            }
        }
    }

    vector <pair <int, string>> words_freq;

    // Making vector of pairs
    for (auto i : words_data) {
        pair <int, string> p;
        p.first = i.second;
        p.second = i.first;

        words_freq.push_back(p); 
    }

    // Sorting vector by frequency
    sort(words_freq.begin(), words_freq.end());

    fout.open(file_out_name);

    // Writing down from most frequent to less
    for (int i = words_freq.size() - 1; i >= 0; i--) {
        fout << words_freq[i].second << "," << words_freq[i].first << "," << percentage(words_freq[i].first, words_total) << "%" << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

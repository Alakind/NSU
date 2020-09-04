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

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("text.txt");

    map <string, int> words_data;

    // Reading strings
    int words_total = 0;
    string current_string;
    while (!fin.eof()) {
        getline(fin, current_string,'\n');

        string new_word = "";
        for (long unsigned int i = 0; i < current_string.length(); i++) {
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

    for (auto i : words_data) {
        pair <int, string> p;
        p.first = i.second;
        p.second = i.first;

        words_freq.push_back(p);
        //cout <<  i.first << " : " << i.second << endl; 
    }

    sort(words_freq.begin(), words_freq.end());
    //qsort(words_freq.begin(), words_freq.size, int_cmp);

    for (auto i : words_freq) {
        cout <<  i.first << " : " << i.second << endl; 
    }

    fout.open("out.csv");

    return 0;
}

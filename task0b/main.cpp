#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

bool is_word_part(char character) {
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9')) {
        return true;
    }
    return false;
}

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("text.txt");

    map <string, int> words_data;

    // Reading strings      HEHEHEHE
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
                new_word = "";
            }
        }
    }

    for(auto i : words_data) {
        cout <<  i.first << " : " << i.second << endl; 
    }

    cout << current_string << endl;

    return 0;
}

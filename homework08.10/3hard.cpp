#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

long long compute_hash(string s, int p) {
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

map<string, int> rabin_karp_algo(string main_string, vector<string> string_vector) {
    int prostoe = 31;
    map<string, int> current_map;
    for (int i = 0; i < string_vector.size(); i++)
    {
        if (current_map.find(string_vector[i]) == current_map.end()) {
            current_map.insert(pair<string,int>(string_vector[i], 0));
        }
        unsigned int start_time = clock();
        long long current_word_hash = compute_hash(string_vector[i], prostoe);
        int current_word_size = string_vector[i].length();
        vector<long long> current_hashs;

        for (int j = 0; j < main_string.size() - current_word_size; j++)
        {
            current_hashs.push_back(compute_hash(main_string.substr(j, current_word_size), prostoe));
        }

        for (int j = 0; j < current_hashs.size(); j++)
        {
            if (current_hashs[j] == current_word_hash) {
                bool flag = true;
                for (int k = 0; k < current_word_size; k++)
                {
                    if (main_string[j + k] != string_vector[i][k]) {
                        flag = false;
                    }
                }
                if (flag) {
                    current_map[string_vector[i]]++;
                }
            }
        }
        unsigned int end_time = clock();
        cout << end_time - start_time << "\n";
    }
    return current_map;
}

int countSubstring(string& str, string& sub)
{
    if (sub.length() == 0) {
        return 0;
    }
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

int main() {
    string main_word = "roze roze rezo agga agga aagg please help me someone";
    vector<string> some_words = { "roze", "rezo", "agga", "aagg", "help", "me", "someone", "net takogo slova" };
    cout << "Times using own algorithm:\n";
    map<string, int> temp = rabin_karp_algo(main_word, some_words);

    cout << "Times using library:\n";
    for (int i = 0; i < some_words.size(); i++)
    {
        unsigned int start_time = clock();
        countSubstring(main_word, some_words[i]);
        unsigned int end_time = clock();
        cout << end_time - start_time << "\n";
    }

    map<string,int>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    
    return 0;
}
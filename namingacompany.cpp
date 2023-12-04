#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
        unordered_map<char, unordered_set<string>> wordMap;

        for (string word: ideas) {
            wordMap[word[0]].insert(word.substr(1, word.length()));
        }

        for (auto iter1: wordMap) {
            for (auto iter2: wordMap) {
                char c1 = iter1.first, c2 = iter2.first;
                unordered_set<string> s1 = iter1.second, unordered_set<string> s2 = iter2.second;
                if (c1 != c2) {
                    int similar_words = 0;
                    for (string str1: s1) {
                        for (string str2: s2) {
                            if (str1 == str2) {
                                similar_words += 1;
                            }
                        }   
                    }
                    int distinct1 = s1.size() - similar_words;
                    int distinct2 = s2.size() - similar_words;
                    res += distinct1 * distinct2;
                }
            }   
        }
        return res;
    }
};

int main() {
    
    return 0;
}
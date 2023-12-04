#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row[9];
        unordered_map<char, int> col[9];
        unordered_map<char, int> box[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if(ch!='.' && (row[i][ch]++ > 0) || col[j][ch]++ > 0 || box[i/3*3+j/3][ch]++ > 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> set;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                string ch (1, board[i][j]);
                if(ch != ".") {
                    string row_element = ch + "row" + to_string(i);
                    string col_element = ch + "col" + to_string(j);
                    string box_number = ch + to_string(i/3) + to_string(j/3); 
                    if(set.find(row_element) != set.end() || set.find(col_element) != set.end() || set.find(box_number) != set.end()) {
                        return false;
                    }
                    else {
                        set.insert(row_element);
                        set.insert(col_element);
                        set.insert(box_number);
                    }
                }
            }
        }
        return true;
    }
};

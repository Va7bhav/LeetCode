
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> hashMap;
        for (int i = 0; i < magazine.length(); i++)
        {
            hashMap[magazine[i]] ++;
        }
        for (int i = 0; i < ransomNote.length(); i++)
        {
            hashMap[ransomNote[i]] --;
        }
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if(hashMap[ransomNote[i]] < 0){
                return false;
            }
        }
        return true;        
    }
};


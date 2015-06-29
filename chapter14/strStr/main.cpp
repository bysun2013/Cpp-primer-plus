/*
https://leetcode.com/problems/implement-strstr/

Implement strStr():
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

it's too simple if use brute force, try to use KMP if you like to challenge !
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();

        for(int i = 0; i <= len1-len2; i++){
            int j;
            for(j = 0; j < len2; j++)
                if(haystack[i+j] != needle[j])
                    break;
            if(j == len2)
                    return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;

    s.strStr(string(), string());
    cout << "Hello world!" << endl;
    return 0;
}

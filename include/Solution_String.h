/*
初级算法-字符串
*/
#include <vector>
using namespace std;

class Solution {
/*
反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
*/
public:
    void reverseString(vector<char>& s) {
        int index = s.size() / 2;
        int i = 0;
        int j = s.size() - 1;
        while(i < index)
        {
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];
            ++i;
            --j;
        }
    }

}; // class Solution 

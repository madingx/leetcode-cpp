// Source : https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author : Mading
// Date   : 2019-06-19

/********************************************************************************** 
* 990. Satisfiability of Equality Equations [Medium]
* Given an array equations of strings that represent relationships between variables, 
* each string equations[i] has length 4 and takes one of two different forms: 
* "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) 
* that represent one-letter variable names.

* Return true if and only if it is possible to assign integers to variable names 
* so as to satisfy all the given equations.

* Example 1:
* Input: ["a==b","b!=a"]
* Output: false
* Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, 
* but not the second.  There is no way to assign the variables to satisfy both equations.

* Example 2:
* Input: ["b==a","a==b"]
* Output: true
* Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

* Example 3:
* Input: ["a==b","b==c","a==c"]
* Output: true

* Example 4:
* Input: ["a==b","b!=c","c==a"]
* Output: false

* Example 5:
* Input: ["c==c","b==d","x!=z"]
* Output: true
 

* Note:
* 1 <= equations.length <= 500
* equations[i].length == 4
* equations[i][0] and equations[i][3] are lowercase letters
* equations[i][1] is either '=' or '!'
* equations[i][2] is '='
*               
**********************************************************************************/


// 8 ms, faster than 86.44% of C++, 9.4 MB, less than 86.05% of C++
class Solution {
public:
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string e : equations)
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};
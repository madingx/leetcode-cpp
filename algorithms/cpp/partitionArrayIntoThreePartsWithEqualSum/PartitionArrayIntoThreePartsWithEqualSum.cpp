// Source : https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Author : Mading
// Date   : 2019-08-19

/*************************************************************************************** 
 * 1013. Partition Array Into Three Parts With Equal Sum [Easy]
 * Given an array A of integers, return true if and only if we can partition 
 * the array into three non-empty parts with equal sums.

 * Formally, we can partition the array if we can find indexes i+1 < j with 
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

 
 * Example 1:
 * Input: [0,2,1,-6,6,-7,9,1,2,0,1]
 * Output: true
 * Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1

 * Example 2:
 * Input: [0,2,1,-6,6,7,9,-1,2,0,1]
 * Output: false

 * Example 3:
 * Input: [3,3,6,5,-2,2,5,1,-9,4]
 * Output: true
 * Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

 * Note:
 * 3 <= A.length <= 50000
 * -10000 <= A[i] <= 10000
 *       
 ***************************************************************************************/

// 68 ms, faster than 55.88% of C++, 12.5 MB, less than 100.00% of C++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s = 0,part = 0,t = 0;
        for(auto i:A)s+=i;
        if(s%3 != 0)return false;
        s /= 3;
        for(auto i:A){
            t += i;
            if(s == t){
                part++;
                t = 0;
            }            
        } 
        return part == 3;
    }
};
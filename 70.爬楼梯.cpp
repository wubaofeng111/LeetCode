/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    
    long count_with(int num1,int num2)
    {
        if (num1 == 0||num2==0) {
           return 1;
        }
        int count = num1+num2;
        int maxNum = num1>num2? num1:num2;
        int minNum = count-maxNum;

        
        vector<int> v1;
        for (int i = maxNum+1; i<=count; i++)
        {
            v1.push_back(i);
        }
        vector<int> v2;
        for (int i = 2; i <= minNum; i++)
        {
            int isDived = 0;
            for (int j = 0; j < v1.size(); j++) {
                int &valueJ = v1.at(j);
                if (valueJ%i == 0) {
                    valueJ = valueJ/i;
                    isDived = 1;
                    break;
                }
            }
            if(isDived == 0)
            {
                v2.push_back(i);
            }
        }
        
        
        long result = 1;
        for (int i = 0; i < v1.size(); i++) {
            result *= v1.at(i);
        }
        for (int i = 0; i < v2.size(); i++) {
            int cValue = v2.at(i);
            result = result/cValue;
        }
        
        return result;
    }
    
    int climbStairs(int n) {
        
        int ommodity  = n/2;
        int count = 0;
        for (int  i = 0; i <= ommodity; i++)
        {    // 1的个数
            int num_1  = n - i * 2;
            int num_2  = i;
            count+=count_with(num_1,num_2);
        }
        return count;
        
    }
};
// @lc code=end


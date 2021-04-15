/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start

#include <iostream>

using namespace std;

typedef struct LargNum
{
    int value[10000];
    int carryOver;
    int hightNum;
}LargNum;

void print_largNum(const LargNum &num)
{
    for(int j = num.hightNum; j >= 0 ;j--)
    {
        cout<<num.value[j];
    }
}

class Solution {
public:
    
    void largNummultiply(LargNum &largNum/*被乘数*/,int num/*乘数*/)
    {
        for(int i = 0;i <= largNum.hightNum ;i++)
        {
            int value = largNum.value[i]*num+largNum.carryOver;
            largNum.carryOver = 0;
            if(value > 10)
            {
                int remainder = value%10;
                largNum.value[i] = remainder;
                largNum.carryOver  = value/10;
            }
            else
            {
                largNum.value[i] = value;
            }
        }
        while(largNum.carryOver > 0)
        {
            largNum.hightNum = largNum.hightNum+1;
            int value = largNum.carryOver;
            int remainder = value%10;
            largNum.value[largNum.hightNum] = remainder;
            largNum.carryOver  = value/10;
        }
    }
    
    int largNumsub(LargNum &num1/*被减数*/,LargNum num2/*减数*/)
    {
//        cout<<endl;
        for(int i = 0;i<=num1.hightNum;i++)
        {
            num1.value[i] += num1.carryOver;
            num1.carryOver = 0;
//            cout<<"num1:"<<num1.value[i]<<","<<"num2:"<<num2.value[i]<<endl;
            if(num1.value[i] >= num2.value[i])
            {
                num1.value[i] -= num2.value[i];
            }
            else
            {
                num1.carryOver = -1;
                num1.value[i] += 10;
                num1.value[i] -= num2.value[i];
            }
        }
        while(num1.value[num1.hightNum]<=0)
        {
            num1.hightNum--;
            if(num1.hightNum<0)
            {
                break;
            }
        }
        if(num1.hightNum < 0)
        {
            return 0;
        }
        return 1;
        
    }
    
    long largNumdivide(LargNum &num1/*被除数*/,LargNum num2/*除数*/)
    {
        
        long count = 0;
        while(1)
        {
            count++;
            if(largNumsub(num1, num2) == 0)
            {
                break;
            }
            
        }
        
        return count;
    }
    
    long count_with(int num1,int num2)
    {
        if (num1 == 0||num2==0) {
            return 1;
        }
        int count = num1+num2;
        int maxNum = num1>num2? num1:num2;
        int minNum = count-maxNum;
        
        
        LargNum num;
        memset(num.value, 0, sizeof(int)*10000);
        num.value[0] = 1;
        num.hightNum = 0;
        num.carryOver = 0;
        for (int i = maxNum+1; i<=count; i++)
        {
            largNummultiply(num, i);
        }
        
        LargNum largNum2;
        memset(largNum2.value, 0, sizeof(int)*10000);
        largNum2.value[0] = 1;
        largNum2.hightNum = 0;
        largNum2.carryOver = 0;
        
        for (int i = 2; i <= minNum; i++) {
            largNummultiply(largNum2, i);
        }
        print_largNum(num);
        cout<<"➗";
        print_largNum(largNum2);
        cout<<"=";
        long numresult = largNumdivide(num,largNum2);
        cout<<numresult<<endl;
        return numresult;
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


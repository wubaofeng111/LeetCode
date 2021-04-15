/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start

#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    
    void replace(string &path,string subPath,string withStr)
    {
       int pos = path.find(subPath);
       while (pos>=0) {
           path.replace(pos, subPath.size(), withStr);
           pos = path.find(subPath);
       }
    }
    
    string simplifyPath(string path) {
        if (path.size() == 1) {
            return path;
        }
        std::vector<std::string> subPaths;
        
        int pathStart = 0;
        for (int i = 0; i < path.size(); i++)
        {
            if (path.at(i) == '/')
            {
                string substr = path.substr(pathStart,i-pathStart);
                if (substr.size()>0) {
                    subPaths.push_back(substr);
                    pathStart = i;
                }
               
                continue;
            }else if (i == path.size()-1)
            {
                string substr = path.substr(pathStart,i-pathStart+1);
                if (substr.size()>0) {
                    subPaths.push_back(substr);
                    pathStart = i;
                }
            }
            
        }
        
        for (int i = 0;  i < subPaths.size(); i++)
        {
            if (subPaths.at(i) == "/."|| subPaths.at(i) == "/")
            {
                subPaths.erase(subPaths.begin()+i);
                i--;
            }
        }
    
        for (int i = 0; i < subPaths.size(); i++) {
            if (subPaths.at(i) == "/..")
            {
                if (i-1 < 0) {
                    subPaths.erase(subPaths.begin()+i);
                    i --;
                }else{
                    subPaths.erase(subPaths.begin()+i-1);
    //                并且删除前一个
                    subPaths.erase(subPaths.begin()+i-1);
                    i -=2;
                    
                }
                
            }
            
        }
        if (subPaths.size() == 0) {
            subPaths.push_back("/");
        }
        string result="";
        for (int i = 0; i < subPaths.size(); i++) {
            result+=subPaths.at(i);
        }
        
        return result;
    }
};
// @lc code=end


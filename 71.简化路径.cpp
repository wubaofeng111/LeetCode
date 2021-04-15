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
        
        vector<string> resultPaths;
        for (int i = 0; i < subPaths.size(); i++) {
            if (subPaths.at(i) == "/."|| subPaths.at(i) == "/")
            {
                continue;
            }
            if (subPaths.at(i) == "/..") {
                if(resultPaths.size()>0)
                    resultPaths.pop_back();
            }else{
                resultPaths.push_back(subPaths.at(i));
            }
        }
        
        if (resultPaths.size() == 0) {
            resultPaths.push_back("/");
        }
        string result="";
        for (int i = 0; i < resultPaths.size(); i++) {
            result+=resultPaths.at(i);
        }
        
        return result;
    }
};
// @lc code=end


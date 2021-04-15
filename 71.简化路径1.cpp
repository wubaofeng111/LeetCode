/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <string>
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
    void jumpFrontPath(string &path)
    {
        int pos = path.find("/../");
        while (pos>=0) {
            if(pos == 0)
            {
                path.replace(pos, 4, "/");
            }
            else
            {
                int frontPath = pos-1;
                while (frontPath > 0)
                {
                    char sub = path.at(frontPath);
                    if (sub == '/')
                    {
                        int findPathSize = pos+4-frontPath;
                        
                        path.replace(frontPath,findPathSize,"/");
                        
                        break;
                    }
                    else
                    {
                        frontPath--;
                    }
                }
            }
            pos = path.find("/../");
        }
    }
    
    string simplifyPath(string path)
    {
        
        replace(path, "/./","");
        
        replace(path, "//","/");
        
        jumpFrontPath(path);
        if (path.size()>1&&path.at(path.size()-1)=='/') {
            path.erase(path.size()-1,1);
        }
        cout<<path<<endl;
        return path;
    }
};
// @lc code=end


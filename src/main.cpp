#include "../include/Greedy/Solution.hpp"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
        Solution s;
        vector<int> nums={2,3,1,1,4};
        s.canJump(nums);
}

//"*aa*ba*a*bb*aa*ab*a*aaaaaa*a*aaaa*bbabb*b*b*aaaaaaaaa*a*ba*bbb*a*ba*bb*bb*a*b*bb"
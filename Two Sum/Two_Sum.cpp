#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int> nums, int target) {

    multimap<int, int> mipmap;
    multimap<int, int> ::iterator it;
    for (int i = 0; i < nums.size(); i++) {
        mipmap.emplace(nums[i], i);
    }
    for (int i = 0; i < nums.size(); i++) {
        if (mipmap.count(nums[i]) < 3) {
            it = mipmap.find(target - nums[i]);
            if (it != mipmap.end() && it->second != i) 
                return { i, it->second };
        }
    }
    return {};
}

void main() {
    
    vector<int> answer = twoSum({2,7,11,15}, 9); //input data

    if (answer.empty())
        cout << "there's no solution :(" << endl;
    else 
        cout << answer[0]<<" "<< answer[1] << endl;
    

}
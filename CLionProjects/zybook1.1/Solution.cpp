#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>


// this solution uses two indices as pointers to try all the combinations of two numbers 
// that might add up to the target.  
// Start with the leftptr at index 0 and the right ptr at the last index.  Find the difference between the number at the first index and the 
// target.  Move the right pointer to the left and try to match the the difference number. If you get smaller, stop, index the left ptr
// recalc the difference, which should be smaller, start the right ptr where you left off comparing.  If you find the right
// left ptrs equal there is no solution.
// We use a pair to have each number maintain its position in the original vector of numbers since they can be 
// in any order.  I have used auto to show its basic behavior.
// What is the Big O of my solution?? nlogn to sort original vector, n to push into new vector, n to do the pointer indexing search
// so nlogn looks correct.
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int,int>> sortVec;
        for(auto i = 0; i< nums.size();i++){
            sortVec.push_back(std::make_pair(nums[i],i));
        }


        std::sort(sortVec.begin(),sortVec.end());
        auto leftPtr = 0;
        auto rightPtr = nums.size() - 1;

//        for(auto i = 0; i< nums.size();i++){
//        std::cout<< sortVec[i].first << "  " <<sortVec[i].second<< std::endl;
//        }

        auto numToFind = 0;


        for (auto i = 0; i < nums.size(); i++) {
            leftPtr = i;
            numToFind = target - sortVec[leftPtr].first;
            //std::cout << "num to find  " << numToFind << std::endl;

            while ((sortVec[rightPtr].first > numToFind) && rightPtr != leftPtr) {
                rightPtr--;
            }

            if (sortVec[rightPtr].first == numToFind) { break; }

            if(leftPtr == rightPtr){std::cout << "no solution" << std::endl;}  //
        }
        std::vector<int> answer {sortVec[leftPtr].second,sortVec[rightPtr].second};

        return answer;
    }
};
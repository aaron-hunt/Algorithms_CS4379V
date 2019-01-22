#include <iostream>
#include "Solution.cpp"
#include <vector>
int main() {

    std::vector<int> probData {5,3,7,6,2,1,8, 9};
    std::vector<int> answer;
    auto target = 15;
    Solution  mysolution;

    answer = mysolution.twoSum(probData,target);
    std::cout << answer[0] << " " << answer[1];

    return 0;
}
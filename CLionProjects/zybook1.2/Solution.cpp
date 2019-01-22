#include <stack>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

class Solution{

public:
    int reverse(int x) {

        std::stack<int> input;
        std::stack<int> reverseInput;
        int answer = 0;
        bool isPositive;
        if (x < 0)
        {
            isPositive = false;
        }
        else
            isPositive = true;

        while (x > 0) {

            int num = x % 10;
            reverseInput.push(num);
            x /= 10;
        }

        double i = 0;
        while (!reverseInput.empty())
        {
            double temp_offset = pow (10, i);
            int offset = temp_offset;

            if ( answer + reverseInput.top()*offset > LONG_MAX ) {
                std::cout <<"LONG_MAX exceeded" << std::endl;
                return 0;
            }
            std::cout << "queue front: " << reverseInput.top() <<  std::endl;
            answer = answer + reverseInput.top() * offset;
            i++;
            reverseInput.pop();
        }
        if (isPositive == false){answer *= -1;}
        return answer;

    }
};
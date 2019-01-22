#//
// Created by Greg LaKomski on 6/18/18.
//


#include<iostream>
#include<cmath>
#include<cstdio>
#include "Solution.cpp"
#include<climits>
using std::cout;
using std::endl;

int main() {

    int sampleInput = -123;
    int reverseInput;
    Solution mysolution;

    reverseInput = mysolution.reverse(sampleInput);
    std::cout << reverseInput;

    return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int solution(vector<int>& blocks) {
    if (!blocks.size()) {
        return 0;
    }
    size_t i = 0;
    size_t curPeakIndex = i + 1;
    size_t prevPeakIndex = i;
    size_t repeatPeaks = 0;
    size_t maxDist = 0;
    bool bUp = false;
    for (; i < blocks.size() - 1; i++) {
        if (blocks[i + 1] >= blocks[i]) {
            curPeakIndex = i + 1;
            if (blocks[i + 1] == blocks[i]) {
                ++repeatPeaks;
            }
            else {
                bUp = true;
                if (repeatPeaks) {
                    repeatPeaks = 0;
                }
            }
        }
        else
        {
            if (bUp) {
                prevPeakIndex = curPeakIndex - repeatPeaks;
                bUp = false;
                repeatPeaks = 0;
            }
            curPeakIndex = i + 1;
        }
        maxDist = (maxDist <= (curPeakIndex - prevPeakIndex + 1)) ? (curPeakIndex - prevPeakIndex + 1) : maxDist;
    }
    return maxDist;
}

int main()
{
    vector<int> v1{ 3,3,3,4,4,5,5,-3,6 };
    cout << solution(v1) << endl;   //7 
    vector<int> v3{ 3,1,5,9,2 };
    cout << solution(v3) << endl;   //4
    vector<int> v4{ 2,6,8,5 };
    cout << solution(v4) << endl;   //3
    vector<int> v5{ 3,2,1,4,5,9 };
    cout << solution(v5) << endl;   //6
    vector<int> v6{ 6,6,5,5,5,6,6 };
    cout << solution(v6) << endl;   //7
    vector<int> v7{ 1 };
    cout << solution(v7) << endl;   //0
    vector<int> v8{ 6,6,5,5,4,4,3,3,3,5 };
    cout << solution(v8) << endl;   //10 Jump up only
    vector<int> v9{ 2,6,8,5 };
    cout << solution(v9) << endl;   
    vector<int> v2{ 1,5,5,2,6 };
    cout << solution(v2) << endl;
    return 0;
}
//mkdir -p .output && g++ -std=c++11 frog.cpp -o .output/frog.o && ./.output/frog.o
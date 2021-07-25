#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> mxL = maxL(height);
        vector<int> mxR = maxR(height);
        vector<int> water;
        
        for(int i =0 ; i< height.size(); i++){
            water.push_back(min(mxL[i],mxR[i])-height[i]);    
        }
        
        long sum = 0 ;
        
        for(int k=0; k < water.size(); k++){
            sum+=water[k];
        }
        
        return sum;
        
    }
    
    vector<int> maxL(vector<int>& height){
        vector<int> mxL;
        
        mxL.push_back(height[0]);
        
        for(int i=1 ; i<height.size(); i++){
            mxL.push_back(max(mxL[i-1],height[i]));
        }
        return mxL;
    }
    
    vector<int> maxR(vector<int>& height){        
        int size = height.size();
        vector<int> mxR(size);
        mxR[size-1]=height[size-1];
        
        for(int i=size-2 ; i>=0; i--){
            mxR[i] = max(mxR[i+1],height[i]);
        }
        return mxR;
    }
};


int main(){
    vector<int> vect{ 0,1,0,2,1,0,1,3,2,1,2,1 }; 
    Solution solution;
    cout<<"Input : ";
    int res = solution.trap(vect);
    cout<< res <<endl;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> left = nSL(heights);
        cout<<"left array : ";
        display(left);
        vector<int> right = nSR(heights);
        cout<<"right array : ";
        display(right);
        vector<int> width;
        vector<int> area;
        for(int i =0 ; i < heights.size();i++)
            width.push_back(right[i] - left[i] -1);

        cout<<"width array : ";
        display(width);
        
        for(int j =0 ; j < heights.size(); j++)
            area.push_back(heights[j]*width[j]);
        cout<<"area array : ";
        display(area);

        return *max_element(area.begin(),area.end());
    }

    void display(vector<int> a){
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " "; 
        cout << endl; 
    }
    
    
    vector<int> nSL(vector<int> heights){
        int pseudoIndex = -1;
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=0; i < heights.size();i++){
            if(s.empty()){
                v.push_back(pseudoIndex);
            }
            else if(!s.empty() && s.top().first < heights[i]){
                    v.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]){
                    while(s.size()>0 && s.top().first >= heights[i]){
                        s.pop();
                    }
                    
                    if(s.empty()){
                        v.push_back(pseudoIndex);
                    }
                    else{
                        v.push_back(s.top().second);
                    }
            }
            
            s.push({heights[i],i});
            
        }
        
        // for(int j=0 ; j < heights.size(); j++ ){
        //     v[j] = j - v[j];
        // }
        
        return v;
    }
    
    
     vector<int> nSR(vector<int> heights){
        int pseudoIndex = heights.size();
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=heights.size()-1; i >= 0; i--){
            if(s.empty()){
                v.push_back(pseudoIndex);
            }
            else if(!s.empty() && s.top().first < heights[i]){
                    v.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]){
                    while(!s.empty() && s.top().first >= heights[i]){
                        s.pop();
                    }
                    
                    if(s.empty()){
                        v.push_back(pseudoIndex);
                    }
                    else{
                        v.push_back(s.top().second);
                    }
            }
            
            s.push({heights[i],i});
            
        } 
        cout<<"nsr vector : ";
        display(v);
       
        reverse(v.begin(), v.end());
       
        return v;
    }
};


int main(){
    vector<int> vect{ 2,1,5,6,2,3 }; 
    Solution solution;
    cout<<"Input : ";
    solution.display(vect);
    int res = solution.largestRectangleArea(vect);
    cout<< res;
}
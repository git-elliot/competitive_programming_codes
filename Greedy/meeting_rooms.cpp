#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end());
    priority_queue <int, vector<int>, greater<int> > q;
    //minimize rooms
    
    q.push(A[0][1]);
    int rooms = 1;
    for(int i=1; i<A.size(); i++){
        cout<<A[i][0]<<endl;
        if(q.top()>A[i][0]){
            q.push(A[i][1]);
        }else{
            while(!q.empty()&&q.top()<=A[i][0])
                q.pop();
             q.push(A[i][1]);
        }
        cout<<"size: "<<q.size()<<endl;
        rooms = max(rooms,(int)q.size());
    }
    return rooms;
}
// 0 -- 8
//   1 --- 14
//     7------------21
//                  21----22

//0---------------14
//  5-------9
//   6------------------------25
//            12----------19
//              13--------19


int main(){

vector<vector<int>> meetings = {
    {0, 14},
  {6, 25},
  {12, 19},
  {13, 19},
  {5, 9}};

  cout<<solve(meetings)<<endl;

}
// g++ -std=c++11 meeting_rooms.cpp -o .outputs/meeting_rooms.o && ./.outputs/meeting_rooms.o 
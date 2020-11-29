#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution{
private :
vector<int>c_arr;


public :
    Solution(vector<int>&arr){
        c_arr.push_back(0);
        for(int i=0; i<arr.size(); i++){
            c_arr.push_back(c_arr[i]+arr[i]);
        }
    }



int sumRange(const vector<int>&arr, int start, int end){
    int sum = c_arr[end+1]-c_arr[start];
    return sum;
    }
};



int main (){
     vector<int>arr={3,2,1,0,1,0};
     int start =3;
     int end =5;
     Solution a(arr);
     cout <<a.sumRange(arr,start,end);
        return 0;
}

#include <vector>
#include <iostream>
//left-rotate of an array
using namespace std;
vector<int> rotLeft(vector<int> a, int d) {
    int size=a.size();
    vector<int> arr(size);
    for(int i=0; i<size; i++){
        arr[i]=a[(i+d)%size];
    }
    return arr;
}

//right-rotate of an array
vector<int>rotRight(vector<int>a, int d){
    int size=a.size();
    vector<int>arr(size);
    for(int i=size; i>0; i--){
        arr[i]=a[(i-d)%size];
    }
    return arr;
}


int main (){
    vector<int>nums ={0,1,2,3,4,5};
    vector<int>arr=rotRight(nums,1);
    for(int num : arr){
        cout<<num;
    }



}

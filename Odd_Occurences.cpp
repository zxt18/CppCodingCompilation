#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A){

    sort(A.begin(),A.end());
    int test_num=A[0];
    bool odd_occured=false;
    int i=0;
    int occurences=-1;
    while (!odd_occured && i<A.size()){
        if(test_num==A[i+1]){
            occurences++;
            i++;
        }
        else{
            if(occurences%2==0){
                test_num=A[i+1];
                i++;
            }
            else{
                odd_occured=true;
            }
            occurences=-1;
        }
    }
    return test_num;
}


int main (){
    int the_num;
    vector<int>A={1,1,1,9,};
    the_num=solution(A);
    cout<<the_num;


}

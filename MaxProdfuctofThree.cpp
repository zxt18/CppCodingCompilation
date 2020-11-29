#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int neg_index;
    int neg_count=0;
    int pos_count=0;
    int min_negative=3;
    int v_size=A.size();
    int max_triplet=A[0]*A[1]*A[2]; //base case when N=3
    std::sort(A.begin(),A.end());
    if(A.size()>3){
        for(int i=0;i<min_negative;i++){
            if(A[i]<0){
                neg_index=i;
                neg_count++;
            }
        }
    }
    else{
        // max_triplet= A[0]*A[1]*A[2];
    }
    if(neg_count<=1){
        max_triplet=A[v_size-1]*A[v_size-2]*A[v_size-3];
    }
    else if(neg_count>1){
       int max_1=A[0]*A[1]*A[v_size-1]; //two neg 1 pos
       int max_2=A[v_size-1]*A[v_size-2]*A[0]; //two pos 1 neg;
       int max_3=A[v_size-1]*A[v_size-2]*A[v_size-3];
       max_triplet= std::max(max_triplet,max_1);
       max_triplet=std::max(max_triplet,max_2);
       max_triplet=std::max(max_triplet,max_3);
       return max_triplet;
    }

    return max_triplet;
}








int main (){
    vector<int>v={-10,0,0,3,4};
    cout<<solution(v);

    return 0;
}

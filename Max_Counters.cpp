#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Counter range =N;
//Array A
//if value A[k] lies within and inclusive of counter range, K is increase (X)
//if value A[k]==N+1 , K is max counter;


vector<int>solution(int N, vector<int> &A) {
    vector<int>B(N,0);
    int max=0;
    int min=0;
    for(int i=0; i<A.size(); i++){
    if(A[i]<=N){
        int B_index=A[i]-1;
        int counter=std::max(B[B_index],min)+1;

        B[B_index]=counter;
        if(counter>max){
            max=counter;
            cout<<"max is now "<< max;
        }
    }
    else{
        min=max;
        cout<<"min is " <<min<<endl;
    }

    }

    for(int j=0; j<B.size(); j++){
        B[j]=std::max(min,B[j]);
    }
    cout<<endl; //removeDDD




    return B;
}

int main (){
    vector<int>A={3,4,4,6,1,4,4};
    vector<int>B=solution(5,A);

    return 0;
}

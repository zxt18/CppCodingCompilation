#include <iostream>
#include <vector>


using namespace std;

vector<int>solution (vector<int>&A, int K){
  vector<int>copy;
  if(!A.empty()){
    if(K==0|A.size()==1){
      copy=A;
      return copy;
    }
    else{
      for(int i=0; i<K; i++){
        if(A.size()>1){

            copy.push_back(A.back());
            for(int j=1; j<A.size(); j++){
              copy.push_back(A[j-1]);
            }
            A=copy;
            if(i<K-1){
              copy.clear();
            }
        }
      }
    }
  }
  return copy;
}



int main (){

  vector<int> A = {0};
  vector<int> copy=solution(A,2);
  for(int a : copy ){
    cout<<a<<endl;
  }
  return 0;

}

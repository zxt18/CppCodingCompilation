    #include <iostream>
    #include <vector>

    using namespace std;


    int solution(int X, vector<int> &A){
        vector<int>occurences(X,0);
        int checkSum=0;
        for(unsigned int i=0; i<A.size(); i++){
            unsigned int index=A[i]-1;
            if(occurences[index]==0){
                occurences[index]=1;
                checkSum++;
            }
            else{
                if(checkSum==X){
                    return i;
                }
            }

        }
        return -1;
    }

int main (){
    vector<int> occurences(9,0);
    vector<int>num={1,3,1,4,2,3,5,4};
    int numzz=solution(5,num);
    cout<<numzz;

  return 0;
}

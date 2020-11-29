    #include <iostream>
    #include <algorithm>
    #include <vector>

    using namespace std;

    int solution (vector<int>&A){
        int miss_elem;
        int test_num=1;
        if(!A.empty()){
            sort(A.begin(),A.end());
            for(int i=0;i<A.size();i++){
                if(test_num==A[i]){
                    if(i==A.size()-1){
                        return test_num+1;
                    }
                    else{
                        test_num++;
                    }


                }
                else{
                    return test_num;
                }
            }
        }
        else{
            return 1;
        }
    }




int main (){
    vector<int>A={1,2,3,4};
    int miss_elem=solution(A);
    cout<<miss_elem<<endl;

return 0;
}

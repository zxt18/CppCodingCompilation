#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
#include <cmath>
#include <limits>
using namespace std;

int solution(vector<int> &A) {
    vector<int>individual_sums;
    int j=1;
    int total_sum=0;
    if(A.size()==1){
        return A[0];
    }


    else{
        int min_sum=numeric_limits<int>::max();

        for(int i=0; i<A.size();i++){
            total_sum+=A[i];
            individual_sums.push_back(total_sum);
        }


        for(int i=0; i<individual_sums.size()-1; i++){
            int sum_1 = individual_sums[i];
            int sum_2 = total_sum-sum_1;
            int abs_diff=(abs(sum_2-sum_1));
            min_sum=min(min_sum,abs_diff);
        }
        return min_sum;
    }

}








int main (){
    vector<int> abc ={1,123,523};
    cout<<solution(abc);

    return 0;
}

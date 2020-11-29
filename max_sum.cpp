#include <bits/stdc++.h>

using namespace std;

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {



vector<int>dp;
dp.reserve(arr.size());
dp[0]=arr[0];

if(arr.size()==1){
    return arr[0];
}
if(arr.size()==2){
    if(arr[0]>arr[1]){
        return arr[0];
    }
    else{
        return arr[1];
    }
}

if(arr.size()>2){
    if(arr[0]>arr[1]){
    dp[1]=arr[0];
}
else{
    dp[1]=arr[1];
}

    for(int i=2; i<arr.size(); i++){

        int tmp=std::max(arr[i], arr[i]+dp[i-2]);
        // cout<<i<<"tmp<<endl;
        dp[i] = dp[i-1];
        dp[i]=std::max(dp[i],tmp);

    }
}

return dp[arr.size()-1];

}

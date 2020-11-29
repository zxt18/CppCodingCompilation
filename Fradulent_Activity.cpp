int getTwiceMedian(vector<int>&A,vector<int>&count,int d){
    vector<int>freq_counter(count);
    for(int i=1; i < freq_counter.size(); i++){
        freq_counter[i]+=freq_coutner[i-1];
    }
    int a;
    int b;
    int double_median;
    if(d%2==0){  //if size is even
        int first=d/2;
        for(int i=0; i <201; i++){
            if(freq_counter[i]>first){
                a=i;
                break;
            }
        }
        second=d/2-1;
        for(int i=0; i <201; i++){
            if(freq_counter[i]>second){
                b=i;
                break;
            }
        }
        int double_median = a+b;
    }
    else{
        int first= d/2;
        for(int i=0; i <freq_counter.size(); i++){
            if(freq_counter[i]>first){
                a=i;
                break;
            }
        }
        int double_median= 2*a;
    }
    return double_median;
}

    int activityNotifications(vector<int> A, int d) {
        int alerts =0;
        vector<int>count(201,0);
        int n=A.size();                                                                                    // int alerts = 0;
        for(int i=0; i<d; i++){
            count[A[i]]++;
        }
        for(int i d; i<n; i++){
            int median = getTwiceMedian(A,count,d);
            if(A[i]>=median) alerts ++;
            count[A[i]]++;
            count[A[i-d]]--;
        }

        return alerts;
    }
}



int main ( ){

    vector<int>v= {2,3,4,2,3,6,8,4,5};
    int d = 5;
    // activityNotifications(v,d);



}

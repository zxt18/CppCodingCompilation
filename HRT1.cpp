#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
int solution(vector<int> &A) {
    vector<pair<int,int>>expense;
    int neg_location;
    int sum=0;
    int min_count=0;
    int move_index;
    bool all_neg=true;
    for(int i=0; i<A.size(); i++){
        sum+=A[i];
        // cout<<"i"<< i <<endl;
        if(A[i]<0){
            if(all_neg==true){

            }
            pair<int,int>p= make_pair(A[i],i);
            expense.push_back(p);  //vector of pairs <val,index> of the negative numbers sort them later;
        }
        else if(A[i]>0 && all_neg==true){
            // cout<<"here"<<endl;
            all_neg=false;
            move_index=i;
            // pair<int,int>p= make_pair(A[i],i);
            // expense.push_back(p);  //vector of pairs <val,index> of the negative numbers sort them later;
            vector<int>::iterator itr=A.begin();
            std::rotate(itr, itr+i,A.end());
            cout<<"print :";
            for(int a: A){
                cout<<a<<",";
            }
            cout<<endl;
            min_count+=i; //add min_count to number of traversals
            sum=A[0]; //reset sum
            i=0; //rest loop

        }
        if(sum<0 && all_neg==false){
            cout<<"executed"<<endl;
            if(sum<0){
                neg_location=i;
            }
            else{
                neg_location=numeric_limits<int>::min();
            }

            sort(expense.begin(), expense.end());
                for(int j=0; j<expense.size(); j++){
                    if(expense[j].second<=neg_location){  // if index is earlier
                        move_index=expense[j].second;
                        vector<int>::iterator itr=A.begin()+move_index;
                        std::rotate(itr, itr,A.end());
                        for(int a: A){
                            cout<<a<<",";
                        }
                        cout<<endl;
                        min_count++;
                        neg_location=numeric_limits<int>::min();
                        sum=sum-expense[j].first;
                        break;
                    }
            }
        }

    }

    cout<<endl;

    return min_count;
    }

int main (){
    vector<int>nums={5,-2,-3,1,-100,-50,200};
    cout<<solution(nums);


  return 0;
}

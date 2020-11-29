#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
//left-rotate of an array
using namespace std;
// vector<int> rotLeft(vector<int> a, int d) {
//     int size=a.size();
//     vector<int> arr(size);
//     for(int i=0; i<size; i++){
//         arr[i]=a[(i+d)%size];
//     }
//     return arr;
// }
//
// //right-rotate of an array
// vector<int>rotRight(vector<int>a, int d){
//     int size=a.size();
//     vector<int>arr(size);
//     for(int i=size-1; i>=0; i--){
//
//         arr[i]=a[((i-d+size))%size];
//     }
//     return arr;
// }

// void minimumBribes(vector<int> q) {
//     int swap =0;
//     if(q[i]!=i+1){
//             for(int i=q.size()-1; i>=0; i--){
//                 if((i-1)>0 && q[i-1]==i){
//                     int tmp=q[i];
//                     q[i]=q[i-1];
//                     q[i-1]=tmp;
//                     swap++;
//                 }
//                 if((i-2)>0 && q[i-2]==i){
//                     int tmp=q[i-2];
//                     int tmp_1=q[i-1];
//                     q[i-2]=q[i];
//                     q[i-1]=tmp;
//                     q[i]=tmp_1;
//                     swap=swap+2;
//                 }
//             }
//             if(swap==0){
//                 cout<<"Too chaotic"<<endl;
//             }
//             else{
//                 cout<<swap<<endl;
//             }
// }
// }


int summer (int rep){
    int sum=0;
    for(int i=1; i<rep; i++){
        sum=i+sum;
    }

    return sum;
}



int sherlockAndAnagrams(string s) {
    int num_anagrams=0;
        std::unordered_map<string,int>str_map;
        int loops=s.size();
        for(int i=0; i <s.size(); i++){
            for(int j=0; j<loops; j++){
                string r;
                r=s.substr(i,j+1);
                std::sort(r.begin(),r.end());
                if(str_map.find(r)==str_map.end()){
                    str_map.insert(make_pair(r,1));
                }
                else{
                    str_map[r]++;
                }
            }
            loops--;
        }

        for(auto const& x : str_map){
            cout<<x.first<<","<<x.second<<endl;
            if(x.second>1){
                num_anagrams=num_anagrams+summer(x.second);
            }
        }
        return num_anagrams;
    }
                // if(str_map::find(s[i])==str_map.end())
                //     str_map(make_pair(s[i]),1);
                // else{
                //     str_map[s[i]]++;
                // }

        //beyond here str_map is populated;





int main (){
    string a ="ifailuhkqq";
    cout<<sherlockAndAnagrams(a);
    // cout<<a.substr(2,3);
    return 0;

}


// vector<string> split_string(string);
//
// // Complete the checkMagazine function below.
// void checkMagazine(vector<string> magazine, vector<string> note) {
//     unordered_map<std::string,int> u;
//     if(note.size()>magazine.size()){
//         for(int i=0; i<magazine.size(); i++){
//             u.insert(std::make_pair(magazine[i],1)); //increment or initiialize to 0 then increment
//         }
//
//         for(int i=0; i<note.size(); i++){
//             if(u.find(note[i])!=u.end()){
//                 cout<<"No"<<endl;
//                 break;
//             }
//         }
//         cout<<"Yes"<<endl;
//
//
//     }
//
//
// }

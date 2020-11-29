#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int summer (int n){
    int a= n-1;
    int sum= a*(a+1)/2;
    return sum;
}

int sherlockAndAnagrams(string s) {
    int num_anagrams=0;
        std::unordered_map<string,int>str_map;
        int loops=s.size();
        for(int i=0; i <s.size(); i++){
            for(int j=0; j<loops; j++){
                string r;
                r=s.substr(i,j+1);                           //substr(pos,number of elements after pos);  substr(0,1) returns first character substr(1,1)returns second character
                                                            //(0,1), (0,2) (0,3) (0,4) & (1,1), (1,2), (1,3), & (2,1) (2,2) & (3,1)
                std::sort(r.begin(),r.end());               //take each substring and sort in alphabetical order to check if it has occured before
                if(str_map.find(r)==str_map.end()){
                    str_map.insert(make_pair(r,1));
                }
                else{
                    str_map[r]++;
                }
            }
            loops--;
        }

        for(auto const& x : str_map){    //C++11 implementation of map iteration
            if(x.second>1){
                num_anagrams=num_anagrams+summer(x.second);
            }
        }

        unordered_map <string,int> str_map;
        for(auto const &x : str_map){

        }
        return num_anagrams;
    }


    int main (){
        string word="abba";

    }

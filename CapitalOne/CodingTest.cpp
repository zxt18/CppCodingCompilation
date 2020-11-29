#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>





using namespace std;
int main() {
string input;
string story1;
ifstream file("text.txt");
    while(getline(file,input)){
    story1.append(input);
    // story.append(" ");
    }
cout<<story1<<endl;
cout<<endl;
cout<<endl;
string delete_1="<script>";
string delete_2="</script>";

    auto finder= story1.find(delete_1);
    auto finder_2= story1.find(delete_2);
string story2=story1;
if(finder!=std::string::npos){

    if(finder_2!=string::npos){
        auto len = finder_2-finder;
        story2.erase(finder,len+delete_2.length());
    }
}


cout<<story2<<endl;

    return 0;
}

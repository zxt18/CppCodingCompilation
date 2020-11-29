#include <iostream>
#include <algorithm>

using namespace std;
//X is the starting position
//Travel > Y;
//D is the reach
int solution (int X, int Y,int D){
    int distance = Y-X;
    int steps=(int)distance/D;
    int remainder= distance%D;
    if(remainder>0){
        steps++;
    }
    return steps;
}


int main (){

    int ans= solution(10,85,30);

    cout<<ans<<endl;




return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
// struct point{
//     int x;
//     int y;
//     int val;
// };


// bool compareTwoPoints(point p1, point p2){
//     return p1.val>p2.val;
// }
//
// void getMaxColumn(vector<vector<int> >&A, vector<point>&p_Column){
//
//     int max_num=0;
//         for(int i=0; i<A[0].size();i++){
//             struct point p1;
//             for(int j=0; j<A.size();j++){
//                 if(A[j][i]>max_num){z
//                     max_num=A[j][i];
//                     p1.x=j;
//                     p1.y=i;
//                     p1.val=max_num;
//                     max_num=0;
//                 }
//             }
//             p_Column.push_back(p1);
//         }
// }
//
// void getMaxRow(vector<vector<int> >&A, vector<point>&p_Row){
//
//     int max_num=0;
//         for(int i=0; i<A.size();i++){
//             struct point p1;
//             for(int j=0; j<A[0].size();j++){
//                 if(A[i][j]>max_num){
//                     max_num=A[i][j];
//                     p1.x=i;
//                     p1.y=j;
//                     p1.val=max_num;
//                     max_num=0;
//                 }
//             }
//             p_Row.push_back(p1);
//         }
// }


int solution(vector< vector<int> > &A) {
    int max_num=0;
    struct point p1;
    vector<point>points;
    vector<point>p_Column;
    vector<point>p_Row;
    getMaxColumn(A,p_Column);
    // for(point a:p_Column){
    //     cout<<a.val<<endl;
    // }
    getMaxRow(A,p_Row);


    sort(p_Column.begin(),p_Column.end(),&compareTwoPoints);
    sort(p_Row.begin(),p_Row.end(),&compareTwoPoints);

    int max_sum=0;
    int max_1;
    int max_2;
    bool overlap=true;

    for(int i=0; i<p_Row.size()-1; i++){
        max_1=p_Row[i].val;
        for(int j=i; j<p_Row.size(); j++){
                if(p_Row[i].x==p_Row[j+1].x|| p_Row[i].y==p_Row[j+1].y){ //if on the same row or Row

            }
        else{
            int sum=0;
            max_2=(p_Row[j]).val;

            sum=max_1+max_2;
            max_sum=std::max(max_sum,sum);
            overlap=false;
            break;
        }
    }
}

    for(int i=0; i<p_Column.size()-1; i++){
        max_1=p_Row[i].val;
        for(int j=i; j<p_Column.size(); j++){

        if(p_Column[i].x==p_Column[j+1].x|| p_Column[i].y==p_Column[j+1].y){ //if on the same row or column
              //             original_points.push_back([j+1])
              //             A[points[j+1].x][points[j+1].y]=-1;
              //             max_2=
              //  }
            }
        else{
            int sum=0;
            max_2=p_Column[j+1].val;
            sum=max_1+max_2;
            max_sum=std::max(max_sum,sum);
            overlap=false;
            break;
        }
    }
}



for(int i=0; i<p_Row.size(); i++){
    max_1=p_Row[i].val;
    for(int j=0; j<p_Column.size(); j++){

            if(p_Row[i].x==p_Column[j].x|| p_Row[i].y==p_Column[j].y){ //if on the same row or column
          //             original_points.push_back([j+1])
          //             A[points[j+1].x][points[j+1].y]=-1;
          //             max_2=
          //  }
            }
            else{
                int sum=0;
                max_2=p_Column[j].val;
                sum=max_1+max_2;
                max_sum=std::max(max_sum,sum);

                overlap=false;
                break;
            }
    }
}







    // vector<point> original_points;
    // for(int i=0; i<points.size()-1; i++){
    //     int max_1=points[i].val;
    //     for(int j=i; j<points.size()-1; j++){
    //
    //         if(points[i].x==points[j+1].x|| points[i].y==points[j+1].y){ //if on the same row or column
    //             original_points.push_back([j+1])
    //             A[points[j+1].x][points[j+1].y]=-1;
    //             max_2=
    //         }
    //         else{
    //             max_2=points[j+1].val;
    //             sum=max_1+max_2;
    //             max_sum=std::max(max_sum,sum);
    //         }
    //     }
    // }

    return max_sum;
}


int main (){
    point p1;
    vector<vector<int>> A=  {
                { 20, 24, 16  },
                { 8, 14, 11 }

            };
    cout<<solution(A);
    return 0;
}

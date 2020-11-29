#include <iostream>
#include <string>
#include <cstring>

using namespace std;
//string matching
// int findmatch(string p, string t){
//     int i,j;
//     int m,n;
//
//     m=p.length();
//     n=t.length();
//
//     for(i=0; i<=(n-m); i++){
//         j=0;
//         while((j<m)&&(t[i+j]==p[j])){
//             j=j+1;
//         }
//         if(j==m)
//         return i;
//     }
//     return (-1);
// }

//list struct
struct llist
{
    int item;
    llist* next;
};

llist* search_list(llist l, int a ){
    if(l==NULL) return(NULL);
    if((l->item)==a)
        return l;
    else
        return (search_list (l->next,x));
}

void  insertion_list(llist** l, int a ){
     p = new llist
     p->item=a;
     p->next=(*l);
     *l=p;
}




int main (){
    string one="ello";
    string main ="Hello";
    cout<<findmatch(one,main);


}

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

//singly linked list struct
// struct llist
// {
//     int item;
//     llist* next;
// };
//
// llist* search_list(llist l, int a ){
//     if(l==NULL) return(NULL);
//     if((l->item)==a)
//         return l;
//     else
//         return (search_list (l->next,x));
// }
//
// void  insertion_list(llist** l, int a ){
//      p = new llist
//      p->item=a;
//      p->next=(*l);
//      *l=p;
// }

//BST search algorithm runs in O(h)
    // tree * search_tree (tree* t, int data_field){
    // 	if(t==NULL) return NULL;
    // 	if(t->data==data_field) return t;
    // 	if(data_field<t->left){
    // 	  return search_tree(t->left,data_field);
    // 	}
    // 	else {
    // 	  return search_tree(t->right,data_field);
    // 	}

    // tree * find_min(tree *t){
    //     if(t==NULL){ return NULL};
    //     tree * min=t;                   //pointer to the minimum node;
    //     while(min->left!=NULL){
    //         min=min->left;
    //     }
    //     return min;
    // }

    //     void traverse_tree(tree *l)
    // {
    //     if (l != NULL) {
    //     traverse_tree(l->left); //pre-order
    //     process_item(l->item);  //in-order traversal
    //     traverse_tree(l->right); //post_order traversal
    //     }
    // }

    //     Node* CreateNode(int data)
    // {
    //     Node* newNode = new Node();
    //     if (!newNode) {
    //         cout << "Memory error\n";
    //         return NULL;
    //     }
    //     newNode->data = data;
    //     newNode->left = newNode->right = NULL;
    //     return newNode;
    // }

    //usually insertion takes in a pointer to pointer parameter

    //Heap Data Structure for a priority queue

//     struct {
//         item_type q[PQ_SIZE+1]; //body of the queue
//         int n;          //num of elements in the priority queue
//     } priority_queue; //priority queue implemented as a heap
//
//     int pq_parent(int n){
//         if(n==1) return(-1);
//         else return ((int)n/2);
//     }
//     int pq_child(int n){
//         return 2*n;
//     }
//
//     void pq_insert(priority_queue *q, item_type x ){
//         if(q->n>=PQ_SIZE)
//             cout<<"Warning" : priority queue overflow insert<<x<<endl;
//         else{
//             q->n++;
//             new=(q->n);
//             q->q[new]=x;
//             bubble_up(q,new);
//         }
//     }
//     void pq_swap(priority_queue *q, int p, int parent){
//         q->q[parent]=p;
//         p=q->q[parent];
//     }
// //bubbling up
//     void bubble_up(priority_queue *q, int p){
//         if(pq_parent(p)==-1) return;
//
//         if(q->q[pq_parent(p)]> q->q[p]){
//             pq_swap(q,p,pq_parent(p));
//             bubble_up(q,pq_parent(p));
//         }
//
//     }
//
//     void pq_init(priority_queue *q)
//     {
//     q->n = 0;
//     }
//
//     make_heap(priority_queue *q, item_type s[], int n)
//     {
//         int i;
//         pq_init(q);
//         for(i=0; i<n; i++)
//         pq_insert(q,s[i]);
//     }
//

void quicksort( item_type s[], int l , int h){

    int p;        //index of the partition
    if((h-l)>0){
        p=partition(s,l,h);
        quicksort(s,l,p-1);
        quicksort(s,p+q,h);
    }
}

int partition(item_type s[], int l, int h){
    int i;  //counter;
    int p;  //pivote element index;
    int firsthigh; //divider position for pivot elements


    p=h;
    firsthigh=l;
    for(i=l; i<h; i++)
        if(s[i]<s[p]){
            swap(&s[i],&s[firsthigh]);
            firsthigh++;
        }
    swap(&s[p],&s[firsthigh]);

    return firsthigh;


}

int binarySearch( int arr[]. int l, int r, int x){
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==x)
            return m;
        if(arr[m]<x)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}


    


int main (){
    string one="ello";
    string main ="Hello";
    cout<<findmatch(one,main);


}

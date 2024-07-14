// -------------------------------------THIS IS DEQUENE (Double Ended Quene)--------------------------------------------------------
// #include <iostream>
// using namespace std;

// class DEquene{
//     public:
//     int f;
//     int r;
//     int size;
//     int* arr;
// };

// int isfullr(DEquene* q){
//     if(q->r == (q->size - 1)){
//         return 1;
//     }
//     return 0;
// }

// int isempty(DEquene* q){
//     if (q->r == q->f )
//     {
//         return 1;
//     }
//     return 0; 
// }

// int isfullf(DEquene* q){
//     if (q->f == -1)
//     {
//         return 1;
//     }
//     return 0;
// }

// void insertionf(DEquene* q, int val){
//     if(q->f == -1){
//         cout<<"DEquene is not possible "<<endl;
//     }
//     if(isfullf(q)){
//         cout<<"DEquene Overflow "<<endl;
//     }
//     else{
//         q->arr[q->f] = val;
//         q->f--;
//     }
// }

// void insertionr(DEquene* q, int val){
//     if(isfullr(q)){
//         cout<<"DEquene Overflow "<<endl;
//     }
//     else{
//         q->r++;
//         q->arr[q->r] = val;
//     }
// }

// int dequener(DEquene* q){
//     if(isempty(q)){
//         cout<<"DEquene Underflow "<<endl;
//         return -1;
//     }
//     int val = q->arr[q->r];
//     q->r--;
//     return val;
// }

// int dequenef(DEquene* q){
//     if(isempty(q)){
//         cout<<"DEquene Underflow "<<endl;
//         return -1;
//     }
//     q->f++;
//     int val = q->arr[q->f];
//     return val;
// }

// int main(){
//     DEquene q;
//     q.f = q.r = -1;
//     q.size = 10;
//     q.arr = new int[q.size];
//     insertionr(&q, 89);
//     insertionr(&q, 45);
//     insertionr(&q, 67);
//     insertionr(&q, 8);
//     cout<<"Dequened element is : "<<dequener(&q)<<endl;
//     cout<<"Dequened element is : "<<dequenef(&q)<<endl;
//     insertionf(&q, 27);
//     cout<<"Dequened element is : "<<dequenef(&q)<<endl;
//     return 0;
// }


// -------------------------------------THIS IS CIRCULAR QUENE--------------------------------------------------------
// #include <iostream>
// using namespace std;

// class circular_quene{
//     public:
//     int r;
//     int f;
//     int size;
//     int* arr;
// };

// int isfull(circular_quene* q){
//     if((q->r + 1)%q->size == q->f){
//         return 1;
//     }
//     return 0;
// }

// int isempty(circular_quene* q){
//     if(q->r == q->f){
//         return 1;
//     }
//     return 0;
// }

// void enquene(circular_quene* q, int val){
//     if(isfull(q)){
//         cout<<"Quene Overflow "<<endl;
//     }
//     else{
//         q->r = (q->r + 1)%q->size;
//         q->arr[q->r] = val;
//     }
// }

// int dequene(circular_quene* q){
//     if(isempty(q)){
//         cout<<"Quene Underflow "<<endl;
//         return -1;
//     }
//     q->f = (q->f + 1)%q->size;
//     return q->arr[q->f];
// }

// int main(){
//     circular_quene q;
//     q.r = q.f = 0;
//     q.size = 3;
//     q.arr = new int[q.size];

//     enquene(&q, 6);
//     enquene(&q, 78);
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     enquene(&q, 506);
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     enquene(&q, 506);
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     enquene(&q, 506);
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     return 0;
// }


// ------------------------------------------THIS IS NORMAL QUENE--------------------------------------------------------------------
// #include <iostream>
// using namespace std;

// class quene{
//     public:
//     int f;
//     int r;
//     int size;
//     int* arr;
// };

// int isfull(quene* q){
//     if(q->r == (q->size - 1 )){
//         return 1;
//     }
//     return 0;
// }

// int isempty(quene* q){
//     if(q->r == q->f ){
//         return 1;
//     }
//     return 0;
// }

// void enquene(quene* q, int val){
//     if(isfull(q)){
//         cout<<"Quene Overflow "<<endl;
//     }
//     else{
//         q->r++;
//         q->arr[q->r] = val;
//     }
// }

// int dequene(quene* q){
//     if(isempty(q)){
//         cout<<"Quene underflow "<<endl;
//         return -1;
//     }
//     q->f++;
//     return q->arr[q->f];
// }

// int main(){
//     quene q;
//     q.size = 10;
//     q.f = q.r = -1;
//     q.arr = new int[q.size];
//     enquene(&q, 10);
//     enquene(&q, 2);
//     enquene(&q, 28);
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     cout<<"Dequened element is : "<<dequene(&q)<<endl;
//     return 0;
// }
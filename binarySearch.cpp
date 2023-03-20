/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <chrono>

using namespace std;
int binary_search(int A[],int n,int x);
int naive_search(int*,int,int);
int main()
{
    int A[] = {2,4,5,7,13,14,15,23};
    int input;
    cout<<"Enter a number: ";
    cin>>input;


    auto start1 = chrono::high_resolution_clock::now(); // get start time
    int index1 = binary_search(A,8,input);
    auto end1 = chrono::high_resolution_clock::now(); // get end time
    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1); // calculate duration
    cout<<"The index using binary search is: "<<index1<<endl;
    cout << "Execution time binary search: " << duration1.count() << " nanoseconds." << endl; // print duration
    
    auto start2 = chrono::high_resolution_clock::now(); // get start time
    int index2 = naive_search(A,8,input);
    auto end2 = chrono::high_resolution_clock::now(); // get end time
    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2); // calculate duration
    cout<<"The index using linear search is: "<<index2<<endl;
    cout << "Execution time linear search: " << duration2.count() << " nanoseconds." << endl; // print duration
    
    return 0;
}
int binary_search(int A[],int n,int x){
    int start = 0,end = n-1;
    while(start<=end){
    int mid = (start+end)/2;
    
    if (A[mid] == x) return mid;
  
    else if (x < A[mid]) end = mid-1;

    else start = mid+1;

    }
    return -1;
}
int naive_search(int A[],int n, int x){
    for(int i=0;i<n;i++){
        if (A[i] == x){
            return i;
        }
    }
    return -1;
}
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h){
    int pivot = arr[h];
    int i=l-1;
    for(int j=l;j<=h;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
void quicksort(int arr[],int l,int h){
    if(l<h){
            int pi = partition(arr,l,h);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}
int main(){
 int arr[] ={4,7,8,3,1,9,5,6,2};
 quicksort(arr,0,8);
 for(int i=0;i<9;i++){
    cout << arr[i] << " ";
 }
 cout << endl;
}

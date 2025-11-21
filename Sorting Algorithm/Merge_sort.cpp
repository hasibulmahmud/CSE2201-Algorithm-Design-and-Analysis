#include<bits/stdc++.h>
using namespace std;
void mergenum(int arr[],int low,int mid,int high){
    int n1 = mid - low+1;
    int n2 = high -mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i] = arr[low+i];
    }
    for(int i=0;i<n2;i++){
        r[i] = arr[mid+1+i];
    }
    int i = 0,j = 0,k=low;
    while(i<n1 && j < n2){
        if(l[i]<=r[j]){
            arr[k++] = l[i++];

        }else{
        arr[k++] = r[j++];
        }
    }
    while(i<n1){
             arr[k++] = l[i++];
    }
    while(j<n2){
         arr[k++] = r[j++];
    }
}
void margesort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid = low+(high-low)/2;
    margesort(arr,low,mid);
    margesort(arr,mid+1,high);
    mergenum(arr,low,mid,high);
}
int main(){
     int arr[] ={4,7,8,3,1,9,5,6,2};
 margesort(arr,0,8);
 for(int i=0;i<9;i++){
    cout << arr[i] << " ";
 }
 cout << endl;
}

#include<bits/stdc++.h>
using namespace std;
void findMinMax(int arr[],int l,int h,int &max,int &min){
    if(l==h){
        max = arr[l];
        min =arr[h];
        return;
    }
    if(h==l+1){
        if(arr[h]>arr[l]){
            max=arr[h];
            min = arr[l];
        }else{
        max=arr[l];
        min = arr[h];
        }
        return;
    }
    int mid = l+(h-l)/2;
    int leftmax,leftmin,rightmax,rightmin;
    findMinMax(arr,l,mid,leftmax,leftmin);
    findMinMax(arr,mid+1,h,rightmax,rightmin);
    if(leftmax>rightmax){
        max = leftmax;
    }else{
    max =rightmax;
    }
    if(leftmin>rightmin){
        min = rightmin;

    }else{
    min = leftmin;
    }
}
int main(){
   int arr[] = {5, 9, 3, 1, 7, 12, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maximum, minimum;
    findMinMax(arr, 0, n - 1, maximum, minimum);

    cout << "Maximum = " << maximum << endl;
    cout << "Minimum = " << minimum << endl;

}

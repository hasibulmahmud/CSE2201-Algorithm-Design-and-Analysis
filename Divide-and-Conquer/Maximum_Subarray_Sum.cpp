#include<bits/stdc++.h>
using namespace std;
int maxcrossingSum(int arr[],int l,int m,int h){
    int sum=0;
    int left =INT_MIN;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        if(left<sum){
            left=sum;
        }
    }
    sum=0;
    int right=INT_MIN;
        for(int i=m+1;i<=h;i++){
        sum+=arr[i];
        if(right<sum){
            right=sum;
        }
    }
    return (left+right);
}
int maxSubarray(int arr[],int l,int h){
    if(l==h){
        return arr[l];
    }
    int m = l+(h-l)/2;
    int left = maxSubarray(arr,l,m);
    int right = maxSubarray(arr,m+1,h);
    int crossSum = maxcrossingSum(arr,l,m,h);
    if(left>=right && left>=crossSum){
        return left;
    }else if(right>=crossSum && right>= left){
    return right;
    }else{
    return crossSum;
    }
}
int main(){
    int arr[] = {3,-1,-7,8,2,9,-2,6};
    cout << maxSubarray(arr,0,7) << endl;
}

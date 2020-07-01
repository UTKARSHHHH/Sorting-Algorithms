#include<iostream>
using namespace std;

swap(int *a,int*b){
int temp = *a;
*a= *b;
*b=temp;
}
void selection(int* arr, int n){
for(int i=0;i<n-1;i++){
        int m=i;
    for(int j=i+1;j<n;j++){
        if(arr[m]>arr[j]){
            m=j;
        }
    }
    swap(&arr[m],&arr[i]);
}
}
void bubble(int *arr,int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
        }
    }

}
}
void insertion(int* arr, int n){

for(int i=1;i<n;i++){
    int key = arr[i];
    int j=i-1;

    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
    j--;
    }
    arr[j+1]=key;
}
}
void bubble_rec(int* arr, int n){

if(n==1)
 return;

for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1])
        swap(&arr[i],&arr[i+1]);
}
bubble_rec(arr,n-1);
}
void insertion_rec(int* arr, int n){

    if(n<=1)
        return;

    insertion_rec(arr,n-1);
    int last=arr[n-1];
    int j=n-1;

    while(j>=0 && arr[j]>last){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=last;
}
void merge(int* arr, int l, int m, int r){
int a1=m-l+1;
int a2=r-m;

int L[a1],R[a2];

for(int i=0;i<a1;i++)
    L[i]=arr[l+i];

for(int j=0;j<a2;j++)
    R[j]=arr[m+1+j];

int i=0,j=0,k=l;

while(i<a1 && j<a2){
    if(L[i]<=R[j]){
        arr[k]=L[i];
        i++;
        k++;
    }
    else{
        arr[k]=R[j];
        j++;
        k++;
    }
}
while(i<a1){
    arr[k]=L[i];
    i++;
    k++;
}
while(j<a2){
    arr[k]=R[j];
    j++;
    k++;
}

}
void mergesort(int* arr,int l,int r){
if(l<r){
int m = (l+(r-1))/2;
mergesort(arr,l,m);
mergesort(arr,m+1,r);
merge(arr,l,m,r);
}
}
int partition(int* arr,int p,int r){
    int x = arr[r];
    int i = p - 1;
    for(int j=p;j<=r;j++){
        if(arr[j]<x){
            i = i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quicksort(int* arr,int p,int r){
    if(p<r){
        int q = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int main(){
int arr[]={2,5,4,7,8,6};
int n= sizeof(arr)/sizeof(arr[0]);
quicksort(arr,0,n-1);
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
return 0;

}

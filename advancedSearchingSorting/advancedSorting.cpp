#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void shellsort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp;
            int j;
            for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}

void myQuicksort(int arr[],int n){
    int left=0;
    int right=n-1;
    while(left<right){
        if(arr[left]>arr[right]){
            swap(arr[left],arr[right]);
            left++;
        }
        else right--;
    }
}
void Quicksort(int arr[],int n){
    int left=0;
    int right=n-1;
    int pivpos=left;
    while(left<right&&pivpos<=n-1){
        if(pivpos==left){
            if(arr[left]>arr[right]){
                swap(arr[left],arr[right]);
                pivpos=right;
                left++;
            }
            else right--;
        }
        else{
            if(arr[left]>arr[right]){
                swap(arr[left],arr[right]);
                pivpos=left;
                right--;
            }
            else left++;
        }
    }
}
void heapify(vector<int>& arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    } 
    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void mergesort(vector<int>& arr){
    int n=arr.size();

}
void printarray(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void interpolation(vector<int>& arr,int key){
    int high=arr.size()-1;
    int low=0;
    int mid;
    while(low<high){
        mid=(low+(high-low))*((key-arr[low])/(arr[high-arr[low]]));
        if(key>arr[mid]){
            low=mid+1;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else break;
    }
    if(arr[mid]==key){
        cout<<"found in the index: "<<mid<<endl;
    }
    else{
        cout<<"not found.\n";
    }
}
void binarysearch(vector<int>& arr,int key){
    int high=arr.size()-1;
    int low=0;
    int mid;
    while(low<high){
        mid=(high+low)/2;
        if(arr[mid]>key){
            high=mid-1;
        }
        else if(key>arr[mid]){
            low=mid+1;
        }
        else break;
    }
    if(key==arr[mid]){
        cout<<"found it in the index: "<<mid<<endl;
    }
    else{
        cout<<"not found.\n";
    }
}
int main(){
    int arr[5];
    cout<<"enter array of 5 numbers.";
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    shellsort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    vector<int> arrr{12,3,4,7,1,8,9};
    heapsort(arrr);
    cout<<"the sorted array: ";printarray(arrr);
    cout<<"search something: ";
    int x;
    cin>>x;
    binarysearch(arrr,x);
    return 0;
}
#include<iostream>
using namespace std;
int main (){
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }

    }
    int v=i+1;
    for(int k=0;k<v;k++){
        cout<<arr[k]<<" ";

    }
    cout<<endl;
}

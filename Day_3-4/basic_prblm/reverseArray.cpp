//reverse an array , create a iterative function and a recursive function to reverse an array.
//
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b){
	a=a+b;
	b=a-b;
	a=a-b;
}

void reverseUsingRec(vector<int>&arr,int start,int end){
	if(start>=end){
		return;
	}
	swap(arr[start],arr[end]);
	reverseUsingRec(arr,start+1,end-1);
}

void reverseUsingIte(vector<int>&arr){
	int l=0 ;
	int r=arr.size()-1;
	while(l<r){
		swap(arr[l++],arr[r--]);

	}
}


void printArr(vector<int>&arr){
	cout<<"The reversed array is:\n";
	for(auto &a:arr)cout<<a<<" ";
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	cout<<"Enter the elements of the array\n";
	vector<int>arr(t);
	for(auto &a:arr)cin>>a;
	reverseUsingRec(arr,0,t-1);
	printArr(arr);
	reverseUsingIte(arr);
	printArr(arr);
}

//Find the Nth fibonacci number using tabulation.
//
//
#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	long long fib_data[10000]={0};
	fib_data[0]=0;
	fib_data[1]=1;
	for(int i=2;i<10000;i++){
		fib_data[i]=fib_data[i-1]+fib_data[i-2];}
	cout<<fib_data[t]<<'\n';
}


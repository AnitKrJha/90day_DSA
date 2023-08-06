#include<iostream>
using namespace std;

long long fact(int n){
	long long N=n;
	if(n<2)return 1;
	return N*fact(N-1);}

int main(){
	int n;
	cin>>n;
	cout<<fact(n)<<'\n';
}

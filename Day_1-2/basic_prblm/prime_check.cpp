#include<bits/stdc++.h>
using namespace std;



bool isPrime(long long n){
	if(n<=1)return false;
	for(int i=2;i<sqrt(n+0.1);i++){
		if(n%i==0)return false;}
	return true;
}


int main(){
	long long n;
	cin>>n;
	cout<<(isPrime(n)?"Yes\n":"No\n");}

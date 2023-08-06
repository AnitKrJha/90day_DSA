#include<iostream>
using namespace std;

long long saved_fib[10000]={-1};

long long fib(long n){

if(saved_fib[n]!=-1)return saved_fib[n];    

if(n<2)
{saved_fib[n]=n;
return saved_fib[n];
}
	
	saved_fib[n]=fib(n-1)+fib(n-2);
	return saved_fib[n];
}

//using memoization



int main(){
for(int i=0;i<10000;i++)saved_fib[i]=-1;
int n;cin>>n;
cout<<fib(n);
}
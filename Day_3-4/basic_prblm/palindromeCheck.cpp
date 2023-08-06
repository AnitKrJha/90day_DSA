// Write a recursive function to check if a string is a palindrome. I wrote recusive function and Iterative version.


#include<iostream>


using namespace std;

bool checkPalindromeRec(string s,int start,int end){
	
	if(start>=end)return true;
	return s[start]==s[end] && checkPalindromeRec(s,start+1,end-1);
}

bool checkPalindromeIte(string s){
	int l=0;
	int r=s.size()-1;
	while(l<r){
		if(s[l++]!=s[r--])return false;
	}
	return true;

}

int main(){
	string s;
	cin>>s;
	cout<<checkPalindromeRec(s,0,s.size()-1);
	cout<<checkPalindromeIte(s);
}
	

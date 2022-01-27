#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<char> &arr,int n){
	
	vector<char> alpha,num;
	for(vector<char>::iterator i=arr.begin();i!=arr.end();i++){
		if(isalpha(*i))
			alpha.push_back(*i);
		else
			num.push_back(*i);
	}
	
	vector<char>::iterator a=alpha.begin(),b=num.begin();
	vector<char>::iterator i=arr.begin();
	
	for(;a!=alpha.end();i++){
		*i=*a;
		a++;
	}
	
	for(;b!=num.end();i++){
		*i=*b;
		b++;
	}
	
}

main(){
	char a[]={'a','1','b','2','c','3','d','4'};
	vector<char> arr(a,a+8);
	rearrange(arr,8);
	
		for(vector<char>::iterator i=arr.begin();i!=arr.end();i++){
			cout<<*i;
	}
}

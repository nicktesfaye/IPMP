#include <iostream>
#include<list>
using namespace std;


void fun(list<int>&l,list<int>::iterator a){
    if(a==l.end())
        return;
    
    fun(l,next(a,1));
    cout<<*a;
}

int main() {
	list<int> l;
	int n,x;
	cin>>n;
	n++;
	while(--n){
	    cin>>x;
	    l.push_back(x);
	}
	fun(l,l.begin());
	return 0;
}

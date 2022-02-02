#include<bits/stdc++.h>

using namespace std;


class Stack{
	public:
		vector<int> S;
		int min;
		
	Stack(int x){
		min=x;
		S.push_back(min); 
	}
	
	void push(int x){
		if(x>=min){
			S.push_back(x);
			return;
		}
		S.push_back((2*x)-min);
		min = x;
	}
	
	void pop(){
		vector<int>::reverse_iterator i=S.rbegin();
		int t =*i;
		S.pop_back();
		
		if(t<min)
			min = 2*min-t;		
	}
	
	void print(){
		
		int min_temp = min;
		
		for(vector<int>::reverse_iterator i=S.rbegin();i!=S.rend();i++){
			if(*i>=min_temp)
			cout<<*i<<" ";
			else{
				cout<<min_temp<<" ";
				min_temp = 2*(min_temp)-(*i);
			}
		}
	}
	
	int getMin(){
		return min;
	}
		
};

main(){
	Stack s(8);	
	s.push(10);
	s.push(6);
	cout<<"min element: "<<s.getMin()<<"\n";
	s.push(3);
	s.pop();
	s.print();
}

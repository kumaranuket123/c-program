#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
	for(int i=0;i< v.size();i++){
		cout<<v[i]<<"  ";
	}
	cout<<endl;
}

int main(){

	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(8);
	v.push_back(2);
	print(v);
	
	sort(v.begin(), v.end());
	print(v);

	reverse(v.begin(),v.end());
	print(v);

	random_shuffle(v.begin(),v.end());
	print(v);

	cout<<*v.begin()<<endl;

}
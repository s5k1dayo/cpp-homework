#include <iostream>
using namespace std;
template <class T>
class Vector{
public:
	int wei=0;
	int size=100;
	T* shuju;
	Vector(){
		shuju=new T [size];
	}
	int add(T x){
		shuju[wei]=x;
		wei++;
		return wei-1;
	}
	int get_size(){
		return wei;
	}
	void remove(int x){
		int X=x-1;
		for(int i=X;i<wei;i++){
			shuju[i]=shuju[i+1];
		}
		wei--;
	}
	int operator [](int x){
		return shuju[x];
	}
};
/* 请在这里填写答案 */

int main()
{
	Vector<int> vint;
	int n,m;
	cin >> n >> m;
	for ( int i=0; i<n; i++ ) {
		//    add() can inflate the vector automatically
		vint.add(i);    
	}
	//    get_size() returns the number of elements stored in the vector
	cout << vint.get_size() << endl;
	cout << vint[m] << endl;
	//    remove() removes the element at the index which begins from zero
	vint.remove(m);
	cout << vint.add(-1) << endl;
	cout << vint[m] << endl;
	Vector<int> vv = vint;
	cout << vv[vv.get_size()-1] << endl;
	vv.add(m);
	cout << vint.get_size() << endl;
}


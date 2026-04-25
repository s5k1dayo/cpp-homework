#include<iostream>
#include<string>
#include"account.h"
using namespace std;

int main() {
	User* user;
	setchain();
	readuser();
	user=begin();
	while(user==NULL){
		system("pause");
		system("cls");
		user=begin();
	}
	usage(user);
	return 0;
}

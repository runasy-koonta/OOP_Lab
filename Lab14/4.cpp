#include <iostream>
using namespace std;

class Account {
private:
	static int BalanceSum;
	string id;
	string name;
	int balance;
public:
	Account(): id(""), name(""), balance(0) {}
	Account(string _id, string _name, int _balance): id(_id), name(_name), balance(_balance) {}
	
	static int getBalanceSum() {
		return Account::BalanceSum;
	}
	
	~Account() {
		BalanceSum += this->balance;
	}
};

int Account::BalanceSum = 0;
int main(void) {
	int n;
	cout << "총 학생 수 입력: ";
	cin >> n;
	
	Account acnt[n];
	for (int i = 0; i < n; i++) {
		cout << (i + 1) << "번째 학생 계좌 입력 : 학번 : ";
		string id, name;
		cin >> id;
		cout << endl << "이름 : ";
		cin >> name;
		cout << endl << "잔액 : ";
		int balance;
		cin >> balance;
		
		acnt[i] = Account(id, name, balance);
		
		cout << "===================" << endl;
	}
	
	cout << "회수된 금액 : " << Account::getBalanceSum() << endl;;
}
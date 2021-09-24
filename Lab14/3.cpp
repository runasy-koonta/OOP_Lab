#include <iostream>
using namespace std;

class Account {
private:
	string name;
	string id;
	int balance;
	
public:
	Account(): name(""), id(""), balance(0) {}
	Account(string _name, string _id, int _balance): name(_name), id(_id), balance(_balance) {}
	
	string getName() {
		return this->name;
	}
	string getId() {
		return this->id;
	}
	int getBalance() {
		return this->balance;
	}
	
	Account operator+(Account& acc2) {
		this->balance += acc2.getBalance();
		return *this;
	}
	Account operator-(Account& acc2) {
		this->balance -= acc2.getBalance();
		if (this->balance < 0) {
			this->balance = 0;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& cout, Account& acc) {
		cout << "학번: " << acc.getId() << ", 이름: " << acc.getName() << ", 잔액: " << acc.getBalance() << endl;
		return cout;
	}
};

int main() {
	Account acnt[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000),
	};

	while (true) {
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		string sdId;
		cin >> sdId;
		
		if (sdId == "종료") {
			cout << "종료합니다." << endl;
			break;
		}
		
		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		string rcvId;
		cin >> rcvId;
		
		if (rcvId == sdId) {
			cout << "보내는 학생과 받는 학생의 학번이 같습니다." << endl;
			continue;
		}
		int sender = -1, receiver = -1;
		for (int i = 0; i < 3; i++) {
			if (sdId == acnt[i].getId()) {
				sender = i;
			} else if (rcvId == acnt[i].getId()) {
				receiver = i;
			}
		}
		if (sender == -1 || receiver == -1) {
			cout << "보내는 학생 혹은 받은 학생의 학번이 존재하지 않습니다.다시 입력해주세요." << endl;
			continue;
		}
		
		if (acnt[sender].getBalance() <= 0) {
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}
		
		acnt[receiver] = acnt[receiver] + acnt[sender];
		acnt[sender] = acnt[sender] - acnt[receiver];
		
		cout << "보낸 학생의 잔액 => " << acnt[sender];
		cout << "받은 학생의 잔액 => " << acnt[receiver];
	}
	
	for (int i = 0; i < 3; i++) {
		cout << acnt[i];
	}
}

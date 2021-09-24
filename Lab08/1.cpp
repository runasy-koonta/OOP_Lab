#include <iostream>
#include <string>

using namespace std;

void getAnswer(string key, string& output) {
	cout << key << " : ";
	cin >> output;
}

int main(void) {
	string city, area, street, building;
	
	getAnswer("시", city);
	getAnswer("구", area);
	getAnswer("로", street);
	getAnswer("건물명", building);
	
	string address = city + area + street + building;
	
	cout << endl << "집 주소 : " << address << endl;
	
	return 0;
}
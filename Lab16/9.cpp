#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
	ofstream ofs;
	ofs.open("temp.txt");
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int r = rand() % 101;
			ofs << r << " ";
		}
		ofs << endl;
	}
	
	ofs.close();

	// 파일이름 입력
	// 입력받은 파일이름에 맞는 파일을 읽어와 vector로 입력 후, 출력 구현
	cout << "파일 이름 : ";
	string filename;
	cin >> filename;
	
	
	ifstream fin(filename);
	int row, col;
	try {
		if (!fin) throw exception();	
	} catch (exception &e) {
		cout << "File \"" << filename << "\" not found" << endl;
		return 0;
	}
	
	vector<vector<int>> data;
	for (int i = 0; i < 10; i++) {
		vector<int> q;
		for (int j = 0; j < 10; j++) {
			int k;
			fin >> k;
			q.push_back(k);
		}
		data.push_back(q);
	}
	
	
    cout << "출력할 행 크기 : ";
	cin >> row;
	
	cout << "출력할 열 크기 : ";
	cin >> col;
	
	try {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << data.at(i).at(j) << " ";
			}
			cout << endl;
		}
	} catch (exception &e) {
		cout << e.what();
	}

	return 0;
}

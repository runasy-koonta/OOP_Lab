#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

void get_num(int& num); 
void get_filename(string& filename);
void open_file(ifstream& fin, string filename); 
void countSameNum(ifstream& fin, int num, int& count);  

int main() {
   int num, count;

   string filename;

   ifstream fin;

   ofstream fout;



   get_filename(filename);

   get_num(num);

   open_file(fin,filename);

   countSameNum(fin, num, count);



   cout << "Output: " << count << endl;



   fin.close();

   return 0;

}

void open_file(ifstream& fin, string filename) {
	fin.open(filename);
	
	if (!fin.is_open()) {
		exit(0);
	}
}

void get_filename(string& filename) {
	cout << "Enter a file name: ":
	cin >> filename;
}

void get_num(int& num) {
	cout << "Enter a number: ":
	cin >> num;
}
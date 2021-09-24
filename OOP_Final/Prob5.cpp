#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
class Point {
public:
    T x, y;
    
	Point(T _x, T _y);
    bool operator==(Point &other);
};

template <typename T>
Point<T>::Point(T _x, T _y) {
	x = _x;
	y = _y;
}

template <typename T>
bool Point<T>::operator==(Point<T> &other) {
    if (other.x == x && other.y == y) {
        return true;
    } else {
        return false;
    }
}

void get_command(string& command) {
    cout << "1. Print" << endl;
    cout << "2. Find Points" << endl;
    cout << "0. Exit" << endl;
    cout << "Input>> ";

    cin >> command;
}

void print(Point<int> p) {
	cout << "(" << p.x << ", " << p.y << ")" << endl;
}

template <typename Iter, typename T>
void count_val(Iter iter_begin, Iter iter_end, const T& seek) {
	int x, y, count = 0;
	cout << "Enter (x, y): ";
	cin >> x, y;
	
	T p(x, y);
	
	for (auto it = iter_begin; it != iter_end; it++) {
		if (p == *it) {
			count++;
		}
	}
	cout << "Number of matching elements: " << count << endl;
}

int main() {
	Point<int> myPoints[] = { {1, 2}, {-1, 5}, {3, 7}, {2, 4}, {1, 10}, {1, 2} };
	string command;

	while (1) {
		get_command(command);

		if (command == "1") for_each(begin(myPoints), end(myPoints), print);
		else if (command == "2")      count_val<int>(begin(myPoints), end(myPoints), myPoints);
		else if (command == "0")      break;
	}

	cout << "Exit program.." << endl;

	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int inputGrade(float grade) {
	cin >> grade;
	if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100) {
		cout << "invalid input!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
		return (int)grade;
}
int* topGrade(vector<int>& grade) {
	int maxIndex = 0, maxValue = grade.at(0);
	for (int i = 0; i < grade.size(); i++) {
		if (grade.at(i) > maxValue) {
			maxIndex = i;
			maxValue = grade.at(i);
		}
	}
	return &(*(grade.begin() + maxIndex));
}

int main() {
	vector<int> grades;
	float _grade = 0;
	for(int i = 0; i < 3; i++) {
		cout << "Input " << i << "-th grade(0~100):";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}
	int* t = topGrade(grades);
	cout << "Top Grade: " << *t;
	return 0;
}
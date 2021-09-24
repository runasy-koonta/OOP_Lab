#include <iostream>
using namespace std;
int main(){
    int i, j, k;
    int ****a = new int*** [2];
    a[0] = new int** [2];
    a[1] = new int** [2];
	
	a[0][0] = new int*[5];
	a[0][1] = new int*[5];
	a[1][0] = new int*[5];
	a[1][1] = new int*[5];
	
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
			for(k=0; k<5; k++) {
				a[i][j][k] = new int;
				*(a[i][j][k]) = i + j + k;
				cout << *a[i][j][k] << " ";
			}
			cout << endl;
        }
        cout << endl;
    }
    return 0;
}


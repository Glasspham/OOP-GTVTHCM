#include"Bieuthuc.h"
using namespace std;

int main() {
	srand(time(0));
	while(1) {
		int level; cin >> level;
		Bieuthuc cauhoi(level);
		cout << cauhoi << endl;
		float traloi; cin >> traloi;
		cout << cauhoi.kiemtra(traloi);
	}
}
#include"Bieuthuc.h"
using namespace std;

int main() {
	srand(time(0));
	int level = 1, correct = 0, score = 0, n = 3;
	while(1) {
		Bieuthuc bt(level);
		cout << "Current level: " << level << endl;
		cout << bt << " = ?\n";
		float answer; cin >> answer;
		if(bt.kiemtra(answer)) {
			cout << "Corrent!\n";
			score += 1;
			correct += 1;
			if(correct == n) {
				cout << "Up 1 level\n";
				++level;
				correct = 0;
			}
		} else {
			cout << "Wrong! The correct answer was: " << bt.giatri() << endl;
			if(level > 1) --level;
			correct = 0;
		}
		cout << "Your score: " << score << endl;
		cout << "--------------------" << endl;
	}
}
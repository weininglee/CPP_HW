#include <iostream>
using namespace std;

int main() {
	int player_hp, player_attack, player_defense;
	int monster_hp, monster_attack, monster_defense;
	int turn = 1;
	cin >> player_hp >> player_attack >> player_defense;
		while (cin >> monster_hp >> monster_attack >> monster_defense) {
			while (player_hp > 0 && monster_hp > 0) {
				if (turn % 2 == 1) {
					if (player_attack > monster_defense) {
						monster_hp -= (player_attack - monster_defense);
					}
					turn++;
					cout << "Player:" << player_hp << " Enemy:" << monster_hp << endl;
				}
				else {
					if (player_defense < monster_attack) {
						player_hp -= (monster_attack - player_defense);
					}
					turn++;
					cout << "Player:" << player_hp << " Enemy:" << monster_hp << endl;
				}
			}
			if (player_hp > 0) cout << "Player Win" << endl;
			else if(player_hp <= 0) {
				cout << "Player Dead" << endl;
				break;
			}
			turn = 1;
		}
}
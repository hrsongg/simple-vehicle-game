#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
// map 크기 키우기 
// 랜덤함수로 장애물 위치 설정
char map[5][6] = {
	"#####",
	"# ^ #",
	"#  V#",
	"#D C#",
	"#####"
};
int carY = 1; // 초기위치 (1, 1)
int carX = 1;
int hp = 100;

void randomMap() { // 랜덤으로 map을 생성하는 함수
	// 벽, 빈 공간 초기화
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (y == 0 || y == 4 || x == 0 | x == 4) {
				map[y][x] == '#';
			}
			else {
				map[y][x] = ' ';
			}
		}
	}
	srand(time(NULL));	// 랜덤함수를 만들 기준점을 정한다. 
	// 현재 시간을 기준으로 랜덤한 수를 생성

	map[rand() % 3 + 1][rand() % 3 + 1] = 'V'; // 차량
	map[rand() % 3 + 1][rand() % 3 + 1] = 'C'; // 충전소
	map[rand() % 3 + 1][rand() % 3 + 1] = 'D'; // 탈출구
	map[rand() % 3 + 1][rand() % 3 + 1] = '^'; // 장애물


}


void printingMap(void) { // map 출력 
	system("cls"); //
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 6; x++) {
			if (y == carY && x == carX) {
				printf("@");
			}
			else {
				printf("%c", map[y][x]);
			}
		}
		printf("\n");
	}
	printf("( HP: %d )", hp);
}

void hp_up(void) {
	hp = 100;
	map[carY][carX] = ' ';
}

int main() {
	system("color 1F");
	randomMap();
	while (1) {
		printingMap();

		if (GetAsyncKeyState(VK_UP)) {
			if (carY > 0 && map[carY - 1][carX] != '#') {
				carY -= 1;
			}
			if (map[carY][carX] == 'V') {
				system("color 0F");
				break;
			}
			if (map[carY][carX] == 'D') {
				system("color 0A");
				break;
			}
			if (map[carY][carX] == '^') {
				hp -= 10;
				if (hp <= 0) {
					system("color 4F");
					break;
				}
			}
			if (map[carY][carX] == 'C') {
				hp_up();
			}
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			if (carY < 5 && map[carY + 1][carX] != '#') {
				carY += 1;
			}
			if (map[carY][carX] == 'V') {
				system("color 0F");
				break;
			}
			if (map[carY][carX] == 'D') {
				system("color 0A");
				break;
			}
			if (map[carY][carX] == '^') {
				hp -= 10;
				if (hp <= 0) {
					system("color 4F");
					break;
				}
			}
			if (map[carY][carX] == 'C') {
				hp_up();
			}
		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			if (carX > 0 && map[carY][carX - 1] != '#') {
				carX -= 1;
			}
			if (map[carY][carX] == 'V') {
				system("color 0F");
				break;
			}
			if (map[carY][carX] == 'D') {
				system("color 0A");
				break;
			}
			if (map[carY][carX] == '^') {
				hp -= 10;
				if (hp <= 0) {
					system("color 4F");
					break;
				}
			}
			if (map[carY][carX] == 'C') {
				hp_up();
			}
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			if (carX < 5 && map[carY][carX + 1] != '#') {
				carX += 1;
			}
			if (map[carY][carX] == 'V') {
				system("color 0F");
				break;
			}
			if (map[carY][carX] == 'D') {
				system("color 0A");
				break;
			}
			if (map[carY][carX] == '^') {
				hp -= 10;
				if (hp <= 0) {
					system("color 4F");
					break;
				}
			}
			if (map[carY][carX] == 'C') {
				hp_up();
			}
		}
		Sleep(100);



	}

	
	if (map[carY][carX] == 'V' || hp <= 0) {
		printf("\n\n\n\n\n\t\tgame over\n\n\n\n\n");
	}
	else if (map[carY][carX] == 'D') {
		printf("\n\n\n\n\n\t\t WIN ( HP: %d )\n\n\n\n\n", hp);
	}

	return 0;
}
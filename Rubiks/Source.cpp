#include<iostream>

void swap(char& a, char& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
class face {
public:
	char tiles[9];
	const char* populatetiles() { for (int i = 0; i < 9; i++)std::cin >> tiles[i]; }
	face* left;
	face* right;
	face* above;
	face* below;
	void setside(int s, face * a) {
		switch (s) {
		case 0:this->left = a; break;
		case 1:this->right = a; break;
		case 2:this->above = a; break;
		case 3:this->below = a; break;
		}
	}
	void rotatecw() {
		swap((right->tiles[0]), (below->tiles[0]));
		swap((right->tiles[3]), (below->tiles[1]));
		swap((right->tiles[6]), (below->tiles[2]));
		swap((left->tiles[2]), (above->tiles[8]));
		swap((left->tiles[5]), (above->tiles[7]));
		swap((left->tiles[8]), (above->tiles[6]));
		swap((right->tiles[0]), (left->tiles[8]));
		swap((right->tiles[3]), (left->tiles[5]));
		swap((right->tiles[6]), (left->tiles[2]));
	}
};
class Cube {
public:
	Cube() {}
	Cube(char a[6][10]) {
		green.setside(0, &orange);
		green.setside(1, &red);
		green.setside(2, &white);
		green.setside(3, &yellow);
		red.setside(0, &green);
		red.setside(1, &blue);
		red.setside(2, &white);
		red.setside(3, &yellow);
		blue.setside(0, &red);
		blue.setside(1, &orange);
		blue.setside(2, &white);
		blue.setside(3, &yellow);
		orange.setside(0, &blue);
		orange.setside(1, &green);
		orange.setside(2, &white);
		orange.setside(3, &yellow);
		white.setside(0, &green);
		white.setside(1, &blue);
		white.setside(2, &orange);
		white.setside(3, &red);
		yellow.setside(0, &green);
		yellow.setside(1, &blue);
		yellow.setside(2, &red);
		yellow.setside(3, &orange);
		for (int j = 0; j < 9; j++) {
			green.tiles[j] = a[0][j];
			red.tiles[j] = a[1][j];
			blue.tiles[j] = a[2][j];
			orange.tiles[j] = a[3][j];
			white.tiles[j] = a[4][j];
			yellow.tiles[j] = a[5][j];
		}


	};

	face green, red, blue, orange, white, yellow;
};
void displayface(char f, Cube& cube) {
	int c = 10;
	switch (f) {
	case 'g':while (c--)std::cout << cube.green.tiles[9 - c]; break;
	case 'r':while (c--)std::cout << cube.red.tiles[9 - c]; break;
	case 'b':while (c--)std::cout << cube.blue.tiles[9 - c]; break;
	case 'o':while (c--)std::cout << cube.orange.tiles[9 - c]; break;
	case 'w':while (c--)std::cout << cube.white.tiles[9 - c]; break;
	case 'y':while (c--)std::cout << cube.yellow.tiles[9 - c]; break;
	}
}
int main()
{
	Cube* cube;
	char orient[6][10] =
	{
	{"ggggggggg"},
	{"rrrrrrrrr"},
	{"bbbbbbbbb"},
	{"ooooooooo"},
	{"wwwwwwwww"},
	{"yyyyyyyyy"}
	};
	cube = new Cube(orient);
	cube->red.rotatecw();
	displayface('b', *cube);
}
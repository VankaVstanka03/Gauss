#include <iostream>
#include <Vector>
#include "My_vectors.h"
#include "My_matrix.h"
#include "GaussSolver.h"

void test1();
void test2();
void test3();
void test4();
void test5();


int main() {
	//std::cout << "test1" << std::endl;
	//test1();
	std::cout << "test2" << std::endl;
	test2();
	//std::cout << "test3" << std::endl;
	//test3();
	//std::cout << "test4" << std::endl;
	//test4();
	//std::cout << "test5" << std::endl;
	//test5();
	return 0;
}

void test1(){
	GaussSolver a1;
	Vector b(7);
	std::vector<int> posmax(7);
	b[0] = 0;
	b[1] = 4;
	b[2] = -4;
	b[3] = 0;
	b[4] = 0;
	b[5] = 1;
	b[6] = 0;
	Matrix a(7, 5);
	a[0][0] = 0;
	a[0][1] = 0;
	a[0][2] = 0;
	a[0][3] = 0;
	a[0][4] = 0;

	a[1][0] = 0;
	a[1][1] = 1;
	a[1][2] = 0;
	a[1][3] = -3;
	a[1][4] = 0;

	a[2][0] = 0;
	a[2][1] = 0;
	a[2][2] = -8;
	a[2][3] = 0;
	a[2][4] = 0;

	a[3][0] = 0;
	a[3][1] = 0;
	a[3][2] = 0;
	a[3][3] = 0;
	a[3][4] = 0;

	a[4][0] = 0;
	a[4][1] = 0;
	a[4][2] = 0;
	a[4][3] = 0;
	a[4][4] = 0;

	a[5][0] = 0;
	a[5][1] = 0;
	a[5][2] = 0;
	a[5][3] = 0;
	a[5][4] = 5;

	a[6][0] = 0;
	a[6][1] = 0;
	a[6][2] = 0;
	a[6][3] = 0;
	a[6][4] = 0;


	std::cout << a << std::endl;
	//std::cout << a.down_triangle(a,b,posmax) << std::endl;
	std::cout << b << std::endl;
	std::vector<Vector> otvet;
	otvet = a1.solve(a, b);
	//std::cout << a.down_triangle(a, b, posmax) << std::endl;
	//std::cout << b << std::endl;
	//std::cout << a.upper_triangle(a.down_triangle(a, b, posmax), b) << std::endl;
}

void test2(){
	GaussSolver a1;
	Vector b(5);
	std::vector<int> posmax(7);
	b[0] = -1;
	b[1] = 0;
	b[2] = 3;
	b[3] = 5;
	b[4] = 0;
	//b[5] = 1;
	//b[6] = 0;

	Matrix a(5, 7);
	a[0][0] = 2;
	a[0][1] = 3;
	a[0][2] = 5;
	a[0][3] = 3;
	a[0][4] = 0;
	a[0][5] = 0;
	a[0][6] = 0;
	
	a[1][0] = 0;
	a[1][1] = -4;
	a[1][2] = 0;
	a[1][3] = 8;
	a[1][4] = 0;
	a[1][5] = 1;
	a[1][6] = -7;
	
	a[2][0] = 0;
	a[2][1] = 0;
	a[2][2] = 0;
	a[2][3] = -8;
	a[2][4] = 0;
	a[2][5] = 1;
	a[2][6] = 4;
	
	a[3][0] = 0;
	a[3][1] = 0;
	a[3][2] = 0;
	a[3][3] = 0;
	a[3][4] = 0;
	a[3][5] = 1;
	a[3][6] = 0;
	
	a[4][0] = 0;
	a[4][1] = 0;
	a[4][2] = 0;
	a[4][3] = 0;
	a[4][4] = 0;
	a[4][5] = 0;
	a[4][6] = 0;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::vector<Vector> otvet;
	otvet = a1.solve(a, b);
	//Matrix d = a.down_triangle(a, b, posmax);
	//std::cout << a.down_triangle(a, b, posmax) << std::endl;
	//std::cout << d.upper_triangle(d, b) << std::endl;
	//std::cout << b << std::endl;
}

void test3(){
	GaussSolver a1;
	Vector b(3);
	std::vector<int> posmax(3);
	b[0] = 6;
	b[1] = 1;
	b[2] = -2;
	Matrix a(3, 3);
	a[0][0] = 1;
	a[0][1] = 2;
	a[0][2] = 3;

	a[1][0] = 3;
	a[1][1] = -7;
	a[1][2] = -1;

	a[2][0] = -2;
	a[2][1] = 9;
	a[2][2] = 4;


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::vector<Vector> otvet;
	otvet = a1.solve(a, b);
	//Matrix d = a.down_triangle(a, b, posmax);
	//std::cout << d << std::endl;
	//std::cout << b << std::endl;
	//std::cout << d.upper_triangle(d, b) << std::endl;
	//std::cout << b << std::endl;
}

void test4(){
	GaussSolver a1;
	Vector b(6);
	b[0] = -3;
	b[1] = 2;
	b[2] = -2;
	b[3] = 7;
	b[4] = 2;
	b[5] = 3;
	Matrix a(3, 6);
	a[0][0] = 1;
	a[0][1] = -1;
	a[0][2] = -2;
	a[0][3] = -3;
	a[0][4] = -3;
	a[0][5] = -3;
	a[1][0] = 3;
	a[1][1] = -2;
	a[1][2] = -1;
	a[1][3] = -2;
	a[1][4] = -2;
	a[1][5] = -2;
	a[2][0] = -2;
	a[2][1] = 1;
	a[2][2] = 3;
	a[2][3] = 3;
	a[2][4] = 3;
	a[2][5] = 3;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::vector<Vector> otvet;
	otvet = a1.solve(a, b);
}

void test5(){
	std::vector<int> posmax(3);
	GaussSolver a1;
	Vector b(6);
	b[0] = -3;
	b[1] = 2;
	b[2] = -2;
	b[3] = -3;
	b[4] = 2;
	b[5] = -2;
	Matrix a(6, 3);
	a[0][0] = 1;
	a[0][1] = -1;
	a[0][2] = -2;
	
	a[1][0] = 3;
	a[1][1] = -2;
	a[1][2] = -1;

	a[2][0] = -2;
	a[2][1] = 1;
	a[2][2] = 3;

	a[3][0] = -7;
	a[3][1] = 6;
	a[3][2] = 1;

	a[4][0] = 2;
	a[4][1] = 3;
	a[4][2] = 9;

	a[5][0] = 0;
	a[5][1] = 11;
	a[5][2] = 3;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//std::vector<Vector> otvet;
	//otvet = a1.solve(a, b);
	Matrix d = a.down_triangle(a, b, posmax);
	std::cout << a.down_triangle(a, b, posmax) << std::endl;
	std::cout << d.upper_triangle(d, b) << std::endl;
	std::cout << b << std::endl;
}

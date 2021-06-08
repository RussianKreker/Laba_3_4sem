#include<iostream>
#include <limits>
#include<fstream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include"queue.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file;
	file.open("text.txt", std::ios::in);
	int index_i, index_j;
	queue* que = new queue;
	reading(que, file);
	int size = que->get_size();
	int** matrix, **matrix_1;
	matrix = new int* [size];
	matrix_1 = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		matrix_1[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
	file.clear();
	file.seekg(0);
	creating_matrix(que, file, matrix, size);
	file.close();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix_1[i][j] = matrix[i][j];
		}
	}
	FU(matrix_1, size);
	cout.setf(std::ios::left);
	cout << "Mатрица всех путей: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << std::setw(3) <<matrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << "Mатрица кратчайших путей: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout<<std::setw(3)<< matrix_1[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << "Выберите города отправления: " << std::endl;
	for (int i = 0; i < que->get_size(); i++) {
		std::cout << i + 1 << " " << que->at(i) << std::endl;
	}
	std::cin >> index_i;
	std::cout << "Выберите город прибытия: " << std::endl;
	for (int i = 0; i < que->get_size(); i++) {
		std::cout << i + 1 << " " << que->at(i) << std::endl;
	}
	std::cin >> index_j;
	std::cout << "Наименьшая стоимость маршрута составляет: " << matrix_1[index_i-1][index_j-1]<< std::endl;
	return 0;
}
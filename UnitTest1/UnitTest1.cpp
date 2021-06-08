#include "pch.h"
#include "CppUnitTest.h"
#include "G:\Программирование\Тутуева\Laba_3_4sem\Laba_3_4sem\Laba_3_4sem\queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			queue* que = new queue;
			std::ifstream file;
			std::string cities[7] = { "Санкт-Петербург","Москва","Хабаровск","Владивосток","Мурманск","Сочи","Астрахань" };
			file.open("G:\\Программирование\\Тутуева\\Laba_3_4sem\\Laba_3_4sem\\Laba_3_4sem\\text.txt", std::ios::in);
			reading(que, file);
			for (int i = 0; i < que->get_size(); i++) 
			{
				Assert::IsTrue(que->at(i) == cities[i]);
			}
			file.close();
		}
		TEST_METHOD(Test2)
		{
			queue* que = new queue;
			std::ifstream file;
			file.open("G:\\Программирование\\Тутуева\\Laba_3_4sem\\Laba_3_4sem\\Laba_3_4sem\\text.txt", std::ios::in);
			reading(que, file);
			int size = que->get_size();
			int** matrix;
			matrix = new int* [size];
			for (int i = 0; i < size; i++) 
			{
				matrix[i] = new int[size];
			}
			for (int i = 0; i < size; i++) 
			{
				for (int j = 0; j < size; j++) 
				{
					matrix[i][j] = 0;
				}
			}
			file.clear();
			file.seekg(0);
			int matrix_1[7][7] = { {0,10,14,20,0,0,0},{20,0,40,0,0,0,0},{0,35,0,8,0,0,0},{0,0,13,0,0,0,0},{0,0,0,0,0,15,50},{0,0,0,0,10,0,40},{0,0,0,0,35,0,0} };
			creating_matrix(que, file, matrix, size);
			for (int i = 0; i < 7; i++) 
			{
				for (int j = 0; j < 7; j++) 
				{
					Assert::IsTrue(matrix[i][j] == matrix_1[i][j]);
				}
			}
			file.close();
			delete matrix;
		}
		TEST_METHOD(Test3)
		{
			queue* que = new queue;
			std::ifstream file;
			file.open("G:\\Программирование\\Тутуева\\Laba_3_4sem\\Laba_3_4sem\\Laba_3_4sem\\text.txt", std::ios::in);
			reading(que, file);
			int size = que->get_size();
			int** matrix;
			matrix = new int* [size];
			for (int i = 0; i < size; i++) 
			{
				matrix[i] = new int[size];
			}
			for (int i = 0; i < size; i++) 
			{
				for (int j = 0; j < size; j++) 
				{
					matrix[i][j] = 0;
				}
			}
			int** matrix_2;
			matrix_2 = new int* [size];
			for (int i = 0; i < size; i++) 
			{
				matrix_2[i] = new int[size];
			}
			for (int i = 0; i < size; i++) 
			{
				for (int j = 0; j < size; j++) 
				{
					matrix_2[i][j] = 0;
				}
			}
			file.clear();
			file.seekg(0);
			int matrix_1[7][7] = { {0,10,14,20,0,0,0},{20,0,34,40,0,0,0},{55,35,0,8,0,0,0},{68,48,13,0,0,0,0},{0,0,0,0,0,15,50},{0,0,0,0,10,0,40},{0,0,0,0,35,50,0} };
			creating_matrix(que, file, matrix, size);
			for (int i = 0; i < size; i++) 
			{
				for (int j = 0; j < size; j++) 
				{
					matrix_2[i][j] = matrix[i][j];
				}
			}
			FU(matrix_2, size);
			for (int i = 0; i < 7; i++) 
			{
				for (int j = 0; j < 7; j++) 
				{
					Assert::IsTrue(matrix_1[i][j] == matrix_2[i][j]);
				}
			}
			file.close();
			delete matrix;
			delete matrix_2;
		}
	};
}

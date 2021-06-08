#ifndef queue_H
#define queue_H
#include <iostream>
#include <string>
#include <fstream>

class queue
{
private:
	class queueNode 
	{
	public:
		queueNode* next;
		std::string city;
		queueNode(queueNode* next = nullptr)
		{
			this->next = next;
		};
		queueNode(std::string  city, queueNode* next = nullptr)
		{
			this->city = city;
			this->next = next;
		};
		~queueNode();

	};
public:
	queueNode* head;
	queueNode* tail;
	unsigned int size;
	queue() 
	{
		tail = nullptr;
		head = nullptr;
		size = 0;
	}
	~queue() 
	{
		clear();
	}
	unsigned int get_size() 
	{
		return size;
	}
	void clear() 
	{
		while (size != 0)
		{
			pop();
		}
	}
	void push(std::string  city) 
	{
		if (size == 0) {
			head = new queueNode(city);
			tail = head;
		}
		else {
			tail->next = new queueNode(city);
			tail = tail->next;
		}
		size++;
	}
	void pop() {
		if (size == 0) 
		{
			return;
		}
		if (size == 1)
		{
			delete head;
			reset_list();
		}
		else {
			queueNode* current = head;
			head = head->next;
			delete current;
		}
		size--;
	}
	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}
	std::string  at(unsigned int index)
	{
		if (index >= size) 
		{
			throw "Index is greater than list size";
		}
		else 
		{
			queueNode* current = head;
			unsigned int counter = 0;
			while (counter != index)
			{
				current = current->next;
				counter++;
			}
			return current->city;
		}
	}
};
#endif

void reading(queue* que, std::ifstream& text)
{
	std::string str, city;
	int count = 0;
	bool flag = true;
	while (!text.eof())
	{
		std::getline(text, str);
		for (unsigned int i = 0; i < str.size(); i++)
		{
			if (str[i] != ';')
			{
				city += str[i];
			}
			else if (count != 2)
			{
				for (int j = 0; j < que->get_size(); j++)
				{
					if (city == que->at(j))
					{
						flag = false;
					}
				}
				if (flag)
				{
					que->push(city);
				}
				flag = true;
				count++;
				city.clear();
			}
			else
			{
				city.clear();
				break;
			}
		}
		count = 0;
	}
	str.clear();
	city.clear();
}
void creating_matrix(queue* que, std::ifstream& text, int** matrix, int N)
{
	std::string str, word;
	int count = 0;
	int unit_1 = 0, unit_2 = 0;
	while (!text.eof())
	{
		std::getline(text, str);
		for (unsigned int i = 0; i < str.size() + 1; i++)
		{
			if (str[i] != ';' && i < str.size())
			{
				word += str[i];
			}
			else if (count < 2)
			{
				for (int j = 0; j < que->get_size(); j++)
				{
					if (word == que->at(j))
					{
						if (count == 0)
							unit_1 = j;
						else
							unit_2 = j;
						break;
					}
				}
				count++;
				word.clear();
			}
			else {
				if (count == 2)
				{
					if (word != "N/A")
					{
						matrix[unit_1][unit_2] = atoi(word.c_str());
					}
					else
					{
						matrix[unit_1][unit_2] = 0;
					}
				}
				else
				{
					if (word != "N/A")
					{
						matrix[unit_2][unit_1] = atoi(word.c_str());
					}
					else
					{
						matrix[unit_2][unit_1] = 0;
					}
				}
				count++;
				word.clear();
			}
		}
		count = 0;
		word.clear();
	}
	str.clear();
	word.clear();
}
void FU(int** D, int N)
{
	int V = N;
	for (int i = 0; i < V; i++) D[i][i] = 0;

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			for (int k = 0; k < V; k++)
				if (D[j][i] && D[i][k] && j != k)
					if (D[j][i] + D[i][k] < D[j][k] || D[j][k] == 0)
						D[j][k] = D[j][i] + D[i][k];
}
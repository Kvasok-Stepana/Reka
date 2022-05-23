#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

//task1
struct Node {
	Node();
	Node(int nameNode);
	~Node();
	
	Node* parent;
	std::list<Node*> listChilds;
	int name;
	static int countNodes;
};

class Graph {
	private :
		Node* head;
		list<Node*> ar;
		int chis;
		//здесь можно писать любые функции, которые могут понадобиться
	public :
		Graph();			
		Graph(int countNodes);
        ~Graph();
		/*
			output		:	-1 - если функция не реализована
						:	положительное число -- число узлов
			author		:
			date		:
			version		:
		*/
		int buildTreeBFS(int countNodes);
		/*
			output		:	-1 - если функция не реализована
						:	положительное число -- число узлов
			author		:
			date		:
			version		:
		*/			
		int buildTreeDFS(int countNodes);
		/*
			description	:	обход графа и записи вершин в файл
			input		:
			output		:
			author		:
			date		:
			version		:
		*/
		void BFS();
		void DFS();
		/*
			description	:	функция поиска узла по его имени,
							DFS - № студ билет чётный
							BSD - № студ билет нечётный
			input 		:	nameNode -- имя узла
			output		:	{bool -- узел найде, list<int> -- список имён узлов до необходимого}
			description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
			author		:
			date		:
			version		:
		*/
		std::pair<bool, list<int>> searchDFS(int nameNode);		
		std::pair<bool, list<int>> searchBFS(int nameNode);
};

//task2
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

//task3
template<class T>
class Filo {
	private :
		T* ar;	//массив
		int size;	//размер массива
		int countData;	//число элементов в массиве
	public :
		Filo() {
			size = 256;
			ar = new T[size];
			countData = 0;
		}
		Filo(int _size) {
			size = _size;
			ar = new T[size];
			countData = 0;
		}
		~Filo() {
			delete ar;
		}
		/*
			input		:	элемент который надо добавить
			output		:	1 - элемент добавлен, 0 - элемент не добавлен
			description	:	добавление элемента в конец массива				
		*/
		int push_back(T el) {
			if (size <= countData) {
				return (0);
			}
			if (size > countData) {
				ar[countData + 1] = el;
				countData++;
				return (1);
			}
		}
		/*
			input		:	элемент который надо добавить
			output		:	пара 
							значение первого аргумента пары
								1 - элемент успешно извлечён, 0 - элементов в массиве нет
							значение второго аргумента пары -- это извлечённый элемент
			description	:	извлечение элемента из массива
		*/
		pair<int,T> pop_back() {
			if (countData != 0) {
				pair<int, T> p = make_pair(1, ar[countData++]);
				countData--;

				return (p);
			}
			else {
				pair<int, T> p = make_pair(0, 0);
				return (p);
			}
		}
		/*
			input		:	элемент который надо добавить
			output		:	пара 
							значение первого аргумента пары
								1 - элемент успешно извлечён, 0 - элементов в массиве нет
							значение второго аргумента пары -- это извлечённый элемент
			description	:	извлечение элемента из массива
		*/
		void returnAr() {}
};

//task4
ostream& operator<<(ostream& ostr, const pair<int, int> znach)
{
	return (ostr << "(" << znach.first << "," << znach.second << ")\n");
}
//task5
template<class T>
class CheckBrackets : public Filo<char> {
private:
    //можно объявляеть любые переменные и функции
public :
    CheckBrackets() : Filo<char>() { }
    ~CheckBrackets() {}
	/*
		input		:	строка со скобками
		output		:	0 - всё хорошо, -1 - скобок не хватает
		description	:	проверка скобок
	*/
    int checkBrackets(const char* strBrackets) {}
};

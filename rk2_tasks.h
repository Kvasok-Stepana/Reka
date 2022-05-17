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

int factorial (int x)
{
    if( x == 0 ) return 1;
    return x * factorial (x - 1);
}

struct Node {
    Node();
    Node(int nameNode);
    ~Node();

    Node* parent;
    list<Node*> listChilds;
    int name;
    int countNodes;
};

class Graph {
private :
    Node* head;
    list<Node*> ar;
    int chis;
    //здесь можно писать любые функции, которые могут понадобиться
public :
    Graph(){
        Node *buf  = new Node;
        head=buf;
        head->name=0;
        chis=0;
    };
    Graph(int countNodes);///ЗАЧЕМ???????????
    ~Graph(){};

    int buildTreeBFS(int countNodes);
    void BFS();
    void DFS();


    pair<bool, list<int>> searchDFS(int nameNode);
    pair<bool, list<int>> searchBFS(int nameNode);
};

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
        countData =0;
    }
    Filo(int _size){
        size = _size;
        ar = new T[size];
        countData =0;
    }
    ~Filo(){
    delete ar;
}
    /*
        input		:	элемент который надо добавить
        output		:	1 - элемент добавлен, 0 - элемент не добавлен
        description	:	добавление элемента в конец массива
    */
    int push_back(T el){
        if (size<=countData){
            return (0);
        }
        if (size>countData){
            ar[countData+1]=el;
            countData++;
            return (1);
        }
    }

    pair<int,T> pop_back(){
        if (countData!=0){
            pair<int,T> p = make_pair(1,ar[countData++]) ;
            countData--;

            return (p);
        } else{
            pair<int,T> p = make_pair(0,0);
            return (p);
        }

    }

};

class CheckBrackets : public Filo<char> {
private:
int skobki [256];
    //можно объявлять любые переменные и функции
public :
    CheckBrackets() : Filo<char>() { }
    ~CheckBrackets() {}

    /*
        input		:	строка со скобками
        output		:	0 - всё хорошо, -1 - скобок не хватает
        description	:	проверка скобок,
    */
    int checkBrackets(const char* strBrackets);
};



Node::Node(int nameNode);

int Graph::buildTreeBFS(int countNodes);


void Graph::BFS();


pair<bool, list<int>>Graph::searchBFS(int nameNode);


pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);
////////2

////////3
ostream& operator<<(ostream& ostr, const pair<int,int> znach )
{
    return (ostr << "(" << znach.first << "," << znach.second << ")\n");
}
///////4
template<>
int CheckBrackets<char>::checkBrackets(const char *strBrackets);
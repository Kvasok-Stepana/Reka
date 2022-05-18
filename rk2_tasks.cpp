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

#include "rk2_tasks.h"

int factorial (int x)
{
    if( x == 0 ) return 1;
    return x * factorial (x - 1);
}




Node::Node() {
    int name=0;
    Node* parent = NULL;
    list<Node*> listChilds;
}
Node::~Node() {
    //// реализховать!!!!!!!!!

}

Node::Node(int nameNode) {
    int n= nameNode;
    list<Node*> generejka;
    for (int i = 1; i < factorial(n)*n+1; ++i) {
        Node *buf  = new Node;
        buf -> name = i;
        generejka.push_back(buf);
    }

    int k=0;
    auto iter = generejka.begin();


    auto a = iter.operator*();



    int b=n;
    int c=n-1;
    auto iterpot = generejka.begin();
    for (int i = 0; i < n; ++i) {
        iterpot++;
    }
    while (b-k>1)
    {
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < n-k-1; ++j)
            {
                iter.operator*()->listChilds.push_back(iterpot.operator*());
                iter.operator*()->countNodes=n-k-1;
                iterpot.operator*()->parent=iter.operator*();
                iterpot.operator*()->countNodes=n-k-2;
                iterpot++;
            }
            iter++;
        }
        b=b*c;
        c=c-1;
        k++;
    }
    if (b-k==1)
    {
        for (int i = 0; i < b*n; ++i) {
            for (int j = 0; j < 1; ++j) {
                iter.operator*()->listChilds.push_back(iterpot.operator*());
                iter.operator*()->countNodes=1;
                iterpot.operator*()->parent=iter.operator*();
                iterpot.operator*()->countNodes=0;
                iterpot++;
            }
            iter++;
        }
    }
/////////////////////////////Батотает!!! не забыть привязать к нулевому корешу

    iter = generejka.begin();
    auto prov=iter.operator*()->listChilds.front();


////////Вывод в ширь
    k=0;
    iter = generejka.begin();
    b=n;
    c=n-1;
    iterpot = generejka.begin();
    for (int i = 0; i < n; ++i) {
        iterpot++;
    }
    while (b-k>1)
    {
        for (int i = 0; i < b; ++i)
        {
            cout<<iter.operator*()->name<<"{";
            for (int j = 0; j < n-k-1; ++j)
            {
                cout<<iterpot.operator*()->name;
                if (j!=n-k-2){
                    cout<<",";
                }
                iterpot++;
            }
            cout<<"} ";
            iter++;
        }
        b=b*c;
        c=c-1;
        k++;
    }
    if (b-k==1)
    {
        for (int i = 0; i < b*n; ++i) {
            cout<<iter.operator*()->name<<"{";
            for (int j = 0; j < 1; ++j) {
                cout<<iterpot.operator*()->name;

                cout<<",";
                iterpot++;
            }
            cout<<"} ";
            iter++;
        }
    }


//////Рас_Ширяемо (проходка в ширь есть )
    cout<<endl;


/////Глубинка
    iter = generejka.begin();





}

int Graph::buildTreeBFS(int countNodes) {
    int n= countNodes;
    int r=n-1;
    int q=n;
    chis=n;

    while(r!=0)
    {
        chis=chis+q*r;
        q=q*r;
        r--;
    }
    list<Node*> generejka;
    for (int i = 1; i < factorial(n)*n+1; ++i) {
        Node *buf  = new Node;
        buf -> name = i;
        generejka.push_back(buf);
    }

    int k=0;
    auto iter = generejka.begin();


    auto a = iter.operator*();



    int b=n;
    int c=n-1;
    auto iterpot = generejka.begin();
    for (int i = 0; i < n; ++i) {
        iterpot.operator*()->parent=head;
        iterpot++;

    }

    while (b-k>1)
    {
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < n-k-1; ++j)
            {
                iter.operator*()->listChilds.push_back(iterpot.operator*());
                iterpot.operator*()->parent=iter.operator*();
                iterpot++;

            }
            iter++;
        }
        b=b*c;
        c=c-1;
        k++;
    }
    if (b-k==1)
    {
        for (int i = 0; i < b*n; ++i) {
            for (int j = 0; j < 1; ++j) {
                iter.operator*()->listChilds.push_back(iterpot.operator*());
                iterpot.operator*()->parent=iter.operator*();
                iterpot++;
            }
            iter++;
        }
    }

    iter = generejka.begin();

    for (int i = 0; i < countNodes; ++i) {

        head->listChilds.push_back(iter.operator*());
        iter.operator*()->parent=head;

        iter++;


    }
    ar=generejka;
}


void Graph::BFS(){
    int k=0;
    ofstream fout("bfs_res");
    auto iter = ar.begin();
    auto iterpot =iter;
    for (int i = 0; i < head->listChilds.back()->name; ++i) {
        iterpot++;
    }
    int n=head->listChilds.back()->name;


    int b=n;
    int c=n-1;

    while (b-k>1&&c>0)
    {
        for (int i = 0; i < b; ++i)
        {
            fout<<iter.operator*()->name<<"{";
            for (int j = 0; j < n-k-1; ++j)
            {fout<<iterpot.operator*()->name;
                if (j!=n-k-2){
                    fout<<",";
                }

                iterpot++;
            }
            iterpot--;
            if (chis!=iterpot.operator*()->name)
                fout<<"}\n";

            if (chis==iterpot.operator*()->name)
                fout<<"}";
            iterpot++;
            iter++;
        }
        b=b*c;
        c=c-1;
        k++;
    }

    if (b-k==1)
    {
        for (int i = 0; i < b*n; ++i) {
            fout<<iter.operator*()->name<<"{";
            for (int j = 0; j < 1; ++j) {
                fout<<iterpot.operator*()->name<<",";
                iterpot++;
            }
            fout<<"} ";
            iter++;
        }
    }
    fout.close();
}


pair<bool, list<int>>Graph::searchBFS(int nameNode) {
    int k=0;
    auto iter =ar.begin();
    for (int i = 0; i < chis; ++i) {
        if (iter.operator*()->name==nameNode){
            k++;
            break;
        }
        iter++;
    }
    list<int> vivod;
    while (iter.operator*()->name!=head->name){
        vivod.push_back(iter.operator*()->name);
        iter.operator*()=iter.operator*()->parent;
    }
    if (k==0){
        vivod.push_back(0);
        pair<bool, list<int>> a;
        make_pair(0,vivod);
        return (a);
    } else
    {
        pair<bool, list<int>> a;
        make_pair(1,vivod);
        return (a);
    }

}


pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el) {
    static int n = 1;

    static bool ch=0;
    static int k=1;
    n=1;
    if (sizeAr == 1  && ar[0]!=el) {
        return {0,0};
    }
    if (ar[(sizeAr / 2)-1] == el) {
        return {k, n};
    } else
    {
        if (el < ar[(sizeAr / 2)]) {

            if (sizeAr%2==1) {
                if (ch==1){
                    ch=0;
                    binSearch(&ar[0], (sizeAr / 2)-1, el);
                } else{
                    ch=0;
                    binSearch(&ar[0], (sizeAr / 2), el);
                }
            }
            if (sizeAr%2!=1) {
                if (ch==1){
                    ch=0;
                    binSearch(&ar[0], (sizeAr / 2)-1, el);
                } else{
                    ch=0;
                    binSearch(&ar[0], (sizeAr / 2), el);
                }
            }
        } else
        {
            if (sizeAr%2==1) {
                ch++;
                if (sizeAr / 4==1){
                    ch++;
                    binSearch(&ar[(sizeAr / 2)], (sizeAr / 2) , el);
                } else{
                    ch++;
                    binSearch(&ar[(sizeAr / 2)+1], (sizeAr / 2) , el);
                }
            }
            if (sizeAr%2!=1) {
                if (sizeAr / 4==1){
                    ch++;
                    binSearch(&ar[(sizeAr / 2)], (sizeAr / 2) , el);
                } else{
                    ch++;
                    binSearch(&ar[(sizeAr / 2)+1], (sizeAr / 2) , el);
                }
            }
        }
        n++;
    }
    k=1;
    for (int i = 0; (el!= ar[i])&&i<=sizeAr; ++i) {

        k++;

    }

    return {k++, n};


}
////////2

////////3
///////4
template<>
int CheckBrackets<char>::checkBrackets(const char *strBrackets)
{
    int length = strlen(strBrackets);
    if (length % 2 != 0)
    {
        return -1;
    }
    int iter=0;
    for (int i = 0; i < length; i++)
    {
        auto x=pop_back().second;
        if (x == '}')
        {
            skobki[iter]=1;
            iter++;
        }
        if (x == ')')
        {
            skobki[iter]=2;
            iter++;
        }
        if (x == ']')
        {
            skobki[iter]=3;
            iter++;
        }
        //проверка на вшивость


        if (x == '{')
        {
            iter--;
            if(skobki[iter]!=1);
            return -1;
        }
        if (x == '(')
        {
            iter--;
            if(skobki[iter]!=2);
            return -1;

        }
        if (x == '[')
        {
            iter--;
            if(skobki[iter]!=3);
            return -1;

        }
        return 0;
    }
}

/*
   File Node.h

   Class Node

   Class Node stores integer values for a linked list.

   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/
#include <iostream>
#include "ClockCalendar.cpp"

using namespace std;

template <class T>
class Node{
    T val;
    Node* next;
    ClockCalendar dataHora;
    int id;

  public:
    Node<T>(T dat, Node* nxt, int idt);
    Node(T dat, Node* nxt, int idt, int d, int m, int y, int h,int min,int s);
    ~Node();
    T getVal();
    int getId();
    void getDataHora(int& d, int& m, int& y, int& h, int& min, int& sec, bool& pm);
    Node* getNext();
    void setVal(T dat);
    void setNext(Node* nxt);
};

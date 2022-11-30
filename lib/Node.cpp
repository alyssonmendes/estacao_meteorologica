/*
   File Node.cpp

   Class Node

   Class Node stores integer values for a linked list.

   This file has the implementation for the Node's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "Node.h"


// Constructor - initializes the node
//
template <class T>
Node<T>::Node(T dat, Node* nxt, int idt){
       val = dat;
       next = nxt;
       id = idt;
}

template <class T>
Node<T>::Node(T dat, Node* nxt, int idt, int d, int m, int y, int h,int min,int s){
       val = dat;
       next = nxt;
       ClockCalendar dataHora(d, m, y, h,min,s);
       id = idt;
}


template <class T>
Node<T>::~Node(){
}
// getVal returns the integer value stored in the node
//
template<class T>
T Node<T>::getVal(){
     return val;
}

// getNext returns a pointer for the next node in the linked list
//
template<class T>
Node<T>* Node<T>::getNext(){
     return next;
}

// setVal stores the integer value in the node
//
template<class T>
void Node<T>::setVal(T dat){
     val = dat;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
template<class T>
void Node<T>::setNext(Node* nxt){
       next = nxt;
}

template<class T>
int Node<T>::getId(){
     return id;
}

template<class T>
void Node<T>::getDataHora(int& d, int& m, int& y, int& h, int& min, int& sec, bool& pm){
    dataHora.readCalendar(d,m,y);
    dataHora.readClock(h, min, sec, pm);
       
    }


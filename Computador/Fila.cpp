/*
   File Fila.cpp

   Class Fila stores Nodes (class Node) in a linked queue.

   This file has the implementation for class Fila

   Class list is definition for a linked list, having the following operations:

   1. Initialize the list to an empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   4. Add a node with a given value into the list following
      the first node with another given value.
   5. Add a node with a given value to the front of the list.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "Fila.h"

template<class T>
Fila<T>::Fila()
{
    head = 0;
}
template<class T>
Fila<T>::~Fila()
{
    Node<T>* cursor = head;
    while(head)
    {
        cursor = cursor->getNext();
        delete head;
        head = cursor;
    }
    head = 0; // Officially empty
}

template<class T>
void Fila<T>::insertAfterLast(T dat,ClockCalendar* dataHora,int id)
{
    Node<T>* p = head;
    Node<T>* q = head;

    if (head == 0)
        head = new Node<T>(dat, head, dataHora, id);
    else
    {
        while (q != 0)
        {
            p = q;
            q = p->getNext();
        }
        p->setNext(new Node<T>(dat,0, dataHora, id));
    }
}

template<class T>
void Fila<T>::insertAfterLast( int id, int d, int m, int y, int h, int min, int s, T dat)
{
    Node<T>* p = head;

    Node<T>* q = head;

    if (head == 0)
        head = new Node<T>(dat, head,id, d, m, y,h, min, s);

    else
    {
        while (q != 0)
        {
            p = q;
            q = p->getNext();
        }
        p->setNext(new Node<T>(dat,0, id, d, m, y,h, min, s));
    }
}

template<class T>
string Fila<T>::readFirst()  //Envia para a serial no formato
{
    int d,m,a,h,min,sec;           //id,dia,mes,ano,hora,min,seg,temp
    bool pm;                       //separado por virgula
    //return head->getVal();
    stringstream buffer;
    head->readCalendar(d,m,a);
    head->readClock(h, min, sec,pm);
    //cout << d<<"/"<<m<<"/"<<a<<endl;
    buffer << head->getId() << "," << d << "," << m << "," << a
           << ","<< h << "," <<  min << "," <<  sec << "," << head->getVal() << endl  ;
    cout << "\nEnviando para serial:\n";
    cout << buffer.str()<< endl;
    return buffer.str();
}

template<class T>
void Fila<T>::removeFirst()
{
    T retval = 0;
    if (head != 0)
    {

        cout << "Removendo: " << head;
        cout << " e fica:" << head->getVal() << endl;

        //retval = head->getVal();
        Node<T>* oldHead = head;
        head = head->getNext();
        delete oldHead;

    }
    else
        cout << "Fila vazia!\n";
}

template<class T>
void Fila<T>::listAll()
{
    Node<T>* aux = head;
    int d,m,a,h,min,sec;
    bool pm;
    cout << "\nListando todos os eventos...\n";
    cout << "========================================================================================="<<endl;
    cout << "|\t ID \t|\t Data\t \t|\t Hora \t\t|\t Temperatura\t|"<< endl;
    cout << "========================================================================================="<<endl;
    do
    {
        aux->getDataHora(d,m,a,h,min,sec,pm);
        //aux->readCalendar(d,m,a);
        //aux->readClock(h, min, sec,pm);

        cout <<"|\t" << aux->getId();
        cout.fill( '0' );
        cout.width(2);
        cout << "\t|\t" << setw(2)<< d << "/" << setw(2) << m << "/" << setw(2) << a << "\t|\t"
             << setw(2)<< h << ":" << setw(2) << min << ":" << setw(2) << sec << "\t|\t";
        cout << aux->getVal()  << " oC\t\t|"<< endl  ;

        aux = aux->getNext();
    }
    while (aux != 0);
    cout << "========================================================================================="<<endl;
}

template<class T>
int Fila<T>::tamanhoFila()
{
    Node<T>* aux = head;
    int i=0;
    while(aux != 0)
    {
        aux = aux->getNext();
        i++;
    }
    return i;
}

template<class T>
void Fila<T>::listIntervalo(int d1, int m1, int a1, int d2, int m2, int a2)
{
    Node<T>* aux = head;
    int d,m,a,h,min,sec, cont =0;
    bool pm;


    do
    {
        aux->getDataHora(d,m,a,h,min,sec,pm);
        if(d >= d1 && d <= d2 && m >= m1 &&  m <= m2 && a >= a1 && a <= a2)
            cont++;
        aux = aux->getNext();
    }    while(aux!=0);

    aux = head;
    if(cont)
    {
        cout << "\nListando eventos de "<< setw(2) << d1 << "/"<< setw(2) << m1 << "/" << a1 <<
             " a " << setw(2)<< d2 << "/" << setw(2)<< m2 << "/" << a2<< endl<<endl;
        cout << "========================================================================================="<<endl;
        cout << "|\t ID \t|\t Data\t \t|\t Hora \t\t|\t Temperatura\t|"<< endl;
        cout << "========================================================================================="<<endl;


        do
        {
            aux->getDataHora(d,m,a,h,min,sec,pm);
            if(d >= d1 && d <= d2 && m >= m1 &&  m <= m2 && a >= a1 && a <= a2 )
            {
                //aux->readCalendar(d,m,a);
                //aux->readClock(h, min, sec,pm);

                cout <<"|\t" << aux->getId();
                cout.fill( '0' );
                cout.width(2);
                cout << "\t|\t" << setw(2)<< d << "/" << setw(2) << m << "/" << setw(2) << a << "\t|\t"
                     << setw(2)<< h << ":" << setw(2) << min << ":" << setw(2) << sec << "\t|\t";
                cout << aux->getVal()  << " oC\t\t|"<< endl  ;
            }

              aux = aux->getNext();


        }while(aux!=0);


        cout << "========================================================================================="<<endl;

    }
    else
        cout << "\nNao ha dados para esse intervalo de datas!\n";

}

#ifndef LISTADOBLELIGADA_H
#define LISTADOBLELIGADA_H

#include <iostream>

using namespace std;
template <class T>
class listadobleligada
{
    public:
        listadobleligada();
        ~listadobleligada();

        bool empty();

        //insertar
        void push_front(const T &dato);
        void push_back(const T &dato);
        size_t size();

        //imprimir
        void print();
        void print_reverse();
        T* front();
        T* back();
        T* find(const T &dato);
        listadobleligada& operator<<(const T &dato)
        {
            push_back(dato);
            return *this;
        }
    private:
        struct Nodo {

            T dato;
            Nodo *sig;
            Nodo *ant;

            Nodo(const T &dato, Nodo *sig=nullptr, Nodo *ant=nullptr):dato(dato),sig(sig),ant(ant){}
        };

        Nodo *head;
        Nodo *tail;
        size_t cont;
};

template <class T>
listadobleligada<T>::listadobleligada()
{
    head=nullptr;
    tail=nullptr;
    cont =0;
}

template <class T>
listadobleligada<T>::~listadobleligada()
{
 //Eliminar todos los nodos
}
template <class T>
bool listadobleligada<T>::empty()
{
    return cont==0;
}
template <class T>
void listadobleligada<T>::push_front(const T &dato)
{
    Nodo *nodo=new Nodo(dato,head);
    if(cont==0){
        head=nodo;
        tail=nodo;

    }else{
        head->ant=nodo;
        head=nodo;
    }
    cont++;
}
template <class T>
void listadobleligada<T>::push_back(const T &dato)
{
    Nodo *nodo=new Nodo(dato,nullptr,tail);
    if(cont==0){
        head=nodo;
        tail=nodo;
    }else{
        tail->sig=nodo;
        tail=nodo;
    }
    cont++;
}
template <class T>
size_t listadobleligada<T>::size()
{
    return cont;
}
template <class T>
void listadobleligada<T>::print()
{
    Nodo *temp= head;
    while(temp!=nullptr)
    {
        cout<<temp->dato<<endl;
        temp=temp->sig;
    }
}
template <class T>
T* listadobleligada<T>::find(const T &dato)
{
  Nodo *nodo=new Nodo(dato);
  Nodo *temp=head;
  while(temp!=nullptr)
  {
    if(nodo->dato == temp->dato){
        return &temp->dato;
    }
    temp=temp->sig;
  }
return nullptr;
}
template <class T>
void listadobleligada<T>::print_reverse()
{
    Nodo *temp=tail;
    while(temp!=nullptr)
    {
        cout<<temp->dato<<endl;
        temp=temp->ant;
    }

}
template <class T>
T* listadobleligada<T>::front()
{
    if(empty()){
        return nullptr;
    }else{
        return &head->dato;
    }
}
template <class T>
T* listadobleligada<T>::back()
{
    if(empty()){
        return nullptr;
    }else{
        return &tail->dato;
    }
}

#endif // LISTADOBLELIGADA_H

#include <iostream>
#include "listadobleligada.h"
using namespace std;

int main()
{
    listadobleligada<int> enteros;

    enteros.push_front(1);
    enteros.push_front(2);
    enteros.push_front(3);
    enteros<<4<<5<<6;

    cout << "Cantidad: "<<enteros.size() << endl;
    enteros.print();
    cout<<endl;
//-------------------------------------------------------------//
     int *ptr_01 = enteros.find(1); // buscar un elemento
    if (ptr_01) {                    // si no es nulo
        *ptr_01 = 3;                 // cambiar valor
    }

     int *ptr_02 = enteros.find(0);   // buscar un elemento
    if (ptr_02 == nullptr) {         // si es nulo
        enteros << 0;                // inserta al final
    }

    cout << "Cantidad: "<<enteros.size() << endl;
    enteros.print();










    /*enteros.print_reverse();
    cout<<endl;

    //Front
    int *front=enteros.front();

    if(front){
        cout<<"Front: "<<*front<<endl;
    }

    //Back
    int *back=enteros.back();
    if(back){
        cout<<"back: "<<*back<<endl;
    }*/
    return 0;
}

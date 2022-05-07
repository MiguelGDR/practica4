#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <array>
#include <string>
#include <cassert>
#include "centros.hpp"

using namespace std;
using namespace bblProgII;

char menu()
{
    system("cls");
    cout << "Opciones para manipular la lista de centros" << endl;
    cout << "0.- Fin." << endl;
    cout << "1.- Insertar centro." << endl;
    cout << "2.- Eliminar centro." << endl;
    cout << "3.- Consultar lista de centros." << endl;
    cout << "4.- Consultar si un elemento esta en la lista." << endl;
    cout << "5.- Consultar el numero de elementos de la lista." << endl;
    cout << "6.- Copiar lista de centros (constructor de copia)." << endl;

    char op;

    do
    {
        cout << " Opcion ?:  ";
        cin >> op;
    } while (op < '0' || op > '6');

    cin.ignore(1000, '\n');
    cout << endl;
    return op;
}

int main()
{
    Centros centro;
    char op;
    bool fin = 1;

    while (fin)
    {
        op = menu(); // Obtengo el valor

        switch (op)
        {
        case '0': // Fin.
        {
            fin = 0; // Finalizo activando el flag
            break;
        }

        case '1': // Insertar centro.
        {
            system("cls"); // Limpio la consola

            if (centro.num_centros() == 10) // Compruebo que hay espacio
            {
                cout << "La lista esta llena." << endl;
                cout << endl;
                system("pause");
                break; // Si no hay espacio, salgo del switch
            }

            string nombre;
            bool insertado = 0;

            cout << "Introduzca el nombre del centro: ";
            while (!insertado)
            {
                getline(cin, nombre);
                system("cls");

                centro.insertar_centro(nombre, insertado);
                if (!insertado)
                {
                    cout << "El centro '" << nombre << "' ya esta en la lista." << endl;
                    cout << "Introduzca un nuevo nombre: ";
                }
            }
            cout << "Centro '" << nombre << "' insertado correctamente a la lista." << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '2':
        {
            system("cls");

            if (centro.num_centros() == 0)
            {
                cout << "La lista esta vacia." << endl;
                cout << endl;
                system("pause");
                break; // Si no hay nada que eliminar, salgo del switch
            }

            string nombre = "";
            string centros;
            centro.consultar_centros(centros); // Obtengo el string con todos los centros
            bool eliminado = 0;

            cout << "Lista actual de los centros es: " << centros << endl;
            cout << " Que centro quieres eliminar? (Escribe su nombre): ";
            while (!eliminado)
            {
                getline(cin, nombre);
                system("cls");

                centro.eliminar_centro(nombre, eliminado);
                if (!eliminado)
                {
                    cout << "Lista actual de los centros es: " << centros << endl;
                    cout << "El centro '" << nombre << "' no se encuentra en la lista." << endl;
                    cout << "Prueba de nuevo: ";
                }
            }
            centro.consultar_centros(centros);
            cout << "Centro '" << nombre << "' eliminado correctamente de la lista." << endl;
            cout << "Lista actualizada: " << centros << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '3':
        {
            system("cls");

            if (centro.num_centros() == 0)
            {
                cout << "La lista esta vacia." << endl;
                cout << endl;
                system("pause");
                break; // Si no hay nada que mostrar, salgo del switch
            }

            string centros;
            centro.consultar_centros(centros); // Obtengo el string con todos los centros

            cout << "La lista actual de los centros es: " << centros << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '4':
        {
            system("cls");

            if (centro.num_centros() == 0)
            {
                cout << "La lista esta vacia." << endl;
                cout << endl;
                system("pause");
                break; // Si no hay nada que mostrar, salgo del switch
            }

            string nombre;
            bool flag;
            cout << "Que centro quieres consultar?: ";
            getline(cin, nombre);

            flag = centro.esta_en_lista(nombre);
            if (flag)
            {
                cout << endl;
                cout << "El centro '" << nombre << "' esta en la lista.";
                cout << endl;
                system("pause");
                break;
            }
            else
            {
                cout << endl;
                cout << "El centro '" << nombre << "' no esta en la lista.";
                cout << endl;
                system("pause");
                break;
            }
        }

        case '5':
        {
            system("cls");

            cout << "Hay un total de " << (centro.num_centros()) << " en la lista." << endl;
            cout << endl;
            system("pause");
            break;
        }

        case '6':
        {
            Centros centro2(centro);   // Creo centro2 a partir de centro. (Constructor copia).
            cout << "Lista copiada con exito" << endl;
            cout << endl;
            system("pause");
            break;
        }
        }
    }
}
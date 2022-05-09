#include <iostream>
#include <cassert>
#include <fstream>

#include "menores.hpp"

using namespace std;
using namespace bblProgII;

char menu()
{
    system("cls");
    cout << "Opciones para manipular la lista de menores" << endl;
    cout << "0.- Fin" << endl;
    cout << "1.- Insertar centro para un identificador" << endl;
    cout << "2.- Eliminar centro de un identificador" << endl;
    cout << "3.- Consultar centros de un identificador" << endl;
    cout << "4.- Consultar el número de centros" << endl;
    cout << "5.- Escribir el historial por pantalla" << endl;
    cout << "6.- Leer el historial desde fichero" << endl;
    cout << "7.- Escribir el historial a fichero" << endl;
    cout << "8.- Copiar historial (constructor de copia)" << endl;

    char op;

    do
    {
        cout << " Opcion ? ";
        cin >> op;
    } while (op < '0' || op > '8');
    cin.ignore(1000, '\n');
    cout << endl;
    return op;
}

int main()
{
    Menores menores;
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
        case '1':
        {
            system("cls");
            string centro, id;
            bool insertado;

            cout << "Que centro quieres insertar?: ";
            getline(cin, centro);
            cout << endl;
            cout << "A quien quieres insertar el centro? (identificador): ";
            cin >> id;

            menores.insertar(id, centro, insertado);

            system("cls");
            if (insertado)
            {
                cout << "Se ha insertado el centro '" << centro << "' correctamente a " << id << endl;
                cout << endl;

                string centros;

                menores.consultar(id, centros);

                cout << "Estos son los centros de " << id << " actualizados: " << centros << endl;
                cout << endl;

                system("pause");
            }
            else
            {
                cout << "No se ha insertado correctamente el centro." << endl;
                cout << endl;
                system("pause");
            }

            break;
        }

        case '2':
        {
            system("cls");
            string centro, id, centros;
            bool eliminado;

            cout << "A quien quieres eliminar el centro? (identificador): ";
            cin >> id;

            menores.consultar(id, centros);
            cout << "Esta es la lista de centros de " << id << endl;
            cout << centros << endl;
            
            cout << endl;
            system("pause");

            cout << "Que centro quieres eliminar?: ";
            getline(cin, centro);

            menores.eliminar(id, centro, eliminado);

            system("cls");
            if (eliminado)
            {
                cout << "Se ha eliminado correctamente el centro '" << centro << "' a " << id << endl;
                cout << endl;
                system("pause");
            }
            else
            {
                cout << "No se ha eliminado correctamente el centro." << endl;
                cout << endl;
                system("pause");
            }
            break;
        }
        }
    }
}
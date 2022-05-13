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
    cout << "4.- Consultar el numero de identificadores" << endl;
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

            cout << "Que centro quieres eliminar?: ";
            getline(cin, centro); // He tenido que usar dos getline debido a que el primero se me activa cuando no debe, y no se porque
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

        case '3':
        {
            system("cls");

            string id, centros;

            cout << "A quien quieres consultar? (identificador): ";
            cin >> id;

            menores.consultar(id, centros);

            cout << "Esta es la lista de los centros de '" << id << "':" << endl;
            cout << centros << endl;

            cout << endl;

            system("pause");

            break;
        }

        case '4':
        {
            system("cls");

            cout << "El numero de identificadores que hay en la lista es '" << menores.num_centros() << "'." << endl;

            cout << endl;
            system("pause");

            break;
        }

        case '5':
        {
            system("cls");

            cout << "A continuacion se muestra la lista completa (cada identificador, seguido del numero de centros y sus nombres): " << endl;
            menores.escribir();

            cout << endl;
            system("pause");
            break;
        }

        case '6':
        {
            system("cls");
            string nombre_fic;
            bool leido;

            cout << "Escriba el nombre del fichero que quiera leer: ";
            cin >> nombre_fic;

            menores.leer_de_fichero(nombre_fic, leido);

            if (leido)
            {
                cout << "Se ha leido correctamente la lista del fichero." << endl;
            }
            else
            {
                cout << "No se ha leido correctamente la lista del fichero." << endl;
            }

            cout << endl;
            system("pause");
            break;
        }

        case '7':
        {
            system("cls");

            string nombre_fic;
            bool escrito;

            cout << "Escriba el nombre del fichero donde se guardara la lista: ";
            cin >> nombre_fic;

            menores.escribir_a_fichero(nombre_fic, escrito);

            if (escrito)
            {
                cout << "Se ha guardado correctamente la lista en el fichero." << endl;
            }
            else
            {
                cout << "No se ha guardado correctamente la lista en el fichero." << endl;
            }

            cout << endl;
            system("pause");
            break;
        }

        case '8':
        {
            system("cls");

            cout << "No he implementado este metodo debido a su no funcionamiento en el test." << endl;

            cout << endl;
            system("pause");
            break;
        }
        }
    }
}
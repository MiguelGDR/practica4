#include "menores.hpp"
#include "centros.hpp"
#include "iostream"
#include <string>
#include <cassert>

using namespace std;
using namespace bblProgII;

// Implementación de los constructores y del destructor

Menores::Menores()
{
    menores = nullptr;
}
Menores::Menores(const Menores &otra_menores)
{
    Lista ptr, ptr2; // Puntero auxiliar
    ptr = menores;
    ptr2 = otra_menores.menores;
    while (ptr != nullptr) // Si el ptr no es el final
    {
        ptr2 = new Nodo;              // Creo un nuevo nodo
        ptr2 = ptr2->sig;             // Apunto al nuevo nodo
        ptr2->id = ptr->id;           // Copio el nombre
        ptr2->centros = ptr->centros; // Copio los centros
        ptr = ptr->sig;               // Avanzo mi puntero a la siguiente posicion
        ptr2 = ptr2->sig;             // Apunto al nuevo nodo
    }
}
Menores::~Menores()
{
    delete menores;
}

// Implementación de los métodos públicos

void Menores::insertar(const std::string &identificador, std::string centro, bool &insertado)
{
    Lista ptr;
    bool flag = 0;
    ptr = menores;
    if (ptr != nullptr) // Si no es nullpointer (contiene elementos), entra en el if
    {
        while (ptr != nullptr && !flag) // No está vacia la lista
        {
            if (ptr->id == identificador) // Si está el id, añado el centro
            {
                ptr->centros.insertar_centro(centro, insertado); // Inserto el centro
                flag = 1;                                        // Cambio flag para salir del bucle
            }
            ptr = ptr->sig;
        }

        if (!flag) // Si no estaba el id en la lista, lo añado. Despues añado el centro
        {
            ptr = menores;                                          // Reinicio el puntero
            Lista nuevo_nodo = new Nodo;                            // Creo un nuevo nodo
            nuevo_nodo->id = identificador;                         // donde guardo el id
            nuevo_nodo->centros.insertar_centro(centro, insertado); // e inserto el centro.

            bool done = false; // Declaro variable flag para salir del bucle.

            if (ordenLex(identificador, menores->id)) // Si se da el caso de que el id es el primero, se añade al principio
            {
                nuevo_nodo->sig = ptr;
                menores = nuevo_nodo;
            }

            while (ptr != nullptr && !done)
            {
                if (ordenLex(identificador, ptr->id)) // Si es 1, identificador < ptr->id (orden lexicográfico).
                {
                    nuevo_nodo->sig = ptr; // Enlazo
                    ptr = nuevo_nodo;      // Inserto el nuevo nodo
                    done = true;           // Salgo del bucle while con done
                }
                ptr = ptr->sig;
            }

            if (ptr == nullptr && !done) // Quiere decir que salió del bucle while porque llego al final y no insertó el id
            {
                ptr = menores; // Reinicio ptr
                while (ptr->sig != nullptr)
                {
                    ptr = ptr->sig;
                }
                ptr->sig = new Nodo;
                ptr->sig->id = identificador;
                ptr->sig->centros.insertar_centro(centro, insertado);
                ptr->sig->sig = nullptr;
            }
        }
    }
    else // Si ptr == nullptr (lista vacia), añado el primer elemento
    {
        ptr = new Nodo;
        ptr->id = identificador;
        ptr->centros.insertar_centro(centro, insertado);
        ptr->sig = nullptr;
        menores = ptr;
    }
}

void Menores::eliminar(const std::string &identificador, std::string centro, bool &eliminado)
{
    Lista ptr = menores;
    bool flag = 0;

    if (ptr != nullptr)
    {
        while (ptr != nullptr && !flag)
        {
            if (ptr->id == identificador) // Si encuentro el id, elimino el centro
            {
                ptr->centros.eliminar_centro(centro, eliminado); // Elimino el centro
                flag = 1;

                if (ptr->centros.num_centros() == 0) // Si no quedan centros en la lista del menor, elimino al menor
                {
                    bool done = 0; // Variable que usaré para indicar que ya se eliminó al menor

                    if (menores->sig == nullptr && !done) // Caso de que hay que eliminar el único menor de la lista
                    {
                        ptr = menores;  // Reinicio
                        menores = menores->sig;
                        delete ptr;
                        ptr = menores;

                        done = 1;
                        break;
                    }

                    if (menores->id == identificador && !done) // Caso de que haya que eliminar el primer menor de la lista
                    {
                        ptr = menores;
                        menores = menores->sig; // Eliminado
                        delete ptr;             // Libero memoria
                        done = 1;
                    }

                    if (ptr->sig == nullptr && !done) // Caso de que haya que eliminar el último menor de la lista
                    {
                        delete ptr;
                        ptr = nullptr;
                        done = 1;
                    }

                    if(!done)   // Si no es ni el primer ni el último menor. Enlazo la lista
                    {
                        Lista ant = nullptr;
                        ant = menores;
                        while(ant->sig != ptr)
                        {
                            ant = ant->sig;
                        }
                        ant->sig = ptr->sig;
                        delete ptr;
                    }
                }
            }
            ptr = ptr->sig;
        }
    }
}

unsigned Menores::num_centros() const
{
    Lista ptr;
    ptr = menores;
    unsigned i = 0;
    while (ptr != nullptr)
    {
        i += 1;
        ptr = ptr->sig;
    }
    return i;
}
// Operadores sobrecargados (implementados por el profesor)
bool Menores::operator==(const Menores &otro_menores)
{
    bool iguales = true;

    Lista ptr1 = menores, ptr2 = otro_menores.menores;

    while (iguales && ptr1 != nullptr && ptr2 != nullptr)
    {
        iguales = ptr1->id == ptr2->id &&
                  ptr1->centros == ptr2->centros;
        ptr1 = ptr1->sig;
        ptr2 = ptr2->sig;
    }

    return (iguales && ptr1 == nullptr && ptr2 == nullptr);
}
// -------------------------------------
Menores &Menores::operator=(const Menores &otro_menores)
{
    if (this != &otro_menores)
    {
        Lista ptr1 = otro_menores.menores, ptr2;

        while (menores != nullptr)
        {
            ptr2 = menores;
            menores = menores->sig;
            delete ptr2;
        }

        while (ptr1 != nullptr)
        {
            if (menores == nullptr)
            {
                menores = new Nodo;
                ptr2 = menores;
            }
            else
            {
                ptr2->sig = new Nodo;
                ptr2 = ptr2->sig;
            }
            ptr2->sig = nullptr;
            ptr2->id = ptr1->id;
            ptr2->centros = ptr1->centros;
            ptr1 = ptr1->sig;
        }
    }
    return *this;
}
// -------------------------------------
// Métodos posicionales (implementados por el profesor)
std::string Menores::get_id_pos(unsigned i) const
{
    assert(i < num_centros());

    unsigned pos = 0;

    Lista ptr = menores;
    while (pos < i)
    {
        ptr = ptr->sig;
        ++pos;
    }

    return ptr->id;
}
// -------------------------------------
Centros Menores::get_centros_pos(unsigned i) const
{
    assert(i < num_centros());

    unsigned pos = 0;

    Lista ptr = menores;
    while (pos < i)
    {
        ptr = ptr->sig;
        ++pos;
    }

    return ptr->centros;
}

//-----------------------------------------------------
//-----------------------------------------------------

// Implementación de métodos privados

bool Menores::ordenLex(string s1, string s2)
{
    bool s1menor = false, s2menor = false;

    if (s1.length() >= s2.length())
    {
        while (!s1menor && !s2menor)
        {
            for (unsigned i = 0; i < s2.length(); i++)
            {
                if (s1[i] < s2[i])
                {
                    s1menor = true;
                    break;
                }
                if (s2[i] < s1[i])
                {
                    s2menor = true;
                    break;
                }
                if ((i + 1) == s2.length())
                {
                    s2menor = true;
                    break;
                }
            }
        }
    }
    else
    {
        while (!s1menor && !s2menor)
        {
            for (unsigned i = 0; i < s1.length(); i++)
            {
                if (s1[i] < s2[i])
                {
                    s1menor = true;
                    break;
                }
                if (s2[i] < s1[i])
                {
                    s2menor = true;
                    break;
                }
                if ((i + 1) == s1.length())
                {
                    s1menor = true;
                    break;
                }
            }
        }
    }

    return (s1menor * !s2menor); // Si es 1, s1 < s2.
                                 // Si es 0, s2 > s1.
}
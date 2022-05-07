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
    if (menores != nullptr) // Si no es nullpointer (contiene elementos), entra en el if
    {
        ptr = menores;
        while (ptr->sig != nullptr && !flag)
        {
            if (ptr->id == identificador)
            {
                ptr->centros.insertar_centro(centro, insertado); // Inserto el centro
                flag = 1;                                        // Cambio flag para salir del bucle
            }
            ptr = ptr->sig;
        }

        if (!flag) // Si no estaba el id en la lista, lo añado
        {
            ptr = menores; // Reinicio el puntero
            Lista nuevo_nodo = new Nodo;
            nuevo_nodo->id = identificador;
            nuevo_nodo->centros.insertar_centro(centro, insertado);
            bool done = false;

            while (ptr->sig != nullptr && !done)
            {
                if (ordenLex(identificador, ptr->id)) // Si es 1, identificador < ptr->id.
                {
                    nuevo_nodo->sig = ptr; // Enlazo
                    ptr = nuevo_nodo;      // Inserto el nuevo nodo
                    done = true;           // Salgo del bucle while con done
                }
                ptr = ptr->sig;
            }
        }
    }
    else // Si menores == nullptr (lista vacia), añado el primer elemento
    {
        menores->id = identificador;
        menores->centros.insertar_centro(centro, insertado);
        menores->sig = nullptr;
    }
}

unsigned Menores::num_centros() const
{
    Lista ptr;
    ptr = menores;
    unsigned i;
    while(ptr != nullptr)
    {
        i++;
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
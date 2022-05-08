#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <array>
#include <string>
#include <cassert>
#include "centros.hpp"

using namespace std;

namespace bblProgII
{
    //-------------------------------------
    //-------------------------------------

    // Constructor por defecto
    Centros::Centros()
    {
        n_centros = 0; // Indice a 0;
        for (unsigned int i = 0; i < 10; i++)
        {
            centros[i] = ""; // Todas las posiciones vacias
        }
    }

    // Contructor copia
    Centros::Centros(const Centros &otra_lista)
    {
        n_centros = otra_lista.n_centros;

        for (unsigned int i = 0; i < n_centros; i++)
        {
            centros[i] = otra_lista.centros[i];
        }
    }

    // Destructor
    Centros::~Centros(){};

    //-------------------------------------
    //-------------------------------------

    // Implementación de los métodos públicos
    void Centros::insertar_centro(std::string centro, bool &insertado)
    {
        insertado = 1; // Inicializo insertado a 1
        for (unsigned int i = 0; i < n_centros; i++)
        {
            if (centros[i].compare(centro) == 0)
            {
                insertado = 0; // Si coincide con un elemento de la lista, no se inserta
            }
        }

        if (insertado)
        {
            n_centros += 1;                  // Incremento el valor del índice
            centros[n_centros - 1] = centro; // Inserto el centro en la última posición

            if (n_centros > 1)
            {
                for (int i = n_centros - 1; i >= 0; i--)
                {
                    if (!((i - 1) == -1))
                        if (!ordenLex(centros[i - 1], centros[i])) // Si s2 < s1
                        {
                            string aux = centros[i - 1];
                            centros[i - 1] = centros[i];
                            centros[i] = aux;
                        }
                }
            }
        }
    }

    void Centros::eliminar_centro(std::string centro, bool &eliminado)
    {
        eliminado = 0;
        for (unsigned int i = 0; i < n_centros; i++)
        {
            if (centros[i] == centro)
            {
                centros[i] == "";
                eliminado = 1; // Si coincide con un elemento de la lista, se elimina de la lista

                n_centros -= 1; // Decremento el número de centros

                for (unsigned int j = i; j < n_centros; j++)
                {
                    centros[j] = centros[j + 1]; // Desplazo los centros
                    centros[j + 1] = "";
                }
            }
        }
    }

    void Centros::consultar_centros(std::string &cntrs) const
    {
        string guion = "-";
        cntrs = ""; // Inicializo en vacio
        for (unsigned int i = 0; i < n_centros; i++)
        {
            cntrs += centros[i]; // Añado el siguiente centro
            cntrs += guion;      // Añado guión
        }
    }

    bool Centros::esta_en_lista(std::string centro) const
    {
        bool flag = false; // Inicializo indicando que no está el centro

        for (unsigned i = 0; i < n_centros; i++)
        {
            if (centros[i].compare(centro) == 0)
            {
                flag = true; // Si está, cambio flag a true
            }
        }

        return flag;
    }

    unsigned Centros::num_centros() const
    {
        return n_centros;
    }

    //-------------------------------------
    //-------------------------------------

    // Operadores sobrecargados

    bool Centros::operator==(const Centros &otra_lista) const
    {
        bool iguales = true;
        iguales = n_centros == otra_lista.n_centros;

        unsigned i = 0;
        while (iguales && i < n_centros)
        {
            iguales = centros[i] == otra_lista.centros[i];
            i++;
        }
        return iguales;
    }

    std::string Centros::operator[](unsigned i) const
    {
        assert(i < n_centros);

        return centros[i];
    }

    //-------------------------------------
    //-------------------------------------

    // Implementación de los métodos privados

    unsigned Centros::buscar_centro(std::string centro) const
    {
        unsigned int j;
        bool done = 0;

        for (unsigned int i = 0; i < n_centros; i++)
        {
            if (centros[i] == centro)
            {
                j = i; // Si está, guardo la posición
                done = 1;
            }
        }

        if (!done) // Si done está a 0, quiere decir que no se encontró el centro en la lista
        {
            array<string, 11> centros_mas_uno; // Pongo 11 para que en caso de estar lleno (10 posiciones ocupadas), al añadir 1 más tenga hueco.
            for (unsigned int i = 0; i < n_centros; i++)
            {
                centros_mas_uno[i] = centros[i]; // Guardo cada posición de la lista en la que voy a usar para ordenar
            }
            centros_mas_uno[n_centros] = centro; // Caso de que n_centros = 10, guardo el centro en la posición 11 de la lista

            std::sort(centros_mas_uno.begin(), centros_mas_uno.end()); // Ordeno la lista alfabéticamente

            for (unsigned int i = 0; i <= n_centros; i++)
            {
                if (centros_mas_uno[i] == centro)
                {
                    j = i; // Guardo la supuesta posición del centro
                }
            }
        }

        return j;
    }

    bool Centros::ordenLex(string s1, string s2)
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
}
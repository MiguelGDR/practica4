/*-----------------------------------------------------------------------------
  centros.hpp

  Fichero de definición de la clase centros, que permite la gestión de una
  lista de centros (cadena de caracteres de tipo string).

  Autor: Mgiuel González del Río

  Código ordenador:
  ---------------------------------------------------------------------------*/

#ifndef __centros_HPP__
#define __centros_HPP__

#include <array>
#include <string>
#include <cassert>

namespace bblProgII {
class Centros {
public:
	Centros();  // Constructor por defecto
	// Inicializa la lista de centros a lista vacía.
	//-------------------------------------
	~Centros();  // Destructor
	// Destruye el objeto, liberando todos los recursos asociados al mismo.
	//-------------------------------------
	Centros(const Centros &otra_lista);
	// Constructor de copia.
	//-------------------------------------
	void insertar_centro(std::string centro, bool &insertado);
	// Inserta un centro en la lista de centros, en orden creciente 
	// de su valor alfabético. Si la lista de centros no está llena y 
	// centro no existe en la lista, el centro se inserta de manera 
	// ORDENADA en la lista e insertado se pone a true. Si no, insertado
	// se pone a false. Nota importante: NO puede haber centros repetidos.
	//-------------------------------------
	void eliminar_centro(std::string centro, bool &eliminado);
	// Elimina un centro de la lista de centros. Si el centro existe
	//  en la lista de centros, se elimina de la lista y eliminado se pone
	// a true. Si no, eliminado se pone a false.
	//-------------------------------------
	void consultar_centros(std::string &cntrs) const;
	// Devuelve un string con la lista de todos los centros separados por
	// un carácter guión. Por ej.: "Virgen de la Esperanza-Prodiversa-Ciudad de los Niños-"
	//-------------------------------------
	bool esta_en_lista(std::string centro) const;
	// Indica si el centro está en la lista de centros.
	//-------------------------------------
	unsigned num_centros() const;
	// Devuelve el número de centros de la lista.
	//-------------------------------------
	// Operdores sobrecargados (implementados on-line por el profesor)
	bool operator==(const Centros &otra_lista) const;
	//-------------------------------------
	std::string operator[](unsigned i) const;
private:
	static const unsigned MAX_centros = 10;
	std::array<std::string, MAX_centros> centros;
	unsigned n_centros;

	// Métodos privados
	unsigned buscar_centro(std::string centro) const;
	// Busca un centro en la lista de centros. Si lo encuentra, 
	// devuelve su posición en la lista. Si no lo encuentra, devuelve 
	// la posición en la que debería estar en la lista, teniendo en cuenta 
	// que ésta está ordenada en orden creciente. (Por ejemplo, si la 
	// lista contiene los elementos {2, 4, 6, 8} y buscamos el centro 5, 
	// debería devolver la posición 3, que es la posición en la que le 
	// correspondería estar al 5 si estuviera en la lista.)
};
}

#endif
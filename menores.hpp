/*-----------------------------------------------------------------------------
  menores.hpp

  Fichero de definición de la clase menores, que permite la gestión de un
  historial de ingresos de menores en centros de protección.

  Autor:

  Código ordenador:
  ---------------------------------------------------------------------------*/


#ifndef __menores_HPP__
#define __menores_HPP__

#include "centros.hpp"

#include <string>
#include <cassert>

namespace bblProgII {
class Menores {
public:
	Menores();  // Constructor por defecto
	// Inicializa la lista a lista vacía.
	// -------------------------------------
	~Menores();  // Destructor
	// Destruye el objeto, liberando todos los recursos asociados al mismo.
	// -------------------------------------
	Menores(const Menores &otra_menores);
	// Constructor de copia.
	// -------------------------------------
	void insertar(const std::string &identificador, std::string centro, bool &insertado);
	// Inserta un nuevo centro para un identificador concreto del historial del menor.
	// Si el identificador no existe, éste se inserta ORDENADO en la lista enlazada,
	// en orden creciente de identificador, junto con su centro en su lista de centros.
	// Si el identificador ya existe, se añade el centro a su lista de centros.
	// Si la inserción ha sido posible, insertado se pone a true.
	// Si no, insertado se pone a false.
	// -------------------------------------
	void eliminar(const std::string &identificador, std::string centro, bool &eliminado);
	// Se elimina un determinado centro de la lista de centros correspondiente
	// a un determinado identificador. Si el identificador existe en el historial del menor y
	// el centro existe en la lista de centros de ese identificador, el centro se
	// elimina de su lista de centros. Si el centro eliminado es el último de
	// la lista de centros para ese identificador, se elimina el nodo completamente de
	// la lista enlazada. Si se consigue elimimar el centro, eliminado se pone a true.
	// Si no, se pone a false.
	// -------------------------------------
	void consultar(const std::string &identificador, std::string &centros) const;
	// Devuelve un string con la lista de centros (separados por guiones)
	// para el identificador que se pasa como parámetro.
	// Si el identificador no existe, el vector de centros devuelto estará vacío.
	// -------------------------------------
	unsigned num_centros() const;
	// Devuelve el número total de centros (identificadores) que hay en la lista
	// -------------------------------------
	void escribir() const;
	// Escribe por pantalla el historial de los menores, sacando, para cada identificador almacenado
	// en la lista, el número de centros en su lista de centros y, a continuación,
	// la lista de centros. Por ejemplo, la salida por pantalla podría ser:
	// Ana Gutierrez
	// 2
	// Virgen de la Victoria
	// Virgen de la Esperanza
	// Monica Sanchez
	// 3
	// Ciudad de los Niños
	// Virgen de la Victoria
	// Málaga Acoge
	// Pepe Gomez
	// 4
	// Virgen de la Esperanza
	// Nuevo Futuro
	// La Retama
	// Prodiversa
	// ...
	// -------------------------------------
	void leer_de_fichero(const std::string &nom_fic, bool &leido);
	// Inicializa el historial de menores a partir de los datos leídos desde fichero.
	// Los identificadores se insertan en orden creciente de identificador, es decir, a partir de llamadas
	// al método insertar(...) de la propia clase. El historial de menores actual debe
	// eliminarse antes de la lectura (es decir, debe borrarse completamente toda la lista
	// enlazada). El método recibe el nombre de fichero. Si el fichero puede abrirse
	// correctamente, leido se pone a true y se leen los datos desde fichero. Si no,
	// leido se pone a false y el historial de menores quedará vacío.
	// El formato de fichero coincide con el de salida por pantalla (véase más arriba).
	// -------------------------------------
	void escribir_a_fichero(const std::string &nom_fic, bool &escrito) const;
	// Escribe en fichero el historial de menores actual. El método recibe el identificador de fichero.
	// Si el fichero puede abrirse correctamente, escrito se pone a true y se escriben los datos a
	// fichero. Si no, escrito se pone a false. El formato de fichero coincide con el de salida
	// por pantalla (véase más arriba).
	// -------------------------------------
	// Operadores sobrecargados (implementados por el profesor)
	bool operator==(const Menores &otro_menores) {
		bool iguales = true;

		Lista ptr1 = menores, ptr2 = otro_menores.menores;

		while (iguales && ptr1 != nullptr && ptr2 != nullptr) {
			iguales = ptr1->id == ptr2->id &&
			          ptr1->centros == ptr2->centros;
			ptr1 = ptr1->sig;
			ptr2 = ptr2->sig;
		}

		return (iguales && ptr1 == nullptr && ptr2 == nullptr);
	}
	// -------------------------------------
	Menores &operator=(const Menores &otro_menores) {
		if (this != &otro_menores) {
			Lista ptr1 = otro_menores.menores, ptr2;

			while (menores != nullptr) {
				ptr2 = menores;
				menores = menores->sig;
				delete ptr2;
			}

			while (ptr1 != nullptr) {
				if (menores == nullptr) {
					menores = new Nodo;
					ptr2 = menores;
				} else {
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
	std::string get_id_pos(unsigned i) const {
		assert(i < num_centros());

		unsigned pos = 0;

		Lista ptr = menores;
		while (pos < i) {
			ptr = ptr->sig;
			++pos;
		}

		return ptr->id;
	}
	// -------------------------------------
	Centros get_centros_pos(unsigned i) const {
		assert(i < num_centros());

		unsigned pos = 0;

		Lista ptr = menores;
		while (pos < i) {
			ptr = ptr->sig;
			++pos;
		}

		return ptr->centros;
	}
	// -------------------------------------	
private:
	struct Nodo {
		std::string id;
		Centros centros;
		Nodo *sig;
	};

	typedef Nodo *Lista;

	Lista menores;

	// Métodos privados

	void buscar_identificador(const std::string &identificador, Lista &pos, Lista &ant) const;
	// Busca un identificador en el historial de menores actual.
	// ---------------------------------------------------------------------------
	void insertar_ordenada(const std::string &identificador, std::string centro);
	// Inserta un nuevo nodo en la lista del historial de menores, con el
	// identificador que se pasa como parámetro y el centro en su lista de centros.
	// La lista debe quedar ordenada en orden creciente de identificador.
	// ---------------------------------------------------------------------------
	void eliminar_ordenada(const std::string &identificador);
	// Elimina de la lista el nodo cuyo identificador se pasa como parámetro.
	// ---------------------------------------------------------------------------
	void copiar_lista(Lista &destino, Lista origen) const;
	// Hace una copia de la lista que cuelga del puntero origen en el puntero destino.
	// ---------------------------------------------------------------------------
	void borrar_lista(Lista &lista) const;
	// Elimina todos los nodos de la lista que se pasa como parámetro, poniendo
	// lista finalmente a NULL (o nullptr).
};
}

#endif
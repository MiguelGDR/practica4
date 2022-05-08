//--------------------------------------------------------------------------
// Programa principal de prueba de Historial de Menores
// Alumnno:
// Código Ordenador:
//--------------------------------------------------------------------------
#include <iostream>
#include <cassert>
#include <fstream>

#include "menores.hpp"

using namespace std;
using namespace bblProgII;

//--------------------------------------------------------------------------
void test_insertar()
{
	Menores menores;
	Centros centros1, centros2, centros3;
	bool ok;

	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	assert(ok);
	centros1.insertar_centro("Virgen de la Esperanza", ok);
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	assert(ok);
	centros1.insertar_centro("Ciudad de los Niños", ok);
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	assert(ok);
	centros1.insertar_centro("Virgen de la Victoria", ok);
	assert(menores.num_centros() == 1);
	assert(menores.get_id_pos(0) == "Pepe");
	assert(menores.get_centros_pos(0) == centros1);

	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	assert(ok);
	centros2.insertar_centro("Virgen de la Esperanza", ok);
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	assert(ok);
	centros2.insertar_centro("Ciudad de los Niños", ok);
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	assert(ok);
	centros2.insertar_centro("Virgen de la Victoria", ok);
	assert(menores.num_centros() == 2);
	assert(menores.get_id_pos(0) == "Ana");
	assert(menores.get_centros_pos(0) == centros2);
	assert(menores.get_id_pos(1) == "Pepe");
	assert(menores.get_centros_pos(1) == centros1);

	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	assert(ok);
	centros3.insertar_centro("Virgen de la Esperanza", ok);
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	assert(ok);
	centros3.insertar_centro("Ciudad de los Niños", ok);
	menores.insertar("Sandra", "Virgen de la Victoria", ok);
	assert(ok);
	centros3.insertar_centro("Virgen de la Victoria", ok);
	assert(menores.num_centros() == 3);
	assert(menores.get_id_pos(2) == "Sandra");
	assert(menores.get_centros_pos(2) == centros3);
	assert(menores.get_id_pos(0) == "Ana");
	assert(menores.get_centros_pos(0) == centros2);
	assert(menores.get_id_pos(1) == "Pepe");
	assert(menores.get_centros_pos(1) == centros1);
}

//-----------------------------------------------------------
void test_eliminar()
{
	Menores menores;
	Centros centros1, centros2, centros3;
	bool ok;

	// Primero insertamos varios Menores con el centro de protección
	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	centros1.insertar_centro("Virgen de la Esperanza", ok);
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	centros1.insertar_centro("Ciudad de los Niños", ok);
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	centros1.insertar_centro("Virgen de la Victoria", ok);

	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	centros2.insertar_centro("Virgen de la Esperanza", ok);
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	centros2.insertar_centro("Ciudad de los Niños", ok);
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	centros2.insertar_centro("Virgen de la Victoria", ok);

	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	centros3.insertar_centro("Virgen de la Esperanza", ok);
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	centros3.insertar_centro("Ciudad de los Niños", ok);
	menores.insertar("Sandra", "Virgen de la Victoria", ok);
	centros3.insertar_centro("Virgen de la Victoria", ok);

	// Ahora eliminamos
	menores.eliminar("Pepe", "Ciudad de los Niños", ok);
	assert(ok);
	centros1.eliminar_centro("Ciudad de los Niños", ok);
	assert(menores.get_centros_pos(1) == centros1);
	menores.eliminar("Pepe", "Virgen de la Esperanza", ok);
	assert(ok);
	centros1.eliminar_centro("Virgen de la Esperanza", ok);
	assert(menores.get_centros_pos(1) == centros1);
	menores.eliminar("Pepe", "Virgen de la Victoria", ok);
	assert(ok);
	assert(menores.get_centros_pos(1) == centros3);
	assert(menores.num_centros() == 2);

	menores.eliminar("Ana", "Ciudad de los Niños", ok);
	assert(ok);
	centros2.eliminar_centro("Ciudad de los Niños", ok);
	assert(menores.get_centros_pos(0) == centros2);
	menores.eliminar("Ana", "Virgen de la Esperanza", ok);
	assert(ok);
	centros2.eliminar_centro("Virgen de la Esperanza", ok);
	assert(menores.get_centros_pos(0) == centros2);
	menores.eliminar("Ana", "Virgen de la Victoria", ok);
	assert(ok);
	assert(menores.get_centros_pos(0) == centros3);
	assert(menores.num_centros() == 1);

	menores.eliminar("Sandra", "Ciudad de los Niños", ok);
	assert(ok);
	centros3.eliminar_centro("Ciudad de los Niños", ok);
	assert(menores.get_centros_pos(0) == centros3);
	menores.eliminar("Sandra", "Virgen de la Esperanza", ok);
	assert(ok);
	centros3.eliminar_centro("Virgen de la Esperanza", ok);
	assert(menores.get_centros_pos(0) == centros3);
	menores.eliminar("Sandra", "Virgen de la Victoria", ok);
	assert(ok);
	assert(menores.num_centros() == 0);

	assert(menores == Menores());
}
/*
//--------------------------------------------------------------------------
void test_consultar()
{
	Menores menores;
	bool ok;
	string cntrs;

	menores.consultar("Pepe", cntrs); assert(cntrs.empty());
	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	menores.consultar("Pepe", cntrs); assert(cntrs == "Virgen de la Esperanza-");
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	menores.consultar("Pepe", cntrs); assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-");
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	menores.consultar("Pepe", cntrs); assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-Virgen de la Victoria-");

	menores.consultar("Ana", cntrs); assert(cntrs.empty());
	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	menores.consultar("Ana", cntrs); assert(cntrs == "Virgen de la Esperanza-");
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	menores.consultar("Ana", cntrs); assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-");
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	menores.consultar("Ana", cntrs); assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-Virgen de la Victoria-");

	menores.consultar("Sandra", cntrs); assert(cntrs.empty());
	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	menores.consultar("Sandra", cntrs); assert(cntrs == "Virgen de la Esperanza-");
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	menores.consultar("Sandra", cntrs); assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-");
	menores.insertar("Sandra", "Virgen de la Victoria", ok);
	menores.consultar("Sandra", cntrs); assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-Virgen de la Victoria-");
}
//--------------------------------------------------------------------------
void test_num_centros() {
	Menores menores;
	bool ok;

	assert(menores.num_centros() == 0);
	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	assert(menores.num_centros() == 1);

	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	assert(menores.num_centros() == 2);

	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	menores.insertar("Sandra", "Virgen de la Victoria", ok);
	assert(menores.num_centros() == 3);

	assert(Menores().num_centros() == 0);
}
//--------------------------------------------------------------------------
void test_leer_de_fichero()
{
	Menores menores;
	bool ok;

	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	menores.insertar("Sandra", "Virgen de la Victoria", ok);

	ofstream out;

	out.open("_fic_temp_.txt");
	out << "Ana" << endl
		<< "3"   << endl
		<< "Ciudad de los Niños" << endl
		<< "Virgen de la Esperanza" << endl
		<< "Virgen de la Victoria" << endl;
	out << "Pepe" << endl
		<< "3"   << endl
		<< "Ciudad de los Niños" << endl
		<< "Virgen de la Esperanza" << endl
		<< "Virgen de la Victoria" << endl;
	out << "Sandra" << endl
		<< "3"   << endl
		<< "Ciudad de los Niños" << endl
		<< "Virgen de la Esperanza" << endl
		<< "Virgen de la Victoria" << endl;
	out.close();

	Menores leido;

	leido.leer_de_fichero("_fic_temp_.txt", ok);
	assert(ok);
	assert(leido == menores);
}
//--------------------------------------------------------------------------
void test_escribir_a_fichero()
{
	Menores menores, copia;
	bool ok;

	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	menores.insertar("Sandra", "Virgen de la Victoria", ok);

	menores.escribir_a_fichero("_fic_temp_.txt", ok);
	assert(ok);
	copia.leer_de_fichero("_fic_temp_.txt", ok);
	assert(menores == copia);
}
//--------------------------------------------------------------------------
void test_copiar()
{
	Menores menores;
	bool ok;

	menores.insertar("Pepe", "Virgen de la Esperanza", ok);
	menores.insertar("Pepe", "Ciudad de los Niños", ok);
	menores.insertar("Pepe", "Virgen de la Victoria", ok);
	menores.insertar("Ana", "Virgen de la Esperanza", ok);
	menores.insertar("Ana", "Ciudad de los Niños", ok);
	menores.insertar("Ana", "Virgen de la Victoria", ok);
	menores.insertar("Sandra", "Virgen de la Esperanza", ok);
	menores.insertar("Sandra", "Ciudad de los Niños", ok);
	menores.insertar("Sandra", "Virgen de la Victoria", ok);

	assert(menores == Menores(menores));
}
*/
//--------------------------------------------------------------------------
int main()
{
	cout << "Test insertar...";
	test_insertar();
	cout << "... OK" << endl;
	cout << "Test eliminar...";
	test_eliminar();
	cout << "... OK" << endl;
	/*cout << "Test consultar...";
	test_consultar();
	cout << "... OK" << endl;
	cout << "Test num_centros...";
	test_num_centros();
	cout << "... OK" << endl;
	cout << "Test leer_de_fichero...";
	test_leer_de_fichero();
	cout << "... OK" << endl;
	cout << "Test escribir_a_fichero...";
	test_escribir_a_fichero();
	cout << "... OK" << endl;
	cout << "Test copiar...";
	test_copiar();
	cout << "... OK" << endl;

	cout << "--- OK." << endl;*/
	system("pause");
}
//--------------------------------------------------------------------------

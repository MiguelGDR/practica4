//--------------------------------------------------------------------------
// Programa principal de prueba de Centros
// Alumnno: Miguel González del Río
// Código Ordenador:
//--------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cassert>

#include "centros.hpp"

using namespace std;
using namespace bblProgII;


//--------------------------------------------------------------------------
void test_insertar_centro()
{
	Centros centros;
	bool insertado;

	centros.insertar_centro("Ciudad de los Niños", insertado);
	assert(insertado);
	assert(centros.esta_en_lista("Ciudad de los Niños"));
	centros.insertar_centro("Virgen de la Esperanza", insertado);
	assert(insertado);
	assert(centros.esta_en_lista("Virgen de la Esperanza"));	
	centros.insertar_centro("Virgen de la Victoria", insertado);
	assert(insertado);
	assert(centros.esta_en_lista("Virgen de la Victoria"));	
	centros.insertar_centro("Ciudad de los Niños", insertado);
	assert(!insertado);

	assert(centros.num_centros() == 3);

	assert(centros[0] == "Ciudad de los Niños" && centros[1] == "Virgen de la Esperanza" && centros[2] == "Virgen de la Victoria" );
}
//-----------------------------------------------------------
void test_eliminar_centro()
{
	Centros centros;
	bool insertado, eliminado;

	// Pimero insertamos
	centros.insertar_centro("Ciudad de los Niños", insertado);
	centros.insertar_centro("Virgen de la Esperanza", insertado);
	centros.insertar_centro("Virgen de la Victoria", insertado);

	// Luego eliminamos
	centros.eliminar_centro("Ciudad de los Niños", eliminado);
	assert(eliminado);
	assert(!centros.esta_en_lista("Ciudad de los Niños"));
	assert(centros[0] == "Virgen de la Esperanza" && centros[1] == "Virgen de la Victoria" );
	centros.eliminar_centro("Virgen de la Esperanza", eliminado);
	assert(eliminado);
	assert(!centros.esta_en_lista("Virgen de la Esperanza"));	
	assert(centros[0] == "Virgen de la Victoria" );
	centros.eliminar_centro("Virgen de la Victoria", eliminado);
	assert(eliminado);
	assert(!centros.esta_en_lista("Virgen de la Victoria"));	
	centros.eliminar_centro("Ciudad de los Niños", eliminado);
	assert(!eliminado);

	assert(centros.num_centros() == 0);

	assert(centros == Centros());
}
//--------------------------------------------------------------------------
void test_consultar_centros()
{
	Centros centros;
	bool insertado;
	string cntrs;

	centros.consultar_centros(cntrs);
	assert(cntrs == "");
	centros.insertar_centro("Ciudad de los Niños", insertado);
	centros.consultar_centros(cntrs);
	assert(cntrs == "Ciudad de los Niños-");
	centros.insertar_centro("Virgen de la Esperanza", insertado);
	centros.consultar_centros(cntrs);
	assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-");	
	centros.insertar_centro("Virgen de la Victoria", insertado);
	centros.consultar_centros(cntrs);
	assert(cntrs == "Ciudad de los Niños-Virgen de la Esperanza-Virgen de la Victoria-");
}
//--------------------------------------------------------------------------
void test_esta_en_lista()
{
	Centros centros;
	bool insertado;
	string cntrs;

	centros.insertar_centro("Ciudad de los Niños", insertado);
	assert(centros.esta_en_lista("Ciudad de los Niños"));
	centros.insertar_centro("Virgen de la Esperanza", insertado);
	assert(centros.esta_en_lista("Virgen de la Esperanza"));	
	centros.insertar_centro("Virgen de la Victoria", insertado);
	assert(centros.esta_en_lista("Virgen de la Victoria"));	
}
//--------------------------------------------------------------------------
void test_num_centros()
{
	Centros centros;
	bool insertado;
	string cntrs;

	assert(centros.num_centros() == 0);
	centros.insertar_centro("Ciudad de los Niños", insertado);
	assert(centros.num_centros() == 1);
	centros.insertar_centro("Virgen de la Esperanza", insertado);
	assert(centros.num_centros() == 2);	
	centros.insertar_centro("Virgen de la Victoria", insertado);
	assert(centros.num_centros() == 3);	
	centros.eliminar_centro("Ciudad de los Niños", insertado);
	assert(centros.num_centros() == 2);	
}
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void test_copiar()
{
	Centros centros;
	bool insertado;

	centros.insertar_centro("Ciudad de los Niños", insertado);
	centros.insertar_centro("Virgen de la Esperanza", insertado);
	centros.insertar_centro("Virgen de la Victoria", insertado);

	assert(centros == Centros(centros));
}
//--------------------------------------------------------------------------
int main()
{

	cout <<"Test insertar_centro...";
	test_insertar_centro();
	cout << "... OK" << endl; 
	cout <<"Test elimnar_centro...";	
	test_eliminar_centro();
	cout << "... OK" << endl; 
	cout <<"Test consultar_centro...";	
	test_consultar_centros();
	cout << "... OK" << endl; 
	cout <<"Test esta_en_lista...";		
	test_esta_en_lista();
	cout << "... OK" << endl; 
	cout <<"Test num_centros...";			
	test_num_centros();
	cout << "... OK" << endl; 
	cout <<"Test copiar...";			
	test_copiar();
	cout << "... OK" << endl; 

	cout << "--- OK." << endl;

	system("pause");

	return 0;
}
//--------------------------------------------------------------------------

#include <iostream>
#include "Paciente.h"
#include <vector>
using namespace std;
class Sistema
{
public:


	Sistema();

	void Executar();
	void Exemplo();



private:
	int MenuInicial();
	void NovoPaciente();
	void ImprimirLista();
	void RemoverPaciente();
	void ProximoPaciente();
	void SituacaoFila();
	void OrganizarFila();
	string GrupoDeRisco(int risco);
	vector<Paciente> pacientes;
	
	};
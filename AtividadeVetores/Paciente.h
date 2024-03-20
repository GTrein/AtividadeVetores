#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <Windows.h>

using namespace std;


class Paciente
{
public:
	Paciente();
	Paciente(string nome, int risco);
	void setNome(string nome);
	void setRisco(int risco);

	string getNome();
	int getRisco() const;


private:
	string nome;
	int risco;



};
#endif
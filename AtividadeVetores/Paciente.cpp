#include "Paciente.h"

Paciente::Paciente() {};


Paciente::Paciente(string nome, int risco)
{
	this->nome = nome;
	this->risco = risco;


}

void Paciente::setNome(string nome)
{
	this->nome = nome;
}
void Paciente::setRisco(int risco)
{
	this->risco = risco;
}

string Paciente::getNome()
{
	return nome;
}
int Paciente::getRisco() const 
{
	return risco;
}



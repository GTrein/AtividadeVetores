#include "Sistema.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "portuguese");
	Sistema meuSistema;
	meuSistema.Exemplo();
	meuSistema.Executar();

	return 0;
}
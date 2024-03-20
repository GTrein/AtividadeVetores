#include "Sistema.h"
#include <algorithm>

Sistema::Sistema()
{
	cout << "Sistema rodando\n";
}

int Sistema::MenuInicial()
{
	int escolha;
	system("cls");
	cout << "===== Menu =====\n";
	cout << "1 - Adicionar paciente.\n";
	cout << "2 - Próximo paciente.\n";
	cout << "3 - Ver fila de espera.\n";
	cout << "4 - Remover paciente.\n";
	cout << "5 - Situação da fila\n";
	cout << "6 - Sair\n";
	cin >> escolha;
	return escolha;
}


void Sistema::Executar()
{
	int escolha;
	do
	{
		escolha = MenuInicial();

		switch (escolha)
		{
		case 1:
			//adicionar paciente nome/risco
			NovoPaciente();
			OrganizarFila();
			break;
		case 2:
			//remover o primeiro paciente da lista e mover todos um para baixo
			ProximoPaciente();
			break;
		case 3:
			ImprimirLista();
			system("pause");
		
			break;
		case 4:
			ImprimirLista();
				RemoverPaciente();
			break;
		case 5:
			//mostrar número de pacientes na fila e quantas vagas tem
			SituacaoFila();
			system("pause");
			
			break;
		case 6:
			//encerrar programa
			break;
		default:
			cout << "Escolha inválida.\n";
			break;
		}
	} while (escolha != 6);
	
}

void Sistema::NovoPaciente()
{
	string nome;
	int risco;
	int escolha = 0;

	bool invalido = true;
	
		if (pacientes.size() >= 50)
		{
			cout << "A fila de espera está cheia, venha mais tarde!\n";
			system("pause");
			return;
		}
		
		cout << "Primeiro nome do paciente:\n";
		cin >> nome;
		
		do
		{
			cout << "Urgência do atendimento:\n";
			cout << "1 - Verde (Leve)\n";
			cout << "2 - Amarelo (Moderada)\n";
			cout << "3 - Vermelho (Grave)\n";
			cout << "4 - Voltar ao menu inicial e não adicionar paciente.\n";
			cin >> escolha;
		} while (escolha != 4 && escolha != 1 &&  escolha != 2 && escolha != 3); {
			switch (escolha)
			{
			case 1:
				risco = 0;
				break;
			case 2:
				risco = 1;
				break;
			case 3:
				risco = 2;
				break;
			case 4:
				return;
				break;
			default:
				cout << "Escolha inválida.\n";
				break;
			}
		};
		

		
	
		Paciente pacienteTemp(nome, risco);
		pacientes.push_back(pacienteTemp);
		cout << "Paciente " << nome << " com o grau de urgência " << risco << " adicionado com sucesso!!\n";
		system("pause");
}

void Sistema::ImprimirLista()
{
	if (pacientes.size() <= 0) {
		cout << "Não há pacientes na fila.\n";
		return;
	}
	
	for (int i = 0; i < pacientes.size(); i++) {
		cout << i + 1 << "- ";
		cout << pacientes[i].getNome() << ": Grupo de risco ";
		cout << GrupoDeRisco(pacientes[i].getRisco()) << endl;
		
	}
	cout << endl;
	
}


void Sistema::RemoverPaciente()
{
	int escolha;
	
	cout << "Qual paciente você deseja remover da lista? \n";
	cout << "0 - para voltar sem remover nenhum.\n";
	cin >> escolha;
	if (escolha == 0)
		return;
	if (escolha < 1 || escolha > pacientes.size())
	{
		cout << "Escolha inválida.\n";
		Sleep(1500);
		return;
	}
	
	cout << "O paciente " << pacientes[escolha - 1].getNome() << " foi removido com sucesso!\n";
	

	pacientes.erase(pacientes.begin() + escolha - 1);
	system("pause");
}



void Sistema::ProximoPaciente()
{
	if (pacientes.size() <= 0) {
		cout << "Não há pacientes na fila.\n";
		system("pause");
		return;
	}
	cout << "O paciente " << pacientes[0].getNome() << " foi atendido e removido da fila!\n";
	pacientes.erase(pacientes.begin());
	if (pacientes.size() <= 0) {
		cout << "Não há pacientes na fila.\n";
		system("pause");
		return;
	}
	cout << "O próximo paciente a ser atendido será " << pacientes[0].getNome() << endl;
	system("pause");
}


void Sistema::Exemplo() 
{

	string nome;
	int risco;

	pacientes.push_back(Paciente("Gabriel", 1));
	OrganizarFila();
	pacientes.push_back(Paciente("Ana", 0));
	OrganizarFila();
	pacientes.push_back(Paciente("Alexandre", 2));
	OrganizarFila();
	pacientes.push_back(Paciente("Maria", 2));
	OrganizarFila();
	pacientes.push_back(Paciente("João", 1));
	OrganizarFila();
	pacientes.push_back(Paciente("Carla", 0));
	OrganizarFila();
	pacientes.push_back(Paciente("Ricardo", 2));
	OrganizarFila();
	pacientes.push_back(Paciente("Juliana", 1));
	OrganizarFila();
	pacientes.push_back(Paciente("Fernando", 0));
	OrganizarFila();
	pacientes.push_back(Paciente("Sandra", 2));
	OrganizarFila();
	pacientes.push_back(Paciente("Rodrigo", 1));
	OrganizarFila();
	pacientes.push_back(Paciente("Luciana", 0));
	OrganizarFila();
	pacientes.push_back(Paciente("Paulo", 2));
	OrganizarFila();
	pacientes.push_back(Paciente("Mariana", 1));
	OrganizarFila();
	pacientes.push_back(Paciente("Pedro", 0));
	OrganizarFila();
}
void Sistema::SituacaoFila()
{
	cout << "No momento tem " << pacientes.size() << " pacientes na fila e " << 50 - pacientes.size() << " espaços disponíveis.\n";
		
}



void Sistema::OrganizarFila()
{
	sort(pacientes.begin(), pacientes.end(), [](const Paciente& lhs, const Paciente& rhs) {
		return lhs.getRisco() > rhs.getRisco();
		});

	
}


string Sistema::GrupoDeRisco(int risco)
{
	if (risco == 0)
		return "Verde";
	if (risco == 1)
		return "Amarelo";
	if (risco == 2)
		return "Vermelho";
}
#include "Emprestimo.h"
#include "../Carro/Carro.h"
#include "../Utilities/Includes.h"

void cadastrarEmprestimo() {
  clear();
  Carro carroEmprestimo;

  cout << "Cadastrar empréstimo:\n";

  // Buscar modelo do carro
  cout << "Digite o modelo do carro para empréstimo: ";
  cin.ignore();
  getline(cin, carroEmprestimo.modelo);

  // Buscar cor do carro
  cout << "Digite a cor do carro para empréstimo: ";
  getline(cin, carroEmprestimo.cor);

  // Coletar informações adicionais
  string nomeCliente, dataInicio, dataFim;

  cout << "Digite o nome do cliente: ";
  getline(cin, nomeCliente);

  cout << "Digite a data de início do empréstimo: ";
  getline(cin, dataInicio);

  cout << "Digite a data de término do empréstimo: ";
  getline(cin, dataFim);

  // Registrar o empréstimo no arquivo "emprestimosCadastrados.txt"
  ofstream arquivoEmprestimos("src/BancoDados/emprestimosCadastrados.txt", ios::app);

  if (arquivoEmprestimos.is_open()) {
    arquivoEmprestimos << "Modelo: " << carroEmprestimo.modelo << ", Cor: " << carroEmprestimo.cor << "\n";
    arquivoEmprestimos << "Cliente: " << nomeCliente << ", Data de início: " << dataInicio << ", Data de término: " << dataFim << "\n";
    arquivoEmprestimos.close();
    cout << "Empréstimo registrado com sucesso!\n";
  }
  else {
    cerr << "Erro ao abrir o arquivo para salvar empréstimo.\n";
  }

  pauseAndClear(2);
}

void listarEmprestimos() {
  clear();
  ifstream arquivoEmprestimos("src/BancoDados/emprestimosCadastrados.txt");

  if (arquivoEmprestimos.is_open()) {
    cout << "Lista de empréstimos cadastrados:\n";
    set<string> emprestimosExibidos;

    string linha;
    while (getline(arquivoEmprestimos, linha)) {
      cout << linha << "\n";
    }
    arquivoEmprestimos.close();
  }
  else {
    cerr << "Erro ao abrir o arquivo de empréstimos.\n";
  }

  pauseAndClear(2);
}

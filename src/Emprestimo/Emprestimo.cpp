#include "Emprestimo.h"
#include "../Carro/Carro.h"
#include "../Utilities/Includes.h"

using namespace std;

void cadastrarEmprestimo() {
  clear();
  Carro carroEmprestimo;
  cout << "Cadastrar empréstimo: \n";
  cout << "Digite o modelo do carro para empréstimo: ";
  cin.ignore();
  getline(cin, carroEmprestimo.modelo);

  cout << "Digite o ano do carro para empréstimo: ";
  cin >> carroEmprestimo.ano;

  cout << "Digite a cor do carro para empréstimo: ";
  cin.ignore();
  getline(cin, carroEmprestimo.cor);

  ifstream arquivoCarros("src/BancoDados/carrosCadastrados.txt");

  if (arquivoCarros.is_open()) {
    bool carroCadastrado = false;
    string linha;
    while (getline(arquivoCarros, linha)) {
      size_t pos1 = linha.find(',');
      size_t pos2 = linha.find(',', pos1 + 1);

      if (pos1 != string::npos && pos2 != string::npos) {
        string modelo = linha.substr(0, pos1);
        string anoStr = linha.substr(pos1 + 1, pos2 - pos1 - 1);
        string cor = linha.substr(pos2 + 1);

        int ano = stoi(anoStr);

        if (modelo == carroEmprestimo.modelo && ano == carroEmprestimo.ano && cor == carroEmprestimo.cor) {
          carroCadastrado = true;

          cout << "Digite o nome do cliente: ";
          cin.ignore();
          getline(cin, carroEmprestimo.cliente);

          cout << "Digite a data de início do empréstimo: ";
          getline(cin, carroEmprestimo.dataInicio);

          cout << "Digite a data de término do empréstimo: ";
          getline(cin, carroEmprestimo.dataFim);

          ofstream arquivoEmprestimos("src/BancoDados/emprestimosCadastrados.txt", ios::app);

          if (arquivoEmprestimos.is_open()) {
            arquivoEmprestimos << "Modelo do Carro: " << carroEmprestimo.modelo << ", Ano: " << carroEmprestimo.ano << ", Cor: " << carroEmprestimo.cor << "\n";
            arquivoEmprestimos << "Cliente: " << carroEmprestimo.cliente << ", Data de início: " << carroEmprestimo.dataInicio << ", Data de término: " << carroEmprestimo.dataFim << "\n";
            arquivoEmprestimos.close();
            cout << "Empréstimo de carro concluído com sucesso!\n";
            break;
          }
          else {
            cerr << "Erro ao abrir o arquivo para salvar empréstimo.\n";
          }
        }
      }
      else {
        cerr << "Formato inválido no arquivo de carros.\n";
      }
    }

    arquivoCarros.close();

    if (!carroCadastrado) {
      cout << "O carro informado não está cadastrado.\n";
    }
  }
  else {
    cerr << "Erro ao abrir o arquivo de carros.\n";
  }
  pauseAndClear(2);
}

void listarEmprestimos() {
  clear();
  ifstream arquivoEmprestimos("src/BancoDados/emprestimosCadastrados.txt");

  if (arquivoEmprestimos.is_open()) {
    string linha;
    int contadorLinhas = 0;  // Contador para rastrear as linhas do empréstimo

    while (getline(arquivoEmprestimos, linha)) {
      // Processar grupos de três linhas
      if (contadorLinhas % 3 == 0) {
        cout << linha << ", ";
      }
      else if (contadorLinhas % 3 == 1) {
        cout << linha << ", ";
      }
      else {
        cout << linha << "\n";
      }

      contadorLinhas++;
    }

    arquivoEmprestimos.close();
  }
  else {
    cerr << "Erro ao abrir o arquivo de empréstimos.\n";
  }
  pauseAndClear(2);
}


#include "Carro.h"
#include "../Utilities/Includes.h"

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

void cadastrarCarro(vector<Carro>& carros) {
  Carro novoCarro;

  clear();
  cout << "Cadastro de Carro\n";
  printDivider();
  cout << "Digite o modelo do carro: ";
  cin.ignore();
  getline(cin, novoCarro.modelo);

  cout << "Digite o ano do carro: ";
  cin >> novoCarro.ano;

  cout << "Digite a cor do carro: ";
  cin.ignore();
  getline(cin, novoCarro.cor);

  carros.push_back(novoCarro);

  ofstream arquivoCarros("src/BancoDados/carrosCadastrados.txt", ios::app);

  if (arquivoCarros.is_open()) {
    arquivoCarros << novoCarro.modelo << "," << novoCarro.ano << "," << novoCarro.cor << "\n";
    arquivoCarros.close();

    clear();

    // Verificar se não houve erro durante a escrita
    if (arquivoCarros.fail()) {
      cout << "Erro ao escrever no arquivo de carros.\n";
    }
    else {
      cout << "Carro cadastrado e salvo com sucesso!\n";
    }
  }
  else {
    cout << "Erro ao abrir o arquivo para salvar carro.\n";
  }
  pauseAndClear(2);
}

void listarCarros(const vector<Carro>& carros) {
  clear();
  if (carros.empty()) {
    cout << "Nenhum carro cadastrado.\n";
  }
  else {
    cout << "Lista de carros cadastrados:\n";
    ifstream arquivoCarros("src/BancoDados/carrosCadastrados.txt");

    if (arquivoCarros.is_open()) {
      set<string> carrosExibidos;  // Conjunto para evitar duplicatas

      string linha;
      while (getline(arquivoCarros, linha)) {
        size_t pos1 = linha.find(',');
        size_t pos2 = linha.find(',', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
          string modelo = linha.substr(0, pos1);
          string anoStr = linha.substr(pos1 + 1, pos2 - pos1 - 1);
          string cor = linha.substr(pos2 + 1);

          string informacoesCarro = modelo + anoStr + cor;

          if (carrosExibidos.find(informacoesCarro) == carrosExibidos.end()) {
            cout << "Modelo: " << modelo << ", Ano: " << anoStr << ", Cor: " << cor << endl;
            carrosExibidos.insert(informacoesCarro);  // Adicionar ao conjunto de carros exibidos
          }
        }
        else {
          cerr << "Formato inválido no arquivo de carros.\n";
        }
      }
      arquivoCarros.close();
    }
    else {
      cerr << "Erro ao abrir o arquivo de carros.\n";
    }
  }
  pauseAndClear(2);
}

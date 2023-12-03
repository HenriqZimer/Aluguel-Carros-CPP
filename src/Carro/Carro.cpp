#include "Carro.h"
#include "../Utilities/Includes.h"

void cadastrarCarro(vector<Carro>& carros) {
  Carro novoCarro;

  clear();
  cout << "Cadastro de Carro\n";
  printDivider();
  cout << "Digite o modelo do carro: ";
  cin.ignore();
  getline(cin, novoCarro.modelo);

  cout << "Digite o cor do carro: ";
  cin >> novoCarro.cor;
  cin.ignore();

  carros.push_back(novoCarro);

  ofstream arquivoCarros("src/BancoDados/carrosCadastrados.txt", ios::app);

  if (arquivoCarros.is_open()) {
    arquivoCarros << novoCarro.modelo << "," << novoCarro.cor << "\n";
    arquivoCarros.close();

    clear();

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

void listarCarros() {
  clear();

  ifstream arquivoCarros("src/BancoDados/carrosCadastrados.txt");

  if (arquivoCarros.is_open()) {
    cout << "Lista de carros cadastrados:\n";
    set<string> carrosExibidos;

    string linha;
    while (getline(arquivoCarros, linha)) {
      size_t pos1 = linha.find(',');

      if (pos1 != string::npos) {
        string modelo = linha.substr(0, pos1);
        string cor = linha.substr(pos1 + 1);

        string informacoesCarro = modelo + cor;

        if (carrosExibidos.find(informacoesCarro) == carrosExibidos.end()) {
          cout << "Modelo: " << modelo << ", Cor: " << cor << endl;
          carrosExibidos.insert(informacoesCarro);
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

  pauseAndClear(2);
}

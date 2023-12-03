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

void apagarCarro() {
  clear();
  cout << "Apagar Carro\n";
  printDivider();

  string modeloCarroParaApagar;
  cout << "Digite o modelo do carro que deseja apagar: ";
  cin.ignore();
  getline(cin, modeloCarroParaApagar);

  ifstream arquivoEntrada("src/BancoDados/carrosCadastrados.txt");
  ofstream arquivoSaida("src/BancoDados/temp.txt");

  if (arquivoEntrada.is_open() && arquivoSaida.is_open()) {
    bool carroEncontrado = false;
    string linha;

    while (getline(arquivoEntrada, linha)) {
      size_t pos = linha.find(',');

      if (pos != string::npos) {
        string modeloCarro = linha.substr(0, pos);

        if (modeloCarro == modeloCarroParaApagar) {
          carroEncontrado = true;
        }
        else {
          arquivoSaida << linha << endl;
        }
      }
      else {
        cerr << "Formato inválido no arquivo de carros.\n";
      }
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    if (remove("src/BancoDados/carrosCadastrados.txt") != 0) {
      cerr << "Erro ao remover o arquivo original.\n";
    }

    if (rename("src/BancoDados/temp.txt", "src/BancoDados/carrosCadastrados.txt") != 0) {
      cerr << "Erro ao renomear o arquivo temporário.\n";
    }

    if (carroEncontrado) {
      cout << "Carro apagado com sucesso!\n";
    }
    else {
      cout << "Carro não encontrado.\n";
    }
  }
  else {
    cerr << "Erro ao abrir os arquivos.\n";
  }

  pauseAndClear(2);
}
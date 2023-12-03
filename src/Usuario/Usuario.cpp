#include "Usuario.h"
#include "../Utilities/Includes.h"

bool verificarCredenciais(const string& username, const string& password) {
  try {
    ifstream arquivo("src/BancoDados/usuariosCadastrados.txt");

    if (arquivo.is_open()) {
      string linha;
      while (getline(arquivo, linha)) {
        size_t pos = linha.find(',');
        string usuario = linha.substr(0, pos);
        string senha = linha.substr(pos + 1);

        if (usuario == username && senha == password) {
          arquivo.close();
          return true;
        }
      }
      arquivo.close();
    }
    else {
      throw runtime_error("Não foi possível abrir o arquivo de usuários.");
    }
  }
  catch (const exception& e) {
    cerr << "Erro: " << e.what() << endl;
  }
  return false;
}

void cadastrarUsuario() {
  clear();
  string username, password;

  cout << "Cadastrar usuário: \n";
  cout << "Digite o nome de usuário: ";
  cin >> username;

  cout << "Digite a senha: ";
  cin >> password;

  ofstream arquivoUsuarios("src/BancoDados/usuariosCadastrados.txt", ios::app);
  clear();
  if (arquivoUsuarios.is_open()) {
    arquivoUsuarios << username << "," << password << "\n";
    arquivoUsuarios.close();
    cout << "Usuário cadastrado com sucesso!\n";

  }
  else {
    cerr << "Erro ao abrir o arquivo para salvar usuário.\n";
  }
  pauseAndClear(2);
}

void listarUsuarios() {
  clear();
  ifstream arquivoUsuarios("src/BancoDados/usuariosCadastrados.txt");

  if (arquivoUsuarios.is_open() && arquivoUsuarios.peek() != ifstream::traits_type::eof()) {
    cout << "Lista de usuários cadastrados:\n";
    set<string> usuariosExibidos;

    string linha;
    while (getline(arquivoUsuarios, linha)) {
      size_t pos = linha.find(',');

      if (pos != string::npos) {
        string usuario = linha.substr(0, pos);
        string informacoesUsuario = usuario;

        if (usuariosExibidos.find(informacoesUsuario) == usuariosExibidos.end()) {
          cout << "Usuário: " << usuario << endl;
          usuariosExibidos.insert(informacoesUsuario);
        }
      }
      else {
        cerr << "Formato inválido no arquivo de usuários.\n";
      }
    }
    arquivoUsuarios.close();
  }
  else {
    cout << "Nenhum usuário cadastrado.\n";
    if (!arquivoUsuarios.is_open()) {
      cerr << "Erro ao abrir o arquivo de usuários.\n";
    }
  }
  pauseAndClear(2);
}
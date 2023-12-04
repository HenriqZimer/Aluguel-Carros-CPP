#include "src/Usuario/Usuario.h"
#include "src/Carro/Carro.h"
#include "src/Emprestimo/Emprestimo.h"
#include "src/Utilities/Includes.h"

using namespace std;

int main() {

  string username, password;
  clear();
  cout << "LOCALIZA - Aluguel de Carros\n";
  printDivider();
  cout << "Insira suas Credenciais para acessar\n";
  cout << "Digite o nome de usuário: ";
  cin >> username;
  cout << "Digite a senha: ";
  cin >> password;

  if (verificarCredenciais(username, password)) {
    clear();
    cout << "Login bem-sucedido!\n";
    pauseAndClear(2);

    vector<Carro> carrosCadastrados;

    int escolha;
    do {
      cout << "\nMenu LOCALIZA:\n";
      cout << "-------- Usuarios ------\n";
      cout << "1. Cadastrar usuário\n";
      cout << "2. Listar usuários\n";
      cout << "\n";
      cout << "-------- Carros ------\n";
      cout << "3. Cadastrar carro para empréstimos\n";
      cout << "4. Listar carros cadastrados para empréstimos\n";
      cout << "\n";
      cout << "-------- Empréstimos ------\n";
      cout << "5. Cadastrar empréstimo de carro\n";
      cout << "6. Listar empréstimos\n";
      cout << "\n";
      cout << "-------- Deletar ------\n";
      cout << "7. Deletar Usuario\n";
      cout << "8. Deletar carro\n";
      cout << "\n";
      cout << "9. Sair\n";
      cout << "Escolha uma opção: ";
      cin >> escolha;

      switch (escolha) {
      case 1:
        cadastrarUsuario();
        break;
      case 2:
        listarUsuarios();
        break;
      case 3:
        cadastrarCarro(carrosCadastrados);
        break;
      case 4:
        listarCarros();
        break;
      case 5:
        cadastrarEmprestimo();
        break;
      case 6:
        listarEmprestimos();
        break;
      case 7:
        apagarUsuario();
        break;
      case 8:
        apagarCarro();
        break;
      case 9:
        cout << "Saindo do programa...\n";
        break;
      default:
        cout << "Opção inválida. Tente novamente.\n";
        break;
      }
    } while (escolha != 9);
  }
  else {
    clear();
    cout << "Credenciais inválidas. Login falhou.\n";
    pauseAndClear(2);
  }

  return 0;
}
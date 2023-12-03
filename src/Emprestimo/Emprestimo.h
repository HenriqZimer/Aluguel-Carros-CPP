#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "../Carro/Carro.h"
#include <string>

using namespace std;

struct Emprestimo {
  Carro carro;
  string cliente;
  string dataInicio;
  string dataFim;
};

void cadastrarEmprestimo();
void listarEmprestimos();

#endif

#ifndef CARRO_H
#define CARRO_H

#include <string>
#include <vector>

using namespace std;

struct Carro {
  string modelo;
  int ano;
  string cor;
  string cliente;
  string dataInicio;
  string dataFim;
};

void cadastrarCarro(vector<Carro>& carros);
void listarCarros(const vector<Carro>& carros);

#endif

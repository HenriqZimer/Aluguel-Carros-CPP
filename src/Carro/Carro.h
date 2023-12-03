#ifndef CARRO_H
#define CARRO_H

#include <string>
#include <vector>

using namespace std;

struct Carro {
  string modelo;
  string cor;
};

void cadastrarCarro(vector<Carro>& carros);
void listarCarros();
void apagarCarro();

#endif

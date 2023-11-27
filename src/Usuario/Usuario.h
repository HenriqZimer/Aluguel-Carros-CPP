#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

bool verificarCredenciais(const string& username, const string& password);
void cadastrarUsuario();
void listarUsuarios();

#endif

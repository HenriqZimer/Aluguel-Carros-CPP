#include "Includes.h"

void printDivider() {
  cout << "-------------------------" << endl;
}

void invalidOption() {
  printDivider();
  cout << "Opção inválida." << endl;
  printDivider();
  pauseAndClear();
}

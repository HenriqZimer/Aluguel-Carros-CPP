#ifndef INCLUDES_H
#define INCLUDES_H

#include <thread> // É utilizado para a função this_thread::sleep_for.
#include <chrono> // É utilizado para especificar a duração do sono na função sleep_for.
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

inline void pauseAndClear(int seconds = 3) {
  this_thread::sleep_for(chrono::seconds(seconds));
  cout << "\x1B[2J\x1B[H";
}
inline void pause(int seconds = 3) {
  this_thread::sleep_for(chrono::seconds(seconds));
}
inline void clear() {
  cout << "\x1B[2J\x1B[H";
}

void printDivider();

void invalidOption();

#endif 

// Playground
// - You can use this template project for quick C++ experiments

#include <iostream>
#include "gamewindow.h"

using namespace std;

int main() {
  auto gw = GameWindow{};

  while (gw.pollEvents()){}

  return EXIT_SUCCESS;
}

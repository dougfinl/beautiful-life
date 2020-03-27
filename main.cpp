#include "lifeuniverse.h"
#include <iostream>

int main() {
  LifeUniverse u(30, 10);

  // Blinker
  u.setCell(12, 5);
  u.setCell(13, 5);
  u.setCell(14, 5);

  // Glider
  u.setCell(5, 5);
  u.setCell(6, 6);
  u.setCell(7, 6);
  u.setCell(7, 5);
  u.setCell(7, 4);

  // Beacon
  u.setCell(16, 0);
  u.setCell(17, 0);
  u.setCell(16, 1);
  u.setCell(17, 1);
  u.setCell(18, 2);
  u.setCell(19, 2);
  u.setCell(18, 3);
  u.setCell(19, 3);

  u.print();

  auto i = 20;
  while (i > 0) {
    u.update();
    u.print();
    i--;
  }

  return 0;
}

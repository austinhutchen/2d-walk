#pragma ONCE
#include "player.hpp"

class matrix {
public:
  char **map;
  matrix(player *_p, unsigned rows, unsigned cols) {
    this->p = _p;
    char **a = new char *[rows];
    for (int i = 0; i < rows; ++i)
      a[i] = new char[cols];
    this->map = a;
    spawn();
  }

  void spawn() {
    map[0][0] = p->character;
    p->py = 0;
    p->px = 0;
  }
  bool spawned() { return (p != 0x0); }
  void right() {
    // y represents columns
    p->py++;
    map[0][p->py] = p->character;
    map[0][p->py - 1] = ' ';
  }
  void clear() {
    for (int i = 0; i < 2; i++) {
      if (map[i] != 0x0) {
        delete map[i];
        map[i] = 0x0;
      }
    }
  }

private:
  player *p;
};
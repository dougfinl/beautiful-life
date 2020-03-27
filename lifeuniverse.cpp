#include "lifeuniverse.h"

#include <iostream>

LifeUniverse::LifeUniverse(size_t w, size_t h)
    : _iteration(0), _swapped(false) {
  std::vector<CellState> defaultRow(w, CS_Dead);
  _uniA.resize(h, defaultRow);
  _uniB.resize(h, defaultRow);
}

LifeUniverse::~LifeUniverse() {}

void LifeUniverse::update() {
  auto &nextUni = _nextUniverseData();

  for (size_t row = 0; row < nextUni.size(); row++) {
    for (size_t col = 0; col < nextUni[row].size(); col++) {
      const auto neighbours = _cellNeighbours(col, row);
      auto cellState = getCell(col, row);

      if (cellState == CS_Alive) {
        if (neighbours < 2 || neighbours > 3)
          cellState = CS_Dead;
      } else {
        if (neighbours == 3) {
          cellState = CS_Alive;
        }
      }

      nextUni[row][col] = cellState;
    }
  }

  _swapped = !_swapped;
  _iteration++;
}

void LifeUniverse::print(char deadChar, char aliveChar) const {
  using namespace std;

  cout << "Iteration " << _iteration << ':' << endl;

  const auto uniData = data();
  for (auto &row : uniData) {
    for (auto &cellState : row) {
      cout << (cellState == CS_Dead ? deadChar : aliveChar) << ' ';
    }
    cout << endl;
  }
}

void LifeUniverse::resize(size_t w, size_t h) {
  _currentUniverseData().resize(h);
  _nextUniverseData().resize(h);

  for (auto& row : _currentUniverseData()) {
    row.resize(w, CS_Dead);
  }

  for (auto& row : _nextUniverseData()) {
    row.resize(w, CS_Dead);
  }
}

void LifeUniverse::setCell(int x, int y) {
  _currentUniverseData()[y][x] = CS_Alive;
}

void LifeUniverse::clearCell(int x, int y) {
  _currentUniverseData()[y][x] = CS_Dead;
}

CellState LifeUniverse::getCell(int x, int y) const { return data()[y][x]; }

const UniverseData &LifeUniverse::data() const {
  return (_swapped ? _uniB : _uniA);
}

UniverseData &LifeUniverse::_currentUniverseData() {
  return (_swapped ? _uniB : _uniA);
}

UniverseData &LifeUniverse::_nextUniverseData() {
  return (_swapped ? _uniA : _uniB);
}

int LifeUniverse::_cellNeighbours(int x, int y) const {
  const auto &uniData = data();

  auto count = 0;
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      // Don't count the cell itself
      if (i == x && j == y)
        continue;

      // Assume cells outisde the universe bounds are dead
      if (i < 0 || j < 0 || i >= width() || j >= height())
        continue;

      if (getCell(i, j) == CS_Alive)
        count++;
    }
  }

  return count;
}

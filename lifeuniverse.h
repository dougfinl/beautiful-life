#ifndef LIFEUNIVERSE_H
#define LIFEUNIVERSE_H

#include <string>
#include <vector>

enum CellState : bool { CS_Dead, CS_Alive };

typedef std::vector<std::vector<CellState>> UniverseData;

class LifeUniverse {
public:
  /// Constructor.
  ///
  /// \param w the width of the universe in cells.
  /// \param h the height of the universe in cells.
  LifeUniverse(size_t w, size_t h);

  /// Destructor.
  ~LifeUniverse();

  /// \returns the width of the universe (cells).
  inline size_t width() const { return _uniA.at(0).size(); }

  /// \returns the height of the universe (cells).
  inline size_t height() const { return _uniA.size(); }

  /// This will be 0 if update() has not yet been called.
  ///
  /// \returns the current iteration number.
  inline unsigned long iteration() const { return _iteration; }

  void update();

  std::string str(char deadChar = '.', char aliveChar = '#') const;

  /// Prints a textual representation of the universe to STDOUT.
  void print(char deadChar = '.', char aliveChar = '#') const;

  /// Resizes the universe, adding or removing from the bottom and right sides.
  ///
  /// If the universe is enlarged, new cells will have CellState CS_Dead. If
  /// the universe is reduced, cells that fall outside the new universe size
  /// will be discarded.
  ///
  /// \param w the new width of the universe in cells. If 0, the width will not
  /// be changed.
  ///
  /// \param h the new height of the universe in cells. If 0, the height will
  /// not be changed.
  void resize(size_t w, size_t h);

  void setCell(int x, int y);
  void clearCell(int x, int y);
  CellState getCell(int x, int y) const;
  const UniverseData &data() const;

private:
  UniverseData &_currentUniverseData();
  UniverseData &_nextUniverseData();

  int _cellNeighbours(int x, int y) const;

  unsigned long _iteration;
  bool _swapped;
  UniverseData _uniA;
  UniverseData _uniB;
};

#endif // LIFEUNIVERSE_H

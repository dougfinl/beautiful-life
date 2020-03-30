#ifndef LIFEMAINWINDOW_H
#define LIFEMAINWINDOW_H

#include "lifeuniverse.h"
#include <QMainWindow>

#define LIFE_DEFAULT_WIDTH 30
#define LIFE_DEFAULT_HEIGHT 10

class QHBoxLayout;
class QPushButton;
class QSpinBox;
class QTextEdit;

class LifeMainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit LifeMainWindow(QWidget *parent = nullptr,
                          Qt::WindowFlags flags = Qt::WindowFlags());

private:
  void initBottomBar();
  void initSignals();
  void updateLifeUniverseOutput();

  LifeUniverse _lifeUniverse;
  QHBoxLayout *_hBoxBottomBar;
  QPushButton *_btnStepUniverse;
  QSpinBox *_spnUniWidth;
  QSpinBox *_spnUniHeight;
  QTextEdit *_txtLifeOutput;
};

#endif // LIFEMAINWINDOW_H
#include "lifemainwindow.h"

#include <QBoxLayout>
#include <QFontDatabase>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>

LifeMainWindow::LifeMainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags),
      _lifeUniverse(LIFE_DEFAULT_WIDTH, LIFE_DEFAULT_HEIGHT) {
  setWindowTitle("Beautiful Life");

  QVBoxLayout *mainLayout = new QVBoxLayout;

  _txtLifeOutput = new QTextEdit(this);
  _txtLifeOutput->setReadOnly(true);
  _txtLifeOutput->setTextInteractionFlags(Qt::NoTextInteraction);
  _txtLifeOutput->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
  mainLayout->addWidget(_txtLifeOutput);

  initBottomBar();
  mainLayout->addItem(_hBoxBottomBar);

  initSignals();

  QWidget *w = new QWidget;
  w->setLayout(mainLayout);
  setCentralWidget(w);

  // Blinker
  _lifeUniverse.setCell(12, 5);
  _lifeUniverse.setCell(13, 5);
  _lifeUniverse.setCell(14, 5);

  // Glider
  _lifeUniverse.setCell(5, 5);
  _lifeUniverse.setCell(6, 6);
  _lifeUniverse.setCell(7, 6);
  _lifeUniverse.setCell(7, 5);
  _lifeUniverse.setCell(7, 4);

  // Beacon
  _lifeUniverse.setCell(16, 0);
  _lifeUniverse.setCell(17, 0);
  _lifeUniverse.setCell(16, 1);
  _lifeUniverse.setCell(17, 1);
  _lifeUniverse.setCell(18, 2);
  _lifeUniverse.setCell(19, 2);
  _lifeUniverse.setCell(18, 3);
  _lifeUniverse.setCell(19, 3);

  updateLifeUniverseOutput();
}

void LifeMainWindow::initSignals() {
  connect(_btnStepUniverse, &QPushButton::released,
          [=]() {
            _lifeUniverse.update();
            updateLifeUniverseOutput();
  });
  connect(_spnUniWidth, QOverload<int>::of(&QSpinBox::valueChanged),
          [=](int newWidth) {
            _lifeUniverse.resize(newWidth, 0);
            updateLifeUniverseOutput();
          });
  connect(_spnUniHeight, QOverload<int>::of(&QSpinBox::valueChanged),
          [=](int newHeight) {
            _lifeUniverse.resize(0, newHeight);
            updateLifeUniverseOutput();
          });
}

void LifeMainWindow::initBottomBar() {
  _hBoxBottomBar = new QHBoxLayout;

  _hBoxBottomBar->addWidget(new QLabel("Width", this));
  _spnUniWidth = new QSpinBox(this);
  _spnUniWidth->setRange(1, 100);
  _spnUniWidth->setValue(_lifeUniverse.width());
  _hBoxBottomBar->addWidget(_spnUniWidth);

  _hBoxBottomBar->addWidget(new QLabel("Height", this));
  _spnUniHeight = new QSpinBox(this);
  _spnUniHeight->setRange(1, 100);
  _spnUniHeight->setValue(_lifeUniverse.height());
  _hBoxBottomBar->addWidget(_spnUniHeight);

  _btnStepUniverse = new QPushButton("Step", this);
  _hBoxBottomBar->addWidget(_btnStepUniverse);
}

void LifeMainWindow::updateLifeUniverseOutput() {
  _txtLifeOutput->clear();
  _txtLifeOutput->setText(_lifeUniverse.str().c_str());
}
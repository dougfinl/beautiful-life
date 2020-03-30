#include "lifemainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QCoreApplication::setOrganizationName("Douglas Finlay");
  QCoreApplication::setApplicationName("Beautiful Life");

  LifeMainWindow win;
  win.show();
  
  return app.exec();
}

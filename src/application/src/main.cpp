#include <application_widget/application_widget.hpp>

#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  ApplicationWidget widget;
  QTimer::singleShot(0, [&] { widget.show(); });

  return app.exec();
}

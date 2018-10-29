#pragma once

#include <QWidget>

#include <memory>

namespace Ui {
class ApplicationWidget;
}

class ApplicationWidget : public QWidget {
  Q_OBJECT

public:
  explicit ApplicationWidget(QWidget *parent = nullptr);
  ~ApplicationWidget() override;

private:
  std::unique_ptr<Ui::ApplicationWidget> ui;
};

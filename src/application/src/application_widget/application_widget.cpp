#include "application_widget.hpp"
#include "ui_application_widget.h"

ApplicationWidget::ApplicationWidget(QWidget *parent)
    : QWidget(parent), ui(std::make_unique<Ui::ApplicationWidget>()) {
  ui->setupUi(this);
}

ApplicationWidget::~ApplicationWidget() = default;

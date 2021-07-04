#pragma once

#include <QtWidgets/QMainWindow>

#include "simple_handler.h"
#include "ui_qtcefwindow.h"

class QtCefWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtCefWindow(QWidget* parent = Q_NULLPTR);

private:
    Ui::QtCefWindowClass ui;
    CefRefPtr<SimpleHandler> simple_handler_; // ������������CefRefPtr<SimpleHandler>��Ա
};
#include <cef_app.h>

#include "qtcefwindow.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

#include "simple_app.h"

/**
 * 初始化QT以及CEF相关
 */
int init_qt_cef(int& argc, char** argv)
{
    const HINSTANCE h_instance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

    const CefMainArgs main_args(h_instance);
    const CefRefPtr<SimpleApp> app(new SimpleApp); //CefApp实现，用于处理进程相关的回调。

    const int exit_code = CefExecuteProcess(main_args, app.get(), nullptr);
    if (exit_code >= 0)
    {
        return exit_code;
    }

    // 设置配置
    CefSettings settings;
    settings.multi_threaded_message_loop = true; //多线程消息循环
    settings.log_severity = LOGSEVERITY_DISABLE; //日志
    settings.no_sandbox = true; //沙盒

    CefInitialize(main_args, settings, app, nullptr);

    return -1;
}


int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);  // 解决高DPI下，界面比例问题
    QApplication a(argc, argv);
    const int result = init_qt_cef(argc, argv);
    if (result >= 0)
    {
        return result;
    }

    QtCefWindow w;
    w.show();
    a.exec();

    CefShutdown(); // 关闭CEF，释放资源

    return 0;
}

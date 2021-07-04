#include <cef_app.h>

#include "qtcefwindow.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

#include "simple_app.h"

/**
 * ��ʼ��QT�Լ�CEF���
 */
int init_qt_cef(int& argc, char** argv)
{
    const HINSTANCE h_instance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

    const CefMainArgs main_args(h_instance);
    const CefRefPtr<SimpleApp> app(new SimpleApp); //CefAppʵ�֣����ڴ��������صĻص���

    const int exit_code = CefExecuteProcess(main_args, app.get(), nullptr);
    if (exit_code >= 0)
    {
        return exit_code;
    }

    // ��������
    CefSettings settings;
    settings.multi_threaded_message_loop = true; //���߳���Ϣѭ��
    settings.log_severity = LOGSEVERITY_DISABLE; //��־
    settings.no_sandbox = true; //ɳ��

    CefInitialize(main_args, settings, app, nullptr);

    return -1;
}


int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);  // �����DPI�£������������
    QApplication a(argc, argv);
    const int result = init_qt_cef(argc, argv);
    if (result >= 0)
    {
        return result;
    }

    QtCefWindow w;
    w.show();
    a.exec();

    CefShutdown(); // �ر�CEF���ͷ���Դ

    return 0;
}

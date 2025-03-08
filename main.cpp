#include <all.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "hello_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    try {
        const QDateTime dt = QDateTime::currentDateTime();
        const QString date = dt.toString("yyyy/MM/dd hh:mm:ss");
        const QString name = Jstr("Current Date and Time : ");

        QTextStream(stdout) << name << date << "\n";
        return 0;

    } catch (const runtime_error &e) {
        cout << "runtime_error : " << e.what() << endl;
    } catch (const exception &e) {
        cout << "some exception : " << e.what() << endl;
    }

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    a.quit();

    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.
    // return a.exec();
}

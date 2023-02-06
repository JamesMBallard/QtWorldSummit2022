#include <QtQuickTest/quicktest.h>
#include <QQmlEngine>
#include <QGuiApplication>

class Setup : public QObject
{
  Q_OBJECT

public:
  Setup()
  {
  }

public slots:
  void qmlEngineAvailable(QQmlEngine* engine)
  {
    engine->addImportPath(QDir(QCoreApplication::applicationDirPath()).filePath("qml"));
#ifdef ARCGIS_RUNTIME_IMPORT_PATH_2
    engine->addImportPath(ARCGIS_RUNTIME_IMPORT_PATH_2);
#endif
  }
};

QUICK_TEST_MAIN_WITH_SETUP(example, Setup)

#include "main.moc"

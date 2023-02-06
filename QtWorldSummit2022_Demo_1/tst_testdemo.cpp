#include <QtTest>
#include <QUrl>
#include "Map.h"
#include "MapTypes.h"

using namespace Esri::ArcGISRuntime;

class TestDemo : public QObject
{
  Q_OBJECT
public:
  TestDemo() = default;
  ~TestDemo() = default;
private slots:
  void test_map_maxScale_setters_and_getters();
  void test_map_maxScale_default();
  void test_that_fails();
  void test_with_missing_dependency();
private:
  Map* m_map = new Map(this);
};

void TestDemo::test_map_maxScale_setters_and_getters()
{
  constexpr double maxScale = 5000.0;
  m_map->setMaxScale(maxScale);
  QCOMPARE(m_map->maxScale(), maxScale);
}

void TestDemo::test_map_maxScale_default()
{
  QCOMPARE(m_map->maxScale(), 0);
}

void TestDemo::test_that_fails()
{
  QCOMPARE(m_map->minScale(), 1234.56);
}

void TestDemo::test_with_missing_dependency()
{
  const QUrl service("https://qtteam.maps.arcgis.com/invalid_webmap");
  m_map = new Map(service, this);
  m_map->load();
  QTRY_COMPARE_WITH_TIMEOUT(m_map->loadStatus(), LoadStatus::Loaded, 1);
}

QTEST_MAIN(TestDemo)

#include "tst_testdemo.moc"

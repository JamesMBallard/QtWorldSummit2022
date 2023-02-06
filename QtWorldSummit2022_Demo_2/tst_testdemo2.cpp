#include <QtTest>
#include <QUrl>
#include "Map.h"
#include "MapTypes.h"

using namespace Esri::ArcGISRuntime;

class TestDemo2 : public QObject
{
  Q_OBJECT
public:
  TestDemo2() = default;
  ~TestDemo2() = default;
private slots:
  void test_map_maxScale_setters_and_getters();
  void test_map_maxScale_default();
  void test_that_fails();
  void test_with_missing_dependency();
};

void TestDemo2::test_map_maxScale_setters_and_getters()
{
  constexpr double maxScale = 5000.0;
  Map map;
  map.setMaxScale(maxScale);
  QCOMPARE(map.maxScale(), maxScale);
}

void TestDemo2::test_map_maxScale_default()
{
  QCOMPARE(Map{}.maxScale(), 0);
}

void TestDemo2::test_that_fails()
{
  QEXPECT_FAIL("", "test is failing and needs to be investigated", Continue);
  QCOMPARE(Map{}.minScale(), 1234.56);
}

void TestDemo2::test_with_missing_dependency()
{
  QSKIP("the test service is offline");
  const QUrl service("https://qtteam.maps.arcgis.com/invalid_webmap");
  Map map{service};
  map.load();
  QTRY_COMPARE_WITH_TIMEOUT(map.loadStatus(), LoadStatus::Loaded, 1);
}

QTEST_MAIN(TestDemo2)

#include "tst_testdemo2.moc"

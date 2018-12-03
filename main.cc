#include "Widget.h"

#include <QApplication>
#include <QSettings>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

#include "Db/Db.h"

#include <QDebug>

int main(int argc, char *argv[])
{
  QSettings settings("dotty.su","MyDoc");
  settings.setDefaultFormat(QSettings::IniFormat);
  QString qSettingsDb = settings.value("db","/tmp/db_name.sqlite").toString();

  Db db (qSettingsDb);
  QVector<QString> names = db.getNames();

  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication a(argc, argv);
  Widget w(db);
  w.setMenu(names);
  w.show();

  return a.exec();
}

#include "Db.h"

#include <QDebug>


Db::Db(QString qSettingsDb, QObject *parent) : QObject(parent)
{
  QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
  sdb.setDatabaseName(qSettingsDb);
  if (!sdb.open()) {
//        qDebug() << sdb.lastError().text();
  };
  QString createTableStr = "CREATE TABLE IF NOT EXISTS posts ( id INTEGER PRIMARY KEY, section text NOT NULL UNIQUE, ctx TEXT );";
  QSqlQuery query(createTableStr);
}


QVector<QString> Db::getNames() {
  QVector<QString> names;
  QSqlQuery query;
  query.exec("SELECT * FROM posts;");
  QSqlRecord rec = query.record();

  QString name,
                  ctx;

  while (query.next()) {
      name = query.value(rec.indexOf("section")).toString();
//      ctx = query.value(rec.indexOf("ctx")).toString();

      names.append(name);
  }
  return names;

}

QString Db::getPage(QString page) {
  QString strQuery = "SELECT ctx FROM posts where section='%1';";
  QSqlQuery query;
  query.exec(strQuery.arg(page));

  QSqlRecord rec = query.record();
  QString ctx;
  while (query.next()) {
      ctx = query.value(rec.indexOf("ctx")).toString();
      return ctx;
  }

  return strQuery.arg(page);
}

void Db::savePost(QString page, QString ctx) {
  qInfo() << "save "<< page;
  qInfo() << "ctx:\n" << ctx;
  /*
UPDATE employees
SET lastname = 'Smith'
WHERE
 employeeid = 3;
   */
  QString strQuery = "UPDATE posts SET ctx = '%1' WHERE section = '%2';";
  QSqlQuery query;
  qInfo() << strQuery.arg(ctx).arg(page);
  query.exec(strQuery.arg(ctx).arg(page));

}
void Db::deletePost(QString page) {
  qInfo() << "delete " << page;
  QString strQuery = "DELETE FROM posts WHERE section = '%1';";
  QSqlQuery query;
  qInfo() << strQuery.arg(page);
  query.exec(strQuery.arg(page));

}

void Db::createPost(QString post) {
  QString strQuery = "INSERT INTO posts (section, ctx) VALUES ("
        "'%1', '');";
  QSqlQuery query;
  qInfo() << strQuery.arg(post);
  bool exec = query.exec(strQuery.arg(post));
  if (exec) {
      addButtonPost(post);
//    PushButton newBtn(post);
  }
}

#ifndef DB_H
#define DB_H

#include <QObject>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

class Db : public QObject
{
  Q_OBJECT
public:
  explicit Db(QString qSettingsDb, QObject *parent = nullptr);
  QVector<QString> getNames();
  QString getPage(QString page);
  void savePost(QString, QString);
  void deletePost(QString);
  void createPost(QString);

signals:
  void addButtonPost(QString post);

public slots:

private:
  QSqlDatabase sdb;
};

#endif // DB_H

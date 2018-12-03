#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QVector>
#include <QMap>
#include <QLabel>

#include "PushButton/PushButton.h"
#include "CtxActions/CtxActions.h"
#include "AddButton/AddButton.h"
#include "Db/Db.h"


class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(Db& db, QWidget *parent = nullptr);
  ~Widget();

public slots:
  void setMenu(QVector<QString> names);

private:
  QString activePage;
  QString titleMenuTxt = "menu:";
  QLabel *titleMenu;
  QHBoxLayout mainLayout;
  QVBoxLayout menu;
  QVBoxLayout ctx;
  Db& db;
  AddButton *add;
//  QVector<PushButton*> btns;
  QMap<PushButton*,QMetaObject::Connection> btns;
  QTextEdit textEdit;
  CtxActions *ctxActions;

private slots:
  void changePage(QString);
  void clearMenu();
  void deletePost();
  void savePost();
  void createPost(QString post);
  void addButtonPost(QString);
};

#endif // WIDGET_H

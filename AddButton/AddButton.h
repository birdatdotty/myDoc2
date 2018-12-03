#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QWidget>
#include <QPushButton>

#include "AddDialog/AddDialog.h"

class AddButton : public QPushButton
{
  Q_OBJECT
public:
  explicit AddButton(QString title);

signals:
  void createTheme(QString);

public slots:
  void released();

private slots:
  void newTheme(QString);

private:
  AddDialog *dialog;
  QMetaObject::Connection dialogConnect;
};

#endif // ADDBUTTON_H

#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class AddDialog : public QDialog
{
  Q_OBJECT
public:
  AddDialog(QWidget *parent = nullptr);

private:
  QGridLayout mainLayout;
  QLineEdit theme;
  QPushButton ok,
                             cancel;

private slots:
  void okClick();

signals:
  void newTheme(QString);
};

#endif // ADDDIALOG_H

#ifndef CTXACTIONS_H
#define CTXACTIONS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class CtxActions : public QWidget
{
  Q_OBJECT
public:
  explicit CtxActions(QWidget *parent = nullptr);
  ~CtxActions();

signals:
  void saveClick();
  void deleteClick();

public slots:
  void active();

private:
  QGridLayout mainLayout;
  //  ctx.addWidget(new
  QPushButton *saveAction;
  //  ctx.addWidget(new
  QPushButton *deleteAction;

};

#endif // CTXACTIONS_H

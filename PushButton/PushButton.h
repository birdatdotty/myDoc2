#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

class PushButton : public QPushButton
{
  Q_OBJECT
public:
  PushButton(QString);

private:
  QString name;

private slots:
  void released_slot();

signals:
    void clickedName(QString);
};


#endif // PUSHBUTTON_H

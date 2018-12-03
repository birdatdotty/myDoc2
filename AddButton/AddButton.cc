#include "AddButton.h"

#include <QDebug>
#include <QInputDialog>

AddButton::AddButton(QString title)
  : QPushButton(title)
{
  connect(this, &QPushButton::released,
                  this, &AddButton::released);
}

void AddButton::newTheme(QString newTheme) {
  QObject::disconnect(dialogConnect);
  delete dialog;

  createTheme(newTheme);
}

void AddButton::released() {
  dialog = new AddDialog();
  dialogConnect = connect(dialog, &AddDialog::newTheme,
                                                   this, &AddButton::newTheme);
  dialog->setModal(true);
  dialog->show();
}

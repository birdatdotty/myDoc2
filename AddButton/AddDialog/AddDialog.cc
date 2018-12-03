#include "AddDialog.h"

#include <QDebug>

AddDialog::AddDialog(QWidget *parent)
  : QDialog(parent),
    ok("Создать"),
    cancel("Передумал")
{
  mainLayout.addWidget(&theme, 0, 0, 1, 2);
  mainLayout.addWidget(&ok, 1, 0);
  mainLayout.addWidget(&cancel, 1, 1);

  ok.setEnabled(false);
  connect(&theme, &QLineEdit::textChanged,
          [=](QString th) { ok.setEnabled(th.size()>0); });

  connect(&cancel, &QPushButton::released,
          [=](){close();});
  connect(&ok, &QPushButton::released,
          this, &AddDialog::okClick);

  setLayout(&mainLayout);
}

void AddDialog::okClick() {
  qInfo() << theme.text();
  newTheme(theme.text());
//  createTheme
}

#include "CtxActions.h"

CtxActions::CtxActions(QWidget *parent)
  : QWidget(parent),
    saveAction(new QPushButton("Сохранить")),
    deleteAction(new QPushButton("Удалить"))
{
  mainLayout.addWidget(saveAction, 0, 0);
  mainLayout.addWidget(deleteAction, 0, 1);

  saveAction->setEnabled(false);
  deleteAction->setEnabled(false);

  connect(  saveAction, &QPushButton::released,
                    [=](){saveClick();});

  connect(  deleteAction, &QPushButton::released,
                    [=](){deleteClick();});


  setLayout(&mainLayout);
}

CtxActions::~CtxActions() {
  delete saveAction;
  delete  deleteAction;
}

void CtxActions::active() {
  saveAction->setEnabled(true);
  deleteAction->setEnabled(true);
}

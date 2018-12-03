#include "PushButton.h"

#include <QDebug>

PushButton::PushButton(QString a)
  : QPushButton(a),
    name(a)
{
  connect( this, &QPushButton::released,
                    this, &PushButton::released_slot);
}

void PushButton::released_slot() {
  clickedName(name);
}

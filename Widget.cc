#include "Widget.h"

#include <QDebug>

Widget::Widget(Db& db, QWidget *parent)
  : QWidget(parent),
    titleMenu(new QLabel(titleMenuTxt)),
    db(db),
    ctxActions(new CtxActions())
{
  mainLayout.addLayout(&menu);
  mainLayout.addLayout(&ctx);
  menu.setAlignment(Qt::AlignTop);

  menu.addWidget(titleMenu);

//  menu.addStretch();
  ctx.addWidget(&textEdit);
  ctx.addWidget(ctxActions);
  connect(ctxActions, &CtxActions::deleteClick,
          [=](){deletePost();});

  connect(ctxActions, &CtxActions::saveClick,
          [=](){savePost();});

  connect(&db, &Db::addButtonPost, this, &Widget::addButtonPost);
  setLayout(&mainLayout);
}

Widget::~Widget()
{
  delete ctxActions;
  clearMenu();
}

void Widget::clearMenu() {
  foreach(PushButton* btn, btns.keys()) {
    QObject::disconnect(btns[btn]);
    delete btn;
  }
  btns.clear();
}

void Widget::addButtonPost(QString post) {
  qInfo() << "Widget::addButtonPost" << post;
  PushButton *btn = new PushButton(post);
  QMetaObject::Connection btnConn =
      connect( btn,&PushButton::clickedName,
                        this, &Widget::changePage);

  btns.insert(btn, btnConn);
  menu.addWidget(btn);
}
void Widget::setMenu(QVector<QString> names) {
  clearMenu();
  for (QString name: names) {
    PushButton *btn = new PushButton(name);
    menu.addWidget(btn);

    QMetaObject::Connection btnConn =
        connect( btn,&PushButton::clickedName,
                          this, &Widget::changePage);
    btns.insert(btn, btnConn);
  }
  add = new AddButton("добавить");
  connect(add, &AddButton::createTheme, this, &Widget::createPost);
  menu.addWidget(add);
}

void Widget::changePage(QString page) {
  activePage = page;
  QString ctx = db.getPage(page);
  textEdit.setText(ctx);
  ctxActions->active();
}

void Widget::deletePost() {
  qInfo() << "delete" << activePage;
  db.deletePost(activePage);
}

void Widget::savePost() {
  qInfo() << "save" << activePage;
  db.savePost(activePage, textEdit.toPlainText());
}

void Widget::createPost(QString post) {
//  createTheme
  qInfo () << "void Widget::createPost(QString " << post << ")";
  db.createPost(post);
}

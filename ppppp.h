#ifndef PPPPP_H
#define PPPPP_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class ppppp; }
QT_END_NAMESPACE

class ppppp : public QWidget
{
    Q_OBJECT

public:
    ppppp(QWidget *parent = nullptr);
    ~ppppp();

public slots:
   void saveText();
   void clearText();
   void add();

private:
    Ui::ppppp *ui;
    QLineEdit *campo1Input;
    QLineEdit *campo2Input;
    QPushButton *okButton;
    QPushButton *clearButton;
    QPushButton *addButton;

    QMap<QString, QString> collect;
    QString oldCampo1;
    QString oldCampo2;
    int count = 0;
};
#endif // PPPPP_H

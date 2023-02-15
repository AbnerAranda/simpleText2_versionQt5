#include "ppppp.h"
#include "ui_ppppp.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QMap>
#include <QDebug>

ppppp::ppppp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ppppp)
{
    QLabel *campo1Label = new QLabel(tr("Campo 1:"));
    campo1Input = new QLineEdit;
    QLabel *campo2Label = new QLabel(tr("Campo 2:"));
    campo2Input = new QLineEdit;

    okButton = new QPushButton(tr("Ok"));
    okButton->show();
    clearButton = new QPushButton(tr("Clear"));
    clearButton->show();
    addButton = new QPushButton(tr("Add"));
    addButton->show();

    connect(okButton, &QPushButton::clicked, this, &ppppp::saveText);
    connect(clearButton, &QPushButton::clicked, this, &ppppp::clearText);
    connect(addButton, &QPushButton::clicked, this, &ppppp::add);

    QHBoxLayout *campo1Layout = new QHBoxLayout;
    campo1Layout->addWidget(campo1Label);
    campo1Layout->addWidget(campo1Input);

    QHBoxLayout *campo2Layout = new QHBoxLayout;
    campo2Layout->addWidget(campo2Label);
    campo2Layout->addWidget(campo2Input);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(clearButton);
    buttonsLayout->addWidget(addButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(campo1Layout);
    mainLayout->addLayout(campo2Layout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);
    setWindowTitle("Simple Text 2");

    ui->setupUi(this);
}

void ppppp::saveText(){
    QString printPreviousText;
    QMap<QString, QString>::iterator i;
    for(i = collect.begin(); i != collect.end(); ++i){
        printPreviousText = printPreviousText + "Campo 1: " + i.key() + "\n" + "Campo 2: " + i.value() + "\n" + "\n";
    }

    QString campo1Print = campo1Input->displayText();
    QString campo2Print = campo2Input->displayText();
    QString printLastText = "Campo 1: " + campo1Print + "\n" + "Campo 2: " + campo2Print + "\n";
    QString printText = printPreviousText + printLastText;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Text"), "",tr("Text (*.txt);;All Files (*)"));
    clearText();

    if(fileName.isEmpty())
            return;
        else{
                QFile file(fileName);
                if (!file.open(QIODevice::WriteOnly)) {
                    QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                    return;
                }
                QTextStream out(&file);
                out << printText;
            }

    collect.clear();
}

void ppppp::clearText(){
    campo1Input->clear();
    campo2Input->clear();
}

void ppppp::add(){
    oldCampo1 = campo1Input->text();
    oldCampo2 = campo2Input->text();
    collect.insert(oldCampo1,oldCampo2);
    clearText();
}

ppppp::~ppppp()
{
    delete ui;
}


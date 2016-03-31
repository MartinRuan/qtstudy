#include <QtWidgets>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent):QDialog(parent)
{
    label = new QLabel(tr("Find &What"), this);
    lineEdit = new QLineEdit(this);
    label->setBuddy(lineEdit);
    caseCheckBox = new QCheckBox(tr("&Case Sensitive"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));
    findPushButton = new QPushButton(tr("&Find"));
    findPushButton->setDefault(true);
    findPushButton->setEnabled(false);
    closePushButton = new QPushButton(tr("Close"));
    connect(lineEdit, SIGNAL(textChanged(QString)), this,
            SLOT(enabledFindButton(QString)));
    connect(findPushButton, SIGNAL(clicked(bool)), this, SLOT(fineClicked(bool)));
    connect(closePushButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findPushButton);
    rightLayout->addWidget(closePushButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    this->setLayout(mainLayout);
    this->setWindowTitle(tr("Find"));
    this->setFixedHeight(sizeHint().height());
}


void FindDialog::enabledFindButton(const QString &text)
{
        this->findPushButton->setEnabled(!text.isEmpty());
}

void FindDialog::fineClicked(bool)
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                       : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }
}

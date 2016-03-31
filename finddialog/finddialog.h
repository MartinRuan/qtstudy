#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QObject>
#include <QDialog>

class QWidget;
class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;
class QString;

class FindDialog:public QDialog
{
    Q_OBJECT
public:
    FindDialog(QWidget *parent = 0);
signals:
    void findNext(const QString & str, Qt::CaseSensitivity cs) ;
    void findPrevious(const QString & str, Qt::CaseSensitivity cs);
private slots:
    void enabledFindButton(const QString & text);
    void fineClicked(bool);
private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findPushButton;
    QPushButton *closePushButton;
};

#endif // FINDDIALOG_H

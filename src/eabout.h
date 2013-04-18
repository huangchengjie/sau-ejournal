#ifndef EABOUT_H
#define EABOUT_H

#include <QMessageBox>

class EAbout : public QMessageBox
{
    Q_OBJECT
public:
    explicit EAbout(QWidget *parent = 0);
private:
    QString* EAboutText;
    void addText(QString);
};

#endif // EABOUT_H

#ifndef EUPGRADE_H
#define EUPGRADE_H

#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QCheckBox>
#include <QButtonGroup>
#include <QGroupBox>
#include <QBoxLayout>

class EUpdate : public QWizard
{
    Q_OBJECT
public:
    explicit EUpdate(QWidget *parent = 0);
private:
    QLabel*EUpdatePageIntroText, * EUpdatePageConfigText;
    QGroupBox* EGroupBoxMain, * EGroupBoxDetail;
    QCheckBox* ECheckBoxUpdateLib, * ECheckBoxUpdateBin, * ECheckBoxDownloadSource;
    QButtonGroup* EButtonGroupMain;
    QVBoxLayout* EUpdatePageIntroMain;
    QVBoxLayout* EUpdatePageConfigMain, * EUpdatePageConfigBox;
    QVBoxLayout* EUpdatePageConfirmn;
    QWizardPage* EUpdatePageIntro;
    QWizardPage* EUpdatePageConfig;
    QWizardPage* EUpdatePageConfirm;
    QWizardPage* EUpdatePageIntroInit();
    QWizardPage* EUpdatePageConfigInit();
    QWizardPage* EUpdatePageConfirmInit();
};

#endif // EUPGRADE_H

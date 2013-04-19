#include "eupdate.h"

EUpdate::EUpdate(QWidget *parent) :
    QWizard(parent)
{
    this->addPage(EUpdatePageIntroInit());
    this->addPage(EUpdatePageConfigInit());
    this->addPage(EUpdatePageConfirmInit());

    this->setWindowTitle("更新向导");
    this->setWizardStyle(QWizard::AeroStyle);
}

QWizardPage *EUpdate::EUpdatePageIntroInit()
{
    EUpdatePageIntro = new QWizardPage();
    EUpdatePageIntroMain = new QVBoxLayout();
    EUpdatePageIntroText = new QLabel();

    EUpdatePageIntroText->setText("更新向导是用以下载并更新最近一期的期刊或者升级软件本身。"
                                  "请点击下一步继续。");
    EUpdatePageIntroMain->addWidget(EUpdatePageIntroText);

    EUpdatePageIntro->setLayout(EUpdatePageIntroMain);
    EUpdatePageIntro->setTitle("欢迎使用更新向导");
    return EUpdatePageIntro;
}

QWizardPage *EUpdate::EUpdatePageConfigInit()
{
    EUpdatePageConfig = new QWizardPage();
    EUpdatePageConfigMain = new QVBoxLayout();
    EUpdatePageConfigBox = new QVBoxLayout();
    EGroupBoxMain = new QGroupBox();
    ECheckBoxUpdateLib = new QCheckBox();
    ECheckBoxUpdateBin = new QCheckBox();
    ECheckBoxDownloadSource = new QCheckBox();
    
    ECheckBoxUpdateLib->setText("更新期刊");
    ECheckBoxUpdateBin->setText("更新软件");
    ECheckBoxDownloadSource->setText("下载源代码");
    EGroupBoxMain->setTitle("更新选项");
    
    EUpdatePageConfigBox->addWidget(ECheckBoxUpdateLib);
    EUpdatePageConfigBox->addWidget(ECheckBoxUpdateBin);
    EUpdatePageConfigBox->addWidget(ECheckBoxDownloadSource);
    EGroupBoxMain->setLayout(EUpdatePageConfigBox);
    EUpdatePageConfigMain->addWidget(EGroupBoxMain);
    
    EUpdatePageConfig->setLayout(EUpdatePageConfigMain);
    EUpdatePageConfig->setTitle("请选择您要更新的组件");
    return EUpdatePageConfig;
}

QWizardPage *EUpdate::EUpdatePageConfirmInit()
{
    EUpdatePageConfirm = new QWizardPage();
    return EUpdatePageConfirm;
}

#include "eupgrade.h"

EUpgrade::EUpgrade(QWidget *parent) :
    QWizard(parent)
{
    this->setWindowTitle("更新向导");
    this->setWizardStyle(QWizard::AeroStyle);
}

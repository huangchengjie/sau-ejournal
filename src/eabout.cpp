#include "eabout.h"

EAbout::EAbout(QWidget *parent) :
    QMessageBox(parent)
{
    EAboutText = new QString("");

#ifdef __linux
    addText("社联会期刊 - Linux版\nSAU Journal for Linux\n\n");
#elif __WIN32
    addText("社联会期刊 - Windows版\nSAU Journal for Windows\n\n");
#endif
    addText("北京市第三十五中学学生社团联合会\nBeijing No.35 High School, Students' Assosiation Union\n\n");
    addText("版本号：1.0.0 Alpha\n");
    addText("开发者：黄诚捷\n");
    addText("刊物设计：学生社团联合会宣传部\n\n");
    addText("基于 Qt 5.0.2 (32 bit)\n");
    addText("使用 GNU Wget 开源工具\n");
#ifdef __linux
    addText("在 Arch Linux 3.8.7 上构建于 ");
#elif __WIN32
    addText("在 Windows 7 上构建于 ");
#endif
    addText("00:48 2013/04/18");
    addText("\n\n此程序是自由软件；您可以以自由软件基金会发布的 GNU通用公共许可协议第二版或(您可以选择)更高版方式重新发布它和/或修改它。\n\n此程序是希望其会有用而发布，但没有任何担保；没有甚至是暗含的适宜销售或特定目的适用性方面的担保。详情参看GNU 通用公共许可协议。");

    this->setWindowTitle("关于");
    this->setIcon(QMessageBox::Information);
    this->setText(*EAboutText);
}

void EAbout::addText(QString EAboutTextNew)
{
    *EAboutText = *EAboutText + EAboutTextNew;
}

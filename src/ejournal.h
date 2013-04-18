#ifndef EJOURNAL_H
#define EJOURNAL_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include <QBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSpacerItem>
#include <QPushButton>
#include <QStatusBar>

#include "eabout.h"
#include "eupgrade.h"

class EJournal : public QMainWindow
{
    Q_OBJECT
    
public:
    EJournal(QWidget *parent = 0);
    ~EJournal();
public slots:
    void EViewFullscreen();
    void EQuitFullscreen();
    void EUpgradeWindowShow();
    void EAboutWindowShow();
private:
    QMenuBar* EMenuBar;
    QMenu* EMenuFile, * EMenuEdit, * EMenuView, * EMenuHelp;
    QWidget* EWidgetMain;
    QBoxLayout* EBoxLayoutMain, * EBoxLayoutButton;
    QGraphicsView* EGraphicsViewMain;
    QGraphicsScene* EGraphicsSceneMain;
    QSpacerItem* ESpacer_A, * ESpacer_B, * ESpacer_C, *ESpacer_D;
    QPushButton* EButtonPre, * EButtonZoomOut, * EButtonZoomIn, * EButtonNext, * EButtonViewFullscreen, * EButtonQuitFullscreen;
    QStatusBar* EStatusBar;
    QAction* EMenuFileQuit;
    QAction* EMenuEditPre, * EMenuEditNext, * EMenuEditZoomOut, * EMenuEditZoomIn, * EMenuEditSetting;
    QAction* EMenuViewMenuBar, * EMenuViewStatusBar, * EMenuViewFullscreen;
    QAction* EMenuHelpUpgrade, * EMenuHelpHelp, * EMenuHelpAbout;

    void keyPressEvent(QKeyEvent *);
};

#endif // EJOURNAL_H

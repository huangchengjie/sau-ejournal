#include "ejournal.h"

EJournal::EJournal(QWidget *parent)
    : QMainWindow(parent)
{
    //Items Initialization
    ////MenuBar Initialization
    EMenuBar = new QMenuBar(this);
    //////File Menu Initialization
    EMenuFile = new QMenu(this);
    EMenuFileQuit = new QAction(this);
    //////Edit Menu Initialization
    EMenuEdit = new QMenu(this);
    EMenuEditSetting = new QAction(this);
    //////View Menu Initialization
    EMenuView = new QMenu(this);
    EMenuViewFullscreen = new QAction(this);
    //////Help Menu Initialization
    EMenuHelp = new QMenu(this);
    EMenuHelpUpgrade = new QAction(this);
    EMenuHelpHelp = new QAction(this);
    EMenuHelpAbout = new QAction(this);

    ////Main Journal View Initialization
    EGraphicsSceneMain = new QGraphicsScene();
    EGraphicsViewMain = new QGraphicsView(EGraphicsSceneMain);

    ////Button Initialization
    EButtonPre = new QPushButton();
    EButtonNext = new QPushButton();
    ESpacer_A = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    ESpacer_B = new QSpacerItem(30, 0);
    EButtonZoomOut = new QPushButton();
    EButtonZoomIn = new QPushButton();
    ESpacer_C = new QSpacerItem(30, 0);
    ESpacer_D = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    EButtonViewFullscreen = new QPushButton();
    EButtonQuitFullscreen = new QPushButton();

    ////Main Widget & Widget Initialization
    EWidgetMain = new QWidget();
    EBoxLayoutMain = new QBoxLayout(QBoxLayout::TopToBottom, EWidgetMain);
    EBoxLayoutButton = new QBoxLayout(QBoxLayout::LeftToRight);

    ////StatusBar Initialization
    EStatusBar = new QStatusBar(this);

    //Menu Action Connection Set
    connect(EMenuFileQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(EMenuViewFullscreen, SIGNAL(triggered()), SLOT(EViewFullscreen()));
    connect(EMenuHelpUpgrade, SIGNAL(triggered()), SLOT(EUpgradeWindowShow()));
    connect(EMenuHelpAbout, SIGNAL(triggered()), SLOT(EAboutWindowShow()));

    //MenuBar Set
    ////File Menu Set
    EMenuFileQuit->setText("退出(&Q)");
    EMenuFile->setTitle("文件(&F)");
    EMenuFile->addAction(EMenuFileQuit);

    ////Edit Menu Set
    EMenuEditSetting->setText("首选项(&E)...");
    EMenuEdit->setTitle("编辑(&E)");
    EMenuEdit->addAction(EMenuEditSetting);

    ////View Menu Set
    EMenuViewFullscreen->setText("全屏(&F)");
    EMenuView->setTitle("视图(&V)");
    EMenuView->addAction(EMenuViewFullscreen);

    ////Help Menu Set
    EMenuHelpUpgrade->setText("检查更新(&U)");
    EMenuHelpHelp->setText("帮助(&H)");
    EMenuHelpAbout->setText("关于(&A)");
    EMenuHelp->setTitle("帮助(&H)");
    EMenuHelp->addAction(EMenuHelpUpgrade);
    EMenuHelp->addSeparator();
    EMenuHelp->addAction(EMenuHelpHelp);
    EMenuHelp->addAction(EMenuHelpAbout);

    ////Add Menu to MenuBar
    EMenuBar->addMenu(EMenuFile);
    EMenuBar->addMenu(EMenuEdit);
    EMenuBar->addMenu(EMenuView);
    EMenuBar->addMenu(EMenuHelp);

    //Button Set
    EButtonPre->setText("上一页");
    EButtonPre->setDefault(false);
    EButtonNext->setText("下一页");
    EButtonNext->setDefault(false);
    EButtonZoomOut->setText("缩小");
    EButtonZoomOut->setDefault(false);
    EButtonZoomIn->setText("放大");
    EButtonZoomIn->setDefault(false);
    EButtonViewFullscreen->setText("全屏模式");
    EButtonViewFullscreen->setDefault(false);
    EButtonQuitFullscreen->setText("退出全屏");
    EButtonQuitFullscreen->setDefault(false);
    EButtonQuitFullscreen->hide();

    //Button Action Connection
    connect(EButtonViewFullscreen, SIGNAL(clicked()), SLOT(EViewFullscreen()));
    connect(EButtonQuitFullscreen, SIGNAL(clicked()), SLOT(EQuitFullscreen()));

    //Main Widget & BoxLayout Set
    ////Button Box Set
    EBoxLayoutButton->addWidget(EButtonZoomOut);
    EBoxLayoutButton->addWidget(EButtonZoomIn);
    EBoxLayoutButton->addItem(ESpacer_A);
    EBoxLayoutButton->addItem(ESpacer_B);
    EBoxLayoutButton->addWidget(EButtonPre);
    EBoxLayoutButton->addWidget(EButtonNext);
    EBoxLayoutButton->addItem(ESpacer_C);
    EBoxLayoutButton->addItem(ESpacer_D);
    EBoxLayoutButton->addWidget(EButtonViewFullscreen);
    EBoxLayoutButton->addWidget(EButtonQuitFullscreen);
    ////Main Box Set
    EBoxLayoutMain->addWidget(EGraphicsViewMain);
    EBoxLayoutMain->addLayout(EBoxLayoutButton);
    EWidgetMain->setLayout(EBoxLayoutMain);

    //MainWindow Set
    this->resize(800, 600);
    this->setWindowTitle("社联会期刊");
    this->setMenuBar(EMenuBar);
    this->setCentralWidget(EWidgetMain);
    this->setStatusBar(EStatusBar);
}

EJournal::~EJournal()
{
    
}

void EJournal::EViewFullscreen()
{
    EMenuBar->hide();
    EStatusBar->hide();
    EButtonViewFullscreen->hide();
    EButtonQuitFullscreen->show();
    this->showFullScreen();
}

void EJournal::EQuitFullscreen()
{
    EMenuBar->show();
    EStatusBar->show();
    EButtonViewFullscreen->show();
    EButtonQuitFullscreen->hide();
    this->showNormal();
}

void EJournal::EUpgradeWindowShow()
{
    EUpgrade EUpgradeWindow;
    EUpgradeWindow.exec();
}

void EJournal::EAboutWindowShow()
{
    EAbout EAboutWindow;
    EAboutWindow.exec();
}

void EJournal::keyPressEvent(QKeyEvent *k)
{
    //Fullscreen Key Set
    if (k->key() == Qt::Key_F11) {
        if ((EMenuBar->isVisible() == true) && (EStatusBar->isVisible() == true)) {
            EViewFullscreen();
        }
        else if ((EMenuBar->isVisible() == false) && (EStatusBar->isVisible() == false)) {
            EQuitFullscreen();
        }
    }
    else if (k->key() == Qt::Key_Escape) {
        EQuitFullscreen();
    }
}

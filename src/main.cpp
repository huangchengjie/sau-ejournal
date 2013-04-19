#include "ejournal.h"
#include <QApplication>

void EAboutWindowShow();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EJournal EJournalMain;

    EJournalMain.showMaximized();
    
    return a.exec();
}

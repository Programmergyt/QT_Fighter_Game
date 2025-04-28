#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//Game1();
	QApplication a(argc, argv);
	QtWidgetsApplication w; w.show();
    return a.exec();
}

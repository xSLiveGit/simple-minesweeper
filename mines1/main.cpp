#include "mines1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Mines1 w;
	w.show();
	return a.exec();
}

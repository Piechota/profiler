#include "profilerMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CProfilerMain w;
	w.show();
	return a.exec();
}

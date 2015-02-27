#include "capturedeviceproperty.h"
#include <QtWidgets/QApplication>
#include <QKeyEvent>

CaptureDeviceProperty *w;

class MyApplication : public QApplication
{
public:
	MyApplication(int argc, char** argv) : QApplication(argc, argv) {};
	~MyApplication() {};

	// global keypress hook
	bool notify(QObject* obj, QEvent *evt) {
		if (evt->type() == QEvent::KeyPress) {
			QKeyEvent *key_evt = (QKeyEvent *)evt;
			if (key_evt->key() == Qt::Key_Escape) {
				w->close();
			}
			return true;
		}
		return QApplication::notify(obj, evt);
	};
};

int main(int argc, char *argv[])
{
	MyApplication a(argc, argv);
	w = new CaptureDeviceProperty();
	w->show();

	int rv = a.exec();

	delete w;
	w = nullptr;

	return rv;
}

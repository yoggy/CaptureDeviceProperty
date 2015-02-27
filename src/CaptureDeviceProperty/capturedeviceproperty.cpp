#include "capturedeviceproperty.h"
#include <QDebug>

CaptureDeviceProperty::CaptureDeviceProperty(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.buttonReload, SIGNAL(clicked()), this, SLOT(onPressReload()));
	QObject::connect(ui.buttonShowProperty, SIGNAL(clicked()), this, SLOT(onPressShowProperty()));

	model = new QStringListModel(this);
	ui.listDevice->setModel(model);

	videoInput::setVerbose(false);

	updateCaptureDeviceList();
}

CaptureDeviceProperty::~CaptureDeviceProperty()
{
}

void CaptureDeviceProperty::updateCaptureDeviceList()
{
	QStringList list;

	for (int i = 0; i < vi.listDevices(); ++i) {
		char *name = vi.getDeviceName(i);
		QString str = QString("[%1] %2").arg(i).arg(name);
		list << str;
	}

	model->setStringList(list);
}

void CaptureDeviceProperty::onPressReload()
{
	qDebug() << "onPressReload";
	updateCaptureDeviceList();
}

void CaptureDeviceProperty::onPressShowProperty()
{
	qDebug() << "onPressShowProperty";

	int idx = ui.listDevice->currentIndex().row();

	if (idx >= 0) {
		vi.setupDevice(idx);
		vi.showSettingsWindow(idx);
		//vi.stopDevice(idx);
	}
}
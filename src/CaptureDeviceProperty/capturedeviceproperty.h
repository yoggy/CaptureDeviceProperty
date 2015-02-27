#ifndef CAPTUREDEVICEPROPERTY_H
#define CAPTUREDEVICEPROPERTY_H

#include <QtWidgets/QMainWindow>
#include "ui_capturedeviceproperty.h"

#include <QStringListModel>

#include "videoInput.h"
#if _DEBUG
#pragma comment(lib, "videoInputD.lib")
#else
#pragma comment(lib, "videoInput.lib")
#endif

class CaptureDeviceProperty : public QMainWindow
{
	Q_OBJECT

public:
	CaptureDeviceProperty(QWidget *parent = 0);
	~CaptureDeviceProperty();

private:
	Ui::CaptureDevicePropertyClass ui;

protected:
	QStringListModel *model;
	videoInput vi;

protected:
	void updateCaptureDeviceList();

public slots:
	void onPressReload();
	void onPressShowProperty();

};

#endif // CAPTUREDEVICEPROPERTY_H

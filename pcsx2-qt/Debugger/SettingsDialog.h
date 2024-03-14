// SPDX-FileCopyrightText: 2002-2024 PCSX2 Dev Team
// SPDX-License-Identifier: LGPL-3.0+

#include <QtWidgets\QDialog>
#include <QtWidgets\QPushButton>
#include <QtGui\QPainter>
#include <QtCore\QPropertyAnimation>
#include "ui_SettingsDialog.h"

class SettingsDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SettingsDialog(QWidget* parent = nullptr)
		: QDialog(parent)
	{
		Ui::SettingsDialog ui;
		ui.setupUi(this);

		//this->setStyleSheet("{background-image: url(':/icons/maxwell.png');}");

		//QPixmap background(":/icons/maxwell.png");

		//// Resize image to fit the widget size
		//background = background.scaled(this->size(), Qt::IgnoreAspectRatio);

		//QPalette palette;
		////palette.setBrush(QPalette::Background, background);
		//this->setPalette(palette);

		//palette.setColor(QPalette::Window, Qt::black);

		//this->setAutoFillBackground(true);
		//this->setPalette(palette);
		//this->show();
		//QPixmap bkgnd(":/images/maxwell.png");
		//bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
		//QPalette palette;
		//palette.setBrush(QPalette::Window, Qt::blue); //bkgnd);
		//this->setPalette(palette);
		//this->setStyleSheet("QWidget { background-color: blue; }");
		//QPainter painter(this);
		//painter.fillRect(rect(), Qt::blue);
		//this->show();


		//setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
		//setAttribute(Qt::WA_TranslucentBackground);
	}

protected:
	void paintEvent(QPaintEvent* event) override {
		QPainter painter(this);
		QPixmap bkgnd(":/images/maxwell.png");
		bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		painter.fillRect(rect(), Qt::transparent);
		painter.drawPixmap(0, 0, bkgnd);
		//painter.fillRect(rect(), Qt::blue);
	}
	//	void mousePressEvent(QMouseEvent* event) override
//	{
//		event->ignore();
//	}
};

//class MainWindow : public QMainWindow
//{
//public:
//	MainWindow()
//	{
		//QPushButton* settingsButton = new QPushButton(this);
		//settingsButton->setIcon(QIcon(":/icons/gear.png"));
		//settingsButton->setGeometry(10, 10, 32, 32);

//		SettingsDialog* panel = new SettingsDialog(this);
//		panel->hide(); // Initially hidden
//
//		QPropertyAnimation* animation = new QPropertyAnimation(panel, "geometry");
//		animation->setDuration(500); // Duration in milliseconds
//		QRect startRect = QRect(10, 10, 0, 0); // Start from the button position
//		QRect endRect = QRect(10, 10, 200, 200); // End size and position
//
//		connect(settingsButton, &QPushButton::clicked, [this, panel, animation, startRect, endRect]() {
//			if (panel->isVisible())
//			{
//				panel->hide();
//			}
//			else
//			{
//				// Adjust startRect and endRect based on the actual desired location and size
//				animation->setStartValue(startRect);
//				animation->setEndValue(endRect);
//				panel->setGeometry(startRect); // Set initial geometry for the animation
//				panel->show();
//				animation->start();
//			}
//		});
//	}
//};

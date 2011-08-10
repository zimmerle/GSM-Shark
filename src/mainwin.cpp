/*
 *
 * Copyright (C) 2011 Felipe Zimmerle <felipe at zimmerle dot org>.
 * All rights reserved.
 *
 * This file is part of GsmShark.
 *
 * GsmShark is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GsmShark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GsmShark. If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#include "mainwin.h"
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QMainWindow>
#include <QDeclarativeView>
#include <QToolBar>
#include <QStatusBar>
#include <QString>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>


#include "fakesegmentedbutton.h"
#include "common.h"
#include "combochannel.h"
#include "arfcn.h"

Spacer::Spacer(int fixedWidth, QWidget *parent)
    : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    if (fixedWidth)
        setFixedWidth(fixedWidth);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupStyleSheet();

    m_combo = new ComboChannel();
    m_scanButton = new QPushButton("Scan");
    m_edit = new QLineEdit();
    m_viewSelectionButton = new FakeSegmentedButton();
    m_statusBar = new QStatusBar();

    QObject::connect(m_combo, SIGNAL(newRange(QString)), m_edit, SLOT(setText(QString)));
    QObject::connect(m_scanButton, SIGNAL(clicked()), this, SLOT(startScan()));

    /* Main View */
    m_view = new QDeclarativeView(this);
    QDeclarativeContext *dc = m_view->rootContext();
    dc->setContextProperty("mainWindowContext", this);
    dc->setContextProperty("viewSwitch", m_viewSelectionButton);

    setupUi();
    m_combo->newBandSelected();

    this->setStatusBar(m_statusBar);
    m_view->setSource(QUrl("../Resources/qml/gsmdog/main.qml"));

    statusMessage("In our command!", 1000);
}

void MainWindow::setupStyleSheet(void)
{
    QFile file(":/res/main.css");
    if (!file.exists())
    {
        qDebug() << this << "::" << "Not able to open the style sheet file.";
        return;
    }
    file.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(StyleSheet);
}

void MainWindow::setupUi(void)
{
    this->setWindowTitle("GSM Shark (" GSMSHARK_VERSION ")");

    m_edit->setAttribute(Qt::WA_MacShowFocusRect, 0);
    m_combo->setAttribute(Qt::WA_MacShowFocusRect, 0);

    QToolBar *toolbar = new QToolBar();
    this->addToolBar(toolbar);
    this->setUnifiedTitleAndToolBarOnMac(true);

    toolbar->addWidget(new QLabel("Select Band: "));
    toolbar->addWidget(m_combo);
    toolbar->addWidget(new QLabel("  Arfcns:"));
    toolbar->addWidget(m_edit);
    toolbar->addWidget(m_scanButton);
    toolbar->addWidget(new Spacer());
    toolbar->addWidget(m_viewSelectionButton);
    toolbar->addWidget(new Spacer(10));

    QSize s(800, 600);
    this->resize(s);
}

void MainWindow::statusMessage(QString message, int timeout)
{
    m_statusBar->showMessage(message, timeout);
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    emit newWindowSize(e->size().width(), e->size().height() - m_statusBar->height());
    QWidget::resizeEvent(e);
}

void MainWindow::startScan(void)
{
    if (!m_edit->isEnabled() || !m_combo->isEnabled())
    {
        emit stopScan();
        return;
    }
    m_edit->setDisabled(true);
    m_combo->setDisabled(true);
    m_scanButton->setText("Stop!");
    emit startScan(m_edit->text());
}

void MainWindow::scanFinished(void)
{
    m_edit->setDisabled(false);
    m_combo->setDisabled(false);
    m_scanButton->setText("Scan");
}

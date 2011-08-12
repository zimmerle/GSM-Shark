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

#ifndef MAINWIN_H
#define MAINWIN_H

#include <QtGui/QMainWindow>
#include <QtGui/QResizeEvent>
#include <QtDeclarative/QDeclarativeView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

#include "scanengine.h"
#include "combochannel.h"
#include "fakesegmentedbutton.h"

class Spacer : public QWidget
{
    Q_OBJECT

public:
    explicit Spacer(int fixedWidth = 0, QWidget *parent = 0);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);

private:
    QDeclarativeView *m_view;
    void setupUi();
    void setupStyleSheet();
    QLineEdit *m_edit;
    QStatusBar *m_statusBar;
    ScanEngine *m_scanEngine;
    ComboChannel *m_combo;
    QPushButton *m_scanButton;
    FakeSegmentedButton *m_viewSelectionButton;

signals:
    void newWindowSize(int width, int height);
    void stopScan();
    void startScan(QString);
    void radioStatus(int status);

protected slots:
    void scanFinished(void);
    void statusMessage(QString, int);
    void startScan();
    void radio(int status);

public slots:
};

#endif // MAINWIN_H

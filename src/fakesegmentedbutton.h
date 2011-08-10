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

#ifndef FAKESEGMENTEDBUTTON_H
#define FAKESEGMENTEDBUTTON_H

#include <QtGui/QPushButton>
#include <QtGui/QMouseEvent>
#include <QtGui/QPaintEvent>
#include <QtGui/QPainter>
#include <QtGui/QLabel>
#include <QtCore/QtDebug>
#include "common.h"

class FakeSegmentedButtonSeparator : public QWidget
{
    Q_OBJECT

public:
    explicit FakeSegmentedButtonSeparator(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent*);

private:
    QPixmap m_pixmap;
};


class FakeSegmentedButtonUnity : public QWidget
{
    Q_OBJECT

public:
    explicit FakeSegmentedButtonUnity(int type = 0, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent*);
    void mouseReleaseEvent(QMouseEvent *);

private:
    bool m_pressed;
    int m_type;
    QPixmap m_button;
    QPixmap m_button_pressed;

signals:
    void clicked(int);

public slots:
    void press(int);
};


class FakeSegmentedButton : public QWidget
{
    Q_OBJECT

public:
    explicit FakeSegmentedButton(QWidget *parent = 0);

public slots:
    void handleClick(int);

signals:
    void switchView(int view);
};

#endif // FAKESEGMENTEDBUTTON_H

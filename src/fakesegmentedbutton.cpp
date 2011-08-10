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

#include "fakesegmentedbutton.h"
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtCore/QDebug>


/* Separator */
FakeSegmentedButtonSeparator::FakeSegmentedButtonSeparator(QWidget *parent) :
    QWidget (parent)
{
    setContentsMargins(0,0,0,0);

    m_pixmap.load(":/res/fake_button_middle_separator.png");

    setFixedWidth(m_pixmap.width());
    setFixedHeight(m_pixmap.height());
}

void FakeSegmentedButtonSeparator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_pixmap);
}

/* Unity */
FakeSegmentedButtonUnity::FakeSegmentedButtonUnity(int type, QWidget *parent) :
    QWidget(parent),
    m_pressed(false),
    m_type(type)
{
    setContentsMargins(0,0,0,0);

    if (type == GsmShark::Maps)
    {
        m_button.load(":/res/view_button_globe.png");
        m_button_pressed.load(":/res/view_button_globe_pressed.png");
    }
    else
    {
        m_button.load(":/res/view_button_list.png");
        m_button_pressed.load(":/res/view_button_list_pressed.png");
    }

    setFixedWidth(m_button.width());
    setFixedHeight(m_button.height());
}

void FakeSegmentedButtonUnity::press(int type)
{
    if (m_type == type)
    {
        m_pressed = true;
    }
    else
    {
        m_pressed = false;
    }

    repaint();
}

void FakeSegmentedButtonUnity::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (m_pressed)
    {
        painter.drawPixmap(rect(), m_button_pressed);
    }
    else
    {
        painter.drawPixmap(rect(), m_button);
    }
}

void FakeSegmentedButtonUnity::mouseReleaseEvent(QMouseEvent *e)
{
    if (!m_pressed)
    {
        emit clicked(m_type);
    }
}

/* Button */
FakeSegmentedButton::FakeSegmentedButton(QWidget *parent) :
    QWidget(parent)
{
    setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setSpacing(0);
    layout->setMargin(0);

    FakeSegmentedButtonUnity *map = new FakeSegmentedButtonUnity(GsmShark::Maps);
    FakeSegmentedButtonUnity *list = new FakeSegmentedButtonUnity(GsmShark::List);
    FakeSegmentedButtonSeparator *separator = new FakeSegmentedButtonSeparator();

    QObject::connect(map, SIGNAL(clicked(int)), this, SLOT(handleClick(int)));
    QObject::connect(this, SIGNAL(switchView(int)), map, SLOT(press(int)));

    QObject::connect(list, SIGNAL(clicked(int)), this, SLOT(handleClick(int)));
    QObject::connect(this, SIGNAL(switchView(int)), list, SLOT(press(int)));

    layout->addWidget(map);
    layout->addWidget(separator);
    layout->addWidget(list);

    this->setLayout(layout);

    emit switchView(GsmShark::Maps);
}

void FakeSegmentedButton::handleClick(int type)
{
    emit switchView(type);
}

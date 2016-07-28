/*
 * ngraphicswebview.cpp
 * Minh 3D OpenGL Flight Simulator on Google Maps
 * Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 *
 * This file is part of MFS.
 *
 * MFS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * MFS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Mgmp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include <QStandardPaths>
#include <QNetworkDiskCache>
#include "nmainwindow.h"
#include "ngraphicswebview.h"
ngraphicswebview::ngraphicswebview(nmainwindow *m):mediator(m) {
 dc=new QNetworkDiskCache(this);
 dc->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::CacheLocation));
 page()->networkAccessManager()->setCache(dc);
 qDebug()<<"ngraphicswebview::ngrahpicswebview";
}
void ngraphicswebview::paint(QPainter *p, const QStyleOptionGraphicsItem *options, QWidget *widget) {
 QGraphicsWebView::paint(p,options,widget);
p->setPen(QColor(0,64,0));
p->setFont(QFont("Tw Cen MT"));
p->drawText(widget->width()*4/5,0,100,100,Qt::AlignBottom|Qt::AlignLeft,"minhinc.com");
 p->beginNativePainting();
 mediator->update(this);
 p->endNativePainting();
 qDebug()<<"ngraphicswebview::paint";
}

/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2010 Fachhochschule Potsdam - http://fh-potsdam.de

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 5783 $:
$Author: cohen@irascible.com $:
$Date: 2012-01-25 22:31:21 -0800 (Wed, 25 Jan 2012) $

********************************************************************/


#include "itemdrag.h"
#include "debugdialog.h"

ItemDrag * ItemDrag::Singleton = new ItemDrag();

ItemDrag::ItemDrag(QObject * parent) :
	QObject(parent)
{
}

void ItemDrag::__dragIsDone() {
	m_cache.clear();
	emit dragIsDoneSignal(this);
}

void ItemDrag::cleanup() {
	if (Singleton) {
		delete Singleton;
		Singleton = NULL;
	}
}

QHash<QObject *, QObject *> & ItemDrag::cache() {
	return Singleton->m_cache;
}

ItemDrag * ItemDrag::singleton() {
	return Singleton;
}

void ItemDrag::dragIsDone() {
	Singleton->__dragIsDone();
}

void ItemDrag::setOriginator(QWidget * originator) {
	Singleton->m_originator = originator;
}

QWidget* ItemDrag::originator() {
	return Singleton->m_originator;
}

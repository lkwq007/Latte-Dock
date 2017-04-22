/*
*  Copyright 2016  Smith AR <audoban@openmailbox.org>
*                  Michail Vourlakos <mvourlakos@gmail.com>
*
*  This file is part of Latte-Dock
*
*  Latte-Dock is free software; you can redistribute it and/or
*  modify it under the terms of the GNU General Public License as
*  published by the Free Software Foundation; either version 2 of
*  the License, or (at your option) any later version.
*
*  Latte-Dock is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef VISIBILITYMANAGER_H
#define VISIBILITYMANAGER_H

#include "../liblattedock/dock.h"

#include <QObject>
#include <QTimer>

#include <Plasma/Containment>

namespace Latte {

class VisibilityManagerPrivate;
class DockView;

class VisibilityManager : public QObject {
    Q_OBJECT

    Q_PROPERTY(Latte::Dock::Visibility mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(bool raiseOnDesktop READ raiseOnDesktop WRITE setRaiseOnDesktop NOTIFY raiseOnDesktopChanged)
    Q_PROPERTY(bool raiseOnActivity READ raiseOnActivity WRITE setRaiseOnActivity NOTIFY raiseOnActivityChanged)
    Q_PROPERTY(bool isHidden READ isHidden WRITE setIsHidden NOTIFY isHiddenChanged)
    Q_PROPERTY(bool blockHiding READ blockHiding WRITE setBlockHiding NOTIFY blockHidingChanged)
    Q_PROPERTY(bool containsMouse READ containsMouse NOTIFY containsMouseChanged)
    Q_PROPERTY(bool edgePressure READ edgePressure WRITE setEdgePressure NOTIFY edgePressureChanged);
    Q_PROPERTY(int timerShow READ timerShow WRITE setTimerShow NOTIFY timerShowChanged)
    Q_PROPERTY(int timerHide READ timerHide WRITE setTimerHide NOTIFY timerHideChanged)


public:
    VisibilityManager(DockView* view);
    virtual ~VisibilityManager();

    Latte::Dock::Visibility mode() const;
    void setMode(Latte::Dock::Visibility mode);

    bool raiseOnDesktop() const;
    void setRaiseOnDesktop(bool enable);

    bool raiseOnActivity() const;
    void setRaiseOnActivity(bool enable);

    bool isHidden() const;
    void setIsHidden(bool isHidden);

    bool blockHiding() const;
    void setBlockHiding(bool blockHiding);

    bool containsMouse() const;

    bool edgePressure() const;
    void setEdgePressure(bool enable);

    int timerShow() const;
    void setTimerShow(int msec);

    int timerHide() const;
    void setTimerHide(int msec);

signals:
    void mustBeShown(QPrivateSignal);
    void mustBeHide(QPrivateSignal);

    void modeChanged();
    void raiseOnDesktopChanged();
    void raiseOnActivityChanged();
    void isHiddenChanged();
    void blockHidingChanged();
    void containsMouseChanged();
    void edgePressureChanged();
    void timerShowChanged();
    void timerHideChanged();

private:
    VisibilityManagerPrivate *const d;

    friend class VisibilityManagerPrivate;
};

}
#endif // VISIBILITYMANAGER_H

#ifndef VISIBILITYMANAGERPRIVATE_H
#define VISIBILITYMANAGERPRIVATE_H

#include "../liblattedock/dock.h"
#include "windowinfowrap.h"
#include "abstractwindowinterface.h"
#include "edgepressure.h"
#include "dockview.h"

#include <unordered_map>
#include <memory>

#include <QObject>
#include <QTimer>
#include <QEvent>

namespace Latte {

class VisibilityManager;

/*!
 * \brief The Latte::VisibilityManagerPrivate is a class d-pointer
 */
class VisibilityManagerPrivate : public QObject {
    Q_GADGET

public:
    VisibilityManagerPrivate(DockView* view, VisibilityManager* q);
    ~VisibilityManagerPrivate();

    void setMode(Dock::Visibility mode);
    void setRaiseOnDesktop(bool enable);
    void setRaiseOnActivity(bool enable);

    void setIsHidden(bool isHidden);
    void setBlockHiding(bool blockHiding);
    void setTimerShow(int msec);
    void setTimerHide(int msec);
    void setEnablePressure(bool enable);

    void raiseDock(bool raise);
    void raiseDockTemporarily();
    void updateHiddenState();

    void setDockGeometry(const QRect &rect);

    void windowAdded(WId id);
    void dodgeActive(WId id);
    void dodgeMaximized(WId id);
    void dodgeWindows(WId id);
    void checkAllWindows();

    bool intersects(const WindowInfoWrap &winfo);

    void saveConfig();
    void restoreConfig();

    void viewEventManager(QEvent *ev);

    VisibilityManager *q;
    PlasmaQuick::ContainmentView *view;
    AbstractWindowInterface *wm;
    Dock::Visibility mode{Dock::None};
    std::array<QMetaObject::Connection, 5> connections;
    std::unordered_map<WId, WindowInfoWrap> windows;
    EdgePressure edgePressure;

    QTimer timerShow;
    QTimer timerHide;
    QTimer timerCheckWindows;
    QTimer timerStartUp;
    QRect dockGeometry;
    bool isHidden{false};
    bool pressureActive{true};
    bool dragEnter{false};
    bool blockHiding{false};
    bool containsMouse{false};
    bool raiseTemporarily{false};
    bool raiseOnDesktopChange{false};
    bool raiseOnActivityChange{false};
    bool hideNow{false};
};

}

#endif // VISIBILITYMANAGERPRIVATE_H

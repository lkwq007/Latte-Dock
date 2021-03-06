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

#include "dockpackage.h"

#include <QDebug>

#include <KPackage/PackageLoader>
#include <KI18n/KLocalizedString>

namespace Latte {

DockPackage::DockPackage(QObject *parent, const QVariantList &args)
    : KPackage::PackageStructure(parent, args)
{
}

DockPackage::~DockPackage()
{
}

void DockPackage::initPackage(KPackage::Package *package)
{
    auto fallback = KPackage::PackageLoader::self()->loadPackage("Plasma/Shell", "org.kde.plasma.desktop");
    package->setDefaultPackageRoot(QStringLiteral("plasma/shells/"));
    package->setPath("org.kde.latte.shell");
    package->addFileDefinition("lattedockui", QStringLiteral("views/Panel.qml"), i18n("Latte Dock panel"));
    //Configuration
    package->addFileDefinition("lattedockconfigurationui", QStringLiteral("configuration/LatteDockConfiguration.qml"), i18n("Dock configuration UI"));
    package->addFileDefinition("configmodel", QStringLiteral("configuration/config.qml"), i18n("Config model"));
    package->addFileDefinition("tangerineFont", QStringLiteral("fonts/tangerine.ttf"), i18n("Tangerine Font"));
    package->setFallbackPackage(fallback);
    qDebug() << "package is valid" << package->isValid();
}

void DockPackage::pathChanged(KPackage::Package *package)
{
    if (!package->metadata().isValid())
        return;

    const QString pluginName = package->metadata().pluginId();

    if (!pluginName.isEmpty() && pluginName != "org.kde.latte.shell") {
        auto fallback = KPackage::PackageLoader::self()->loadPackage("Plasma/Shell", "org.kde.latte.shell");
        package->setFallbackPackage(fallback);
    } else if (pluginName.isEmpty() || pluginName == "org.kde.latte.shell") {
        package->setFallbackPackage(KPackage::Package());
    }
}

}

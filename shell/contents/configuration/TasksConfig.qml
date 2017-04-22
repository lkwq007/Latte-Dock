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
import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.kde.plasma.plasmoid 2.0

import org.kde.latte 0.1 as Latte

PlasmaComponents.Page {
    Layout.maximumWidth: content.width + content.Layout.leftMargin * 2
    Layout.maximumHeight: content.height + units.smallSpacing * 2

    ColumnLayout {
        id: content

        width: dialog.maxWidth - Layout.leftMargin * 2
        spacing: units.largeSpacing
        anchors.centerIn: parent
        Layout.leftMargin: units.smallSpacing * 2

        //! BEGIN: Tasks Appearance
        ColumnLayout {
            spacing: units.smallSpacing

            Header {
                text: i18n("Appearance")
            }

            PlasmaComponents.CheckBox {
                id: showGlow
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Show glow around windows points")
                checked: plasmoid.configuration.showGlow

                onClicked: {
                    plasmoid.configuration.showGlow = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: threeColorsWindows
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Different color for minimized windows")
                checked: plasmoid.configuration.threeColorsWindows

                onClicked: {
                    plasmoid.configuration.threeColorsWindows = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: dotsOnActive
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Indicator for active window group")
                checked: plasmoid.configuration.dotsOnActive
//                tooltip: i18n("Grouped windows show both a line and a dot when \none of them is active")

                onClicked: {
                    plasmoid.configuration.dotsOnActive = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: reverseLinesPosition
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Reverse position for lines and dots")
                checked: plasmoid.configuration.reverseLinesPosition

                onClicked: {
                    plasmoid.configuration.reverseLinesPosition = checked
                }
            }
        }
        //! END: Tasks Appearance

        //! BEGIN: Tasks Interaction
        ColumnLayout {
            spacing: units.smallSpacing

            Header {
                text: i18n("Interaction")
            }

            PlasmaComponents.CheckBox {
                id: showPreviewsChk
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Preview windows on hovering")
                checked: plasmoid.configuration.showToolTips

                onClicked: {
                    plasmoid.configuration.showToolTips = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: highlightWindowsChk
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Highlight windows on hovering")
                checked: plasmoid.configuration.highlightWindows

                onClicked: {
                    plasmoid.configuration.highlightWindows = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: windowActionsChk
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Show window actions in the context menu")
                checked: plasmoid.configuration.showWindowActions

                onClicked: {
                    plasmoid.configuration.showWindowActions = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: smartLaunchersChk
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Show progress information for tasks")
                checked: plasmoid.configuration.smartLaunchersEnabled
//                tooltip: i18n("Show a beautiful progress animation e.g. when copying \nfiles with Dolphin")


                onClicked: {
                    plasmoid.configuration.smartLaunchersEnabled = checked
                }
            }

            RowLayout {
                Layout.leftMargin: units.smallSpacing * 2
                visible: plasmoid.configuration.advanced

                PlasmaComponents.Label {
                    text: i18n("On middle-click:")
                    Layout.alignment: Qt.AlignRight
                }

                PlasmaComponents.ComboBox {
                    id: middleClickAction
                    Layout.fillWidth: true
                    model: [i18nc("The click action", "None"), i18n("Close Window or Group"), i18n("New Instance"), i18n("Minimize/Restore Window or Group")]

                    currentIndex: plasmoid.configuration.middleClickAction
                    onCurrentIndexChanged: plasmoid.configuration.middleClickAction = currentIndex
                }
            }

            RowLayout {
                Layout.leftMargin: units.smallSpacing * 2
                spacing: units.smallSpacing
                visible: plasmoid.configuration.advanced

                PlasmaComponents.ComboBox {
                    id: modifier
                    Layout.maximumWidth: theme.mSize(theme.defaultFont).width * 5
                    model: ["Shift", "Ctrl", "Alt", "Meta"]

                    currentIndex: plasmoid.configuration.modifier
                    onCurrentIndexChanged: plasmoid.configuration.modifier = currentIndex
                }

                PlasmaComponents.Label {
                    text: "+"
                }

                PlasmaComponents.ComboBox {
                    id: modifierClick
                    Layout.maximumWidth: theme.mSize(theme.defaultFont).width * 10
                    model: [i18n("Left Click"), i18n("Middle Click"), i18n("Right Click")]

                    currentIndex: plasmoid.configuration.modifierClick
                    onCurrentIndexChanged: plasmoid.configuration.modifierClick = currentIndex
                }

                PlasmaComponents.Label {
                    text: "="
                }

                PlasmaComponents.ComboBox {
                    id: modifierClickAction
                    Layout.fillWidth: true
                    model: [i18nc("The click action", "None"), i18n("Close Window or Group"), i18n("New Instance"), i18n("Minimize/Restore Window or Group")]

                    currentIndex: plasmoid.configuration.modifierClickAction
                    onCurrentIndexChanged: plasmoid.configuration.modifierClickAction = currentIndex
                }
            }
        }
        //! END: Tasks Interaction

        //! BEGIN: Tasks Filters
        ColumnLayout {
            spacing: units.smallSpacing

            Header {
                text: i18n("Filters")
            }

            PlasmaComponents.CheckBox {
                id: showOnlyCurrentScreen
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Show only tasks from the current screen")
                checked: plasmoid.configuration.showOnlyCurrentScreen

                onClicked: {
                    plasmoid.configuration.showOnlyCurrentScreen = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: showOnlyCurrentDesktop
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Show only tasks from the current desktop")
                checked: plasmoid.configuration.showOnlyCurrentDesktop

                onClicked: {
                    plasmoid.configuration.showOnlyCurrentDesktop = checked
                }
            }

            PlasmaComponents.CheckBox {
                id: showOnlyCurrentActivity
                Layout.leftMargin: units.smallSpacing * 2
                text: i18n("Show only tasks from the current activity")
                checked: plasmoid.configuration.showOnlyCurrentActivity

                onClicked: {
                    plasmoid.configuration.showOnlyCurrentActivity = checked
                }
            }
        }
        //! END: Tasks Filters
    }
}

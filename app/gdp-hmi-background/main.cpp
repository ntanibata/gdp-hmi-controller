/**
 * SPDX license identifier: MPL-2.0
 *
 * Copyright (C) 2015 GENIVI Alliance
 *
 * This file is part of GENIVI Demo Platform HMI.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License (MPL), v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * For further information see http://www.genivi.org/.
 *
 * List of changes:
 * 06.Feb.2015, Holger Behrens, written based on template created by QtCreator
 */

#include <QApplication>
#include <QQuickView>
#include <systemd/sd-journal.h>

#define GDP_BACKGROUND_SURFACE_ID 2

int main(int argc, char *argv[])
{
    setenv("QT_QPA_PLATFORM", "wayland", 1); // force to use wayland plugin
    setenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", "1", 1);

	sd_journal_print(LOG_DEBUG, "GDP: background surface (id=%u)",
		GDP_BACKGROUND_SURFACE_ID);

    QGuiApplication app(argc, argv);
    QQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));
    QQuickView view2(QUrl(QStringLiteral("qrc:/main.qml")));

    view.setProperty("IVI-Surface-ID", GDP_BACKGROUND_SURFACE_ID);
    view2.setProperty("IVI-Surface-ID", GDP_BACKGROUND_SURFACE_ID + 1000);
    view.show();
    view2.show();

    return app.exec();
}

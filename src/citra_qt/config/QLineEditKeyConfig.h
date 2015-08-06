// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <map>

#include <QLineEdit>
#include <core/settings.h>

class QKeyEvent;

/// The LineEdits used for button configuration
class QLineEditKeyConfig : public QLineEdit {
    Q_OBJECT

public:
    Settings::NativeInput::Values button;
    QLineEditKeyConfig(Settings::NativeInput::Values button, QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
    bool focusNextPrevChild(bool next) override;
signals:
    void ValueChanged(Settings::NativeInput::Values, int);
};

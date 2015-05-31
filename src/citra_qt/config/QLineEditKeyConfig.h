// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <QLineEdit>
#include <map>
#include "../core/settings.h"

class QKeyEvent;

/// An enum for the buttons on the 3DS
enum Button {
    A, B, X, Y, L, R, ZL, ZR,
    DUp, DDown, DLeft, DRight,
    SUp, SDown, SLeft, SRight,
    CUp, CDown, CLeft, CRight,
    Start, Select, Home
};

/// Map a button to its name
extern std::map<Button, std::string> ButtonNameMap;

/// The LineEdits used for button configuration
class QLineEditKeyConfig : public QLineEdit {
    Q_OBJECT

public:
    Button button;
    QLineEditKeyConfig(Settings::Values& temp_settings, Button button, QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;

private:
    Settings::Values& temp_settings;
};

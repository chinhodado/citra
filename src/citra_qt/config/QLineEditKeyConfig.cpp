// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QKeyEvent>

#include "QLineEditKeyConfig.h"
#include "inputs.h"

std::map<Button, std::string> ButtonNameMap({
    { Button::A, "A" }, { Button::B, "B" }, { Button::X, "X" }, { Button::Y, "Y" },
    { Button::L, "L" }, { Button::R, "R" }, { Button::ZL, "ZL" }, { Button::ZR, "ZR" },
    { Button::DLeft, "D-Left" }, { Button::DRight, "D-Right" }, { Button::DUp, "D-Up" }, { Button::DDown, "D-Down" },
    { Button::SLeft, "S-Left" }, { Button::SRight, "S-Right" }, { Button::SUp, "S-Up" }, { Button::SDown, "S-Down" },
    { Button::CLeft, "C-Left" }, { Button::CRight, "C-Right" }, { Button::CUp, "C-Up" }, { Button::CDown, "C-Down" },
    { Button::Start, "Start" }, { Button::Select, "Select" }, { Button::Home, "Home" } }
);

QLineEditKeyConfig::QLineEditKeyConfig(Button button, QWidget* parent)
    : button(button), QLineEdit(parent) {}

void QLineEditKeyConfig::keyPressEvent(QKeyEvent* event) {
    QString key_name = GInputsDialog::GetKeyName(event->key());
    setText(key_name);

    ValueChanged(button, event->key());
}

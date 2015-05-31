// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "QLineEditKeyConfig.h"
#include "inputs.h"
#include <QKeyEvent>

std::map<Button, std::string> ButtonNameMap({
    { Button::A, "A" }, { Button::B, "B" }, { Button::X, "X" }, { Button::Y, "Y" },
    { Button::L, "L" }, { Button::R, "R" }, { Button::ZL, "ZL" }, { Button::ZR, "ZR" },
    { Button::DLeft, "D-Left" }, { Button::DRight, "D-Right" }, { Button::DUp, "D-Up" }, { Button::DDown, "D-Down" },
    { Button::SLeft, "S-Left" }, { Button::SRight, "S-Right" }, { Button::SUp, "S-Up" }, { Button::SDown, "S-Down" },
    { Button::CLeft, "C-Left" }, { Button::CRight, "C-Right" }, { Button::CUp, "C-Up" }, { Button::CDown, "C-Down" },
    { Button::Start, "Start" }, { Button::Select, "Select" }, { Button::Home, "Home" } }
);

QLineEditKeyConfig::QLineEditKeyConfig(Settings::Values& temp_settings, Button button, QWidget* parent)
    : button(button), temp_settings(temp_settings), QLineEdit(parent) {}

void QLineEditKeyConfig::keyPressEvent(QKeyEvent* event) {
    QString key_name = GInputsDialog::GetKeyName(event->key());
    setText(key_name);

    int key = event->key();
    switch (button) {
    case Button::A:
        temp_settings.pad_a_key = key;
        break;
    case Button::B:
        temp_settings.pad_b_key = key;
        break;
    case Button::X:
        temp_settings.pad_x_key = key;
        break;
    case Button::Y:
        temp_settings.pad_y_key = key;
        break;
    case Button::L:
        temp_settings.pad_l_key = key;
        break;
    case Button::R:
        temp_settings.pad_r_key = key;
        break;
    case Button::ZL:
        temp_settings.pad_zl_key = key;
        break;
    case Button::ZR:
        temp_settings.pad_zr_key = key;
        break;
    case Button::DUp:
        temp_settings.pad_dup_key = key;
        break;
    case Button::DDown:
        temp_settings.pad_ddown_key = key;
        break;
    case Button::DLeft:
        temp_settings.pad_dleft_key = key;
        break;
    case Button::DRight:
        temp_settings.pad_dright_key = key;
        break;
    case Button::SUp:
        temp_settings.pad_sup_key = key;
        break;
    case Button::SDown:
        temp_settings.pad_sdown_key = key;
        break;
    case Button::SLeft:
        temp_settings.pad_sleft_key = key;
        break;
    case Button::SRight:
        temp_settings.pad_sright_key = key;
        break;
    case Button::CUp:
        temp_settings.pad_cup_key = key;
        break;
    case Button::CDown:
        temp_settings.pad_cdown_key = key;
        break;
    case Button::CLeft:
        temp_settings.pad_cleft_key = key;
        break;
    case Button::CRight:
        temp_settings.pad_cright_key = key;
        break;
    case Button::Home:
        temp_settings.pad_home_key = key;
        break;
    case Button::Start:
        temp_settings.pad_start_key = key;
        break;
    case Button::Select:
        temp_settings.pad_select_key = key;
        break;
    default:
        break;
    }
}

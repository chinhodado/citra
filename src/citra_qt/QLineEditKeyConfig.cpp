// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QLineEditKeyConfig.h>
#include <inputs.h>
#include <QKeyEvent>
#include <QLineEdit>

QLineEditKeyConfig::QLineEditKeyConfig(QWidget* parent) : QLineEdit(parent) {}

void QLineEditKeyConfig::keyPressEvent(QKeyEvent* event) {
    QString key_name = GInputsDialog::getKeyName(event->key());
    this->setText(key_name);

    int key = event->key();
    switch (this->button) {
    case Button::A:
        GInputsDialog::temp_settings.pad_a_key = key;
        break;
    case Button::B:
        GInputsDialog::temp_settings.pad_b_key = key;
        break;
    case Button::X:
        GInputsDialog::temp_settings.pad_x_key = key;
        break;
    case Button::Y:
        GInputsDialog::temp_settings.pad_y_key = key;
        break;
    case Button::L:
        GInputsDialog::temp_settings.pad_l_key = key;
        break;
    case Button::R:
        GInputsDialog::temp_settings.pad_r_key = key;
        break;
    case Button::Start:
        GInputsDialog::temp_settings.pad_start_key = key;
        break;
    case Button::Select:
        GInputsDialog::temp_settings.pad_select_key = key;
        break;
    case Button::Home:
        GInputsDialog::temp_settings.pad_home_key = key;
        break;
    case Button::DUp:
        GInputsDialog::temp_settings.pad_dup_key = key;
        break;
    case Button::DDown:
        GInputsDialog::temp_settings.pad_ddown_key = key;
        break;
    case Button::DLeft:
        GInputsDialog::temp_settings.pad_dleft_key = key;
        break;
    case Button::DRight:
        GInputsDialog::temp_settings.pad_dright_key = key;
        break;
    case Button::SUp:
        GInputsDialog::temp_settings.pad_sup_key = key;
        break;
    case Button::SDown:
        GInputsDialog::temp_settings.pad_sdown_key = key;
        break;
    case Button::SLeft:
        GInputsDialog::temp_settings.pad_sleft_key = key;
        break;
    case Button::SRight:
        GInputsDialog::temp_settings.pad_sright_key = key;
        break;
    default:
        break;
    }
}
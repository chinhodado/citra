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

    GInputsDialog* parent_dialog = static_cast<GInputsDialog*>(this->parent()->parent());
    Settings::Values& temp_settings = parent_dialog->temp_settings;

    int key = event->key();
    switch (this->button) {
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
    case Button::Start:
        temp_settings.pad_start_key = key;
        break;
    case Button::Select:
        temp_settings.pad_select_key = key;
        break;
    case Button::Home:
        temp_settings.pad_home_key = key;
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
    default:
        break;
    }
}
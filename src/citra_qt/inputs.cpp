// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QKeySequence>
#include <QSettings>
#include "core/settings.h"
#include "inputs.h"
#include "KeyPressEater.h"
#include <map>

GInputsDialog::GInputsDialog(QWidget* parent) : QDialog(parent)
{
    ui.setupUi(this);
    KeyPressEater *keyPressEater = new KeyPressEater(this);

    // display current key settings
    this->ui.lineEdit_A->setText(QKeySequence(Settings::values.pad_a_key).toString());
    this->ui.lineEdit_B->setText(QKeySequence(Settings::values.pad_b_key).toString());
    this->ui.lineEdit_X->setText(QKeySequence(Settings::values.pad_x_key).toString());
    this->ui.lineEdit_Y->setText(QKeySequence(Settings::values.pad_y_key).toString());
    this->ui.lineEdit_L->setText(QKeySequence(Settings::values.pad_l_key).toString());
    this->ui.lineEdit_R->setText(QKeySequence(Settings::values.pad_r_key).toString());
    this->ui.lineEdit_Start->setText(QKeySequence(Settings::values.pad_start_key).toString());
    this->ui.lineEdit_Select->setText(QKeySequence(Settings::values.pad_select_key).toString());
    this->ui.lineEdit_dUp->setText(QKeySequence(Settings::values.pad_dup_key).toString());
    this->ui.lineEdit_dDown->setText(QKeySequence(Settings::values.pad_ddown_key).toString());
    this->ui.lineEdit_dLeft->setText(QKeySequence(Settings::values.pad_dleft_key).toString());
    this->ui.lineEdit_dRight->setText(QKeySequence(Settings::values.pad_dright_key).toString());
    this->ui.lineEdit_sUp->setText(QKeySequence(Settings::values.pad_sup_key).toString());
    this->ui.lineEdit_sDown->setText(QKeySequence(Settings::values.pad_sdown_key).toString());
    this->ui.lineEdit_sLeft->setText(QKeySequence(Settings::values.pad_sleft_key).toString());
    this->ui.lineEdit_sRight->setText(QKeySequence(Settings::values.pad_sright_key).toString());
    this->ui.lineEdit_Home->setText(QKeySequence(Settings::values.pad_home_key).toString());

    // setup event filters for the LineEdits
    this->ui.lineEdit_A->installEventFilter(keyPressEater);
    this->ui.lineEdit_B->installEventFilter(keyPressEater);
    this->ui.lineEdit_X->installEventFilter(keyPressEater);
    this->ui.lineEdit_Y->installEventFilter(keyPressEater);
    this->ui.lineEdit_L->installEventFilter(keyPressEater);
    this->ui.lineEdit_R->installEventFilter(keyPressEater);
    this->ui.lineEdit_Start->installEventFilter(keyPressEater);
    this->ui.lineEdit_Select->installEventFilter(keyPressEater);
    this->ui.lineEdit_dUp->installEventFilter(keyPressEater);
    this->ui.lineEdit_dDown->installEventFilter(keyPressEater);
    this->ui.lineEdit_dLeft->installEventFilter(keyPressEater);
    this->ui.lineEdit_dRight->installEventFilter(keyPressEater);
    this->ui.lineEdit_sUp->installEventFilter(keyPressEater);
    this->ui.lineEdit_sDown->installEventFilter(keyPressEater);
    this->ui.lineEdit_sLeft->installEventFilter(keyPressEater);
    this->ui.lineEdit_sRight->installEventFilter(keyPressEater);
    this->ui.lineEdit_Home->installEventFilter(keyPressEater);
}

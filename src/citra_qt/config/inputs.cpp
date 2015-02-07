// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/logging/log.h"

#include <QKeySequence>
#include <QSettings>
#include <QPushButton>

#include "config.h"
#include "inputs.h"
#include "QLineEditKeyConfig.h"

GInputsDialog::GInputsDialog(QWidget* parent) : QDialog(parent) {
    ui.setupUi(this);

    // setup the LineEdits
    this->ui.lineEdit_A->button = Button::A;
    this->ui.lineEdit_B->button = Button::B;
    this->ui.lineEdit_X->button = Button::X;
    this->ui.lineEdit_Y->button = Button::Y;
    this->ui.lineEdit_L->button = Button::L;
    this->ui.lineEdit_R->button = Button::R;
    this->ui.lineEdit_Start->button = Button::Start;
    this->ui.lineEdit_Select->button = Button::Select;
    this->ui.lineEdit_Home->button = Button::Home;
    this->ui.lineEdit_dUp->button = Button::DUp;
    this->ui.lineEdit_dDown->button = Button::DDown;
    this->ui.lineEdit_dLeft->button = Button::DLeft;
    this->ui.lineEdit_dRight->button = Button::DRight;
    this->ui.lineEdit_sUp->button = Button::SUp;
    this->ui.lineEdit_sDown->button = Button::SDown;
    this->ui.lineEdit_sLeft->button = Button::SLeft;
    this->ui.lineEdit_sRight->button = Button::SRight;

    // set up event handlers for the buttons
    QPushButton* defaultButton = this->ui.buttonBox->button(QDialogButtonBox::RestoreDefaults);
    connect(defaultButton, SIGNAL(clicked()), this, SLOT(RestoreDefaultSettings()));

    QPushButton* okButton = this->ui.buttonBox->button(QDialogButtonBox::Ok);
    connect(okButton, SIGNAL(clicked()), this, SLOT(SaveSettings()));

    // create a copy of the current settings
    this->temp_settings = Settings::Values(Settings::values);

    // display current key settings
    this->displayButtonSettings(Settings::values);
}

void GInputsDialog::displayButtonSettings(const Settings::Values& values) {
    this->ui.lineEdit_A->setText(GInputsDialog::getKeyName(values.pad_a_key));
    this->ui.lineEdit_B->setText(GInputsDialog::getKeyName(values.pad_b_key));
    this->ui.lineEdit_X->setText(GInputsDialog::getKeyName(values.pad_x_key));
    this->ui.lineEdit_Y->setText(GInputsDialog::getKeyName(values.pad_y_key));
    this->ui.lineEdit_L->setText(GInputsDialog::getKeyName(values.pad_l_key));
    this->ui.lineEdit_R->setText(GInputsDialog::getKeyName(values.pad_r_key));
    this->ui.lineEdit_Start->setText(GInputsDialog::getKeyName(values.pad_start_key));
    this->ui.lineEdit_Select->setText(GInputsDialog::getKeyName(values.pad_select_key));
    this->ui.lineEdit_Home->setText(GInputsDialog::getKeyName(values.pad_home_key));
    this->ui.lineEdit_dUp->setText(GInputsDialog::getKeyName(values.pad_dup_key));
    this->ui.lineEdit_dDown->setText(GInputsDialog::getKeyName(values.pad_ddown_key));
    this->ui.lineEdit_dLeft->setText(GInputsDialog::getKeyName(values.pad_dleft_key));
    this->ui.lineEdit_dRight->setText(GInputsDialog::getKeyName(values.pad_dright_key));
    this->ui.lineEdit_sUp->setText(GInputsDialog::getKeyName(values.pad_sup_key));
    this->ui.lineEdit_sDown->setText(GInputsDialog::getKeyName(values.pad_sdown_key));
    this->ui.lineEdit_sLeft->setText(GInputsDialog::getKeyName(values.pad_sleft_key));
    this->ui.lineEdit_sRight->setText(GInputsDialog::getKeyName(values.pad_sright_key));
}

QString GInputsDialog::getKeyName(int key_code) {
    if (key_code == Qt::Key_Shift)
        return tr("Shift");

    if (key_code == Qt::Key_Control)
        return tr("Ctrl");

    if (key_code == Qt::Key_Alt)
        return tr("Alt");

    if (key_code == Qt::Key_Meta)
        return tr("Meta");

    return QKeySequence(key_code).toString();
}

void GInputsDialog::RestoreDefaultSettings() {
    // load the default button settings into temp_settings
    this->temp_settings.pad_a_key      = Qt::Key_A;
    this->temp_settings.pad_b_key      = Qt::Key_S;
    this->temp_settings.pad_x_key      = Qt::Key_Z;
    this->temp_settings.pad_y_key      = Qt::Key_X;
    this->temp_settings.pad_l_key      = Qt::Key_Q;
    this->temp_settings.pad_r_key      = Qt::Key_W;
    this->temp_settings.pad_start_key  = Qt::Key_M;
    this->temp_settings.pad_select_key = Qt::Key_N;
    this->temp_settings.pad_home_key   = Qt::Key_B;
    this->temp_settings.pad_dup_key    = Qt::Key_T;
    this->temp_settings.pad_ddown_key  = Qt::Key_G;
    this->temp_settings.pad_dleft_key  = Qt::Key_F;
    this->temp_settings.pad_dright_key = Qt::Key_H;
    this->temp_settings.pad_sup_key    = Qt::Key_Up;
    this->temp_settings.pad_sdown_key  = Qt::Key_Down;
    this->temp_settings.pad_sleft_key  = Qt::Key_Left;
    this->temp_settings.pad_sright_key = Qt::Key_Right;

    // then display it
    this->displayButtonSettings(GInputsDialog::temp_settings);
}

void GInputsDialog::SaveSettings() {
    Config config;

    // load the temporary settings into our real settings
    Settings::values.pad_a_key      = this->temp_settings.pad_a_key;
    Settings::values.pad_b_key      = this->temp_settings.pad_b_key;
    Settings::values.pad_x_key      = this->temp_settings.pad_x_key;
    Settings::values.pad_y_key      = this->temp_settings.pad_y_key;
    Settings::values.pad_l_key      = this->temp_settings.pad_l_key;
    Settings::values.pad_r_key      = this->temp_settings.pad_r_key;
    Settings::values.pad_start_key  = this->temp_settings.pad_start_key;
    Settings::values.pad_select_key = this->temp_settings.pad_select_key;
    Settings::values.pad_home_key   = this->temp_settings.pad_home_key;
    Settings::values.pad_dup_key    = this->temp_settings.pad_dup_key;
    Settings::values.pad_ddown_key  = this->temp_settings.pad_ddown_key;
    Settings::values.pad_dleft_key  = this->temp_settings.pad_dleft_key;
    Settings::values.pad_dright_key = this->temp_settings.pad_dright_key;
    Settings::values.pad_sup_key    = this->temp_settings.pad_sup_key;
    Settings::values.pad_sdown_key  = this->temp_settings.pad_sdown_key;
    Settings::values.pad_sleft_key  = this->temp_settings.pad_sleft_key;
    Settings::values.pad_sright_key = this->temp_settings.pad_sright_key;

    // then save it
    config.Save();
    LOG_INFO(Config, "Input settings changed.");
}

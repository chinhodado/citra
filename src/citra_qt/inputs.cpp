// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QKeySequence>
#include <QSettings>
#include <QtWidgets>
#include "inputs.h"
#include "KeyPressEater.h"
#include "config.h"
#include "common/log.h"

std::map<QString, Button> GInputsDialog::edit_input_map;
bool GInputsDialog::edit_input_map_initialized = false;
Settings::Values GInputsDialog::temp_settings;

GInputsDialog::GInputsDialog(QWidget* parent) : QDialog(parent) {
    ui.setupUi(this);

    // initialize the edit_input_map
    if (!edit_input_map_initialized) {
        GInputsDialog::edit_input_map = std::map<QString, Button> {
            { this->ui.lineEdit_A->objectName(), Button::A},
            { this->ui.lineEdit_B->objectName(), Button::B },
            { this->ui.lineEdit_X->objectName(), Button::X },
            { this->ui.lineEdit_Y->objectName(), Button::Y },
            { this->ui.lineEdit_L->objectName(), Button::L },
            { this->ui.lineEdit_R->objectName(), Button::R },
            { this->ui.lineEdit_Start->objectName(), Button::Start },
            { this->ui.lineEdit_Select->objectName(), Button::Select },
            { this->ui.lineEdit_Home->objectName(), Button::Home },
            { this->ui.lineEdit_dUp->objectName(), Button::DUp },
            { this->ui.lineEdit_dDown->objectName(), Button::DDown },
            { this->ui.lineEdit_dLeft->objectName(), Button::DLeft },
            { this->ui.lineEdit_dRight->objectName(), Button::DRight },
            { this->ui.lineEdit_sUp->objectName(), Button::SUp },
            { this->ui.lineEdit_sDown->objectName(), Button::SDown },
            { this->ui.lineEdit_sLeft->objectName(), Button::SLeft },
            { this->ui.lineEdit_sRight->objectName(), Button::SRight },
        };
        edit_input_map_initialized = true;
    }

    // set up event handlers for the buttons
    QPushButton *resetButton = this->ui.buttonBox->button(QDialogButtonBox::Reset);
    connect(resetButton, SIGNAL(clicked()), this, SLOT(OnResetClicked()));

    QPushButton *okButton = this->ui.buttonBox->button(QDialogButtonBox::Ok);
    connect(okButton, SIGNAL(clicked()), this, SLOT(OnOkClicked()));

    // create a copy of the current settings
    GInputsDialog::temp_settings = Settings::Values(Settings::values);

    // display current key settings
    this->displayButtonSettings(Settings::values);

    // setup event filters for the LineEdits
    KeyPressEater* keyPressEater = new KeyPressEater(this);
    this->ui.lineEdit_A->installEventFilter(keyPressEater);
    this->ui.lineEdit_B->installEventFilter(keyPressEater);
    this->ui.lineEdit_X->installEventFilter(keyPressEater);
    this->ui.lineEdit_Y->installEventFilter(keyPressEater);
    this->ui.lineEdit_L->installEventFilter(keyPressEater);
    this->ui.lineEdit_R->installEventFilter(keyPressEater);
    this->ui.lineEdit_Start->installEventFilter(keyPressEater);
    this->ui.lineEdit_Select->installEventFilter(keyPressEater);
    this->ui.lineEdit_Home->installEventFilter(keyPressEater);
    this->ui.lineEdit_dUp->installEventFilter(keyPressEater);
    this->ui.lineEdit_dDown->installEventFilter(keyPressEater);
    this->ui.lineEdit_dLeft->installEventFilter(keyPressEater);
    this->ui.lineEdit_dRight->installEventFilter(keyPressEater);
    this->ui.lineEdit_sUp->installEventFilter(keyPressEater);
    this->ui.lineEdit_sDown->installEventFilter(keyPressEater);
    this->ui.lineEdit_sLeft->installEventFilter(keyPressEater);
    this->ui.lineEdit_sRight->installEventFilter(keyPressEater);
}

void GInputsDialog::displayButtonSettings(Settings::Values values) {
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
    if (key_code == Qt::Key_Shift) { return tr("Shift"); }
    else if (key_code == Qt::Key_Control) { return tr("Ctrl"); }
    else if (key_code == Qt::Key_Alt) { return tr("Alt"); }
    else if (key_code == Qt::Key_Meta) { return tr("Meta"); }
    else return QKeySequence(key_code).toString();
}

void GInputsDialog::OnResetClicked() {
    // load the default button settings into temp_settings
    GInputsDialog::temp_settings.pad_a_key      = Qt::Key_A;
    GInputsDialog::temp_settings.pad_b_key      = Qt::Key_S;
    GInputsDialog::temp_settings.pad_x_key      = Qt::Key_Z;
    GInputsDialog::temp_settings.pad_y_key      = Qt::Key_X;
    GInputsDialog::temp_settings.pad_l_key      = Qt::Key_Q;
    GInputsDialog::temp_settings.pad_r_key      = Qt::Key_W;
    GInputsDialog::temp_settings.pad_start_key  = Qt::Key_M;
    GInputsDialog::temp_settings.pad_select_key = Qt::Key_N;
    GInputsDialog::temp_settings.pad_home_key   = Qt::Key_B;
    GInputsDialog::temp_settings.pad_dup_key    = Qt::Key_T;
    GInputsDialog::temp_settings.pad_ddown_key  = Qt::Key_G;
    GInputsDialog::temp_settings.pad_dleft_key  = Qt::Key_F;
    GInputsDialog::temp_settings.pad_dright_key = Qt::Key_H;
    GInputsDialog::temp_settings.pad_sup_key    = Qt::Key_Up;
    GInputsDialog::temp_settings.pad_sdown_key  = Qt::Key_Down;
    GInputsDialog::temp_settings.pad_sleft_key  = Qt::Key_Left;
    GInputsDialog::temp_settings.pad_sright_key = Qt::Key_Right;

    // then display it
    this->displayButtonSettings(GInputsDialog::temp_settings);
}

void GInputsDialog::OnOkClicked() {
    Config config;

    // load the temporary settings into our real settings
    Settings::values.pad_a_key      = GInputsDialog::temp_settings.pad_a_key;
    Settings::values.pad_b_key      = GInputsDialog::temp_settings.pad_b_key;
    Settings::values.pad_x_key      = GInputsDialog::temp_settings.pad_x_key;
    Settings::values.pad_y_key      = GInputsDialog::temp_settings.pad_y_key;
    Settings::values.pad_l_key      = GInputsDialog::temp_settings.pad_l_key;
    Settings::values.pad_r_key      = GInputsDialog::temp_settings.pad_r_key;
    Settings::values.pad_start_key  = GInputsDialog::temp_settings.pad_start_key;
    Settings::values.pad_select_key = GInputsDialog::temp_settings.pad_select_key;
    Settings::values.pad_home_key   = GInputsDialog::temp_settings.pad_home_key;
    Settings::values.pad_dup_key    = GInputsDialog::temp_settings.pad_dup_key;
    Settings::values.pad_ddown_key  = GInputsDialog::temp_settings.pad_ddown_key;
    Settings::values.pad_dleft_key  = GInputsDialog::temp_settings.pad_dleft_key;
    Settings::values.pad_dright_key = GInputsDialog::temp_settings.pad_dright_key;
    Settings::values.pad_sup_key    = GInputsDialog::temp_settings.pad_sup_key;
    Settings::values.pad_sdown_key  = GInputsDialog::temp_settings.pad_sdown_key;
    Settings::values.pad_sleft_key  = GInputsDialog::temp_settings.pad_sleft_key;
    Settings::values.pad_sright_key = GInputsDialog::temp_settings.pad_sright_key;

    // then save it
    config.Save();
    LOG_INFO(Config, "Input settings changed.");
}

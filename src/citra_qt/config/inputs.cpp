// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/logging/log.h"

#include <QKeySequence>
#include <QSettings>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QDialogButtonBox>

#include "config.h"
#include "inputs.h"

GInputsDialog::GInputsDialog(QWidget* parent) : QDialog(parent) {
    // create a copy of the current settings
    temp_settings = Settings::Values(Settings::values);

    // create the lineEdits
    lineEdit_A = new QLineEditKeyConfig(temp_settings, Button::A);
    lineEdit_B = new QLineEditKeyConfig(temp_settings, Button::B);
    lineEdit_X = new QLineEditKeyConfig(temp_settings, Button::X);
    lineEdit_Y = new QLineEditKeyConfig(temp_settings, Button::Y);
    lineEdit_L = new QLineEditKeyConfig(temp_settings, Button::L);
    lineEdit_R = new QLineEditKeyConfig(temp_settings, Button::R);
    lineEdit_ZL = new QLineEditKeyConfig(temp_settings, Button::ZL);
    lineEdit_ZR = new QLineEditKeyConfig(temp_settings, Button::ZR);
    lineEdit_dUp = new QLineEditKeyConfig(temp_settings, Button::DUp);
    lineEdit_dDown = new QLineEditKeyConfig(temp_settings, Button::DDown);
    lineEdit_dLeft = new QLineEditKeyConfig(temp_settings, Button::DLeft);
    lineEdit_dRight = new QLineEditKeyConfig(temp_settings, Button::DRight);
    lineEdit_sUp = new QLineEditKeyConfig(temp_settings, Button::SUp);
    lineEdit_sDown = new QLineEditKeyConfig(temp_settings, Button::SDown);
    lineEdit_sLeft = new QLineEditKeyConfig(temp_settings, Button::SLeft);
    lineEdit_sRight = new QLineEditKeyConfig(temp_settings, Button::SRight);
    lineEdit_cUp = new QLineEditKeyConfig(temp_settings, Button::CUp);
    lineEdit_cDown = new QLineEditKeyConfig(temp_settings, Button::CDown);
    lineEdit_cLeft = new QLineEditKeyConfig(temp_settings, Button::CLeft);
    lineEdit_cRight = new QLineEditKeyConfig(temp_settings, Button::CRight);
    lineEdit_Home = new QLineEditKeyConfig(temp_settings, Button::Home);
    lineEdit_Start = new QLineEditKeyConfig(temp_settings, Button::Start);
    lineEdit_Select = new QLineEditKeyConfig(temp_settings, Button::Select);

    lineEdits = {{
        lineEdit_A, lineEdit_B, lineEdit_X, lineEdit_Y, lineEdit_L, lineEdit_R, lineEdit_ZL, lineEdit_ZR,
        lineEdit_dUp, lineEdit_dDown, lineEdit_dLeft, lineEdit_dRight,
        lineEdit_sUp, lineEdit_sDown, lineEdit_sLeft, lineEdit_sRight,
        lineEdit_cUp, lineEdit_cDown, lineEdit_cLeft, lineEdit_cRight,
        lineEdit_Home, lineEdit_Start, lineEdit_Select
    }};

    // put the lineEdits and their labels into a grid
    QGridLayout *grid = new QGridLayout();
    size_t size = lineEdits.size();
    for (size_t i = 0; i < size; i++) {
        const int numRow = 8;
        int row = i % numRow;
        int labelColumn = i / numRow * 2;
        QLineEditKeyConfig *lineEdit = lineEdits[i];
        QLabel *label = new QLabel(QString::fromStdString(ButtonNameMap[lineEdit->button]));
        grid->addWidget(label, row, labelColumn);
        grid->addWidget(lineEdit, row, labelColumn + 1);
    }

    // the button box that contains the restore default/ok/cancel buttons
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    QDialogButtonBox *buttonBox = new QDialogButtonBox(this);
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok | QDialogButtonBox::RestoreDefaults);

    verticalLayout->addLayout(grid);
    verticalLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    setLayout(verticalLayout);
    setWindowTitle(tr("Input Settings"));
    resize(165, height());

    // set up event handlers for the buttons
    QPushButton* defaultButton = buttonBox->button(QDialogButtonBox::RestoreDefaults);
    connect(defaultButton, SIGNAL(clicked()), this, SLOT(RestoreDefaultSettings()));

    QPushButton* okButton = buttonBox->button(QDialogButtonBox::Ok);
    connect(okButton, SIGNAL(clicked()), this, SLOT(SaveSettings()));

    // display current key settings
    UpdateKeyLabels();
}

void GInputsDialog::UpdateKeyLabels() {
    lineEdit_A->setText(GetKeyName(temp_settings.pad_a_key));
    lineEdit_B->setText(GetKeyName(temp_settings.pad_b_key));
    lineEdit_X->setText(GetKeyName(temp_settings.pad_x_key));
    lineEdit_Y->setText(GetKeyName(temp_settings.pad_y_key));
    lineEdit_L->setText(GetKeyName(temp_settings.pad_l_key));
    lineEdit_R->setText(GetKeyName(temp_settings.pad_r_key));
    lineEdit_ZL->setText(GetKeyName(temp_settings.pad_zl_key));
    lineEdit_ZR->setText(GetKeyName(temp_settings.pad_zr_key));
    lineEdit_dUp->setText(GetKeyName(temp_settings.pad_dup_key));
    lineEdit_dDown->setText(GetKeyName(temp_settings.pad_ddown_key));
    lineEdit_dLeft->setText(GetKeyName(temp_settings.pad_dleft_key));
    lineEdit_dRight->setText(GetKeyName(temp_settings.pad_dright_key));
    lineEdit_sUp->setText(GetKeyName(temp_settings.pad_sup_key));
    lineEdit_sDown->setText(GetKeyName(temp_settings.pad_sdown_key));
    lineEdit_sLeft->setText(GetKeyName(temp_settings.pad_sleft_key));
    lineEdit_sRight->setText(GetKeyName(temp_settings.pad_sright_key));
    lineEdit_cUp->setText(GetKeyName(temp_settings.pad_cup_key));
    lineEdit_cDown->setText(GetKeyName(temp_settings.pad_cdown_key));
    lineEdit_cLeft->setText(GetKeyName(temp_settings.pad_cleft_key));
    lineEdit_cRight->setText(GetKeyName(temp_settings.pad_cright_key));
    lineEdit_Home->setText(GetKeyName(temp_settings.pad_home_key));
    lineEdit_Start->setText(GetKeyName(temp_settings.pad_start_key));
    lineEdit_Select->setText(GetKeyName(temp_settings.pad_select_key));
}

QString GInputsDialog::GetKeyName(int key_code) {
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
    temp_settings.pad_a_key      = Qt::Key_A;
    temp_settings.pad_b_key      = Qt::Key_S;
    temp_settings.pad_x_key      = Qt::Key_Z;
    temp_settings.pad_y_key      = Qt::Key_X;
    temp_settings.pad_l_key      = Qt::Key_Q;
    temp_settings.pad_r_key      = Qt::Key_W;
    temp_settings.pad_zl_key     = Qt::Key_1;
    temp_settings.pad_zr_key     = Qt::Key_2;

    temp_settings.pad_dup_key    = Qt::Key_T;
    temp_settings.pad_ddown_key  = Qt::Key_G;
    temp_settings.pad_dleft_key  = Qt::Key_F;
    temp_settings.pad_dright_key = Qt::Key_H;
    temp_settings.pad_sup_key    = Qt::Key_Up;
    temp_settings.pad_sdown_key  = Qt::Key_Down;
    temp_settings.pad_sleft_key  = Qt::Key_Left;
    temp_settings.pad_sright_key = Qt::Key_Right;
    temp_settings.pad_cup_key    = Qt::Key_I;
    temp_settings.pad_cdown_key  = Qt::Key_K;
    temp_settings.pad_cleft_key  = Qt::Key_J;
    temp_settings.pad_cright_key = Qt::Key_L;

    temp_settings.pad_home_key   = Qt::Key_B;
    temp_settings.pad_start_key  = Qt::Key_M;
    temp_settings.pad_select_key = Qt::Key_N;

    // then display it
    UpdateKeyLabels();
}

void GInputsDialog::SaveSettings() {
    Config config;

    // load the temporary settings into our real settings
    Settings::values.pad_a_key      = temp_settings.pad_a_key;
    Settings::values.pad_b_key      = temp_settings.pad_b_key;
    Settings::values.pad_x_key      = temp_settings.pad_x_key;
    Settings::values.pad_y_key      = temp_settings.pad_y_key;
    Settings::values.pad_l_key      = temp_settings.pad_l_key;
    Settings::values.pad_r_key      = temp_settings.pad_r_key;
    Settings::values.pad_zl_key     = temp_settings.pad_zl_key;
    Settings::values.pad_zr_key     = temp_settings.pad_zr_key;

    Settings::values.pad_dup_key    = temp_settings.pad_dup_key;
    Settings::values.pad_ddown_key  = temp_settings.pad_ddown_key;
    Settings::values.pad_dleft_key  = temp_settings.pad_dleft_key;
    Settings::values.pad_dright_key = temp_settings.pad_dright_key;
    Settings::values.pad_sup_key    = temp_settings.pad_sup_key;
    Settings::values.pad_sdown_key  = temp_settings.pad_sdown_key;
    Settings::values.pad_sleft_key  = temp_settings.pad_sleft_key;
    Settings::values.pad_sright_key = temp_settings.pad_sright_key;
    Settings::values.pad_cup_key    = temp_settings.pad_cup_key;
    Settings::values.pad_cdown_key  = temp_settings.pad_cdown_key;
    Settings::values.pad_cleft_key  = temp_settings.pad_cleft_key;
    Settings::values.pad_cright_key = temp_settings.pad_cright_key;

    Settings::values.pad_home_key   = temp_settings.pad_home_key;
    Settings::values.pad_start_key  = temp_settings.pad_start_key;
    Settings::values.pad_select_key = temp_settings.pad_select_key;

    // then save it
    config.Save();
}

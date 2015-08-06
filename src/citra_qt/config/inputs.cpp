// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QKeySequence>
#include <QSettings>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QDialogButtonBox>

#include "common/logging/log.h"
#include "config.h"
#include "inputs.h"
#include "QLineEditKeyConfig.h"

GInputsDialog::GInputsDialog(QWidget* parent) : QDialog(parent) {
    // create a copy of the current settings
    temp_settings = Settings::Values(Settings::values);

    // create the lineEdits
    for (int i = 0; i < Settings::NativeInput::NUM_INPUTS; ++i) {
        lineEdits[i] = new QLineEditKeyConfig(Settings::NativeInput::All[i]);
        lineEdits[i]->setFocusPolicy(Qt::ClickFocus);
    }

    // put the lineEdits and their labels into a grid
    QGridLayout* grid = new QGridLayout();
    size_t size = lineEdits.size();
    for (size_t i = 0; i < size; i++) {
        const int NUM_ROW = 8;
        int row = i % NUM_ROW;
        int labelColumn = (int)i / NUM_ROW * 2;
        QLineEditKeyConfig* lineEdit = lineEdits[i];
        QLabel* label = new QLabel(tr(ButtonNameMap[lineEdit->button].c_str()));
        grid->addWidget(label, row, labelColumn);
        grid->addWidget(lineEdit, row, labelColumn + 1);

        connect(lineEdit, SIGNAL(ValueChanged(Settings::NativeInput::Values, int)), this, SLOT(UpdateValue(Settings::NativeInput::Values, int)));
    }

    // the button box that contains the restore default/ok/cancel buttons
    QVBoxLayout* verticalLayout = new QVBoxLayout();
    QDialogButtonBox* buttonBox = new QDialogButtonBox();
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

void GInputsDialog::UpdateValue(Settings::NativeInput::Values button, int key) {
    temp_settings.input_mappings[Settings::NativeInput::All[button]] = key;
}

void GInputsDialog::UpdateKeyLabels() {
    for (int i = 0; i < Settings::NativeInput::NUM_INPUTS; ++i) {
        lineEdits[i]->setText(GetKeyName(temp_settings.input_mappings[Settings::NativeInput::All[i]]));
    }
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
    for (int i = 0; i < Settings::NativeInput::NUM_INPUTS; ++i) {
        temp_settings.input_mappings[Settings::NativeInput::All[i]] = Config::defaults[i].toInt();
    }

    // then display it
    UpdateKeyLabels();
}

void GInputsDialog::SaveSettings() {
    Config config;

    // load the temporary settings into our real settings
    for (int i = 0; i < Settings::NativeInput::NUM_INPUTS; ++i) {
        Settings::values.input_mappings[Settings::NativeInput::All[i]] =
            temp_settings.input_mappings[Settings::NativeInput::All[i]];
    }

    // then save it
    config.Save();
}

// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <QDialog>

#include "../core/settings.h"
#include "ui_inputs.h"

/// The input configuration dialog
class GInputsDialog : public QDialog {
    Q_OBJECT

public:
    GInputsDialog(QWidget* parent = nullptr);

    /// Temporary settings used when configuration is changed but not saved yet
    Settings::Values temp_settings;

    /// Given a key code, return the key name. Needed for modifier keys
    static QString getKeyName(int key_code);

private:
    Ui::inputs ui;

    /// Display the button settings on the LineEdits from the given values
    void displayButtonSettings(const Settings::Values& values);

private slots:
    void OnDefaultClicked();
    void OnOkClicked();
};

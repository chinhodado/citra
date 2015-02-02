// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once
#include <QDialog>
#include <map>
#include "core/settings.h"
#include "ui_inputs.h"

/// An enum for the buttons on the 3DS
enum Button {
    A, B, X, Y, L, R, Start, Select, Home,
    DUp, DDown, DLeft, DRight,
    SUp, SDown, SLeft, SRight
};

/// The input configuration dialog
class GInputsDialog : public QDialog {
    Q_OBJECT

public:
    GInputsDialog(QWidget* parent = NULL);

    /// A map between the name of a LineEdit and the button that it modifies
    static std::map<QString, Button> edit_input_map;

    /// true if edit_input_map is initialized
    static bool edit_input_map_initialized;

    /// Temporary settings used when configuration is changed but not saved yet
    static Settings::Values temp_settings;

    /// Given a key code, return the key name. Needed for modifier keys
    static QString getKeyName(int key_code);

private:
    Ui::inputs ui;

    /// Display the button settings on the LineEdits from the given values
    void displayButtonSettings(Settings::Values values);

private slots:
    void OnResetClicked();
    void OnOkClicked();
};

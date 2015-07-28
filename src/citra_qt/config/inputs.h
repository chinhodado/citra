// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <array>

#include <QDialog>

#include "../core/settings.h"

class QLineEditKeyConfig;

/// The input configuration dialog
class GInputsDialog : public QDialog {
    Q_OBJECT

public:
    GInputsDialog(QWidget* parent = nullptr);

    /// Given a key code, return the key name. In addition to QKeySequence(key_code).toString(); this will translate modifier keys properly.
    static QString GetKeyName(int key_code);

private:
    /// An array of all the lineEdits for easy iterating though them
    std::array<QLineEditKeyConfig*, 23> lineEdits;

    /// Display the button settings on the LineEdits from the given values
    void UpdateKeyLabels();

    /// Temporary settings used when configuration is changed but not saved yet
    Settings::Values temp_settings;

private slots:
    void SaveSettings();
    void RestoreDefaultSettings();
    void UpdateValue(Settings::NativeInput::Values button, int key);
};

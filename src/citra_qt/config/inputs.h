// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <array>

#include <QDialog>

#include "../core/settings.h"
#include "QLineEditKeyConfig.h"

/// The input configuration dialog
class GInputsDialog : public QDialog {
    Q_OBJECT

public:
    GInputsDialog(QWidget* parent = nullptr);

    /// Given a key code, return the key name. In addition to QKeySequence(key_code).toString(); this will translate modifier keys properly.
    static QString GetKeyName(int key_code);

private:
    QLineEditKeyConfig *lineEdit_A;
    QLineEditKeyConfig *lineEdit_B;
    QLineEditKeyConfig *lineEdit_X;
    QLineEditKeyConfig *lineEdit_Y;
    QLineEditKeyConfig *lineEdit_L;
    QLineEditKeyConfig *lineEdit_R;
    QLineEditKeyConfig *lineEdit_ZL;
    QLineEditKeyConfig *lineEdit_ZR;
    QLineEditKeyConfig *lineEdit_dUp;
    QLineEditKeyConfig *lineEdit_dDown;
    QLineEditKeyConfig *lineEdit_dLeft;
    QLineEditKeyConfig *lineEdit_dRight;
    QLineEditKeyConfig *lineEdit_sUp;
    QLineEditKeyConfig *lineEdit_sDown;
    QLineEditKeyConfig *lineEdit_sLeft;
    QLineEditKeyConfig *lineEdit_sRight;
    QLineEditKeyConfig *lineEdit_cUp;
    QLineEditKeyConfig *lineEdit_cDown;
    QLineEditKeyConfig *lineEdit_cLeft;
    QLineEditKeyConfig *lineEdit_cRight;
    QLineEditKeyConfig *lineEdit_Start;
    QLineEditKeyConfig *lineEdit_Select;
    QLineEditKeyConfig *lineEdit_Home;

    /// An array of all the lineEdits above for easy iterating though them
    std::array<QLineEditKeyConfig*, 23> lineEdits;

    /// Display the button settings on the LineEdits from the given values
    void UpdateKeyLabels();

    /// Temporary settings used when configuration is changed but not saved yet
    Settings::Values temp_settings;

private slots:
    void SaveSettings();
    void RestoreDefaultSettings();
};

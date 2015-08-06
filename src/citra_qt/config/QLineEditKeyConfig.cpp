// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QKeyEvent>

#include "QLineEditKeyConfig.h"
#include "inputs.h"

using namespace Settings::NativeInput;

std::map<Values, std::string> ButtonNameMap({
    { A, "A" }, { B, "B" }, { X, "X" }, { Y, "Y" },
    { L, "L" }, { R, "R" }, { ZL, "ZL" }, { ZR, "ZR" },
    { DLEFT, "D-Left" }, { DRIGHT, "D-Right" }, { DUP, "D-Up" }, { DDOWN, "D-Down" },
    { SLEFT, "S-Left" }, { SRIGHT, "S-Right" }, { SUP, "S-Up" }, { SDOWN, "S-Down" },
    { CLEFT, "C-Left" }, { CRIGHT, "C-Right" }, { CUP, "C-Up" }, { CDOWN, "C-Down" },
    { START, "Start" }, { SELECT, "Select" }, { HOME, "Home" } }
);

QLineEditKeyConfig::QLineEditKeyConfig(Values button, QWidget* parent)
    : QLineEdit(parent), button(button) {}

void QLineEditKeyConfig::keyPressEvent(QKeyEvent* event) {
    QString key_name = GInputsDialog::GetKeyName(event->key());
    setText(key_name);

    emit ValueChanged(button, event->key());
}

bool QLineEditKeyConfig::focusNextPrevChild(bool next) {
    return false;
}

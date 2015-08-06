// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QKeyEvent>

#include "QLineEditKeyConfig.h"
#include "inputs.h"

using namespace Settings::NativeInput;

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

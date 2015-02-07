// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <QLineEdit>

class QKeyEvent;

/// An enum for the buttons on the 3DS
enum Button {
    A, B, X, Y, L, R, Start, Select, Home,
    DUp, DDown, DLeft, DRight,
    SUp, SDown, SLeft, SRight
};

/// The LineEdits used for button configuration
class QLineEditKeyConfig : public QLineEdit {
    Q_OBJECT

public:
    Button button;
    QLineEditKeyConfig(QWidget* parent);
    void keyPressEvent(QKeyEvent* event) override;
};

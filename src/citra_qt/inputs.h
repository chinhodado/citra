// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <QDialog>
#include "ui_inputs.h"

class GInputsDialog : public QDialog
{
    Q_OBJECT

public:
    GInputsDialog(QWidget* parent = NULL);

private:
    Ui::inputs ui;
};

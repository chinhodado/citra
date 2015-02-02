#include <KeyPressEater.h>
#include <inputs.h>
#include <QKeyEvent>
#include <QLineEdit>

KeyPressEater::KeyPressEater(QObject* parent) : QObject(parent) {}

bool KeyPressEater::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        auto keyName = QKeySequence(keyEvent->key()).toString();

        QLineEdit* lineEdit = static_cast<QLineEdit*>(obj);
        Button button_modified = GInputsDialog::edit_input_map[lineEdit->objectName()];

        switch (button_modified) {
        case Button::A:
            GInputsDialog::temp_settings.pad_a_key = keyEvent->key();
            break;
        case Button::B:
            GInputsDialog::temp_settings.pad_b_key = keyEvent->key();
            break;
        case Button::X:
            GInputsDialog::temp_settings.pad_x_key = keyEvent->key();
            break;
        case Button::Y:
            GInputsDialog::temp_settings.pad_y_key = keyEvent->key();
            break;
        case Button::L:
            GInputsDialog::temp_settings.pad_l_key = keyEvent->key();
            break;
        case Button::R:
            GInputsDialog::temp_settings.pad_r_key = keyEvent->key();
            break;
        case Button::Start:
            GInputsDialog::temp_settings.pad_start_key = keyEvent->key();
            break;
        case Button::Select:
            GInputsDialog::temp_settings.pad_select_key = keyEvent->key();
            break;
        case Button::Home:
            GInputsDialog::temp_settings.pad_home_key = keyEvent->key();
            break;
        case Button::DUp:
            GInputsDialog::temp_settings.pad_dup_key = keyEvent->key();
            break;
        case Button::DDown:
            GInputsDialog::temp_settings.pad_ddown_key = keyEvent->key();
            break;
        case Button::DLeft:
            GInputsDialog::temp_settings.pad_dleft_key = keyEvent->key();
            break;
        case Button::DRight:
            GInputsDialog::temp_settings.pad_dright_key = keyEvent->key();
            break;
        case Button::SUp:
            GInputsDialog::temp_settings.pad_sup_key = keyEvent->key();
            break;
        case Button::SDown:
            GInputsDialog::temp_settings.pad_sdown_key = keyEvent->key();
            break;
        case Button::SLeft:
            GInputsDialog::temp_settings.pad_sleft_key = keyEvent->key();
            break;
        case Button::SRight:
            GInputsDialog::temp_settings.pad_sright_key = keyEvent->key();
            break;
        default:
            break;
        }

        lineEdit->setText(keyName);
        return true;
    }
    else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
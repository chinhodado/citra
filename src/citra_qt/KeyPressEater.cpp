#include <KeyPressEater.h>
#include <inputs.h>
#include <QKeyEvent>
#include <QLineEdit>

KeyPressEater::KeyPressEater(QObject* parent) : QObject(parent) {}

bool KeyPressEater::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* key_event = static_cast<QKeyEvent*>(event);
        QLineEdit* line_edit = static_cast<QLineEdit*>(obj);
        Button button_modified = GInputsDialog::edit_input_map[line_edit->objectName()];

        QString key_name = GInputsDialog::getKeyName(key_event->key());
        line_edit->setText(key_name);

        int key = key_event->key();
        switch (button_modified) {
        case Button::A:
            GInputsDialog::temp_settings.pad_a_key = key;
            break;
        case Button::B:
            GInputsDialog::temp_settings.pad_b_key = key;
            break;
        case Button::X:
            GInputsDialog::temp_settings.pad_x_key = key;
            break;
        case Button::Y:
            GInputsDialog::temp_settings.pad_y_key = key;
            break;
        case Button::L:
            GInputsDialog::temp_settings.pad_l_key = key;
            break;
        case Button::R:
            GInputsDialog::temp_settings.pad_r_key = key;
            break;
        case Button::Start:
            GInputsDialog::temp_settings.pad_start_key = key;
            break;
        case Button::Select:
            GInputsDialog::temp_settings.pad_select_key = key;
            break;
        case Button::Home:
            GInputsDialog::temp_settings.pad_home_key = key;
            break;
        case Button::DUp:
            GInputsDialog::temp_settings.pad_dup_key = key;
            break;
        case Button::DDown:
            GInputsDialog::temp_settings.pad_ddown_key = key;
            break;
        case Button::DLeft:
            GInputsDialog::temp_settings.pad_dleft_key = key;
            break;
        case Button::DRight:
            GInputsDialog::temp_settings.pad_dright_key = key;
            break;
        case Button::SUp:
            GInputsDialog::temp_settings.pad_sup_key = key;
            break;
        case Button::SDown:
            GInputsDialog::temp_settings.pad_sdown_key = key;
            break;
        case Button::SLeft:
            GInputsDialog::temp_settings.pad_sleft_key = key;
            break;
        case Button::SRight:
            GInputsDialog::temp_settings.pad_sright_key = key;
            break;
        default:
            break;
        }

        return true;
    }
    else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
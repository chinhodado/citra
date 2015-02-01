#include <KeyPressEater.h>
#include <QKeyEvent>
#include <QLineEdit>

KeyPressEater::KeyPressEater(QObject* parent) : QObject(parent) {}

bool KeyPressEater::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        auto keyName = QKeySequence(keyEvent->key()).toString();

        QLineEdit* lineEdit = static_cast<QLineEdit*>(obj);
        lineEdit->setText(keyName);
        return true;
    }
    else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
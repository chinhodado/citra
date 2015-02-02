#include <QObject>
#include <QEvent>

/// The event filter used for LineEdits to handle key presses
class KeyPressEater : public QObject {
    Q_OBJECT
public:
    KeyPressEater(QObject* parent);
    bool eventFilter(QObject *obj, QEvent *event);
};
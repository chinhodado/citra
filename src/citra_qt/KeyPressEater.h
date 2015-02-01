#include <QObject>
#include <QEvent>

class KeyPressEater : public QObject
{
    Q_OBJECT
public:
    KeyPressEater(QObject* parent);
    bool eventFilter(QObject *obj, QEvent *event);
};
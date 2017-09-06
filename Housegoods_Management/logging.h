#ifndef LOGGING_H
#define LOGGING_H

#include <QFrame>

namespace Ui {
class Logging;
}

class Logging : public QFrame
{
    Q_OBJECT

public:
    explicit Logging(QWidget *parent = 0);
    ~Logging();

private:
    Ui::Logging *ui;
};

#endif // LOGGING_H

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <QGraphicsSimpleTextItem>
#include <QObject>

class TextBox : public QObject, public QGraphicsSimpleTextItem{
    Q_OBJECT
public:
    TextBox(qreal x, qreal y);
    void setTitle(QString title);
    void setDigit(int digit);
private:
    QString Title, Digit;
    qreal x, y;
private slots:
    void update();
};

#endif // TEXTBOX_H

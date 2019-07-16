#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_encode_button_clicked();

    void on_decode_button_clicked();

    void on_file_encode_button_clicked();

    void on_to_file_button_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

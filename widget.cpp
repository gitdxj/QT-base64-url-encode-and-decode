#include "widget.h"
#include "ui_widget.h"
#include "base64.h"
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QFileDialog>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_encode_button_clicked()
{
    QString q_str = this->ui->raw_text->toPlainText();
    std::string std_str = q_str.toStdString();
    std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(std_str.c_str()), std_str.length());

    QString encoded_q_str = QString::fromStdString(encoded);
    this->ui->base64_text->clear();
    this->ui->base64_text->setPlainText(encoded_q_str);

    std::string url_encoded = URLEncode(std_str);
    this->ui->url_text->clear();
    this->ui->url_text->setPlainText(QString::fromStdString(url_encoded));

}


void Widget::on_decode_button_clicked()
{
    QString q_str = this->ui->raw_text->toPlainText();
    std::string std_str = q_str.toStdString();
    std::string decoded_std_str = base64_decode(std_str);
    QString decoded_q_str = QString::fromStdString(decoded_std_str);
    this->ui->base64_text->clear();
    this->ui->base64_text->setPlainText(decoded_q_str);

    std::string url_encoded = URLDecode(std_str);
    this->ui->url_text->clear();
    this->ui->url_text->setPlainText(QString::fromStdString(url_encoded));
}

void Widget::on_file_encode_button_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "请选择文件", "C:/");
    if(filename.isEmpty())
        return;
    string std_filename = filename.toStdString();

    // 从文件中读取全部内容到string
    ifstream reader;
    reader.open(std_filename, ios::in | ios::binary);
    std::stringstream buffer;
    buffer << reader.rdbuf();
    std::string std_text(buffer.str());
    string std_encoded = base64_encode(reinterpret_cast<const unsigned char*>(std_text.c_str()), std_text.length());

    this->ui->base64_text->setPlainText(QString::fromStdString(std_encoded));

}

void Widget::on_to_file_button_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "创建文件");
    if(filename.isEmpty())
        return;
    QString q_textContent = ui->base64_text->toPlainText();
    string std_textContent = q_textContent.toStdString();
    string decoded = base64_decode(std_textContent);
    const char* out = decoded.c_str();
    int length = decoded.size();
    ofstream outFile;
    outFile.open(filename.toStdString(), ios::binary);
    for(int i = 0; i<length; i++)
        outFile << out[i];
    outFile.close();

}

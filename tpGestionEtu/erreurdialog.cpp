#include "erreurdialog.h"

ErreurDialog::ErreurDialog(const QString &message, QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel(message, this);
    QPushButton *ok = new QPushButton("OK", this);
    layout->addWidget(label);
    layout->addWidget(ok);

    connect(ok, &QPushButton::clicked, this, &QDialog::accept);
}

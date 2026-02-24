#ifndef ERREURDIALOG_H
#define ERREURDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class ErreurDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ErreurDialog(const QString &message, QWidget *parent = nullptr);
};

#endif // ERREURDIALOG_H

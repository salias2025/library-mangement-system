#include "add_newspaper.h"
#include "ui_add_newspaper.h"
#include <QMessageBox>
#include "user.h"
#include "ubook.h"
#include "database.h"
#include "table_newspaper.h"
add_newspaper::add_newspaper(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_newspaper)
{
    ui->setupUi(this);
    ui->submit->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
    connect(ui->MyTextEdit, &QPlainTextEdit::textChanged, this, &add_newspaper::limitTextSize);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(100);
}

add_newspaper::~add_newspaper()
{
    delete ui;
}
void add_newspaper::limitTextSize() {
    const int maxLength = 100;  // max characters allowed

    QString currentText = ui->MyTextEdit->toPlainText();

    if (currentText.length() > maxLength) {
        // Cut off extra characters
        QString trimmedText = currentText.left(maxLength);

        // Prevent infinite recursion by blocking signals temporarily
        ui->MyTextEdit->blockSignals(true);
        ui->MyTextEdit->setPlainText(trimmedText);
        ui->MyTextEdit->blockSignals(false);

        // Move cursor to the end
        QTextCursor cursor = ui->MyTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->MyTextEdit->setTextCursor(cursor);
    }
}

void add_newspaper::on_submit_clicked()
{
    QString titre= ui->title->text();
    QString auteur=ui->author->text();
    int nombre_de_pages = ui->paginas->text().toInt();
    QString editeur=ui->editor->text();
    int copies=ui->spinBox->value();
    QString description =ui->MyTextEdit->toPlainText();



    // Check if any field is empty or invalid
    if (titre.isEmpty() ||
        auteur.isEmpty() ||
        ui->paginas->text().isEmpty() ||  // To avoid zero from empty input
        ui->editor->text().isEmpty() ||
        description.isEmpty()) {

        QMessageBox::warning(this, "Input Error", "Please fill all the fields.");
        return;  // stop further processing
    }

    if (nombre_de_pages <= 0) {
        QMessageBox::warning(this, "Input Error", "Number of pages must be a positive number.");
        return;
    }
    newspaper *n=new newspaper(titre.trimmed(),auteur,"newspaper",description,nombre_de_pages,copies,editeur);
    admin a;
    if(a.add_newspaper(n)){
          QMessageBox::information(this,"congrats","Newsaper  added successfully!!");
        table_newspaper p;
          p.setModal(true);
        this->close();
          p.exec();


    }else{
        QMessageBox::warning(this,"Error","Failed to add the book!!");
    }
}


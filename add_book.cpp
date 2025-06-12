#include "add_book.h"
#include "ui_add_book.h"
#include <QMessageBox>
#include "ubook.h"
#include "user.h"
#include "database.h"
#include "table_books.h"
add_book::add_book(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_book)
{
    ui->setupUi(this);
    ui->submit->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
    connect(ui->MyTextEdit, &QPlainTextEdit::textChanged, this, &add_book::limitTextSize);
    ui->comboBox->addItem("course material");
    ui->comboBox->addItem("additional ressources");
    ui->comboBox->addItem("maths support");
    ui->comboBox->addItem("programming guide ");
    ui->comboBox->addItem("entertainment");
    ui->spinBox->setMinimum(1);


}

add_book::~add_book()
{
    delete ui;
}
void add_book::limitTextSize() {
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



void add_book::on_submit_clicked()
{
    QString titre= ui->title->text();
    QString auteur=ui->author->text();
  int nombre_de_pages = ui->paginas->text().toInt();
    QString genres=ui->comboBox->currentText();
  int copies=ui->spinBox->value();
    QString description =ui->MyTextEdit->toPlainText();

  for (int i=0;i<book::books_counter;i++){
        if (titre == book::books[i]->get_title()){
          QMessageBox::warning(this,"error","failed to add the book ,already exists");
            return;
        }
  }


  // Check if any field is empty or invalid
  if (titre.isEmpty() ||
      auteur.isEmpty() ||
      ui->paginas->text().isEmpty() ||  // To avoid zero from empty input
      genres.isEmpty() ||
      description.isEmpty()) {

      QMessageBox::warning(this, "Input Error", "Please fill all the fields.");
      return;  // stop further processing
  }

  if (nombre_de_pages <= 0) {
      QMessageBox::warning(this, "Input Error", "Number of pages must be a positive number.");
      return;
  }
  book *b=new book(titre.trimmed(),auteur,genres,description,nombre_de_pages,copies);
  admin a;
  if(a.add_book(b)){
      QMessageBox::information(this,"congrats","Book added successfully!!");
      table_books b;
      b.setModal(true);
      this->close();
      b.exec();


  return ;}
  else{
      QMessageBox::warning(this,"Error","Failed to add the book!!");
  }



  }




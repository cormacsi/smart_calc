#include "mainwindow.h"

extern "C" {
#include "../back/smart_calc.h"
}

void Calculator::Calc_Pressed() { ui->stackedWidget->setCurrentIndex(0); }

void Calculator::Symbol_Pressed() {
  QPushButton *button = static_cast<QPushButton *>(sender());
  QString butVal = button->text();

  QLineEdit *tmpLine;
  if (ui->lineEdit->hasFocus()) {
    tmpLine = ui->lineEdit;
  } else {
    tmpLine = ui->lineX;
  }

  QString newSymbol;
  if (QString::compare(butVal, "÷", Qt::CaseInsensitive) == 0) {
    newSymbol = "/";
  } else if (QString::compare(butVal, "×", Qt::CaseInsensitive) == 0) {
    newSymbol = "*";
  } else if (QString::compare(butVal, "√", Qt::CaseInsensitive) == 0) {
    newSymbol = "sqrt(";
  } else if (QString::compare(butVal, "sin", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "asin", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "cos", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "acos", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "tan", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "atan", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "ln", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else if (QString::compare(butVal, "log", Qt::CaseInsensitive) == 0) {
    newSymbol = butVal + "(";
  } else {
    newSymbol = butVal;
  }

  QString displayVal = tmpLine->text();
  int pos = tmpLine->cursorPosition();
  if (displayVal == "" && button == ui->dot) {
    newSymbol = "0.";
    displayVal = newSymbol;
  } else if (displayVal == "0" && Is_Operation(button)) {
    displayVal = newSymbol;
  } else {
    displayVal.insert(pos, newSymbol);
  }
  tmpLine->setText(displayVal);
  tmpLine->setCursorPosition(pos + newSymbol.length());
}

bool Calculator::Is_Operation(QPushButton *button) {
  return button != ui->dot && button != ui->mod && button != ui->pow &&
         button != ui->div && button != ui->mul && button != ui->add &&
         button != ui->sub;
}

void Calculator::Backspace_Pressed() {
  QString displayVal;
  if (ui->lineEdit->hasFocus()) {
    displayVal = ui->lineEdit->text();
    displayVal.chop(1);
    ui->lineEdit->setText(displayVal);
  } else {
    displayVal = ui->lineX->text();
    displayVal.chop(1);
    ui->lineX->setText(displayVal);
  }
}

void Calculator::Clean_Pressed() {
  if (ui->lineEdit->hasFocus()) {
    ui->lineEdit->setText("");
  } else {
    ui->lineX->setText("");
  }
}

void Calculator::Equal_Pressed() {
  QString displayVal = ui->lineEdit->text();
  QString x_Val = ui->lineX->text();

  if (displayVal.contains("x") && x_Val == "") {
    ui->lineX->setFocus();
  } else if (displayVal == "") {
    ui->lineEdit->setFocus();
  } else if (displayVal.endsWith("=")) {
    displayVal.chop(1);
    ui->lineEdit->setText(displayVal);
  } else {
    Calculate_Result();
  }
}

void Calculator::Calculate_Result() {
  std::string input_line = ui->lineEdit->text().toUtf8().constData();
  const char *input_str = input_line.c_str();

  std::string x_line = ui->lineX->text().toUtf8().constData();
  const char *x_str = x_line.c_str();

  int error = 0;

  long double resultDouble = smart_calc(const_cast<char *>(input_str),
                                        const_cast<char *>(x_str), &error);

  if (error) {
    Print_Error(error);
  } else {
    std::stringstream resultStr;
    resultStr << resultDouble;
    QString output_line = QString::fromStdString(resultStr.str());
    ui->lineEdit->setText(output_line);
    ui->lineX->setText("");
    ui->lineEdit->setFocus();
  }

  // if (error) {
  //   Print_Error(error);
  //   // ui->lineEdit->inputRejected();
  // } else {
  //   char str[255];
  //   result_to_string(result, str);
  //   ui->lineEdit->setText(QString::fromStdString(str));
  //   ui->lineX->setText("");
  //   ui->lineEdit->setFocus();
  // }
}

void Calculator::Print_Error(int error) {
  QString error_details;
  if (error == SIZE_ERROR) {
    error_details = "The string size should be {1-255} symbols\n";
  } else if (error == INPUT_ERROR) {
    error_details =
        "Please exclude invalid symbols\n\n"
        "Valid symbols are: 123456789.,()+-*×·/÷^xmodsincotalgsqr√↑π \n";
  } else if (error == SORT_ERROR) {
    error_details =
        "Sort error\n\n"
        "Please check the sequence of operations or exclude invalid brackets\n";
  } else if (error == YARD_ERROR) {
    error_details =
        "Yard error\n\n"
        "Please check the sequence of operations or exclude invalid brackets\n";
  } else if (error == CALCULATION_ERROR) {
    error_details =
        "Calculation error\n\n"
        "Please check the sequence of operations or exclude invalid brackets\n";
  } else if (error == GRAPH_ERROR) {
    error_details =
        "The Minimum value should be less than Maximum value!\n\n"
        "Check the size of the graph again:)";
  } else if (error == ERROR) {
    error_details = "Unknown error\n";
  }
  QMessageBox::critical(this, "Error", error_details);
}

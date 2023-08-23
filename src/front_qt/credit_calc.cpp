#include "mainwindow.h"

extern "C" {
#include "../back/credit_calc.h"
}

void Calculator::Credit_Pressed() {
  ui->stackedWidget->setCurrentIndex(2);

  ui->loan_amount->setValidator(
      new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]*"), this));
  ui->interest_rate->setValidator(new QRegularExpressionValidator(
      QRegularExpression("\\d*\\.?\\d+"), this));
}

void Calculator::Calculate_Credit() {
  long double K = ui->loan_amount->text().toDouble();
  long double P = ui->interest_rate->text().toDouble();
  int years = ui->years->text().toInt();
  int months = ui->months->text().toInt();
  int M = years * 12 + months;

  if (K > 0 && P > 0. && M > 0) {
    if (ui->payment_type->currentIndex() == 0) {
      long double A = credit_calc(K, P, M);
      long double T = A * M;
      ui->monthly_payment->setText(QString::number(A, 'f', 2));
      ui->overpayment->setText(QString::number(T - K, 'f', 2));
      ui->total_payment->setText(QString::number(T, 'f', 2));
    } else {
      Differentiated_Credit(K, P, M);
    }
  } else {
    ui->monthly_payment->setText("ERROR");
  }
}

void Calculator::Differentiated_Credit(long double K, long double P, int M) {
  long double overpayment = 0.;
  long double total = K;
  long double payment[M];
  long double MP = K / M;
  int year[M];
  int month[M];

  QDate date = QDate::currentDate();
  year[0] = date.year() - 2000;
  month[0] = date.month();
  QString output_result = "№\t Month\tPayment\n";
  QString pay_monthly = " ";

  for (int i = 0; i < M; i++) {
    payment[i] = differen_calc(K, P);
    overpayment += payment[i];
    payment[i] += MP;
    output_result += QString::number(i + 1) + "\t";
    output_result += QString::number(month[i]) + ".";
    output_result += QString::number(year[i]) + "   ";
    output_result += QString::number(payment[i], 'f', 2) + "\n";
    if (i == 0) pay_monthly += QString::number(payment[i], 'f', 2);

    month[i + 1] = month[i] + 1;
    year[i + 1] = year[i];
    if (month[i + 1] > 12) {
      month[i + 1] = 1;
      year[i + 1] = year[i] + 1;
    }
    K = K - MP;
  }
  total += overpayment;

  pay_monthly += "..." + QString::number(payment[M - 1], 'f', 2);
  ui->monthly_payment->setText(pay_monthly);
  ui->overpayment->setText(QString::number(overpayment, 'f', 2));
  ui->total_payment->setText(QString::number(total, 'f', 2));

  QMessageBox::information(this, "Monthly payment", output_result);
}

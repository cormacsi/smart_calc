#include "mainwindow.h"

extern "C" {
#include "../back/deposit_calc.h"
}

void Calculator::Deposit_Pressed() {
  ui->stackedWidget->setCurrentIndex(3);

  QRegularExpression amount_regex = QRegularExpression("[1-9][0-9]*");
  QRegularExpression rate_regex = QRegularExpression("\\d*\\.?\\d+");
  ui->deposit_amount->setValidator(
      new QRegularExpressionValidator(amount_regex, this));
  ui->deposit_rate->setValidator(
      new QRegularExpressionValidator(rate_regex, this));
  ui->tax_rate->setValidator(new QRegularExpressionValidator(rate_regex, this));
  ui->replenishment->setValidator(
      new QRegularExpressionValidator(amount_regex, this));
  ui->withdrawal->setValidator(
      new QRegularExpressionValidator(amount_regex, this));
}

void Calculator::Calculate_Deposit() {
  long double K = ui->deposit_amount->text().toDouble();
  long double P = ui->deposit_rate->text().toDouble();
  int years = ui->deposit_years->text().toInt();
  int months = ui->deposit_month->text().toInt();
  int M = years * 12 + months;

  if (K > 0 && P > 0. && M > 0) {
    QDate date = QDate::currentDate();
    deposit calc;
    calc.amount = K;
    calc.pay_type = ui->payment_per->currentIndex();
    calc.total_month = M;
    calc.interest = P;
    calc.tax = ui->tax_rate->text().toDouble();
    calc.cap = ui->capitalization->isChecked();
    calc.rep_type = ui->replenishment_type->currentIndex();
    calc.rep_amount = ui->replenishment->text().toDouble();
    calc.wit_type = ui->partial_withdraw->currentIndex();
    calc.wit_amount = ui->withdrawal->text().toDouble();

    t_date current;
    current.date = date.day();
    current.month = date.month();
    current.year = date.year();

    s_result result = deposit_calculator(calc, current);
    ui->accrued_interest->setText(QString::number(result.accrued, 'f', 2));
    ui->tax_amount->setText(QString::number(result.t_amount, 'f', 2));
    ui->deposit_amount_end->setText(QString::number(result.d_amount, 'f', 2));
  } else {
    ui->accrued_interest->setText("ERROR");
  }
}

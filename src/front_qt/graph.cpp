#include "mainwindow.h"

extern "C" {
#include "../back/smart_calc.h"
}

void Calculator::Graph_Pressed() {
  ui->stackedWidget->setCurrentIndex(1);

  ui->graph_line->setFocus();
  ui->graph_img->addGraph();

  ui->graph_img->xAxis->setLabel("X");
  ui->graph_img->yAxis->setLabel("Y");

  ui->graph_img->xAxis->setRange(-10, 10);
  ui->graph_img->yAxis->setRange(-5, 5);

  ui->graph_img->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                                 QCP::iSelectPlottablesBeyondAxisRect);
  Check_Graph();
}

void Calculator::Check_Graph() {
  int error = 0;
  QString graph_str = ui->graph_line->text();
  std::string x_line = graph_str.toUtf8().constData();

  ui->graph_img->clearGraphs();
  ui->graph_img->addGraph();

  s_graph g_val;
  g_val.func = x_line.c_str();
  g_val.x_Min = ui->xMin->value();
  g_val.x_Max = ui->xMax->value();
  g_val.y_Min = ui->yMin->value();
  g_val.y_Max = ui->yMax->value();

  if (g_val.x_Min >= g_val.x_Max || g_val.y_Min >= g_val.y_Max) {
    error = GRAPH_ERROR;
  } else {
    if (graph_str == "batman") {
      Draw_Batman();
    } else if (graph_str == "love") {
      Draw_Love();
    } else if (!check_input(const_cast<char*>(g_val.func))) {
      ui->graph_img->xAxis->setRange(g_val.x_Min, g_val.x_Max);
      ui->graph_img->yAxis->setRange(g_val.y_Min, g_val.y_Max);

      error = Draw_Graph(g_val);
    } else {
      error = INPUT_ERROR;
    }
  }
  if (error) {
    Print_Error(error);
  }
  ui->graph_img->replot();
  ui->graph_img->update();
}

int Calculator::Draw_Graph(s_graph g_val) {
  int error = 0;
  char math_str[400] = "";
  create_math_string(const_cast<char*>(g_val.func), math_str);

  double h = 0.01, last = 0;
  ;

  QVector<double> x, y;

  double i = g_val.x_Min;
  while (i < g_val.x_Max) {
    double y_res = graph_only(const_cast<char*>(math_str), i, &error);
    if (error) break;
    if (qFabs(qFabs(y_res) - qFabs(last)) < 10) {
      if (y_res >= (g_val.y_Min - qFabs(g_val.y_Min)) &&
          y_res <= (g_val.y_Max + qFabs(g_val.y_Max))) {
        x.push_back(i);
        y.push_back(y_res);
      }
    } else {
      x.push_back(i);
      y.push_back(NAN);
    }
    last = y_res;
    i += h;
  }
  if (!error) {
    ui->graph_img->graph(0)->addData(x, y);
    ui->graph_img->addGraph();
  }
  return error;
}

void Calculator::Draw_Love() {
  int x_Min = -30, x_Max = 30, y_Min = -18, y_Max = 13;

  ui->xMin->setValue(x_Min);
  ui->xMax->setValue(x_Max);
  ui->yMin->setValue(y_Min);
  ui->yMax->setValue(y_Max);

  ui->graph_img->xAxis->setRange(x_Min, x_Max);
  ui->graph_img->yAxis->setRange(y_Min, y_Max);

  QVector<double> x, y;
  double t = 0.;
  double t_Max = 2 * M_PI;
  while (t < t_Max) {
    double x_tmp = 16 * qPow(sin(t), 3);
    x.push_back(x_tmp);
    double y_tmp = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
    y.push_back(y_tmp);
    t += 0.01;
  }
  ui->graph_img->addGraph();
  ui->graph_img->graph(0)->addData(x, y);
}

void Calculator::Draw_Batman() {
  int x_Min = -8, x_Max = 8, y_Min = -7, y_Max = 7;

  ui->xMin->setValue(x_Min);
  ui->xMax->setValue(x_Max);
  ui->yMin->setValue(y_Min);
  ui->yMax->setValue(y_Max);

  ui->graph_img->xAxis->setRange(x_Min, x_Max);
  ui->graph_img->yAxis->setRange(y_Min, y_Max);

  QVector<double> x0, y0, y1, y2, y3;
  double i = x_Min - 2;
  while (i < x_Max) {
    double tmp = 2 *
                     sqrt(-abs(abs(i) - 1) * abs(3 - abs(i)) /
                          ((abs(i) - 1) * (3 - abs(i)))) *
                     (1 + abs(abs(i) - 3) / (abs(i) - 3)) *
                     sqrt(1 - (i / 7) * (i / 7)) +
                 (5 + 0.97 * (abs(i - .5) + abs(i + .5)) -
                  3 * (abs(i - .75) + abs(i + .75))) *
                     (1 + abs(1 - abs(i)) / (1 - abs(i)));
    x0.push_back(i);
    y0.push_back(tmp);
    tmp =
        -3 * sqrt(1 - (i / 7) * (i / 7)) * sqrt(abs(abs(i) - 4) / (abs(i) - 4));
    y1.push_back(tmp);
    tmp = abs(i / 2) - 0.0913722 * (i * i) - 3 +
          sqrt(1 - (abs(abs(i) - 2) - 1) * (abs(abs(i) - 2) - 1));
    y2.push_back(tmp);
    tmp = (2.71052 + (1.5 - .5 * abs(i)) -
           1.35526 * sqrt(4 - (abs(i) - 1) * (abs(i) - 1))) *
              sqrt(abs(abs(i) - 1) / (abs(i) - 1)) +
          0.9;
    y3.push_back(tmp);
    i += 0.05;
  }
  ui->graph_img->addGraph();
  ui->graph_img->graph(0)->addData(x0, y0);
  ui->graph_img->addGraph();
  ui->graph_img->graph(1)->addData(x0, y1);
  ui->graph_img->addGraph();
  ui->graph_img->graph(2)->addData(x0, y2);
  ui->graph_img->addGraph();
  ui->graph_img->graph(3)->addData(x0, y3);
}

# SmartCalculator

<img src="../img/calculator.png" alt="" width="40"> <a href="https://youtu.be/RQUuqbzQVsY">SmartCalculator</a> is an educational project for ``School 21`` in Moscow.

### Introduction

This project implements an intelligent calculator consisting of two parts: back in C programming language and front in C++ and QT.
There are two directories in a project folder: ``back`` and ``front_qt``. All the files in back directory are written in C language and create a method for calculating complex mathematical expressions passed in a С-line from the front. Calculations are performed by pressing the "=" button or the "enter" button. After that, the string is checked for valid characters and the program determines whether it is necessary to refer to the second additional string with ``x`` value or ``x`` expression. 

### The program struct

``Back`` in its turn uses the Edsger Dijkstra's method (better known as the shunting-yard algorithm) to convert expressions (including complex functions) from infix to Reverse Polish notation. The Shunting-yard algorithm is stack-based. There are at least three dynamic arrays of stack involved in the conversion: the input, the output and the operator stack. The conversion process uses the operator stack to store operations not yet added to the output stack. The conversion program sequentially reads each token from the input stack and on each step does some actions based on which tokens have been read or used.

<a>
    <img src="../img/calc_struct.png" alt="" width="1000">
</a>

### Report

The project implements full coverage of library functions with Unit-tests using the ``Check library`` in C (#include <check.h>).
The gcov_report target (a part of Makefile) generates a gcov-report in the form of an html page: <a href="../../back/gcov_report/gcov_report.html">GCOVR report</a>.

### The author

<img src="../img/say_hi.gif" alt="" width="50"> *Polina* a.k.a **polza** a.k.a <a href="https://github.com/cormacsi">cormacsi</a>

<br>
<a>
    <img src="../img/calc.gif" alt="" width="1000">
</a>

<br>
<h3 align="center">Contact me by:</h3>
<div align="center">
  <a href="https://github.com/cormacsi/">
    <img src="../img/github-cormacsi.svg" alt="GitHub">
  </a>
   <a href="https://t.me/ampolza">
    <img src="../img/telegram-ampolza.svg" alt="Telegram">
  </a><br />
</div>
<br>


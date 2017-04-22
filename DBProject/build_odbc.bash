#!/bin/bash
set -e -v

g++ -Wall -o hello.exe hello.cpp
g++ -c odbc_insert_student.cpp
g++ -c odbc_db.cpp
g++ -Wall -I/usr/include/cppconn -o odbc_insert_student.exe odbc_insert_student.o odbc_db.o -L/usr/lib -lmysqlcppconn

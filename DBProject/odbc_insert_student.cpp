/* Compile using:
g++ -Wall -I/usr/include/cppconn -o odbc odbc_insert_restaurant.cpp -L/usr/lib -lmysqlcppconn 
run: 
./odbc */
#include "odbc_db.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
string Username = "ls008";            // Change to your own username
string mysqlPassword = "ahri3muS";  // Change to your mysql password
string SchemaName = "ls008";          // Change to your username

   odbc_db myDB;
   myDB.Connect(Username, mysqlPassword, SchemaName);
   myDB.initDatabase();
 
   // For debugging purposes:  Show the database before insert
   string builder = "";
   string query1 = "SELECT * from Student;";
   builder.append("<br><br><br> Student table before:" + myDB.query(query1) +"<br>");

   // Read command line arguments
   // First arg, arg[0] is the name of the program
   // Next args are the parameters
   string studentId = argv[1];
   string name = argv[2];
   string major = argv[3];
 
   // Insert the new restaurant
   string input = "'" + studentId + "','" + name + "','" + major + "'";               
   myDB.insert("Student", input);    // insert new restaurant
 
   //For debugging purposes: Show the database after insert
   builder.append("<br><br><br> Table Student after:" + myDB.query(query1));
   cout << builder; 
       
   myDB.disConnect();//disconect Database

   return 0;
}



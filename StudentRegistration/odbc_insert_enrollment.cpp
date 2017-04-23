#include "odbc_db.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
   odbc_db myDB;
   myDB.Connect();

   // Read command line arguments
   // First arg, arg[0] is the name of the program
   // Next args are the parameters
   string studentId = argv[1];
   string deptCode = argv[2];
   string courseNum = argv[3];
 
   // Insert the new course
   string input = "'" + studentId + "','" + deptCode + "','" + courseNum + "'";   
   try {            
      myDB.insert("Enrollment", input);    // insert new enrollment
   } catch (sql::SQLException &e) {
      cout << "ERROR: Unable to insert enrollment.\n"
           << "Please make sure the Student ID, Deptartment Code, and Course Number are valid.";
   }
       
   myDB.disConnect();//disconect Database

   return 0;
}

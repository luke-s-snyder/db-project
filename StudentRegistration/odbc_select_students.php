<html>
<head><title>View Students</title></head>
<style>
table {
	border-collapse: collapse;
}

td, th {
	border: 1px solid #dddddd;
	text-align: left;
	padding: 8px;
}

tr:nth-child(even) {
	background-color: #dddddd;
}
</style>
<body>
<h1>All Student Information:</h1>
<?php
    $command = '/home/ls008/public_html/StudentRegistration/odbc_select_students.exe';

    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // run odbc_select_students.exe
    system($command);           
?>

<br><a href="../StudentRegistration">Back to home page.</a>

</body>
</html>

<html>
<body>
<h3>Enter your name:</h3>

<form action="hello.php" method="post">
    Name: <input type="text" name="name"><br>
    <input name="submit" type="submit" >
</form>
<br><br>

</body>
</html>

<?php
if (isset($_POST['submit'])) 
{
    // replace ' ' with '\ ' in the strings so they are treated as single command line args
    $name = escapeshellarg($_POST[name]);

    // build the linux command that you want executed; use full path for safety
    $command = '/home/ls008/public_html/DBProject/hello.exe ' . $name;

    // remove dangerous characters from command to protect web server
    $command = escapeshellcmd($command);
 
    // echo then run the command
    echo "command: $command <br>";
    system($command);           
}
?>

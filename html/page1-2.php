<html>
    <head>
        <title> Exercice1 PHP </title>
    </head>
    <body>
        <?php
            $p = $_GET['fname'];
            $l = $_GET['lname'];
            // Create connection
            $con = new mysqli("localhost", "root", "", "mydb");
            // Check connection
            if(!$con)
            {
                die("Connection failed");
            }
            $result = $con->query("SELECT identifiant,pwd FROM administrateur");
            while ($row = $result->fetch_array(MYSQLI_NUM))
            {
                $Row0 =$row[0];
                $Row1 =$row[1];
            }
            if($Row0 == $p && $Row1 == $l)
            {
                echo"identifiants correct";
                header("Refresh: 0;URL =http://projet1/inscription.php");
            }
            else
            {
                echo"mauvais identifiants";
            }
            $con->close();
        ?>
    </body>
</html>
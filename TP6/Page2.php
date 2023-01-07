<html>
    <head>
        <title> Exercice1 PHP </title>
    </head>
    <body>
    <?php
        $p = $_GET['fname'];
        $l = $_GET['lname'];

        echo $p;
        echo $l;
        
        $con = new mysqli("localhost","root","","tp6");
        if (!$con)
        {
            die( "echec de la connexion:" );
        }

        $sql = "INSERT INTO administrateur (Login,Pwd)
        VALUES ( 'Yolo', 'yolo')" ;

        if ($con->query($sql))
        {
            echo "Le nouvel enregistrement est insere avec succes";
        }
        else
        {
            echo "Erreur:";
        }

        $con-> close();
        ?> 
    </body>
</html>
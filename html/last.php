<!DOCTYPE html>
<html>
    <head>
        <title> merci </title>
    </head>
    <body>
        <h1>Merci pour votre inscription</h1>
        <?php>
            $nom = 
            $con = new mysqli("localhost", "root", "", "mydb");
            if(!$con)
            {
                die("Connection failed");
            }
            $sql = "INSERT INTO mydb(nom, prenom, email, portable,adresse,sexe,nationalite,centre,vip)
            VALUES ('$nom','$prenom', '$email','$portable','$adresse','$sexe','$nationalite','$centre','$vip')";

            if
        ?>
    </body>
</html>

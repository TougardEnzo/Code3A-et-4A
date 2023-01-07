<html>
    <head>

    </head>
    <body>
        <?php
            function rectangle(int $longueur,int $largeur)
            {
                for($i = 0; $i < $largeur; $i++)
                {
                    for($j = 0; $j < $longueur; $j++)
                    {
                        echo " * ";
                    }
                    echo "<br>";
                }
            }
            rectangle(10,10);
            echo "<br><br><br><br>";
            rectangle(5,5);
        ?>
    </body>
</html>
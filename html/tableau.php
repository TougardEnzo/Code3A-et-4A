<html>
    <head>

    </head>
    <body>
        <?php
            $days = array("lundi","mardi","mercredi","jeudi","vendredi","samedi","dimanche");
            foreach ($days as $day)
            {
                echo "<ul><li> $day</ul></li>";
            }
        ?>
    </body>
</html>
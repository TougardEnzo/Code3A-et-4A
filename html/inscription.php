<!DOCTYPE html>
<html>
    <head>
        <title>inscription client</title>
        <h1>Formulaire d'inscription</h1>
    </head>
    <body>
        <form name = "Form" method = "GET" action = "last.php">
            Nom : <input id="nom">
            <br><br>
            Prenom : <input id="prenom">
            <br><br>
            Email : <input type="email" id="email">
            <br><br>
            Portable : <input type="tel" id="portable">
            <br><br>
            Adresse : <input id="adresse">
            <br><br>
            <p>Sexe :<br> <input type="radio" id="male" name="gender" value="male" checked>
            <label for="male">Male</label>
            <br>
            <input type="radio" id="female" name="gender" value="female">
            <label for="female">Female</label></p>
            Nationalité : 
                <select name="nationalite" size="1">
                    <option>choisir</option>
                    <option>Francais</option>
                    <option>Anglais</option>
                    <option>Americain</option>
                    <option>Italien</option>
                    <option>Allemand</option>
                    <option>Breton</option>
                </select>
            <br>
            Centre d'interets : 
                <input type="checkbox" id="hobby" name="hobby" value="lecture" checked>
                <label for="hobby">Lecture</label><br>
                <input type="checkbox" id="hobby2" name="hobby2" value="echecs">
                <label for="hobby2">echecs</label><br>
                <input type="checkbox" id="hobby3" name="hobby3" value="skate">
                <label for="hobby3">skate</label>
            VIP : 
            <input type="checkbox" id="yes" name="yes">
            <label for="yes">yes</label>
            <input type="checkbox" id="no" name="no" checked>
            <label for="no">no</label>
            <br><br>
            <script src="verif.js"></script>
            <button type="button" onclick="verification()">Confirmer</button>
        </form>
    </body>
</html>
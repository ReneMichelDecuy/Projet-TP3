<?php function Connexion($serveur, $user, $passwd, $bdd)
{
    try {
        /*on teste la connexion à la base de données
        $serveur = addresse IP de la base de données
        $bdd = nom de la base de données
        $user,$passswd = login et mot de passe d'un utilisateur de la base de données
        */
        return new PDO('mysql:host=' . $serveur . ';dbname=' . $bdd, $user, $passwd);
    } catch (Exception $e) {
        echo $e;
    }
}

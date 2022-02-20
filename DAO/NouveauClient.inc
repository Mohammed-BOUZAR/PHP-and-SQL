<?php

    // préparation des informations nécessaires
    //define('DSN', 'mysql:host=localhost;dbname=bank');
    //define('USER', 'root');
    //define('MDP', '');


    function NouveauClient(){
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            
            // préparation de la requête
            $requete = $connDB->prepare("
                                        INSERT INTO client (CIN,nom,prenom,adresse) 
                                        VALUES (:cin, :nom, :pre, :ads);
                                        ");
            $requete -> bindParam(':cin', $GLOBALS['cin']);
            $requete -> bindParam(':nom', $GLOBALS['nom']);
            $requete -> bindParam(':pre', $GLOBALS['pre']);
            $requete -> bindParam(':ads', $GLOBALS['ads']);
            $requete -> execute();
            //echo "<script>alert('Success');</script>";
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
    }

?>
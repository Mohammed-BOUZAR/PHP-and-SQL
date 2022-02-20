<?php

    // préparation des informations nécessaires
    define('DSN', 'mysql:host=localhost;dbname=bank');
    define('USER', 'root');
    define('MDP', '');
    
    function ExisteClient($cin){
        
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            // préparation de la requête
            $requete = "SELECT count(CIN) FROM client WHERE CIN = '$cin'";
            $resultat = $connDB->query($requete);
            $count = $resultat->fetchColumn();
            
            /*
            if($count){
                echo "cette client existe";
            }
            else 
                echo "cette client n'existe pas";
            */
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
        return $count;
    }
 


    function Infos($cin){
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $requete1 = "SELECT * FROM client WHERE CIN = '$cin'";
            $resultat1 = $connDB -> query($requete1);
            $donnees1 = $resultat1 -> fetchAll();
            foreach($donnees1 as $ligne) {
                echo $ligne['nom']." ".$ligne['prenom']."<br>";
            }

            $requete2 = "SELECT * FROM compte WHERE CIN = '$cin'";
            $resultat2 = $connDB -> query($requete2);
            $donnees2 = $resultat2 -> fetchAll();
            foreach($donnees2 as $ligne) {
                echo "Numéro de compte : ".$ligne['NumCompte'].
                    " et Le Montant : ".$ligne['Montant']."<br>";
            }
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
    }


    
    function Supprimer($cin){
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $requete1 = "DELETE FROM client WHERE CIN = '$cin';";
            $resultat1 = $connDB -> exec($requete1);

            $requete2 = "DELETE FROM compte WHERE CIN = '$cin';";
            $resultat2 = $connDB -> exec($requete2);

            echo "<script>alert('Success');</script>";
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
    }



    
    function Debiteurs(){
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            $requete1 = "SELECT nom,prenom FROM client,compte 
                        WHERE Montant < 0 and compte.CIN = client.CIN ;";
            $resultat1 = $connDB -> query($requete1);
            $donnees1 = $resultat1 -> fetchAll();
            foreach($donnees1 as $ligne) {
                echo $ligne['nom']." ".$ligne['prenom']."<br>";
            }
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
    }
?>
<?php

    require "Client.inc";

    // préparation des informations nécessaires
    //define('DSN', 'mysql:host=localhost;dbname=bank');
    //define('USER', 'root');
    //define('MDP', '');
    
    function ExisteCompte($num){
        
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            // préparation de la requête
            $requete = "SELECT count(CIN) FROM compte WHERE NumCompte = '$num'";
            $resultat = $connDB->query($requete);
            $count = $resultat->fetchColumn();

            /*
            if($count){
                echo "cette Compte existe";
            }
            else 
                echo "cette Compte n'existe pas";
            */
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
        return $count;
    }

    function NouveauCompte($cin,$num,$montant){
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            // préparation de la requête
            $requete = $connDB->prepare("INSERT INTO compte (NumCompte,CIN,Montant) 
                        VALUES (:unNum,:unCIN,:unMontant);");
            if((ExisteClient($cin) == 1) && (ExisteCompte($num) == 0)){
                $requete -> bindParam(':unNum', $num);
                $requete -> bindParam(':unCIN', $cin);
                $requete -> bindParam(':unMontant', $montant);
                $requete -> execute();
                echo "<script>alert('Success');</script>";
            }
            else echo "<script>alert('Faild');</script>";
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
    }


    function Virement($num, $montant){
        try {
            $connDB = new PDO(DSN, USER, MDP);
            $connDB -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

            // préparation de la requête
            $requete = $connDB->prepare("UPDATE compte SET Montant = Montant + :montant 
                                        WHERE NumCompte = $num;");
                                        
            $requete -> bindParam(':montant', $montant);
            $requete -> execute();
            echo "<script>alert('Success');</script>";
            
        } 
        catch (Exception $erreur) {
            echo "Outch, erreur : ".$erreur -> getMessage();
            exit();
        }
    }
?>
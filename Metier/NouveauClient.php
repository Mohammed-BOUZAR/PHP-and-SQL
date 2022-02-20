<?php
    require "../DAO/Compte.inc";
    require "../DAO/NouveauClient.inc";
    $cin = $_POST['cin'];
    $nom = $_POST['nom'];
    $pre = $_POST['prenom'];
    $ads = $_POST['adresse'];
    $num = $_POST['num'];
    $montant = $_POST['montant'];
    NouveauClient();
    NouveauCompte($cin,$num,$montant);
    
?>
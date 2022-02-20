<?php
    require "../DAO/Compte.inc";
    $num = $_POST['num'];
    $montant = $_POST['montant'];
    Virement($num, $montant);
?>
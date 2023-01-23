<?php
error_reporting(E_ALL);
$tabReponse = [];

/* Lit le port du service WWW. */
$service_port = 80;

/* Lit l'adresse IP du serveur de destination */
$address = gethostbyname('192.168.65.135');

/* Crée un socket TCP/IP. */
$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket === false) {
   array_push($tabReponse, "<span class='TCP'>socket_create() a échoué : raison :  " . socket_strerror(socket_last_error()) . "</span>");
}

$result = socket_connect($socket, $address, $service_port);
if ($socket === false) {
    array_push($tabReponse, "<span class='TCP'>socket_connect() a échoué : raison : ($result) " . socket_strerror(socket_last_error()) . "</span>");
}

$in = "test envoi";
$out[0] = '';

socket_write($socket, $in, strlen($in));
$text = "";
while ($out[0] = socket_read($socket, 2048)) {
    $text .=$out[0];
}

array_push($tabReponse, $text);
echo str_replace('\\u0000',"", json_encode($tabReponse));
socket_close($socket);
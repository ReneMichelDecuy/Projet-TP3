function getDonnees() {
    //pour appeler une API on utilise la méthode fetch()
    fetch('./fonctions/TCP.php').then((resp) => resp.json())
        .then(function (data) {
            // data est la réponse http de notre API.
            donnees = data[0].split('§');
            console.log(donnees);
            UpdateDiv("mesure", donnees[0]);
            if (donnees[1]===1) {
                UpdateDiv("bouton1", "Sale");
                UpdateDiv("bouton2", "Allumée");
            }
            else {
                UpdateDiv("bouton1", "Propre");
                UpdateDiv("bouton2", "Eteinte");
            }
        })
        .catch(function (error) {
            // This is where you run code if the server returns any errors
            console.log(error);
        });
}

function UpdateDiv(id, text) {
    var e = document.getElementById(id).innerHTML = text;
}

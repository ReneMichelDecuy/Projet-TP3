#include <SPI.h> // Libairie communication SPI avec le Shield éthernet
#include <Ethernet.h> // Librairie communication Ethernet sur un réseau local
const int Trig = 7; //Déclaration d’une constante Trig
const int Echo = 5; //Déclaration d’une constante Echo
const int VITESSE = 340 ; //Déclaration d’une constante VITESSE = 340 m/s
const int directionPin = 12; //Déclaration d’une constante directionPin
const int pwmPin = 3;//Déclaration d’une constante pwmPin
const int brakePin = 9;//Déclaration d’une constante brakePin
const int led = 6;
const int bouton= 2;
int val = 0;

//On donne l'adresse MAC au shield Ethernet (ne doit pas être identique à une autre adresse MAC présente sur votre réseau)
byte MAC[] = { 0x10, 0x11, 0x12, 0x13, 0x14, 0x15 }; // Adresse MAC du shield Ethernet

//On affecte l'adresse IP du Shield Ethernet
IPAddress IP(192,168,65,135); // Adresse IP donné au Shield Ethernet

// On attribue la fonction serveur au Shield Ethernet sur le port 80
EthernetServer server = EthernetServer(80); // Le Shield devient un serveur sur le port 80 (port HTTP)


void setup() {
  Ethernet.begin(MAC, IP); //lancement MAC+IP
  server.begin();//Lancement Serveur HTTP
  Serial.begin(9600);
  pinMode(Trig, OUTPUT); //Affectation de la broche Trig comme sortie
  pinMode(Echo, INPUT); //Affectation de la broche Echo comme entrée
  pinMode(directionPin, OUTPUT);//Affectation de la broche directionPin comme sortie
  pinMode(pwmPin, OUTPUT);//Affectation de la broche PwmPin comme sortie
  pinMode(brakePin, OUTPUT);//Affectation de la broche brakePin comme sortie
  pinMode(led, OUTPUT);//Affectation de la broche led comme sortie
  pinMode(bouton, INPUT);//Affectation de la broche bouton comme entré
  Serial.begin(9600); //Initialisation de la communication série avec le PC
}

void loop()
{
  digitalWrite(Trig, HIGH); //Mise au niveau haut sur la broche Trig
  delayMicroseconds(10); //Pause de 10 µs
  digitalWrite(Trig, LOW); //Mise au niveau bas sur la broche Trig
  unsigned long duree = pulseIn(Echo, HIGH); //Lecture de la durée de l’état haut sur Echo
  duree = duree/2; //Division de la durée par deux
  float temps = duree/1000000.0; //Conversion en seconde
  float distance = (temps*VITESSE)*100; //Calcul de la distance
  Serial.print("Durée [µs] = "); //Ecriture de "Durée = "
  Serial.println(duree); //Affichage du temps de vol d'un trajet en secondes
  Serial.print("Distance [cm] = "); //Ecriture de "Distance = "
  Serial.println(distance); //Affichage de la distance mesurée en mètres
  if(distance > 5)
  {
    Serial.print("Durée [µs] = "); //Ecriture de "Durée = "
    Serial.println(duree); //Affichage du temps de vol d'un trajet en secondes
    Serial.print("Distance [cm] = "); //Ecriture de "Distance = "
    Serial.println(distance); //Affichage de la distance mesurée en mètres
    digitalWrite(pwmPin,0);
  } //Si duree est supérieure à 30ms, l’onde est considérée comme perdue
  else
  {
    Serial.println("Onde faible, allumé pompe !");
    digitalWrite(pwmPin, 100);
  }
  val = digitalRead(bouton);   // read the input pin
  if(val == 1)
  {
    Serial.println("Eau sale, allumé pompe !");
    digitalWrite(led,val);
    digitalWrite(pwmPin, 100);
  }
  else
  {
    Serial.println("Eau Propre !");
    digitalWrite(led, 0);
    digitalWrite(pwmPin, 0);
  }
  
delay(2000); //Pause de 7secondes
  EthernetClient client = server.available(); // check for incoming client
  if (client) { // if a client connects
    Serial.println("Client connected");
    
    while (client.connected()) { // while the client is connected
      if (client.available()) { // if there's incoming data
        String request = client.readStringUntil('\r'); // read the incoming data
        Serial.println(request); // print the incoming data for debugging
        client.print(distance); // send HTML content type
        client.print("§");
        client.print(val);
        Serial.print(distance); // send HTML content type
        Serial.print("§");
        Serial.print(val);
        break;
      }
    }
    client.stop(); // stop the client
    Serial.println("Client disconnected");
  }
}

// digitalWrite(directionPin, HIGH);
  //digitalWrite(brakePin, LOW);

//Incluir bibliotecas
#include <WiFi.h> //https://www.arduinolibraries.info/libraries/wi-fi
#include <PubSubClient.h> //https://www.arduinolibraries.info/libraries/pub-sub-client
#include <DHTesp.h> //https://www.arduinolibraries.info/libraries/dht-sensor-library-for-es-px

//Definições e constantes
char SSIDName[] = "Wokwi-GUEST"; //nome da rede WiFi
char SSIDPass[] = ""; //senha da rede WiFi

const int DHT_PIN = 15; //Pino do sensor DHT22

char BrokerURL[] = "broker.hivemq.com"; //URL do broker MQTT
char BrokerUserName[] = ""; //nome do usuário para autenticar no broker MQTT
char BrokerPassword[] = ""; //senha para autenticar no broker MQTT
char MQTTClientName[] = "mqtt-explorer-effaebaf"; //nome do cliente MQTT
int BrokerPort = 1883; //porta do broker MQTT

char Topico_Temperatura[] = "projetoMonitoramento/Temperatura"; //tópico para temperatura
char Topico_Umidade[] = "projetoMonitoramento/Umidade"; //tópico para umidade

//Variáveis globais e objetos
WiFiClient espClient; //Objeto para conexão WiFi
PubSubClient clienteMQTT(espClient); //Cliente MQTT
DHTesp dhtSensor; //Objeto para o sensor DHT

//Funções definidas pelo usuário

//Função para reconectar ao broker
void mqttReconnect() {
  while (!clienteMQTT.connected()) {
    Serial.println("Conectando-se ao broker MQTT...");
    if (clienteMQTT.connect(MQTTClientName, BrokerUserName, BrokerPassword)) {
      Serial.println("Conectado ao broker!");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(clienteMQTT.state());
      Serial.println(" Tentando novamente em 5 segundos.");
      delay(5000);
    }
  }
}

//Setup
void setup() {
  clienteMQTT.setServer(BrokerURL, BrokerPort); //Configura o broker MQTT
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22); //Inicializa o sensor DHT22

  Serial.begin(9600);
  Serial.print("Conectando-se ao Wi-Fi");
  WiFi.begin(SSIDName, SSIDPass); //Inicializa Wi-Fi
  while (WiFi.status() != WL_CONNECTED) { //Repete enquanto não conecta
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP()); //Imprime o endereço IP
}

//Loop
void loop() {
  if (!clienteMQTT.connected()) { //Verifica se está conectado ao broker
    mqttReconnect(); //Se não, tenta reconectar
  }
  clienteMQTT.loop(); //Mantém a conexão MQTT ativa

  TempAndHumidity dados = dhtSensor.getTempAndHumidity(); //Obtém dados do sensor
  float temperatura = dados.temperature;
  float umidade = dados.humidity;

  //Publica temperatura
  char valorTemperatura[8];
  dtostrf(temperatura, 1, 2, valorTemperatura); //Converte para string
  clienteMQTT.publish(Topico_Temperatura, valorTemperatura);
  Serial.print("Temperatura publicada: ");
  Serial.println(valorTemperatura);

  //Publica umidade
  char valorUmidade[8];
  dtostrf(umidade, 1, 2, valorUmidade); //Converte para string
  clienteMQTT.publish(Topico_Umidade, valorUmidade);
  Serial.print("Umidade publicada: ");
  Serial.println(valorUmidade);

  delay(1000); //Espera 1 segundo
}

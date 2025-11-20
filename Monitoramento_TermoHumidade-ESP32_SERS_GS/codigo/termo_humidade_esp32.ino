// Projeto: Monitoramento Termo-Humidade com ESP32 e DHT22
// Descrição: Lê temperatura e umidade usando o sensor DHT22 e classifica a temperatura em três faixas, acionando LEDs.
// Integrantes: Gustavo Cordeiro Braga, Murilo Justino Arcanjo, Rafael Quattrer Dalla Costa

#include "DHT.h"

// Definições do sensor DHT
#define DHTPIN 15         // Pino do ESP32 conectado ao DHT22
#define DHTTYPE DHT22     // Tipo do sensor (pode ser DHT11 ou DHT22)

DHT dht(DHTPIN, DHTTYPE);

// LEDs de indicação
const int LED_BAIXO   = 25;  // LED azul  - temperatura baixa
const int LED_MEDIO   = 26;  // LED verde - temperatura confortável
const int LED_ALTO    = 27;  // LED vermelho - temperatura alta

// Limiares de temperatura (em °C)
const float LIMIAR_BAIXO = 20.0;
const float LIMIAR_ALTO  = 27.0;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(LED_BAIXO, OUTPUT);
  pinMode(LED_MEDIO, OUTPUT);
  pinMode(LED_ALTO, OUTPUT);

  // Inicializa LEDs desligados
  digitalWrite(LED_BAIXO, LOW);
  digitalWrite(LED_MEDIO, LOW);
  digitalWrite(LED_ALTO, LOW);

  Serial.println("Iniciando Monitoramento Termo-Humidade...");
}

void loop() {
  // Lê umidade e temperatura (Celsius)
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  // Verifica se houve erro na leitura
  if (isnan(hum) || isnan(temp)) {
    Serial.println("Erro ao ler o sensor DHT!");
    delay(2000);
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" °C | Umidade: ");
  Serial.print(hum);
  Serial.print(" %");

  // Classifica a temperatura e aciona LEDs
  if (temp < LIMIAR_BAIXO) {
    // Temperatura baixa
    digitalWrite(LED_BAIXO, HIGH);
    digitalWrite(LED_MEDIO, LOW);
    digitalWrite(LED_ALTO, LOW);
    Serial.println(" | Faixa: BAIXA");
  } else if (temp <= LIMIAR_ALTO) {
    // Temperatura confortável
    digitalWrite(LED_BAIXO, LOW);
    digitalWrite(LED_MEDIO, HIGH);
    digitalWrite(LED_ALTO, LOW);
    Serial.println(" | Faixa: CONFORTÁVEL");
  } else {
    // Temperatura alta
    digitalWrite(LED_BAIXO, LOW);
    digitalWrite(LED_MEDIO, LOW);
    digitalWrite(LED_ALTO, HIGH);
    Serial.println(" | Faixa: ALTA");
  }

  delay(2000); // Espera 2 segundos antes da próxima leitura
}

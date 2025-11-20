// Projeto: Monitoramento de Energia Luminosa com ESP32 e LDR
// Repositório: Monitoramento-Energetico-ESP32_SERS_GS.2
// Integrantes: Gustavo Cordeiro Braga, Murilo Justino Arcanjo, Rafael Quattrer Dalla Costa

const int PINO_LDR   = 34;  // Entrada analógica do LDR (ADC1)
const int LED_BAIXO  = 25;  // LED vermelho  - baixa luminosidade
const int LED_MEDIO  = 26;  // LED amarelo   - luminosidade intermediária
const int LED_ALTO   = 27;  // LED verde     - alta luminosidade

// Limiares de classificação (podem ser ajustados conforme o ambiente)
const int LIMIAR_BAIXO = 1200;
const int LIMIAR_MEDIO = 2600;

void setup() {
  Serial.begin(115200);

  pinMode(LED_BAIXO, OUTPUT);
  pinMode(LED_MEDIO, OUTPUT);
  pinMode(LED_ALTO, OUTPUT);

  // Garante que todos os LEDs comecem apagados
  digitalWrite(LED_BAIXO, LOW);
  digitalWrite(LED_MEDIO, LOW);
  digitalWrite(LED_ALTO, LOW);

  Serial.println("Sistema de Monitoramento de Energia Luminosa - Iniciado");
}

void loop() {
  // Leitura do valor analógico do LDR
  int valorLDR = analogRead(PINO_LDR);

  Serial.print("Leitura LDR: ");
  Serial.print(valorLDR);

  // Classificação do nível de luminosidade
  if (valorLDR < LIMIAR_BAIXO) {
    // Nível baixo de luz
    digitalWrite(LED_BAIXO, HIGH);
    digitalWrite(LED_MEDIO, LOW);
    digitalWrite(LED_ALTO, LOW);
    Serial.println(" | Nível: BAIXO");
  } else if (valorLDR < LIMIAR_MEDIO) {
    // Nível intermediário
    digitalWrite(LED_BAIXO, LOW);
    digitalWrite(LED_MEDIO, HIGH);
    digitalWrite(LED_ALTO, LOW);
    Serial.println(" | Nível: MÉDIO");
  } else {
    // Nível alto de luminosidade
    digitalWrite(LED_BAIXO, LOW);
    digitalWrite(LED_MEDIO, LOW);
    digitalWrite(LED_ALTO, HIGH);
    Serial.println(" | Nível: ALTO");
  }

  delay(500); // Pausa para facilitar a leitura no Serial Monitor
}

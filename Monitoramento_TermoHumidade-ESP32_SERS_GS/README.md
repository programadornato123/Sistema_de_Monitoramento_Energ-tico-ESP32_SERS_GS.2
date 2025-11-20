# Monitoramento Termo-Humidade com ESP32 – SERS GS

## Integrantes

Gustavo Cordeiro Braga – RM: 562247  
Murilo Justino Arcanjo – RM: 565470  
Rafael Quattrer Dalla Costa – RM: 562052  

---

## 1. Introdução

O controle de temperatura e umidade em ambientes internos é crucial para o conforto humano, a conservação de equipamentos e a eficiência energética. As variações térmicas influenciam diretamente o consumo de climatização, enquanto a umidade inadequada pode deteriorar materiais e comprometer a saúde.  

Este projeto apresenta um sistema embarcado baseado no microcontrolador **ESP32** e no sensor **DHT22**, capaz de medir **temperatura** e **umidade relativa** do ar em tempo real. A proposta demonstra como plataformas de Internet das Coisas (IoT) podem ser empregadas para desenvolver soluções acessíveis de monitoramento ambiental, promovendo ambientes mais sustentáveis.

---

## 2. Componentes Utilizados

- **ESP32 DevKit V1** – microcontrolador Wi-Fi/Bluetooth responsável pelo processamento das leituras.  
- **Sensor DHT22** – sensor digital que mede temperatura e umidade com boa precisão.  
- **3 LEDs indicadores** – representando níveis de temperatura:  
  - **Azul** → Temperatura baixa (ex.: abaixo de 20 °C)  
  - **Verde** → Temperatura confortável (20–27 °C)  
  - **Vermelho** → Temperatura elevada (acima de 27 °C)  
- **Resistores de 220 Ω** para os LEDs.  
- **Jumpers e protoboard**.  
- **Ambiente de simulação Wokwi**.

---

## 3. Dados Coletados

O sistema coleta, a cada intervalo definido, os valores de **temperatura** (em graus Celsius) e **umidade relativa** (%) fornecidos pelo DHT22.  
O ESP32 converte esses dados em leituras digitais e aplica uma lógica de classificação sobre a temperatura para acionar os LEDs.

**Fonte dos dados:** leituras em tempo real realizadas pelo sensor DHT22.

---

## 4. Objetivo do Sistema

- **Monitorar continuamente a temperatura e a umidade** de um ambiente interno.
- **Identificar condições de temperatura baixa, confortável ou alta**, utilizando LEDs como indicadores visuais.
- **Demonstrar a aplicação de IoT** em cenários de gestão ambiental e eficiência energética.

---

## 5. Funcionamento

1. O sensor DHT22 é consultado periodicamente pelo ESP32 para obter a temperatura e a umidade.  
2. O valor de temperatura é comparado com dois limiares pré-definidos (20 °C e 27 °C).  
3. Dependendo da faixa de temperatura, um dos LEDs é acionado:  
   - **Azul** → temperatura baixa.  
   - **Verde** → temperatura confortável.  
   - **Vermelho** → temperatura elevada.  
4. A temperatura e a umidade lidas, bem como a classificação da faixa térmica, são impressas no **Serial Monitor**.  
5. O sistema funciona tanto em simulação (Wokwi) quanto em um dispositivo ESP32 real.

---

## 6. Código do Projeto

O código principal está em:

```
/ codigo / termo_humidade_esp32.ino
```

Ele realiza:

- Inicialização do sensor DHT22.  
- Leitura periódica de temperatura e umidade.  
- Classificação da temperatura em três faixas.  
- Acionamento dos LEDs correspondentes.  
- Impressão dos valores e da faixa no Serial Monitor.

---

## 7. Simulação no Wokwi

A pasta `simulacao` contém:

- `diagram.json` – descrição do circuito (ESP32, DHT22, LEDs) para importação no Wokwi.  
- `serial_monitor` – exemplo de saída do Serial Monitor.

### Como executar a simulação:

1. Acesse **https://wokwi.com** e crie um projeto baseado em ESP32.  
2. No editor do Wokwi, importe o conteúdo de `diagram.json` para montar o circuito.  
3. Copie o código de `termo_humidade_esp32.ino` para o editor de código do Wokwi.  
4. Clique em **Run** para iniciar a simulação.  
5. Observe a leitura de temperatura e umidade e o acendimento dos LEDs de acordo com a classificação.

---

## 8. Execução no Dispositivo Real

1. Abra o arquivo `.ino` no **Arduino IDE** ou **PlatformIO**.  
2. Selecione a placa **ESP32 DevKit V1**.  
3. Instale a biblioteca **DHT sensor library** (if needed).  
4. Conecte o sensor DHT22 ao ESP32:  
   - **VCC** → 3.3 V  
   - **DATA** → GPIO 15 (ou outro definido no código)  
   - **GND** → GND  
5. Conecte os LEDs aos GPIOs indicados no código (com resistores apropriados).  
6. Faça o upload do código para a placa.  
7. Abra o Serial Monitor em **115200 baud** e observe as leituras de temperatura e umidade, bem como o LED que é acionado.

---

## 9. Conexão com o Futuro do Trabalho

O monitoramento inteligente de condições ambientais é uma tendência nas estratégias de sustentabilidade corporativa.  
Ambientes com controle adequado de temperatura e umidade contribuem para a **eficiência energética**, reduzem custos de climatização e melhoram o bem-estar das pessoas.  
O uso de **microcontroladores como o ESP32** e **sensores ambientais** permite coletar dados precisos, acionando sistemas de automação ou emitindo alertas, integrando-se a plataformas de **smart building** e **climatização inteligente**.  

Ao adotar tecnologias IoT para acompanhar parâmetros como temperatura e umidade, empresas podem otimizar o uso de recursos, melhorar a qualidade do ambiente de trabalho e alinhar-se a práticas de responsabilidade ambiental, pilares fundamentais do futuro do trabalho.

---

## 10. Conclusão

Este projeto propõe e implementa um sistema de monitoramento termo‑humidímetro baseado em ESP32 e sensor DHT22.  
A solução demonstra, de maneira simples e eficaz, como é possível construir uma plataforma de IoT para acompanhar condições ambientais em tempo real, categorizar a temperatura em níveis críticos e fornecer feedback visual imediato.  

Embora seja um protótipo inicial, o projeto pode ser expandido para integrar interfaces web, armazenamento de dados em nuvem e algoritmos de controle automático de climatização, consolidando-se como um componente essencial de ambientes inteligentes e sustentáveis.

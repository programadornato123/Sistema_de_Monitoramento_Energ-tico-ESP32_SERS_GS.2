# Monitoramento-Energetico-ESP32_SERS_GS.2

## Integrantes

Gustavo Cordeiro Braga - RM: 562247  
Murilo Justino Arcanjo - RM: 565470  
Rafael Quattrer Dalla Costa - RM: 562052  

---

## Sistema de Monitoramento de Energia Luminosa com ESP32 + LDR

Este projeto apresenta um sistema de monitoramento de intensidade luminosa em ambientes internos, utilizando um microcontrolador **ESP32**, um sensor **LDR (Light Dependent Resistor)** e três LEDs indicadores (baixo, médio e alto).  

A proposta demonstra como tecnologias de **Internet das Coisas (IoT)** podem apoiar práticas de eficiência energética, permitindo identificar, em tempo real, situações de **iluminação insuficiente, adequada ou excessiva**.

---

## Dados Utilizados

O sistema utiliza dados de luminosidade coletados continuamente por um sensor LDR.  
O valor lido pelo conversor analógico-digital do ESP32, em uma faixa de **0 a 4095**, representa a quantidade de energia luminosa incidente sobre o sensor.

**Fonte dos dados:** medições diretas do sensor LDR conectado ao ESP32, em ambiente controlado ou real.

---

## Componentes Utilizados

- ESP32 DevKit V1  
- Sensor LDR  
- Resistores para montagem do divisor resistivo  
- 3 LEDs de indicação:
  - Vermelho → Nível de luminosidade baixo  
  - Amarelo → Nível intermediário  
  - Verde → Nível elevado  
- Resistores de 220 Ω para os LEDs  
- Ambiente de simulação **Wokwi**  

---

## Objetivo do Projeto

O objetivo central é **avaliar e interpretar o nível de energia luminosa** em um ambiente, explorando conceitos de IoT e automação para:

- Otimizar o uso de iluminação artificial;
- Identificar momentos de desperdício energético, quando há luz excessiva;
- Detectar situações de baixa luminosidade que possam prejudicar a execução de tarefas;
- Servir de base para sistemas mais complexos de automação voltados à sustentabilidade.

---

## Funcionamento da Solução

1. O sensor LDR capta a intensidade de luz presente no ambiente.
2. O ESP32 realiza a leitura analógica do valor do divisor de tensão.
3. O valor lido é classificado em três faixas de luminosidade:
   - **Baixa** → LED vermelho aceso  
   - **Média** → LED amarelo aceso  
   - **Alta** → LED verde aceso  
4. As medições e a respectiva classificação são exibidas em tempo real no **Serial Monitor**.
5. O sistema foi concebido para funcionar tanto em um **protótipo físico** quanto em simulação no **Wokwi**.

---

## Código do Projeto

O código principal do sistema está localizado em:

`/codigo/luminosidade_esp32.ino`

Ele implementa:

- Leitura periódica do valor analógico do LDR;
- Classificação da intensidade luminosa com base em limiares pré-definidos;
- Acionamento dos LEDs conforme o nível identificado;
- Impressão dos resultados (valor lido + nível categórico) no Serial Monitor.

---

## Simulação (Wokwi)

A pasta `/simulacao/` contém:

- `diagram.json` → descrição do circuito no Wokwi;  
- `serial_monitor` → exemplo de saída com as leituras e classificações.

### Como executar a simulação:

1. Acesse: **https://wokwi.com**  
2. Crie um novo projeto baseado em **ESP32**;
3. Importe o conteúdo de `diagram.json` para configurar o circuito;
4. Substitua o código padrão pelo conteúdo de `luminosidade_esp32.ino`;
5. Clique em **Run** (botão verde);
6. Ajuste o valor do LDR na interface do Wokwi;
7. Observe:
   - A mudança de estado dos LEDs;
   - A saída no Serial Monitor, indicando o nível de luminosidade.

---

## Execução em um ESP32 Real

1. Abra o arquivo `.ino` no **Arduino IDE** ou **PlatformIO**;  
2. Selecione a placa **ESP32 DevKit V1**;  
3. Conecte o ESP32 ao computador via USB;  
4. Faça o upload do código para a placa;  
5. Abra o **Serial Monitor** em **115200 baud**;  
6. Altere a luminosidade incidente sobre o LDR (por exemplo, cobrindo o sensor ou aproximando uma fonte de luz) e observe:
   - Qual LED é acionado;
   - As mensagens exibidas no Serial Monitor.

---

## Conexão com o Futuro do Trabalho

Em um cenário de crescente digitalização dos ambientes de trabalho, soluções de monitoramento e automação tornam-se fundamentais para a construção de espaços mais **eficientes, confortáveis e sustentáveis**. A iluminação é um dos componentes mais relevantes do consumo de energia em escritórios, laboratórios, indústrias e instituições de ensino.

Ao integrar um sensor LDR a um microcontrolador como o ESP32, este projeto ilustra:

- A viabilidade de sistemas de **monitoramento em tempo real**;
- A possibilidade de automação baseada em dados objetivos de luminosidade;
- O uso de tecnologias acessíveis como ponto de partida para **smart buildings** e gestão inteligente de recursos.

Tais iniciativas dialogam diretamente com o **futuro do trabalho**, no qual decisões relacionadas à infraestrutura física são apoiadas por dados, algoritmos e dispositivos conectados em rede.

---

## Conclusão

O projeto **Monitoramento-Energetico-ESP32_SERS_GS.2** demonstra, de maneira aplicada, como a combinação de sensores simples e plataformas de IoT pode contribuir para o desenvolvimento de soluções voltadas à sustentabilidade energética.  

Mesmo configurando um protótipo de baixa complexidade, o sistema:

- Evidencia o potencial da IoT para monitoramento contínuo de variáveis ambientais;
- Permite identificar padrões de uso da iluminação;
- Cria oportunidades para a implementação de rotinas automáticas de controle de carga.

Dessa forma, o trabalho reforça a importância de iniciativas tecnológicas que promovam o uso mais consciente dos recursos energéticos, alinhando-se às demandas contemporâneas de eficiência, responsabilidade ambiental e inovação no contexto do futuro do trabalho.

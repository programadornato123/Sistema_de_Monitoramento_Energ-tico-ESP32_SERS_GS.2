# Sistema_de_Monitoramento_Energético-ESP32_SERS_GS.2


## **Monitoramento de Energia Luminosa com ESP32 e Sensor LDR**

### **Integrantes**

* **Luiz Miguel Martin Crocco - RM: 562796**
* **Rafael Louzã Lopes - RM: 564963**
---

## **1. Introdução**

O monitoramento da intensidade luminosa em ambientes internos constitui uma etapa fundamental para o desenvolvimento de soluções voltadas à eficiência energética. A adequação dos níveis de iluminação impacta diretamente o conforto visual, o consumo elétrico e a qualidade das atividades laborais. Nesse contexto, este projeto apresenta um sistema embarcado baseado no microcontrolador **ESP32**, empregando um sensor **LDR (Light Dependent Resistor)** para mensurar variações de luminosidade e interpretar essas medições em tempo real.

A proposta visa demonstrar, por meio de uma arquitetura simples e de baixo custo, como dispositivos IoT podem apoiar estratégias de gestão inteligente de energia, especialmente em ambientes corporativos, produtivos ou educativos.

---

## **2. Materiais Utilizados**

* ESP32 DevKit (modelo padrão)
* Sensor LDR para detecção de intensidade luminosa
* Resistores para montagem do divisor de tensão
* Três LEDs indicadores

  * Vermelho: baixa luminosidade
  * Amarelo: luminosidade intermediária
  * Verde: alta luminosidade
* Resistores de 220 Ω para proteção dos LEDs
* Ambiente de simulação **Wokwi**

---

## **3. Descrição dos Dados**

As medições utilizadas neste sistema são obtidas diretamente do sensor LDR, cujo comportamento resistivo varia conforme a quantidade de luz incidente. O ESP32 realiza leituras analógicas (intervalo de 0 a 4095) que são convertidas em níveis categóricos de iluminação. Tais registros permitem avaliar, de forma contínua, o comportamento da luminosidade no ambiente monitorado.

**Fonte dos dados:** leituras em tempo real provenientes do sensor LDR conectado ao microcontrolador.

---

## **4. Objetivo do Sistema**

O projeto tem como finalidade:

* **Analisar o nível de energia luminosa disponível no ambiente;**
* **Identificar potenciais situações de desperdício ou insuficiência de iluminação;**
* **Fornecer um modelo inicial para sistemas de automação voltados à redução de consumo energético.**

Ao traduzir o valor analógico em três faixas interpretativas (baixa, média e alta luminosidade), a solução cria uma base objetiva para tomadas de decisão e futuras melhorias arquiteturais.

---

## **5. Funcionamento da Solução**

O funcionamento do sistema segue as etapas:

1. O sensor LDR registra a intensidade da luz no ambiente.
2. O ESP32 realiza a leitura analógica do valor proveniente do divisor resistivo.
3. O microcontrolador categoriza o nível de luminosidade em três classes:

   * **Baixa** → LED vermelho aceso
   * **Moderada** → LED amarelo aceso
   * **Elevada** → LED verde aceso
4. As informações são exibidas no Serial Monitor, possibilitando análise em tempo real.

A arquitetura foi validada tanto em ambiente simulado quanto em um dispositivo ESP32 físico.

---

## **6. Código-Fonte**

O código responsável pelo processamento está localizado em:

> `/codigo/luminosidade_esp32.ino`

Ele contempla:

* Leitura analógica contínua
* Definição dos intervalos de luminosidade
* Acionamento dos LEDs conforme a classificação
* Registro dos valores no terminal serial

---

## **7. Simulação no Wokwi**

A pasta `/simulacao/` contém:

* `serial_monitor`
* `diagram.json`

Para executar:

1. Acesse **[https://wokwi.com](https://wokwi.com)**
2. Abra o projeto correspondente
3. Inicie a simulação
4. Ajuste o valor do sensor LDR na interface
5. Observe a reação dos LEDs e a leitura no monitor serial

---

## **8. Execução no Dispositivo Físico**

1. Abra o arquivo `.ino` no Arduino IDE ou PlatformIO
2. Selecione a placa **ESP32 DevKit V1**
3. Compile e faça o upload
4. Configure o Serial Monitor em **115200 baud**
5. Varie a luminosidade e observe os indicadores

---

## **9. Relação com o Futuro do Trabalho**

A crescente digitalização dos ambientes laborais reforça a importância de mecanismos automáticos de monitoramento e gestão de recursos. A iluminação, apesar de parecer um elemento trivial, é um dos componentes mais relevantes dos gastos energéticos em empresas, instituições de ensino e setores industriais.

O uso combinado de sensores e microcontroladores, como o LDR e o ESP32, oferece uma alternativa acessível para o desenvolvimento de sistemas de controle baseados em dados. A partir dessas medições, é possível:

* Implementar rotinas automáticas que ajustem a iluminação conforme a necessidade real;
* Reduzir custos operacionais e impactos ambientais;
* Incrementar o conforto visual e a ergonomia dos colaboradores;
* Integrar informações com plataformas mais amplas de smart buildings;
* Criar soluções educacionais e protótipos em IoT para o contexto do futuro do trabalho.

Esse tipo de monitoramento ilustra como tecnologias emergentes podem transformar práticas cotidianas em iniciativas sustentáveis e eficientes.

---

## **10. Conclusão**

O sistema desenvolvido demonstra, de maneira objetiva e prática, que a aplicação de microcontroladores e sensores simples é suficiente para estabelecer uma estrutura eficiente de acompanhamento da energia luminosa em ambientes internos. A análise contínua dos níveis de iluminação contribui tanto para a redução de desperdícios quanto para melhorias na experiência dos usuários.

Embora se trate de uma solução introdutória, sua escalabilidade é evidente: ela pode ser expandida para sistemas integrados de automação predial, conectada a fontes de energia renovável ou adaptada para processos industriais. Desse modo, o projeto evidencia o papel crucial da Internet das Coisas na construção de espaços mais inteligentes, sustentáveis e alinhados às demandas do futuro do trabalho.



# Sistema de Detecção Precoce de Incêndios Florestais Utilizando IoT

Este projeto apresenta um sistema inovador de **monitoramento e detecção precoce de incêndios florestais**, utilizando tecnologias de **Internet das Coisas (IoT)** para fornecer uma solução eficiente, escalável e integrada. O sistema combina sensores, processamento de dados em tempo real para identificar condições críticas de incêndio em florestas. Com foco na preservação ambiental e alinhado aos Objetivos de Desenvolvimento Sustentável (ODS), a solução visa mitigar danos ambientais, proteger a biodiversidade e apoiar respostas rápidas a incêndios, utilizando tecnologias modernas de baixo custo e alto impacto.

## 📂 Estrutura do Repositório

- **`sketch.ino`**: Código fonte do ESP32 para leitura de sensores e publicação dos dados no MQTT.
- **`diagram.json`**: Configuração do circuito simulado no Wokwi.
- **`libraries.txt`**: Lista de bibliotecas necessárias para o projeto.
- **`flows.json`**: Código fonte do Node-RED

## 📋 Descrição do Projeto

O sistema utiliza tecnologias de **Internet das Coisas (IoT)** para integrar sensores, processamento de dados e visualização. As principais funcionalidades incluem:

- **Monitoramento de Temperatura e Fumaça**: Sensores IoT coletam dados ambientais em tempo real.
- **Transmissão via MQTT**: Protocolo de comunicação para envio eficiente dos dados ao sistema.
- **Processamento no Node-RED**: Plataforma *low-code* utilizada para análise e integração de dados.
- **Armazenamento na Nuvem**: Banco de dados InfluxDB para registro histórico dos dados.
- **Dashboards no Grafana**: Visualização interativa e alertas automáticos para condições críticas.

## 🚀 Tecnologias Utilizadas

As tecnologias empregadas neste projeto incluem:

- **[Node-RED](https://nodered.org/)**: Para processamento e automação de dados.
- **[MQTT](https://mqtt.org/)**: Protocolo de mensagens para dispositivos IoT.
- **[InfluxDB](https://www.influxdata.com/)**: Banco de dados de séries temporais.
- **[Grafana](https://grafana.com/)**: Ferramenta de visualização e monitoramento.
- **[Wokwi](https://wokwi.com/)**: Simulador para prototipagem de circuitos IoT.

## 🌍 Objetivo e Impacto

Este sistema está alinhado aos **Objetivos de Desenvolvimento Sustentável (ODS)** da ONU, especialmente o **ODS 15**: **"Proteger, recuperar e promover o uso sustentável dos ecossistemas terrestres"**. 

Ao identificar incêndios florestais precocemente, o sistema contribui para:

- Preservação da biodiversidade.
- Redução de impactos ambientais severos.
- Apoio ao manejo sustentável de florestas.

- ## 🛠️ Configuração

1. **Bibliotecas Necessárias**  
   As seguintes bibliotecas devem ser instaladas no Arduino IDE:
   - [DHT sensor library for ESPx](https://www.arduinolibraries.info/libraries/dht-sensor-library-for-es-px)
   - [PubSubClient](https://www.arduinolibraries.info/libraries/pub-sub-client)
   - [WiFi](https://www.arduinolibraries.info/libraries/wi-fi)

2. **Configuração no Wokwi**  
   Utilize o arquivo `diagram.json` para carregar o circuito no [Wokwi](https://wokwi.com).

3. **Configuração MQTT**  
   - Broker: `broker.hivemq.com`  
   - Porta: `1883`  
   - Tópicos:
     - Temperatura: `projetoMonitoramento/Temperatura`
     - Umidade: `projetoMonitoramento/Umidade`

## 👩‍💻 Equipe

- **Isabella Akemi Kato**  
  - Email: [10409153@mackenzista.com](mailto:10409153@mackenzista.com)
- **Júlia Monteiro**  
  - Email: [10400678@mackenzista.com.br](mailto:10400678@mackenzista.com.br)
- **Natan Angelotti**  
  - Email: [10401990@mackenzista.com.br](mailto:10401990@mackenzista.com.br)
- **Nicole Previd**  
  - Email: [10409002@mackenzista.com.br](mailto:10409002@mackenzista.com.br)


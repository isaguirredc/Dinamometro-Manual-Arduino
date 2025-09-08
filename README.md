# Dinamômetro Digital com Visualização Web

Projeto desenvolvido para medição de peso utilizando **célula de carga (HX711)**, Arduino e uma interface web em **HTML/JS** para visualização em tempo real.

---

## Descrição

O sistema lê o peso de uma célula de carga conectada ao Arduino, envia os dados via **porta serial** para um arquivo `.txt` e exibe o valor em um **velocímetro digital** em uma página web.
O projeto permite visualizar o peso em **tempo real**, com atualização automática a cada 200 ms.

---

## Funcionalidades

* Ler peso usando HX711 e Arduino
* Calibrar a célula de carga com fator de calibração ajustável
* Zerar a balança automaticamente (Tare)
* Enviar valores via porta serial para um arquivo `peso.txt`
* Visualizar o peso em uma interface web com **personalizada**
* Atualização do valor em tempo real (a cada 200 ms)

---

## Estrutura do Projeto

```
├── Arduino
│   └── dinamometro.ino      # Código Arduino para leitura do HX711
├── Web
│   └── index.html           # Interface web do velocímetro
├── Python
│   └── le_peso.py     # Leitura da porta serial e gravação em peso.txt
└── peso.txt                 # Arquivo gerado com o valor do peso
```

---

## Requisitos

* **Arduino Uno/Nano** com **HX711** e célula de carga
* **Python 3** para script de leitura serial
* Navegador moderno para acessar a interface web
* Conexão do Arduino na porta correta (`/dev/ttyACM0` ou equivalente no Windows)

---

## Como Executar

1. **Carregar código Arduino** (`dinamometro.ino`) no Arduino.
2. Conectar a célula de carga ao Arduino conforme pinos configurados (`DOUT = 4`, `SCK = 5`).
3. Executar o script Python para ler a porta serial e atualizar o arquivo `peso.txt`:

   ```bash
   python le_peso.py
   ```
4. Abrir `index.html` em um navegador para visualizar o velocímetro em tempo real.

---

## Responsável

**Isadora Aguirre Dal Conte** — RA: **1136123**


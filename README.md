
# Face Detection and Emotion Analysis with ESP32CAM


Este projeto demonstra a implementação de um sistema de visão computacional em tempo real utilizando a placa ESP32-CAM. A câmera captura imagens, que são processadas para:
- detectar rostos,
- analisar as emoções expressas. 
- Comparar a semlhança entre rostos. 

O sistema é capaz de identificar as principais emoções humanas, como felicidade, tristeza, surpresa e raiva. E comparar o rosto capturado com um rosto de 'referencia'. 




## Stack utilizada

**Hardware:** Esp32-CAM, Modulo conversor serial FDTI, protoboard e jumpers

**Back-end:** Pyhton


## Principais Bibliotecas



```http
  Open-CV
```

| Instalação|
| :---------- |
| `#!pip install opencv-python` |

```http
 Deepface 
```

| Instalação|
| :---------- |
| `#!pip install deepface opencv-python` |

#### add (haarcascade_frontalface_alt2.xml)

Baixar arquivo do repositório - https://github.com/opencv/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml


## Ligação do ESP32-CAM

![ESP32](https://blog.eletrogate.com/wp-content/uploads/2022/01/Setup_programar-1024x634.png) <img src="/assets/WhatsApp Image 2024-11-18 at 15.57.47.jpg">


## Demonstração - Detecção de Rostos

O código realiza a captura de vídeo em tempo real a partir de um stream fornecido por um ESP32-CAM, detecta rostos no vídeo usando o Haar Cascade, e exibe os resultados. Lendo cada frame em um loop contínuo e convertendo para escala de cinza, necessário para a detecção. Os rostos são identificados com detectMultiScale, que retorna as coordenadas dos rostos detectados, sobre os quais são desenhados retângulos.

- - O método detectMultiScale é uma função do OpenCV usada para detectar objetos em uma imagem (como rostos, olhos, corpos, etc.) com base em classificadores pré-treinados, como o Haar Cascade ou LBP (Local Binary Patterns). É amplamente utilizado para detectar múltiplas instâncias de um objeto em imagens ou vídeos.

<img src="/assets/2024-11-18 15-25-22.gif">



## Demonstração - Analise de Sentimentos 

Este código realiza a captura de vídeo em tempo real de uma câmera ESP32-CAM para detectar e exibir emoções faciais utilizando a biblioteca DeepFace e o OpenCV. Ele funciona da seguinte forma:

 - cv2: Para manipulação de vídeo e imagem.
 - DeepFace: Para análise facial, como a detecção de emoções.

 - DeepFace.analyze: Este método analisa uma imagem (neste caso, o frame do vídeo) para identificar características faciais, como emoções, idade, gênero, ou raça, dependendo das ações especificadas.
 - O DeepFace é uma biblioteca de código aberto para análise facial em Python.

A emoção predominante é extraída e exibida diretamente sobre o vídeo com cv2.putText, posicionado na tela com fonte verde.

## DIFICULDADE: Dependência de boas imagens: Para obter resultados precisos, o DeepFace precisa de boas imagens ou vídeos com rostos bem iluminados e claramente visíveis. O que é muito dificil com o esp32.

<img src="/assets/gif-emoções.gif">

Exemplo com imagem estática: 

<img src="/assets/imagem-estaatica.png">



## Demonstração - Comparação de Rostos

O código detecta rostos no stream de vídeo, calcula embeddings em tempo real e compara cada rosto detectado com uma imagem de referência. A similaridade é exibida diretamente no vídeo. Este é um exemplo de aplicação prática de reconhecimento facial em tempo real.

- Embedding: Representação numérica (vetor) do rosto, extraída pelo modelo VGG-Face.
  
### Características do VGG-Face:
#### 1. Arquitetura de Rede:
  - O VGG-Face é baseado na arquitetura VGG16, que foi originalmente desenvolvida para tarefas de classificação de imagens. O "16" no nome se refere ao número de camadas da rede.
  - VGG16 consiste em 13 camadas convolucionais e 3 camadas totalmente conectadas.
  - A arquitetura foi projetada para ser simples e profunda, o que ajuda a capturar padrões mais complexos nas imagens.
 
#### 2. Treinamento:
O VGG-Face foi treinado com um grande conjunto de dados de rostos humanos, utilizando mais de 2,6 milhões de imagens de 2.622 pessoas diferentes. Durante o treinamento, o modelo aprendeu a extrair características faciais únicas e representações vetoriais de rostos (também conhecidas como embeddings). A ideia é que cada rosto tenha um vetor único (embedding) que representa suas características faciais, o que permite a comparação e a identificação de pessoas.

  
- Converte o frame para escala de cinza, que é necessário para a detecção de rostos.
- face_cascade.detectMultiScale: Detecta rostos no frame usando o Haar Cascade.
  
- Parâmetros:
 - - scaleFactor=1.1: Reduz a imagem para detectar rostos de diferentes tamanhos.
 - - minNeighbors=5: Número de vizinhos necessários para validar uma detecção.
 - - minSize=(50, 50): Tamanho mínimo dos rostos detectados.
     
- Extrai a região de interesse (ROI) correspondente ao rosto detectado e compara o embedding do rosto detectado com o embedding da imagem de referência.
-  ### obs: quanto mais perto de 0 a distância entre os embeddings, maior a similaridade entre os rostos.
- DeepFace.verify retorna uma distância (quanto menor, maior a semelhança).
  
- cv2.putText: Adiciona a similaridade no vídeo.
- cv2.rectangle: Desenha um retângulo ao redor do rosto.
- Exibe o frame processado com os resultados.
  


<img src="/assets/comparacao.gif">






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

<img src="/assets/2024-11-18 15-25-22.gif">



## Demonstração - Analise de Sentimentos 

Gif demonstração de reconhecimento de emoções. 

Dificuldade é que a biblioteca funciona melhor com arquivos estáticos, sendo assim, em videos ela "analisa" muito rapido as emoções, entao cada micro mudança como piscar, muda a analise. 

<img src="/assets/gif-emoções.gif">

Exemplo com imagem estática: 

<img src="/assets/imagem-estaatica.png">




## Demonstração - Comparação de Rostos

O código detecta rostos no stream de vídeo, calcula embeddings em tempo real e compara cada rosto detectado com uma imagem de referência. A similaridade é exibida diretamente no vídeo. Este é um exemplo de aplicação prática de reconhecimento facial em tempo real.



- Embedding: Representação numérica (vetor) do rosto, extraída pelo modelo VGG-Face.
  
- A função DeepFace.represent converte a imagem de referência em um embedding. Esse embedding será usado para comparação posterior.
- Redimensiona o frame para facilitar o processamento.
  
- Converte o frame para escala de cinza, que é necessário para a detecção de rostos.
- face_cascade.detectMultiScale: Detecta rostos no frame usando o Haar Cascade.
  
- Parâmetros:
 - - scaleFactor=1.1: Reduz a imagem para detectar rostos de diferentes tamanhos.
 - - minNeighbors=5: Número de vizinhos necessários para validar uma detecção.
 - - minSize=(50, 50): Tamanho mínimo dos rostos detectados.
     
- Extrai a região de interesse (ROI) correspondente ao rosto detectado.
- compara o embedding do rosto detectado com o embedding da imagem de referência.
- DeepFace.verify retorna uma distância (quanto menor, maior a semelhança).
  
- cv2.putText: Adiciona a similaridade no vídeo.
- cv2.rectangle: Desenha um retângulo ao redor do rosto.
- Exibe o frame processado com os resultados.
  
 ### obs: quanto mais perto de 0 a distância entre os embeddings, maior a similaridade entre os rostos.

<img src="/assets/comparacao.gif">

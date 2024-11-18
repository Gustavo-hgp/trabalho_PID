
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

![ESP32](https://blog.eletrogate.com/wp-content/uploads/2022/01/Setup_programar-1024x634.png)


## Demonstração - Analise de Sentimentos 

Gif demonstração de reconhecimento de emoções. 

Dificuldade é que a biblioteca funciona melhor com arquivos estaticos, sendo assim, em videos ela "analisa" muito rapido as emoções, entao cada micro mudança como piscar, muda a analise. 

<img src="/assets/gif-emoções.gif">

Exeemplo imagem estatica: 

<img src="/assets/imagem-estaatica.png">


## Demonstração - Detectção de Rostos

<img src="/assets/gif-emoções.gif">


#include <WiFi.h>
#include <HTTPClient.h>

// Configurações do Wi-Fi
const char* ssid = "Seu_SSID";
const char* password = "Sua_Senha";

void setup() {
  Serial.begin(115200);

  // Conecta ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi");

  // Exemplo de requisição GET
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://httpbin.org/get"); // URL do servidor
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Erro na requisição GET: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }

  // Exemplo de requisição POST
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://httpbin.org/post"); // URL do servidor
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST("value=12345");

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Erro na requisição POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}

void loop() {
  // Nada necessário aqui
}

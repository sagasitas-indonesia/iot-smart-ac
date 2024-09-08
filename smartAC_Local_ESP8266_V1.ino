//Code for ESP8266(NodeMCU V3) Board

#include <ESP8266WiFi.h>

#define relay_on HIGH
#define relay_off LOW

const char* ssid = "YourWiFiSSID";//type your ssid (nama WiFi)
const char* password = "YourWiFiPassword";//type your password (password WiFi)

IPAddress staticIP(192, 168, 8, 11); // IP Addres stasit untuk arduino (sesuaikan dengan gateway)
IPAddress gateway(192, 168, 8, 1); // Gateway atau IP Router
IPAddress subnet(255, 255, 255, 0);

int relPin = 2; //D4
WiFiServer server(80);

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 1000;

void setup() {
    Serial.begin(9600);
    delay(10);

    pinMode(relPin, OUTPUT);
    digitalWrite(relPin, relay_off);

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.mode(WIFI_STA);
    WiFi.setSleepMode(WIFI_NONE_SLEEP);
    WiFi.config(staticIP, subnet, gateway);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi terhubung");

    server.begin();
    Serial.println("Server started...");
    Serial.print("Gunakan URL berikut untuk membuka panel : ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
}

void loop() {
    WiFiClient client = server.available();
    if (!client) {
        return;
    }
    Serial.println("new client");

    currentTime = millis();
    previousTime = currentTime;
    while (!client.available()) {
        currentTime = millis();
        delay(10);
        if (currentTime - previousTime >= timeoutTime) {
            Serial.println("Timeout");
            return;
        }
    }

    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    String sts = "mati";
    if (request.indexOf("/AC=ON") != -1) {
        digitalWrite(relPin, relay_on);
        sts = "nyala";
    }
    if (request.indexOf("/AC=OFF") != -1) {
        digitalWrite(relPin, relay_off);
        sts = "mati";
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); // Jangan lupakan yang satu ini
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<meta charset=\"utf-8\">");
    client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
    client.println("<link href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" rel=\"stylesheet\">");
    client.println("<title>Control AC</title>");
    client.println("</head>");
    client.println("<body class=\"container mt-4\">");

    client.println("<h1 class=\"text-center\">Control AC</h1>");
    client.print("<p class=\"lead text-center\">Status AC: ");
    if (sts == "nyala") {
        client.print("<span class=\"text-success\">Nyala</span>");
    } else {
        client.print("<span class=\"text-danger\">Mati</span>");
    }
    client.println("</p>");

    client.println("<div class=\"text-center\">");
    if (sts == "nyala") {
        // Jika AC nyala, tombol akan berwarna hijau dan berfungsi untuk mematikan
        client.println("<a href=\"/AC=OFF\" class=\"btn btn-danger\">Matikan AC</a>");
    } else {
        // Jika AC mati, tombol akan berwarna merah dan berfungsi untuk menyalakan
        client.println("<a href=\"/AC=ON\" class=\"btn btn-success\">Nyalakan AC</a>");
    }
    client.println("</div>");

    client.println("</body>");
    client.println("</html>");

    delay(1);
    Serial.println("Client disconnected");
    Serial.println("");

}

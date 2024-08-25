#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebUI.h>

const char* ssid = "****";
const char* password = "****";

ESP8266WebServer server(80);

Page firstpage("first");
Page secondpage("second");

void first();
void second();

void setup(){
    Serial.begin(9600);
    Serial.println();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED){
        Serial.println("Trying to connect...");
        delay(500);
    }
    Serial.println("Connected successful!");

    server.on("/1", first);
    server.on("/2", second);
    server.begin();
    Serial.print("Server started on ");
    Serial.println(WiFi.localIP());

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);

    firstpage.getBlocks()->addHeader("This is first page");
    Block testblock;
    firstpage.getBlocks()->addBlock(testblock.addButton("Go 2", "/2")->addButton("Go 1", "/1", true)->addButton("Go 1", "/1", true));
    Block testblock2;
    testblock2.addButton("1", "", true)->addButtonCancel("2", "", true)->addButtonConfirm("3", "", true)->addButtonNoStyle("4", "", true);

    secondpage.getBlocks()->addHeader("This is second page");
    secondpage.getBlocks()->addBlock(&testblock)->addHeader("Block 2")->addBlock(&testblock2)->addBlock(&testblock2);
}

void loop(){
    server.handleClient();
}

void first(){
    server.send(200, "text/html", firstpage.getPageHtml());
}
void second(){
    server.send(200, "text/html", secondpage.getPageHtml());
}

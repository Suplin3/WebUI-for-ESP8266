#pragma once
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

class Block {
    private:
    String _html;
    public:
    Block* addButtonNoStyle(String textButton, String location, bool HalfButton = false){
        String html = "<button class=\"";
        html += HalfButton ? "halfbutton" : "fullbutton";
        html += "\" name=\"no-style\" onclick=\"window.location = '";
        html += location;
        html += "'\">";
        html += textButton;
        html += "</button>";
        _html += html;
        return this;
    }
    Block* addButton(String textButton, String location, bool HalfButton = false){
        String html = "<button class=\"";
        html += HalfButton ? "halfbutton" : "fullbutton";
        html += "\" name=\"simple\" style=\"background-color: rgb(69, 69, 69); border-radius: 4px; border-color: rgb(185, 182, 182); border-width: 1px; color: rgb(185, 182, 182); font-weight: bold; cursor: pointer;\" onclick=\"window.location = '";
        html += location;
        html += "'\">";
        html += textButton;
        html += "</button>";
        _html += html;
        return this;
    }
    Block* addButtonConfirm(String textButton, String location, bool HalfButton = false){
        String html = "<button class=\"";
        html += HalfButton ? "halfbutton" : "fullbutton";
        html += "\" name=\"confirm\" style=\"background-color: greenyellow; border-radius: 4px; border-color: green; border-width: 2px; color: green; font-weight: bold; cursor: pointer;\" onclick=\"window.location = '";
        html += location;
        html += "'\">";
        html += textButton;
        html += "</button>";
        _html += html;
        return this;
    }
    Block* addButtonCancel(String textButton, String location, bool HalfButton = false){
        String html = "<button class=\"";
        html += HalfButton ? "halfbutton" : "fullbutton";
        html += "\" name=\"cancel\" style=\"background-color: red; border-radius: 4px; border-color: darkred; border-width: 2px; color: white; font-weight: bold; cursor: pointer;\" onclick=\"window.location = '";
        html += location;
        html += "'\">";
        html += textButton;
        html += "</button>";
        _html += html;
        return this;
    }
    String getHtml(){
        String html = "<div style=\"background-color: rgba(128, 128, 128, 0.219); border-radius: 10px; padding: 10px; margin-top: 10px;\">";
        html += _html;
        html += "</div>";
        return html;
    }
};

class Blocks {
    private:
    String _html;
    public:
    Blocks* addHeader(String header) {
        String html = "<h1 style='text-align: center; margin-bottom: 3px; color: white;'>";
        html += header;
        html += "</h1><br>";
        _html += html;
        return this;
    }
    Blocks* addBlock(Block* block){
        _html += block->getHtml();
        return this;
    }

    String getHtml(){
        return _html;
    }
};

class Page {
    private:
    Blocks _blocks;
    String _html;
    String _title;
    public:
    Page(String title = "Page"){
        _title = title;
    }

    String getPageHtml(){
        _html = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>";
        _html += _title;
        _html += "</title><style>body{padding: 0;background-color: rgb(37, 37, 37);}button{ margin-bottom: 5px;height: 30px;font-size: medium;transition: 1s;}button:hover{font-size: small;}.halfbutton{width: 50%;}.fullbutton{width: 100%;}#Footer{margin-top: 20px;border-top: white solid 4px;color:white;font-size: larger;padding: 50px;height: 100%;background-color: rgba(137, 43, 226, 0.174);}</style></head><body>";
        _html += _blocks.getHtml();
        _html +=  "<footer id='Footer'>&copy 2024<br>Designed by Suplin3</footer></body></html>";
        return _html;
    }

    Blocks* getBlocks(){
        return &_blocks;
    }
};

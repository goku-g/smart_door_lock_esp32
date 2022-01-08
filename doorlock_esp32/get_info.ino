void getInfo() {
  
//  camera_fb_t * fb = NULL;
//  fb = esp_camera_fb_get();
//  if(!fb) {
//    Serial.println("Camera capture failed");
//    delay(1000);
//    ESP.restart();
//  }

String header = "";

  if(client.connect(serverName.c_str(), serverPort)){
    header = httpGETRequest(serverName);
    Serial.print("c value: ");
    Serial.print(header);
    Serial.println("");

    
  
    if (header.indexOf("GET /capture/true") >= 0){
      Serial.println("worked");
    }
//    if (header.indexOf("GET /capture")){
//      Serial.println("true");
//    }
  }
  
  
}

String httpGETRequest(String serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

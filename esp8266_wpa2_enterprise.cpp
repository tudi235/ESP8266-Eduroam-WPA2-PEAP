#include <ESP8266WiFi.h>
#include <c_types.h>
#include <user_interface.h>
#include <wpa2_enterprise.h>

//fill with network data here

char ssid[] = "your ssid";
char username[] = "your username";
char identity[] = "same as above";
char password[] = "your password";


void setup() {
  Serial.begin(115200);
  delay(1000);
  
  wifi_set_opmode(0x01);
  struct station_config wifi_config;
  memset(&wifi_config, 0, sizeof(wifi_config));
  strcpy((char*)wifi_config.ssid, ssid);
  strcpy((char*)wifi_config.password, password);
  wifi_station_set_config(&wifi_config);
  wifi_station_set_wpa2_enterprise_auth(1);
  wifi_station_clear_cert_key();
  wifi_station_clear_enterprise_ca_cert();
  wifi_station_clear_enterprise_identity();
  wifi_station_clear_enterprise_username();
  wifi_station_clear_enterprise_password();
  //wifi_station_set_enterprise_ca_cert(ca_cert, sizeof(ca_cert));  		//uncomment if not connecting without certificate
  wifi_station_set_enterprise_identity((uint8*)identity, strlen(identity));
  wifi_station_set_enterprise_username((uint8*)username, strlen(username));
  wifi_station_set_enterprise_password((uint8*)password, strlen(password));
  //wifi_station_set_enterprise_ca_cert(ca_pem, ca_pem_len);			//uncomment if not connecting without certificate
  wifi_station_connect();

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.print("*");
  }

  Serial.println("");
  Serial.println("WIFI CONNECTED!");
  Serial.print("IP ADDRESS: ");
  Serial.println(WiFi.localIP());
}

void loop(){
//put your code here
}

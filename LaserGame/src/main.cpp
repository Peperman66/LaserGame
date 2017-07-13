#include <LearningKit.h>
#include <vector>

int currentPhoto = analogRead(PHOTO);
int previousPhoto = currentPhoto;
int target;

void setup() {
  setupLeds();
  ledcSetup(0, 1000, 10); ledcAttachPin(L_R, 0);
  setupButtons();
  Serial.begin(115200);
  while (digitalRead(SW1)==true) {
    for(int i = 0; i<1024; i++){
      Serial.println(analogRead(PHOTO));
      ledcWrite(0, i);
      delay(1);
    }
    for(int i = 1023; i>-1; i--) {
      Serial.println(analogRead(PHOTO));
      ledcWrite(0, i);
      delay(1);
    }
  }
  target = analogRead(PHOTO);

  std::vector<int> pole;
  // pole.push_back(12);
  // int x = pole[0];
  // pole[0] = 42;
  // pole.resize(100);
}



void loop() {
  currentPhoto = analogRead(PHOTO);
  if (currentPhoto >= target) {
    digitalWrite(L_Y, HIGH);
    delay(5000);
    digitalWrite(L_Y, LOW);
  }
  previousPhoto=currentPhoto;
  Serial.println(currentPhoto);
}

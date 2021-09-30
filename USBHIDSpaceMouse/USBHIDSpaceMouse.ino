// Read 3Dconnection SpaceMouse values

#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>
#include "hidspacenavigatorrptparser.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
SpaceNavigatorEvent SpaceNavigatorEvent;
SpaceNavigatorReportParser SpaceNavigator(&SpaceNavigatorEvent);

void setup() {
  Serial.begin(115200);

  if (Usb.Init() == -1) {
    Serial.println("OSC did not start.");
  }
  delay(200);
  if (!Hid.SetReportParser(0, &SpaceNavigator)) {
    ErrorMessage<uint8_t > (PSTR("SetReportParser"), 1);
  }
}

void loop() {
  Usb.Task();
  printSpaceNavigatorValues();
}

void printSpaceNavigatorValues() {
  SpaceNavigatorEvent.getSpaceMouseValues();
  Serial.print(SpaceNavigatorEvent.Tx);
  Serial.print("\t");
  Serial.print(SpaceNavigatorEvent.Ty);
  Serial.print("\t");
  Serial.print(SpaceNavigatorEvent.Tz);
  Serial.print("\t");
  Serial.print(SpaceNavigatorEvent.Rx);
  Serial.print("\t");
  Serial.print(SpaceNavigatorEvent.Ry);
  Serial.print("\t");
  Serial.print(SpaceNavigatorEvent.Rz);
  Serial.print("\t");
  Serial.println(SpaceNavigatorEvent.Bb);
}

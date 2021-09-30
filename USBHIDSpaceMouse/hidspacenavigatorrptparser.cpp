#include "hidspacenavigatorrptparser.h"
SpaceNavigatorReportParser::SpaceNavigatorReportParser(SpaceNavigatorEvent *evt) :
  spaceNavigatorEvent(evt)
{
}

void SpaceNavigatorReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
  // Calling SpaceNavigator event handler
  spaceNavigatorEvent->OnSpaceNavigatorChanged((const SpaceNavigatorEventData*)buf);
}

void SpaceNavigatorEvent::OnSpaceNavigatorChanged(const SpaceNavigatorEventData *evt) {

  // Translation vector
  if (evt->rptid == 1) {
    Tx = evt->xl + (evt->xh << 8);
    Ty = evt->yl + (evt->yh << 8);
    Tz = evt->zl + (evt->zh << 8);
  }

  // Rotation vector
  else if (evt->rptid == 2) {
    Rx = evt->yl + (evt->yh << 8);
    Ry = evt->xl + (evt->xh << 8);
    Rz = evt->zl + (evt->zh << 8);
  }

  // Buttons
  else if (evt->rptid == 3) {
    Bb = evt->xl;
  }
}

void SpaceNavigatorEvent::OnButton(uint8_t but_id) {
}

void SpaceNavigatorEvent::getSpaceMouseValues() {
}

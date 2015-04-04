#include <VirtualWire.h>

void setup() {
	vw_set_ptt_inverted(true);
	vw_set_rx_pin(12);
	vw_setup(4000); // speed of data transfer Kbps
	vw_rx_start(); // Start the receiver PLL running

	pinMode(13, OUTPUT);
}

void loop() {
	uint8_t buf[VW_MAX_MESSAGE_LEN];
	uint8_t buflen = VW_MAX_MESSAGE_LEN;

	if (vw_get_message(buf, &buflen))
	{
		if (buf[0] == 'O') {
			digitalWrite(13, HIGH);
		}
		if (buf[0] == 'X') {
			digitalWrite(13, LOW);
		}
	}
}

#include <VirtualWire.h>

char *controller;

void setup() {
	pinMode(13, OUTPUT);

	vw_set_ptt_inverted(true);
	vw_set_tx_pin(12);
	vw_setup(4000); // speed of data transfer Kbps
}

void loop() {
	controller = "O";
	vw_send((uint8_t *)controller, strlen(controller));
	vw_wait_tx(); // Wait until the whole message is gone

	digitalWrite(13, 1);
	delay(2000);

	controller = "X";
	vw_send((uint8_t *)controller, strlen(controller));
	vw_wait_tx(); // Wait until the whole message is gone

	digitalWrite(13, 0);
	delay(2000);
}

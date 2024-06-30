from gpiozero import LED
import time

RED = LED(16)
YELLOW = LED(18)
GREEN = LED(17)
while(1) :
    RED.on()
    time.sleep(3)
    RED.off()
    YELLOW.on()
    time.sleep(2)
    YELLOW.off()
    GREEN.on()
    time.sleep(3)
    GREEN.off()

import Adafruit_DHT
import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
sensor = Adafruit_DHT.DHT11
pin = 23
while True:
    humidity, temprature = Adafruit_DHT.read_retry(sensor, pin)
    if humidity is None and temprature is None:
        print("Failed")
    else:
        print("temp={0:0.1f}%C Humidity={0:0.1f}%".format(temprature,humidity))
        
    time.sleep(1)
              
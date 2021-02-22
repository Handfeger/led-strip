#include <FastLED.h>
#include <SPI.h>
#include <wifi.h>

// TODO mqtt

#define LED_PIN     7
#define NUM_LEDS    100
#define DELAY       1000

CRGB leds[NUM_LEDS];

void reset() {
    for(int i=0; i<NUM_LEDS; i++) {
        leds[i] = CRGB(0,0,0);
    }
}

void error() {
    Serial.println("error");
    int error_delay(20);
    reset();
    for(int i=0;i<5;i++) {
        for(int i=0; i<NUM_LEDS; i++) {
            leds[i] = CRGB(255,0,0);
        }
        FastLED.show();
        delay(error_delay);
        reset();
        FastLED.show();
        delay(error_delay);
    }
}

void do_n(int n, CRGB power, int every = 1) {
    if(n*every >= NUM_LEDS) {
        return error();
    }

    for(int i=0; i<n; i++) {
        leds[i*every] = CRGB(power,power,power);
    }
    FastLED.show();
}

void do_n_white(int n, int power, int every = 1) {
    do_n(n,CRGB(power,power,power),every);
}

void do_n_full(int n, int every = 1) {
    do_n_white(n, 255, every);
}

void only_one() {
    do_n_full(1);
}

void little_light() {
    for(int i=0; i<NUM_LEDS; i++) {
        leds[i] = CRGB(255,255,255);
        FastLED.show();
        delay(DELAY);
    }
    delay(10000);
    for(int i=0; i<NUM_LEDS; i++) {
        leds[i] = CRGB(0,0,0);
        FastLED.show();
        delay(DELAY);
    }
    FastLED.show();
}

void setup() {
    Serial.begin(9600);
    while (!Serial) {}

    establish_wifi();


    // put your setup code here, to run once:
    CFastLED::addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    reset();
}

void test1() {
    int power = 255;
    do_n_full(19);
    delay(DELAY);
    reset();
    do_n_full(19,2);
    delay(DELAY);
    reset();
    do_n_full(19,3);
    delay(DELAY);
    reset();
    do_n_full(19,4);
    delay(DELAY);
    reset();
    do_n_full(19,5);
    delay(DELAY);
    reset();
}

void loop() {
    test1();
}
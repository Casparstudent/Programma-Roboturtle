/********************************************************************************
* Namen:                    Caspar, Hiljan, Bart, Dylan en Robin
* Datum:                    18 juni 2025
* Versie:                   v1.0
* Microcontroller           NUCLEO-F411RE
*********************************************************************************
* Programma Roboturtle
*
********************************************************************************/

#include "mbed.h"

// PWM-uitgangen -  motor A en B
PwmOut ena(D6), enb(D10);

// Richtingscontrole motor A en B
DigitalOut in1(D4), in2(D5), in3(D8), in4(D9);

// Infrarood lijnsensor
DigitalIn irSensor(D2);

// Ultrasone sensoren: trig/echo links, rechts, onder
DigitalOut trigLinks(D3), trigRechts(D7), trigOnder(PB_1);
DigitalIn echoLinks(D12), echoRechts(D11), echoOnder(PB_2);

// Timer afstandsmeting
Timer timer;

// Instelbare parameters
const float vooruit_snelheid = 0.5f;      // Motor snelheid standaard
const int draaitijd_ms = 200;             // AANPASSEN NAAR DUUR DRAAI
const int vooruit_tijd_ms = 2000;         // Tijd vooruitrijden na een bocht
const float obstakel_drempel_cm = 10.0;   // Minimale afstand voor obstakel
const float afgrond_drempel_cm = 5.0;     // Maximale afstand voor geen afgrond

// Functie afstand meten
float meetAfstand(DigitalOut& trig, DigitalIn& echo) {
    trig = 0;
    wait_us(2);
    trig = 1;
    wait_us(10);
    trig = 0;

    while (echo == 0);
    timer.reset();
    timer.start();
    while (echo == 1);
    timer.stop();

    float tijd_us = timer.elapsed_time().count();
    return tijd_us / 58.0f;
}

// Vooruit
void motorenVooruit(float snelheid) {
    in1 = 1; in2 = 0; ena.write(snelheid);
    in3 = 1; in4 = 0; enb.write(snelheid);
}

// Achteruit
void motorenAchteruit(float snelheid) {
    in1 = 0; in2 = 1; ena.write(snelheid);
    in3 = 0; in4 = 1; enb.write(snelheid);
}

// Stoppen
void stopMotoren() {
    ena.write(0);
    enb.write(0);
}

// Functie draai links
void draaiLinks(int graden) {
    in1 = 0; in2 = 1;
    in3 = 1; in4 = 0;
    ena.write(vooruit_snelheid);
    enb.write(vooruit_snelheid);
    ThisThread::sleep_for(graden * draaitijd_ms);
    stopMotoren();
}

// Functie draai rechts
void draaiRechts(int graden) {
    in1 = 1; in2 = 0;
    in3 = 0; in4 = 1;
    ena.write(vooruit_snelheid);
    enb.write(vooruit_snelheid);
    ThisThread::sleep_for(graden * draaitijd_ms);
    stopMotoren();
}

// Functie 180 graden om
void draai180() {
    draaiLinks(18);
}

// Hooft loop
int main() {
    ena.period(0.001);
    enb.period(0.001);
    timer.start();

    while (true) {
        // Meet afstanden van sensoren
        float afstandLinks = meetAfstand(trigLinks, echoLinks);
        float afstandRechts = meetAfstand(trigRechts, echoRechts);
        float afstandOnder = meetAfstand(trigOnder, echoOnder);
        int zwart = irSensor.read();

        // Controleer afgrond:
        if (afstandOnder > afgrond_drempel_cm) {
            draaiLinks(1);
            continue;
        }

        // Detecteer zwarte lijn: draai 180 graden
        if (zwart == 0) {
            stopMotoren();
            draai180();
            motorenVooruit(vooruit_snelheid);
            ThisThread::sleep_for(vooruit_tijd_ms);
            continue;
        }

        // Obstructie links: draai rechts
        if (afstandLinks < obstakel_drempel_cm) {
            draaiRechts(1);
            motorenVooruit(vooruit_snelheid);
            ThisThread::sleep_for(vooruit_tijd_ms);
            draaiLinks(1);
            continue;
        }

        // Obstructie rechts: draai links 
        if (afstandRechts < obstakel_drempel_cm) {
            draaiLinks(1);
            motorenVooruit(vooruit_snelheid);
            ThisThread::sleep_for(vooruit_tijd_ms);
            draaiRechts(1);
            continue;
        }

        // Normaal rijden
        motorenVooruit(vooruit_snelheid);
    }
}
/* 
 * File:   main-projfinal.c
 * Author: Maria Clara Martins Santana
 *2020012227
 */

#include <pic18f4520.h>
#include "config.h"
#include "bits.h"
#include "lcd.h"
#include "keypad.h"
#include "ssd.h"
#include "pwm.h"



#define L0  0x80
#define L1  0xC0 //defines para as linhas 
#define L2  0x90

int tempo; //variavel para delay

void tela(int op) {
    int i;

    char msg[15] = "   ";

    lcdCommand(L0);
    for (i = 0; i < 15; i++) {
        lcdData(msg[i]);
    }

    lcdCommand(L1);
    for (i = 0; i < 15; i++) {
        lcdData(msg[i]);
    }

    lcdCommand(L2);
    for (i = 0; i < 15; i++) {
        lcdData(msg[i]);
    }

    if (op == 6) { //tela desligada
        char msg[15] = "* - On/Off";
        lcdCommand(L0); //primeira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg[i]);
        }
    }

    if (op == 0) { //tela padrao
        char msg[15] = "Escolha direcao";
        lcdCommand(L0); //primeira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg[i]);
        }

        char msg2[15] = "1-Frente/2-Tras";
        lcdCommand(L1); //segunda linha
        for (i = 0; i < 15; i++) {
            lcdData(msg2[i]);
        }
        char msg3[15] = "4-Left/5-Right";
        lcdCommand(L2); //terceira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg3[i]);
        }
    }

    if (op == 1) {
        char msg[15] = "Frente...";
        lcdCommand(L0); //primeira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg[i]);
        }
    }
    
    if (op == 2) {
        char msg[15] = "Tras...";
        lcdCommand(L0); //primeira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg[i]);
        }
    }
    
    if (op == 4) {
        char msg[15] = "Esquerda...";
        lcdCommand(L0); //primeira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg[i]);
        }
    }
    
    if (op == 5) {
        char msg[15] = "Direita...";
        lcdCommand(L0); //primeira linha
        for (i = 0; i < 15; i++) {
            lcdData(msg[i]);
        }
    }
    
}


void direction(int d) {

    if (d == 0) // parado
        PORTB = 0x00;

    if (d == 1) //frente
        PORTB = 0x10;

    if (d == 2) // tras
        PORTB = 0x80;

    if (d == 4) //esquerda
        PORTB = 0xC0;

    if (d == 5) //direita
        PORTB = 0x30;

    if (d == 6) { //Liga
        PORTB = 0xF0;
        for (tempo = 0; tempo < 10000; tempo++);
        for (tempo = 0; tempo < 5000; tempo++);
        for (tempo = 0; tempo < 5000; tempo++);

        PORTB = 0xA0;
        for (tempo = 0; tempo < 5000; tempo++);
        for (tempo = 0; tempo < 5000; tempo++);
        for (tempo = 0; tempo < 5000; tempo++);

        PORTB = ~PORTB;
        for (tempo = 0; tempo < 5000; tempo++);
        for (tempo = 0; tempo < 5000; tempo++);
        for (tempo = 0; tempo < 5000; tempo++);

        PORTB = 0x00;
    }

}

void charge(int bat) {
    ssdDigit((bat % 10), 3);
    ssdDigit(((bat / 10) % 10), 2);
    ssdDigit(((bat / 100) % 10), 1);
    ssdUpdate();
}

void main(void) {

    int temp; //temporaria para auxiliar nas teclas
    int bateria = 100;
    unsigned char tecla; //guarda a tecla

    TRISB = 0x00; //configurado como saida para exibir as luzes
    PORTB = 0x00;
    
    kpInit();
    ssdInit();
    pwmInit();
    
    int i = 1; //variaveis de controle
    int j = 2;
    int m = 4;
    int n = 5;
    int p = 6;
    
    unsigned char v1 = 99; //frente
    unsigned char v2 = 85; //lados
    unsigned char v3 = 70; //tras

    lcdInit();
    
    tela(6);
    charge(bateria);
    
    for (;;) {
        kpDebounce();
        tecla = kpRead();
        charge(bateria); //atualiza a cada laco

        if (kpRead() != temp) {
            temp = kpRead();

            if (bitTst(tecla, 0)) { // tecla * - Liga/Desliga
                if (p == 6) {
                    direction(6);
                    tela(0);
                }
                if (p == -6) {
                    tela(6);
                    pwmSet(0);
                }
                p *= -1;
            }

            if (bitTst(tecla, 3)) { // tecla 1 - Frente
                if (i == 1) {
                    tela(1);
                    direction(1);
                    pwmSet(v1);
                }
                if (i == -1) {
                    tela(0);
                    direction(0);
                    pwmSet(0);
                }
                
                i *= -1;
            }

            if (bitTst(tecla, 7)) { // tecla 2 - Tras

                if (j == 2) {
                    tela(2);
                    direction(2);
                    pwmSet(v3);
                }
                if (j == -2) {
                    tela(0);
                    direction(0);
                    pwmSet(0);
                }
                
                
                j *= -1;
            }

            if (bitTst(tecla, 2)) { // tecla 4 - Esquerda

                if (m == 4) {
                    tela(4);
                    direction(4);
                    pwmSet(v2);
                }
                if (m == -4) {
                    tela(0);
                    direction(0);
                    pwmSet(0);
                }
                
                
                m *= -1;
            }

            if (bitTst(tecla, 6)) { // tecla 5 - Direita

                if (n == 5) {
                    tela(5);
                    direction(5);
                    pwmSet(v2);
                }
                if (n == -5) {
                    tela(0);
                    direction(0);
                    pwmSet(0);
                }
               
                
                n *= -1;
            }
            
            bateria = bateria - 2; //a cada comando, eh gasto 2 porcento de bateria
            if (bitTst(tecla, 4)) { //tecla 0
                bateria = 102;
            }


        }
        if (bateria == 0) { //caso bateria zere, para de funcionar
            for (;;);
        }

        for (tempo = 0; tempo < 5; tempo++); //delay

    }

}

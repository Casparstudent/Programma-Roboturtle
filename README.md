# Programma-Roboturtle

Programma alléén geschikt voor Nucleo F411-RE

Uitvoeren in Mbed

Downloaden via deze website: https://os.mbed.com/

1. Klik op Overview > Development tools Mbed Studio (Download the desktop IDE for Mbed OS)
2. Klik op de Download for Windows knop, en volg de installatieprocedure.
3. Ga naar menu Help > Check for tools updates... en klik op de knop "update" als dat aan de orde is.

Download eerst de Nucleo F411-RE drivers:

1. Ga naar de Mbed website, en klik op Hardware > Boards, en zoek op NUCLEO.
2. Scroll naar de tegel met de NUCLEO-F411RE, en klik daar op. (Hier staat tevens informatie over de poorten)
3. Gebruik de zoekfunctie in de browser (ctrl-F) en zoek met "ST-LINK" tot er een geel vak staat. Daarin staat een link naar twee drivers die geïnstalleerd moeten worden.
  1. ST LINK DRIVER: volg de installatieinstructie om de file STSW -LINK009 te downloaden.
  Voer 'dpinst_amd64.exe' uit.
  2. Nucleo Firmware: volg de installatieinstructie om de file STSW -LINK007 te downloaden en te installeren.

Open het programma in Github:
1. Klik op de knop: Import into Compiler > Import into Mbed Studio, en kopieer de link.
2. Open Mbed Studio, en ga naar menu File > Import Program... en plak daar de gekopieerde link in het veld URL

Na het importeren en het verbinden van de Nucleo zou het programma moeten compileren en uitvoeren.

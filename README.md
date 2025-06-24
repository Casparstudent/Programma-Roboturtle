# Programma-Roboturtle

Programma alléén geschikt voor Nucleo F411-RE

Uitvoeren in Mbed

Downloaden via deze website: https://os.mbed.com/

1. Klik op Overview > Development tools Mbed Studio (Download the desktop IDE for Mbed OS)
2. Klik op de Download for Windows knop, en volg de installatieprocedure.
3. Ga naar menu Help > Check for tools updates... en klik op de knop "update" als dat aan de orde is.

Download eerst de Nucleo F411-RE drivers:

1. Ga naar de Mbed website, en klik op Hardware > Boards, en zoek op NUCLEO.
2. Scroll naar de tegel met de NUCLEO-F411RE, en klik daar op. (je vindt daar ook diverse informatie over de pinning)
3. Gebruik de zoekfunctie in jouw browser (ctrl-F) en zoek met "ST-LINK" tot je een geel vak vindt. Daarin staat een link naar twee drivers die je moet installeren.
  1. ST LINK DRIVER (deze software wordt op jouw laptop geinstalleerd)
  volg de installatieinstructie om de file STSW -LINK009 te downloaden.
  Run dpinst_amd64.exe.
  2. Nucleo Firmware (deze software wordt op jouw bordje geinstalleerd)
  volg de installatieinstructie om de file STSW -LINK007 te downloaden en te installeren.

Open het programma in Github:
1. Klik op de knop: Import into Compiler > Import into Mbed Studio, en kopieer de link.
2. Open Mbed Studio, en ga naar menu File > Import Program... en paste daar de gekopieerde link in het veld URL

Na het importeren en het verbinden van de Nucleo zou het programma moeten compileren en uitvoeren.

# Hőmérsékletfigyelő állomás
Arduino alapú hőmérsékletfigyelő rendszer, TinkerCAD környezetben megvalósítva.

A projekt célja a környezeti hőmérséklet mérése és annak többféle módon történő megjelenítése.

A rendszer a mért hőmérsékleti adatokat valós időben dolgozza fel, majd különböző kimeneteken jeleníti meg:
- LCD kijelzőn a pontos hőmérsékleti értéket
- állapotjelző LED-ekkel a hőmérsékleti tartományt
- NeoPixel gyűrűn vizuális formában
- indítási animációval a rendszer inicializálásakor

## Funkciók
- valós idejű hőmérsékletmérés
- több szintű állapotjelzés
- vizuális megjelenítés NeoPixel gyűrűvel
- LCD alapú adatmegjelenítés
- rendszerindítási animáció
- soros monitoros naplózás hibakereséshez

## Hőmérsékleti kategóriák
- **Hideg** (0–15 °C)
- **Normál** (16–25 °C)
- **Meleg** (26–32 °C)
- **Forró** (33 °C felett)

## Felhasznált alkatrészek
- Arduino Uno
- TMP36 hőmérsékletérzékelő
- 16x2 LCD kijelző
- 4 db LED
- 4 db 220 Ω ellenállás
- NeoPixel LED gyűrű (12 LED)
- Breadboard
- Jumper kábelek

## Bekötési áttekintés

### TMP36

- bal láb → 5V
- középső láb → A0
- jobb láb → GND

### LCD kijelző
- RS → D12
- E → D11
- DB4 → D5
- DB5 → D4
- DB6 → D3
- DB7 → D2
- VCC → 5V
- GND → GND
- RW → GND
- VO → GND

### Állapotjelző LED-ek
- Hideg → D6
- Normál → D7
- Meleg → D8
- Forró → D9

### NeoPixel gyűrű
- PWR → 5V
- GND → GND
- IN → D10

## Projektstruktúra
├── README.md
├── docs/
│   └── projekt-dokumentacio.pdf
└── src/
    └── homersekletfigyelo.ino

## TinkerCAD szimuláció

[Időjárás állomás LED-es kijelzővel](https://www.tinkercad.com/things/etK4Lkb7zCh-idojaras-allomas-led-es-kijelzovel?sharecode=r5AeXdDxQIYc_wAjrZIVBkJIgDoyPJw8N4ff7F-3e4M)

## Dokumentáció

A részletes dokumentáció az alábbi helyen található:

```text
docs/projekt-dokumentacio.pdf
```

## Készítette
Baki László

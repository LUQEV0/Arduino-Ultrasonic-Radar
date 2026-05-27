# Digitális Technika II. - Projektfeladat

## Mikrovezérlő Alapú Ultrahangos Radarrendszer Tervezése és Szimulációja

**Készítette:** Bóta Richárd  
**Neptun kód:** LUQEV0  
**Intézmény:** Neumann János Egyetem, Kecskemét (GAMF Kar)  
**Oktatók:** Drenyovszki Rajmund / Zsupányi Krisztián  

---

## Projekt leírása
Ez a projekt a *Digitális Technika II.* tantárgy kötelező mérföldköveként készült. A rendszer egy autonóm működésű, ultrahangos elven alapuló térpásztázó és távolságmérő berendezés (radar) digitális prototípusa, amely képes a környezetében lévő objektumok pozíciójának (szög és távolság) valós idejű meghatározására. 

Ha egy tárgy vagy akadály a kritikusan közeli, 30 cm-es biztonsági zónán belülre kerül, a rendszer automatikusan működésbe hoz egy piezoelektromos zümmögőt, amely hangjelzéssel figyelmeztet a veszélyre.

## Online Szimuláció és Megtekintés
A projekt teljes áramköri kapcsolása élőben, interaktívan tesztelhető és futtatható az alábbi linken keresztül:

[Kattints ide a Tinkercad szimuláció megnyitásához](https://www.tinkercad.com/things/kqoTpWcmc6V/editel?sharecode=j5SMH6y1zif73bByqfuOXZFj2KxN5QAXiDZNcgQh94U)

*(Megjegyzés: A szimuláció elindítása után kattints az ultrahangos szenzorra a Tinkercad asztalán, és a megjelenő zöld pötty mozgatásával tesztelheted az akadályok érzékelését és a riasztási funkciót!)*

## A repozitórium (tárhely) felépítése
- `/src/radar_code.ino`: A teljes, tiszta C++ nyelven íródott, részletesen, magyar nyelven kommentelt működtető forráskód.
- `projekt_dokumentacio_Bota_Richard_LUQEV0.pdf`: A hivatalos tanszéki követelményeknek megfelelően összeállított, 12 oldalas részletes mérnöki dokumentáció (tartalmazza a matematikai számításokat, a hardverek leírását, a huzalozási jegyzéket és a tesztelési jegyzőkönyvet).

## Felhasznált hardverkomponensek (Tinkercad Circuits)
1. **Arduino Uno R3** mikrokontroller fejlesztőkártya (ATmega328P)
2. **HC-SR04** Ultrahangos távolságmérő szenzor
3. **TowerPro SG90** Micro Servo motor (a pásztázó mozgáshoz)
4. **Piezoelektromos zümmögő** (Buzzer - az akusztikus vészjelzéshez)

---
*Nyilatkozat: A projekt a hallgató önálló munkájának eredménye, a felhasznált külső források és könyvtárak jegyzéke a csatolt PDF dokumentációban hiánytalanul megtalálható.*

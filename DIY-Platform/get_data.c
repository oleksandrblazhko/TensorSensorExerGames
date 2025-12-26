#include "HX711.h"

/* ---------------- ПІНИ ---------------- */
#define DT1 2
#define SCK1 3

#define DT2 4
#define SCK2 5

#define DT3 6
#define SCK3 7

#define DT4 8
#define SCK4 9

/* ---------------- HX711 ОБʼЄКТИ ---------------- */
HX711 scale1;
HX711 scale2;
HX711 scale3;
HX711 scale4;

/* ---------------- КАЛІБРУВАННЯ ----------------
   Значення ПРИКЛАДНІ!
   Потрібно підібрати індивідуально
*/
float CAL1 = -7050.0;
float CAL2 = -7050.0;
float CAL3 = -7050.0;
float CAL4 = -7050.0;

/* ---------------- РОЗМІРИ ПЛАТФОРМИ (мм) ---------------- */
float Lx = 500.0;   // ширина
float Ly = 300.0;   // глибина

void setup() {
  Serial.begin(9600);
  Serial.println("=== Balance Platform старт ===");

  scale1.begin(DT1, SCK1);
  scale2.begin(DT2, SCK2);
  scale3.begin(DT3, SCK3);
  scale4.begin(DT4, SCK4);

  scale1.set_scale(CAL1);
  scale2.set_scale(CAL2);
  scale3.set_scale(CAL3);
  scale4.set_scale(CAL4);

  scale1.tare();
  scale2.tare();
  scale3.tare();
  scale4.tare();

  Serial.println("Тарування завершено");
}

void loop() {

  float w1 = scale1.get_units(5);
  float w2 = scale2.get_units(5);
  float w3 = scale3.get_units(5);
  float w4 = scale4.get_units(5);

  float totalWeight = w1 + w2 + w3 + w4;

  /* ---- Центр маси ---- */
  float xCM = 0.0;
  float yCM = 0.0;

  if (totalWeight > 0.1) {
    xCM = (w2 * Lx + w4 * Lx) / totalWeight;
    yCM = (w3 * Ly + w4 * Ly) / totalWeight;
  }

  /* ---- Вивід ---- */
  Serial.println("----------------------------------");
  Serial.print("LC1 (FL): "); Serial.print(w1); Serial.println(" kg");
  Serial.print("LC2 (FR): "); Serial.print(w2); Serial.println(" kg");
  Serial.print("LC3 (BL): "); Serial.print(w3); Serial.println(" kg");
  Serial.print("LC4 (BR): "); Serial.print(w4); Serial.println(" kg");

  Serial.print("TOTAL: "); Serial.print(totalWeight); Serial.println(" kg");

  Serial.print("Center X: "); Serial.print(xCM); Serial.println(" mm");
  Serial.print("Center Y: "); Serial.print(yCM); Serial.println(" mm");

  delay(300);
}

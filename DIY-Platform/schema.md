                  ┌─────────────────────────┐
                  │   Balance Platform      │
                  │                         │
                  │  [Load Cell 1] (Front-Left) ──┐
                  │  [Load Cell 2] (Front-Right) ─┼─┐
                  │  [Load Cell 3] (Back-Left)  ──┤ │
                  │  [Load Cell 4] (Back-Right) ─┘ │
                  └─────────────────────────┘     │
                                                    │
         ┌───────────────────┐  ┌───────────────────┐
         │      HX711 #1      │  │      HX711 #2      │
         │  A+ ← White LC1    │  │  A+ ← White LC2    │
         │  A- ← Green LC1    │  │  A- ← Green LC2    │
         │  E+ ← Red LC1      │  │  E+ ← Red LC2      │
         │  E- ← Black LC1    │  │  E- ← Black LC2    │
         │  DT  → D2 Nano     │  │  DT  → D4 Nano     │
         │  SCK → D3 Nano     │  │  SCK → D5 Nano     │
         │  VCC → 5V Nano     │  │  VCC → 5V Nano     │
         │  GND → GND Nano    │  │  GND → GND Nano    │
         └───────────────────┘  └───────────────────┘
                  │                        │
         ┌───────────────────┐  ┌───────────────────┐
         │      HX711 #3      │  │      HX711 #4      │
         │  A+ ← White LC3    │  │  A+ ← White LC4    │
         │  A- ← Green LC3    │  │  A- ← Green LC4    │
         │  E+ ← Red LC3      │  │  E+ ← Red LC4      │
         │  E- ← Black LC3    │  │  E- ← Black LC4    │
         │  DT  → D6 Nano     │  │  DT  → D8 Nano     │
         │  SCK → D7 Nano     │  │  SCK → D9 Nano     │
         │  VCC → 5V Nano     │  │  VCC → 5V Nano     │
         │  GND → GND Nano    │  │  GND → GND Nano    │
         └───────────────────┘  └───────────────────┘

                             ┌────────────────┐
                             │ Arduino Nano   │
                             │                │
                             │ D2-D3 → HX711#1│
                             │ D4-D5 → HX711#2│
                             │ D6-D7 → HX711#3│
                             │ D8-D9 → HX711#4│
                             │ 5V / GND →     |
                             |VCC/GND         |
                             |всіх HX711      │
                             └────────────────┘

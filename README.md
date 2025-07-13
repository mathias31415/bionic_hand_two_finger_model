# bionic_hand_two_finger_model

This repository contains the outcomes of the project focused on developing a two-finger model of a bionic hand. The work was conducted by **Mathias Fuhrer, Tobias Klausmann, Jens Polzien, and Thomas Rapp** at **Hochschule Karlsruhe (H-KA**) during the summer semester of 2022.

<p align="center">
  <img src="/03_Doc/cad_asm_complete_1.png" alt="asm1" width="45%" />
  <img src="/03_Doc/cad_asm_complete_2.png" alt="asm2" width="45%" />
</p>

<p align="center">
  <img src="/03_Doc/asm_complete_1.png" alt="asm1" width="45%" />
  <img src="/03_Doc/asm_complete_2.png" alt="asm2" width="45%" />
</p>

## Demo video
TODO

## Bill of Materials – Purchased Components
| Description                      | Quantity | Manufacturer |
|----------------------------------|----------|--------------|
| Micro Servo BMS-101HV           | 6        | Bluebird     |
| Servo HS-40                     | 2        | Hitec        |
| Arduino Uno                     | 1        | Arduino      |
| Toggle switch                   | 1        | —            |
| Countersunk screw M2            | —        | —            |
| Cylinder head screw M3          | —        | —            |
| Perforated circuit board 70x30mm| 1        | —            |
| Barrel socket                   | 1        | —            |

## Bill of Materials – Additive Manufactured Parts
| Description                                    | Quantity | Manufacturing Method |
|------------------------------------------------|----------|----------------------|
| Joint1_top (Gelenk1_oben)                      | 2        | SLA                  |
| Joint1_bottom (Gelenk1_unten)                  | 2        | SLA                  |
| Link1_top (Glied1_oben)                        | 2        | SLA                  |
| Link1_bottom (Glied1_unten)                    | 2        | SLA                  |
| Link2_right (Glied2_rechts)                    | 2        | SLA                  |
| Link2_left (Glied2_links)                      | 2        | SLA                  |
| Link3_right (Glied3_rechts)                    | 2        | SLA                  |
| Link3_left (Glied3_links)                      | 2        | SLA                  |
| Spreader_servo_holder (Spreizen_servohalter)   | 2        | SLA                  |
| Palm_finger_holder (Mittelhand_Fingerhalter)   | 1        | FDM                  |
| Palm_bottom (Mittelhand_unten)                 | 1        | FDM                  |
| PCB_mount (Halter_Leiterplatte)                | 1        | FDM                  |
| Lid (Deckel)                                   | 1        | FDM                  |

## Servo Preparation for Finger Integration
| Work Step   | Tools        | Illustration   |
|-------------|--------------|---------|
| Three micro servos (Blue Bird - BMS 101DMG) for bending and one Hitec HS-40 for spreading must be modified.   | –                                                                                                       |   |
| Open the servo housing by removing the two screws. Keep them for reassembly. Remove the bottom cover.        | Screwdriver                                                                                              | ![img](/03_Doc/servo_prep_1.png)  |
| Remove ~5mm of the housing around the PCB to make space for the joint bearing. Cut off the mounting flanges. | Cutter knife, side cutter                                                                               | ![img](/03_Doc/servo_prep_2.png)  |
| Reinsert the screws until they are flush with the housing surface.                                            | Screwdriver                                                                                              | ![img](/03_Doc/servo_prep_3.png)  |
| Desolder the angle sensor (potentiometer) from the PCB. Carefully remove the PCB, which is now only attached to the motor wires. | Soldering iron, desoldering pump, desoldering braid, solder                                            | ![img](/03_Doc/servo_prep_4.png) |
| Extend motor wires of one servo by ~3 cm.                                                                 | Soldering iron, solder, wire extensions, heat shrink, heat gun, side cutter, wire stripper              | ![img](/03_Doc/servo_prep_5.png)  |
| Resolder the three angle sensor pins to the PCB using ~6cm long enameled copper wires.                       | Soldering iron, solder, side cutter, enameled copper wire                                                | ![img](/03_Doc/servo_prep_6.png)  |
| For the other two servos, resolder angle sensor with 4–5cm enameled copper wires; no motor wire extension needed. | Soldering iron, solder, side cutter, enameled copper wire, tweezers                                     | ![img](/03_Doc/servo_prep_7.png)  |
| Bend the angle sensor pins flat against the housing surface.                                                  | Tweezers                                                                                                 |   |
| Apply solder mask to protect solder joints from corrosion and shorts.                                         | Solder mask                                                                                              |  |
| For the Hitec HS-40, remove the glued bottom cover of the housing.                                            | Flat-nose pliers, cutter knife, etc.                                                                    | ![img](/03_Doc/servo_prep_8.png) |

## Assembly steps for building the finger

| Step | Tools | Illustration |
|-------|--------|--------------|
| First, the Blue Bird servo with extended motor and angle sensor cables must be installed into the middle finger segment. The circuit board is placed into the designated recess. The supply cable is routed through the slit to the outside. The two motor cables and three angle sensor cables must be placed in the intended cable guide. | Tweezers | ![img](/03_Doc/asm1.png) ![img](/03_Doc/asm2.png)  |
| The motor can now be slowly pushed into the finger segment as shown on the right. From the backside, through the hub opening, the circuit board and cables can be positioned with a tweezer. This is important so the servo can be fully inserted into the housing. Also ensure all excess cable lengths fit into the cavity of the circuit board. | Tweezers | ![img](/03_Doc/asm3.png) ![img](/03_Doc/asm4.png)  |
| The two remaining BMS 101 servos are installed in the base segment and positioned as shown in the picture on the right. The circuit board is placed on top of the servo and will be enclosed by the upper housing half. | Tweezers | ![img](/03_Doc/asm5.png) ![img](/03_Doc/asm6.png) |
| The housing top can now be attached. The servo cable in the middle segment must be routed through the base segment. Cables are arranged in the provided cable ducts. To allow bending of the middle finger joint, a loop must be placed in the designated gap as shown on the right. The housing top is then screwed down with an M2 countersunk screw. Ensure all motor ends are aligned on the same side when positioning the finger joints. | Screwdriver, Tweezers | ![img](/03_Doc/asm7.png) |
| The base and middle segments can be connected by attaching the second housing half of the middle segment. The halves are screwed together with an M2 countersunk screw. | Screwdriver, Tweezers | ![img](/03_Doc/asm8.png) |
| The housing halves of the end segment seen in the previous step can now also be installed and secured with an M2 countersunk screw. | Screwdriver | ![img](/03_Doc/asm9.png) |
| The Hitec HS-40 servo is inserted into the spreading mechanism and fastened with the supplied screws to the SLA part. | Screwdriver | ![img](/03_Doc/asm10.png) |
| This is the drive unit for the spreading function, which can now be connected to the rest of the finger. The last two SLA parts are assembled with two M2 countersunk screws. These two parts form the bearing for the bending function of the finger base joint as well as the spreading joint. The cables exiting the finger are routed through the designated cable channel. | Screwdriver | ![img](/03_Doc/asm11.png)  ![img](/03_Doc/asm12.png)  ![img](/03_Doc/asm13.png) |
| The power transmission from the four servos to the SLA parts is realized by a modified adapter supplied with the servos. The adapter must be adjusted as shown in the image. Only the gearwheel is needed, and material is removed in parallel on two opposite sides. | Cutter, Side cutters, Sandpaper, File | ![img](/03_Doc/asm14.png) |
| The modified adapters are pressed onto the servo shafts, creating a form-fit power transmission between the servo and the finger segment. Before pressing in the adapter, ensure the servo is in the correct end position. This can be easily done using a servo tester or control via Arduino, for example. If there is any play, a new adapter must be made with slightly less material removed on the sides. If the adapter doesn’t fit into the recess, more material can be removed using a file or knife. | Cutter, Side cutters, Sandpaper, File | ![img](/03_Doc/asm15.png) ![img](/03_Doc/asm16.png) ![img](/03_Doc/asm17.png)|
| The above steps are then repeated for the second finger. The two fingers are then fastened to the Arduino and power supply housing. The power supply and Arduino board are also installed in the housing. Servo cables can be routed through the provided openings into the housing and connected with appropriate pins and power supply. Servo cables may need to be extended if necessary. | Soldering iron, Hot air gun, Tweezers, Screwdriver |  |
| The Arduino can then be programmed via the USB port placed on the outside. | USB cable, Programmer, Arduino software |  |

## Schematic
![img](/03_Doc/schematic.png)
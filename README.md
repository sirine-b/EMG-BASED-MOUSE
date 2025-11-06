# EMG-Based Mouse

## Overview
This project demonstrates the design and implementation of a mouse with **3 degrees of freedom (DOF)** controlled via **surface EMG signals**, aimed at assisting people with an amputated hand. The system allows the user to perform the following actions by contracting specific muscles:

- **Left Click** – contraction of biceps  
- **Move Right** – contraction of brachioradialis  
- **Move Left** – contraction of flexor carpi radialis  

The EMG signals are captured via surface electrodes, processed through analog circuits for amplification, filtering, and rectification, and finally interpreted by an Arduino Leonardo to control mouse movements.

---

## EMG Signal Characteristics [see reference 1]

- **Frequency:** 0–500 Hz (usable energy: 50–150 Hz)  
- **Amplitude:** 0–10 mV (typical, amplified to Arduino 0–5 V range)  

**Muscles Used:**

| Muscle | Function |
|--------|----------|
| Biceps | Left Click |
| Brachioradialis | Move Right |
| Flexor Carpi Radialis | Move Left |

**Electrode Placement:** Bipolar electrodes placed along the midline of the muscle, 1–2 cm apart, with a reference on the elbow as shown on Figure 1.
<p align="center">
  <img src="https://github.com/user-attachments/assets/777ccefb-b3ae-4297-a7d8-b4abd3a39fa3" width="560" height="215" />
  <br>
  <b>Figure 1:</b> Bipolar electrodes configuration [see reference 2].
</p>

---

## Circuit Design

The analog signal processing circuit was designed to condition the EMG signal before Arduino input:

1. **Instrumentation Amplifier (INA126)** – initial amplification of weak EMG signals  
2. **Passive High-Pass Filter (50 Hz)** – removes low-frequency noise  
3. **Non-Inverting Amplifier** – further amplification, gain adjusted experimentally  
4. **Sallen-Key Low-Pass Filter (150 Hz)** – removes high-frequency noise  
5. **Active Full-Wave Rectifier** – converts signal to positive voltage compatible with Arduino  

> The order of blocks was adjusted during testing to eliminate signal offsets.

**Characterisation:** Each circuit block was tested using a myDAQ for voltage, frequency response, and gain, and results were verified using oscilloscope plots.

<p align="center">
  <img width="1748" height="1125" alt="image" src="https://github.com/user-attachments/assets/205194c7-a8e0-4a24-9bdb-b9fb31499192" />
  <br>
  <b>Figure 2:</b> Circuit Diagram, Image and Characterisation of each circuit block Note: For the characterisation of the Active Full-Wave Rectifier, we compared the input signal entering the rectifier (i.e. left image of cadrant 5.C) to the output signal leaving it (right image of cadrant 5.C).
</p>

<p align="center">
  <img width="1354" height="1041" alt="image" src="https://github.com/user-attachments/assets/bebe1e71-30a0-4de3-b480-51afce5189a0" />
  <br>
  <b>Figure 3:</b> Circuit Diagram and Image of the 2-channel (i.e. left and right movements) circuit connections.  
</p>

---

## Arduino Code

The Arduino code was developed progressively:

1. **Test Code:** Plotted the EMG signal to verify electrode and circuit connections.  
2. **Click Code:** Detects biceps contraction above threshold to trigger left click.  
3. **Left-Right Code:** Reads brachioradialis (right) and flexor carpi radialis (left) signals to move the mouse. Threshold values were experimentally determined and adjusted for comfort, accuracy, and speed.  

**Code Improvements / Troubleshooting:**

- Threshold adjustments for user comfort and to reduce fatigue  
- AND conditions to prevent false movement from cross-muscle contraction  
- Optimised step size and delay for faster and accurate mouse movements  

<p align="center">
  <img width="750" height="500" alt="image" src="https://github.com/user-attachments/assets/6950bd68-298d-4d17-a655-77d5fb3e8da2" />
  <br>
  <b>Figure 4:</b> Code Flowchart.
</p>


---

## Signal Visualisation

- **Function Generator Input:** Verified circuit gain using known signals  
- **Human Muscle Input:** Verified real EMG signals from team member, adjusted gain accordingly  

<p align="center">
  <img width="1211" height="1008" alt="image" src="https://github.com/user-attachments/assets/e7fc6d5c-7be2-4b90-9b80-fb3df98af77c" />
  <br>
  <b>Figure 5:</b> Signal shown on Arduino when muscle is relaxed (max ~140mV) and contracted (max ~750mV)
</p>

## Electrode Placement and Video Demonstration
<p align="center">
  <img width="788" height="965" alt="image" src="https://github.com/user-attachments/assets/76cad6ef-5d09-40b1-af6d-d8883e8c5bec" />
  <br>
  <b>Figure 6:</b> Electrode placement for the 2-channel configuration (i.e. left and right). The two electrodes on the flexor carpi radialis control the left gesture, and the two on the brachioradialis control the right motion. The 2 reference electrodes were placed on the elbow. 
</p>

![2-channel EMG mouse demo](Video_Demo.gif)
![Test GIF](https://github.com/sirine-b/EMG-BASED-MOUSE/blob/main/Video_Demo.gif?raw=true)
<p align="center">
  <img src="Video_Demo.gif" width="560"/>
</p>

<p align="center">
  <img src="Video_Demo.gif" alt="2-channel EMG mouse demo" width="560"/>
  <br>
  <b>Figure 7:</b> Video demonstration of the 2-channel mouse successfully used to play a left/right game.
</p>

---

## Limitations & Future Work

- Current implementation uses **3 DOF** (click, left, right) due to time and safety constraints  
- Extension to a **5-channel system** (including up/down movement) may require additional myDAQs and more advanced power management  

---

## References

1. Shaw, L., & Bhaga, S. *Online EMG Signal Analysis for diagnosis of Neuromuscular diseases.* Int. J. Eng. Sci. Tech., 2012.  
2. Muhammad Zahak, J. *Signal Acquisition Using Surface EMG and Circuit Design Considerations for Robotic Prosthesis.* In R. N. Ganesh (Ed.), IntechOpen, 2012.  

# Traffic-Light-Controller
By Muhammed Nabeel Azard
Released on: 22/01/2024

# Description

Programming a simulator for a simple traffic light controller using Timers and Switches on a MSP432P401R microcontroller. The program models a traffic light's behaviour. The program
goes through an infinite cycle: green light for 5 seconds, yellow light for 1 second, red light for 3 seconds. The model is implemented using a timer-based solution. The timer ISR keeps track of the time, and when the right time comes, it changes the traffic light state. This information is shared with the main program, which is in charge of changing the colors.  

# Running the Program

1. Download the Keil uVision (Development Environment for Cortex and Arm devices) IDE. It can 
   be downloaded from the following link: http://www2.keil.com/mdk5/install/  

2. Configure the Keil development environment to use the MSP432P401R Launchpad.

3. Create a new project in Keil. The following video shows how to create one on Keil:
   https://www.youtube.com/watch?v=i9zwf_W2e58
   
4. Within Keil, click the Options menu. Then the 'Options for Target 'Target' tab. Here, select 
   **default compiler version 5** for the compiler. If another compiler is selected, the 
   program would not run. The **CMSIS-DAP Debugger** should be the chosen debugger, by clicking 
   on the debugger tab and choosing it from the drop-down menu. If another debugger is 
   selected, the program would not run.

5. Download the main.c file. Move it to your project folder.

6. Add the file within Keil to the project. To do that, right-click on the Source Group 1-> Add 
   Exisiting files to Group. Then, Select the main.c file

7. Connect a MSP432P401R microcontroller to the device to visialize the output. The
   microcontroller is not required for the program itself to run, but you would not be able
   to visualize the output.

# Using the program

1. If the microcontroller is connected, click the run button. Then press SW1 (switch/button 1)
   once to see the LED cycle through the different colours of the traffic light.

# Demo
The video below shows the simple traffic light controller working in real-time:
https://youtube.com/shorts/CPhA2sOjCtM?feature=share

# Credits
Author: Muhammed Nabeel Azard

Copyright © 2024 Muhammed Nabeel Azard. All rights reserved.

# Fortune Teller
Fortune Teller Project for COMS3930. For my final project for COMS-3930, I built a fortune teller that will give the user an answer to a ‘yes’ or ‘no’ question at the press of a button. In its short life span, this box has answered questions from “Will I fail my exam tomorrow?” to “Should I take a nap?”, providing answers to all of life’s most pressing questions. However, if you take a look at the back of the box, the mystery of the answers falls away. Here, a potentiometer allows an operator to select what answer they want to get from the box. However, a user who is facing the front of the box will never know that this process has been rigged. Learn more about the artistic design and challenges in building this project here: https://medium.com/@emilydringel/fortune-teller-fd1949f81399

![IMG_5613](https://user-images.githubusercontent.com/43360191/167316296-7da56634-c95e-4a51-9a33-5303ca74a5bf.jpg)

Files in this repository:
1) fortune-teller.ino: Main Program to Run Fortune Teller
2) fortune-teller-reset.ino: Program to Reset Wheel to "Yes" by Pressing Button
3) caseplans.svg : File to Laser Cut Box with 1/4" Width
4) wheel.stl: File to 3D Print Wheel with Fortunes

Hardware:
1) ESP-32
2) Button
3) Potentiometer
4) Stepper Motor

How to Build:
1) Laser cut 1/4" wood using the above plans
2) 3D print wheel using above plans
3) Hot glue button, potentiometer, and wheel into box
4) Connect wires to relevant ESP-32 pins
5) Hot glue box together, leaving one side unglued for access

How to Use:
1) Use fortune-teller-reset.ino to place "Yes" visibly on the wheel
2) Upload fortune-teller.ino
3) Use the button to spin the wheel for a fortune
4) Move the potentiometer on the back to "rig" the wheel


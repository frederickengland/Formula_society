# TASK 2 Using Motor Drivers
## Context
Last week we learnt how to control 3.2volt motors with steering inputs, this week though since most motors are above 5 volts but still want to be programable then we use a motor driver. Which brings us to the L298N. This module can handle up to 12 volts making it useful for powering. So the the pwr will go from the power supply set to 12 volts 3 amps --> to the motor driver --> motor driver to arduino.
# Concerns
So upload the code to the arduino then plug the usb-b cable into the power supply so that if anything goes wrong, it's on the pwr supply and not the laptop.
## Step 1 - Programming
Since I've found it useful to program before configuring I thought I would switch it up and do the programming first.
You can find the code [here:](https://github.com/frederickengland/Formula_society/blob/main/code/hbridge/hbridge.ino)
After you've finished you want to upload the code with the arrow at the top right.
## Step 2 - Configuration
Keep the potionometer the same from last weeks task
![pic](tinkercd.png)
Keep the potion meter wiring from last week
# Step 3 - Testing
As it's already uploaded the arduino will run it at runtime / on boot up. So now just plug it into the power supply usb hub set the voltage and output to 12 volts and 3 amps. When your ready press output and start twisting the potionometer.
# Step 4 - Congratulations
Great job now that you've configured a motor driver. Next we begin work on the next and final step. [THE ODRIVE!!!](https://www.youtube.com/watch?v=Ym3srZ0MRIA)

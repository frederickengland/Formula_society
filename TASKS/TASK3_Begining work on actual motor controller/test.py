import odrive

# Find a connected ODrive
odrv0 = odrive.find_any()

# Print VBUS voltage
print(odrv0.vbus_voltage)
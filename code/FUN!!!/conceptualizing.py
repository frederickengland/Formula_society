import odrive
import random
import time

# Connect to the ODrive
print("Searching for ODrive...")

odrv0 = odrive.find_any()

print("ODrive connected!")

# Initialise scores
human_score = 0
computer_score = 0

possible_actions = ["rock", "paper", "scissors"]

try:
    while True:
        # Read the voltage again every iteration
        voltage = odrv0.vbus_voltage

        print(f"\nBus voltage: {voltage:.2f} V")

        # Check whether voltage is sufficient
        if voltage <= 20:
            print("Voltage is 20 V or below. Stopping the game.")
            break

        # Get human input
        user_action = input(
            "Enter rock, paper, scissors, or quit: "
        ).strip().lower()

        if user_action == "quit":
            break

        if user_action not in possible_actions:
            print("Invalid choice. Please try again.")
            continue

        # Computer selects an action
        computer_action = random.choice(possible_actions)

        print(f"You chose: {user_action}")
        print(f"Computer chose: {computer_action}")

        # Determine the winner
        if user_action == computer_action:
            print("It's a tie!")

        elif (
            (user_action == "rock" and computer_action == "scissors")
            or (user_action == "paper" and computer_action == "rock")
            or (user_action == "scissors" and computer_action == "paper")
        ):
            print("You win this round!")
            human_score += 1

        else:
            print("Computer wins this round!")
            computer_score += 1

        # Display the current scores
        print(
            f"Score: Human {human_score} - Computer {computer_score}"
        )

except KeyboardInterrupt:
    print("\nGame stopped by user.")

except Exception as error:
    print(f"An error occurred: {error}")

finally:
    print("\nFinal score:")
    print(f"Human: {human_score}")
    print(f"Computer: {computer_score}")
    print("Program finished.")

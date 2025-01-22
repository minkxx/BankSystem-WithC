import subprocess
import os
import time

def clear_screen():
    """Clear the terminal screen."""
    # Check the operating system
    if os.name == "nt":  # For Windows
        os.system("cls")
    else:  # For Linux/Mac
        os.system("clear")

def run_exe(file_path):
    try:
        # Run the .exe file and wait for it to complete
        result = subprocess.run(file_path, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Execution failed with return code: {e.returncode}")
    except FileNotFoundError:
        print(f"File not found: {file_path}")

if __name__ == "__main__":
    while True:
        clear_screen()
        print("        Admin Panel")
        print("1. Run Bank\n2. Convert users data to csv\n3. Exit")
        choice = int(input(": "))
        if choice == 1:
            run_exe("bank.exe")
        elif choice == 2:
            run_exe("data_TxtToCsv.exe")
        elif choice == 3:
            break
        else:
            print("Invalid choice\n")
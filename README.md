# Banking System Project

This project is a simple banking system that demonstrates the integration of Python and C. It includes functionalities for creating bank accounts, depositing and withdrawing money, and converting user data to a CSV format. The project consists of three main components:

1. **Banking System (C)**: Manages bank accounts and performs operations like creating accounts, depositing, and withdrawing money.
2. **Data Conversion (C)**: Converts user data from a text file to a CSV file.
3. **Admin Panel (Python)**: Provides a command-line interface to run the banking system and data conversion programs.

## Features

- Create bank accounts with account holder name, bank name, account number, and balance.
- Deposit and withdraw money from accounts.
- Save and load account data from files.
- Convert account data from a text file to a CSV file.
- Clear terminal screen for better user experience.

## Setup Instructions

Follow these steps to set up the project on your local machine:

### Prerequisites

- GCC compiler for C programs.
- Python 3.x installed.
- A terminal or command prompt.

### Steps

1. **Clone the Repository**

    ```sh
    git clone https://github.com/minkxx/BankSystem-WithC.git
    cd BankingSystem
    ```

2. **Compile the C Programs**

    Compile the `bank.c` and `data_TxtToCsv.c` files to create executable files.

    ```sh
    gcc -o bank.exe bank.c
    gcc -o data_TxtToCsv.exe data_TxtToCsv.c
    ```

3. **Run the Admin Panel**

    Use the Python script `run_bank.py` to interact with the banking system and data conversion.

    ```sh
    python run_bank.py
    ```

4. **Follow the On-Screen Instructions**

    The admin panel will provide options to run the banking system, convert user data to CSV, or exit the program.

## Usage

- **Run Bank**: Start the banking system to create accounts, deposit, withdraw, and check balances.
- **Convert Users Data to CSV**: Convert the user data from `accounts.txt` to `accounts.csv`.
- **Exit**: Exit the admin panel.

## File Structure

- `bank.c`: Contains the banking system logic.
- `data_TxtToCsv.c`: Contains the logic to convert user data from text to CSV.
- `run_bank.py`: Python script to provide a command-line interface for running the C programs.
- `accounts.dat`: Binary file to store account data.
- `accounts.txt`: Text file to store account data in a readable format.
- `accounts.csv`: CSV file to store account data in a CSV format.
- `last_user_id_created.txt`: Text file to keep track of the last created user ID.

## License

This project is licensed under the MIT License.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Contact

For any questions or inquiries, please contact [minkxx](mailto:aryuokk@gmail.com).


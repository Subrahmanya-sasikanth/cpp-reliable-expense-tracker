# Reliable Command-Line Utility — Expense Tracker

A beginner-friendly C++ command-line expense tracker built for EdVyro C++ Programming Task 1.

## Requirements covered

- Define expense fields and a menu-driven user flow.
- Add expenses.
- List all recorded expenses.
- Calculate a total for a selected category.
- Calculate the overall expense total.
- Validate empty text, invalid amounts, and invalid menu choices without crashing.
- Keep the program organised into focused functions.

## Expense fields

Each expense contains:

- `id` — automatically generated integer ID.
- `description` — what the expense was for.
- `category` — category such as Food, Travel, or Study.
- `amount` — positive amount in INR.

## Project structure

```text
task02_reliable_command_line_utility/
├── main.cpp
└── README.md
```

## Build and run

### Linux / macOS / MinGW

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o expense_tracker
./expense_tracker
```

### Windows PowerShell with MinGW

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o expense_tracker.exe
.\expense_tracker.exe
```

## Example execution

```text
==============================================
  Reliable Command-Line Expense Tracker
==============================================
Track your expenses using a simple validated menu.

------------- EXPENSE TRACKER -------------
1. Add expense
2. List expenses
3. Category total
4. Overall total
5. Exit

Choose an option: 1

==============================================
  Add Expense
==============================================
==============================================
Description: Lunch
Category: Food
Amount (INR): 180
Expense added successfully with ID 1.

Choose an option: 1
Description: Bus pass
Category: Travel
Amount (INR): 500
Expense added successfully with ID 2.

Choose an option: 3

==============================================
  Category Total
==============================================
Enter category: Food
Total for Food: INR 180.00

Choose an option: 4

==============================================
  Overall Total
==============================================
Total expenses: INR 680.00
```

## Validation examples

The program safely handles:

- Empty descriptions/categories.
- Negative or zero amounts.
- Non-numeric amounts such as `abc`.
- Decimal amounts.
- Menu values outside `1–5`.
- Non-numeric menu input.

Invalid input is rejected and the user is prompted again instead of the program terminating unexpectedly.

## Passing checklist

- [x] Expense fields and menu-driven flow defined.
- [x] Add action implemented.
- [x] List action implemented.
- [x] Category total implemented.
- [x] Overall total implemented.
- [x] Invalid values handled without crashing.
- [x] Work and explanation are contained in this project.

## Submission

Submit the public or view-only repository/project link containing `main.cpp` and this `README.md`.

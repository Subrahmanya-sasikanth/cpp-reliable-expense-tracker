#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

struct Expense {
    int id;
    string description;
    string category;
    double amount;
};

void printHeader(const string& title) {
    cout << "\n==============================================\n";
    cout << "  " << title << "\n";
    cout << "==============================================\n";
}

string trim(const string& text) {
    size_t start = text.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = text.find_last_not_of(" \t\r\n");
    return text.substr(start, end - start + 1);
}

string readNonEmpty(const string& prompt) {
    while (true) {
        cout << prompt;
        string value;
        getline(cin, value);
        value = trim(value);
        if (!value.empty()) return value;
        cout << "Input cannot be empty. Please try again.\n";
    }
}

double readPositiveAmount(const string& prompt) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        input = trim(input);

        try {
            size_t pos = 0;
            double amount = stod(input, &pos);
            if (pos != input.size() || amount <= 0) {
                throw invalid_argument("invalid amount");
            }
            return amount;
        } catch (...) {
            cout << "Invalid amount. Enter a positive number such as 250.50.\n";
        }
    }
}

int readMenuChoice() {
    while (true) {
        cout << "\nChoose an option: ";
        string input;
        getline(cin, input);
        input = trim(input);

        try {
            size_t pos = 0;
            int choice = stoi(input, &pos);
            if (pos != input.size() || choice < 1 || choice > 5) {
                throw invalid_argument("invalid choice");
            }
            return choice;
        } catch (...) {
            cout << "Invalid choice. Enter a number from 1 to 5.\n";
        }
    }
}

void addExpense(vector<Expense>& expenses, int& nextId) {
    printHeader("Add Expense");

    Expense expense;
    expense.id = nextId++;
    expense.description = readNonEmpty("Description: ");
    expense.category = readNonEmpty("Category: ");
    expense.amount = readPositiveAmount("Amount (INR): ");

    expenses.push_back(expense);
    cout << "Expense added successfully with ID " << expense.id << ".\n";
}

void listExpenses(const vector<Expense>& expenses) {
    printHeader("All Expenses");

    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << left << setw(6) << "ID"
         << setw(25) << "Description"
         << setw(18) << "Category"
         << right << setw(12) << "Amount" << "\n";
    cout << string(61, '-') << "\n";

    cout << fixed << setprecision(2);
    for (const auto& expense : expenses) {
        cout << left << setw(6) << expense.id
             << setw(25) << expense.description.substr(0, 24)
             << setw(18) << expense.category.substr(0, 17)
             << right << setw(12) << expense.amount << "\n";
    }
}

void showCategoryTotal(const vector<Expense>& expenses) {
    printHeader("Category Total");
    string category = readNonEmpty("Enter category: ");

    double total = 0.0;
    bool found = false;

    for (const auto& expense : expenses) {
        if (expense.category == category) {
            total += expense.amount;
            found = true;
        }
    }

    if (!found) {
        cout << "No expenses found for category '" << category << "'.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Total for " << category << ": INR " << total << "\n";
}

void showOverallTotal(const vector<Expense>& expenses) {
    printHeader("Overall Total");

    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }

    cout << fixed << setprecision(2);
    cout << "Total expenses: INR " << total << "\n";
}

void showMenu() {
    cout << "\n------------- EXPENSE TRACKER -------------\n";
    cout << "1. Add expense\n";
    cout << "2. List expenses\n";
    cout << "3. Category total\n";
    cout << "4. Overall total\n";
    cout << "5. Exit\n";
}

int main() {
    vector<Expense> expenses;
    int nextId = 1;

    printHeader("Reliable Command-Line Expense Tracker");
    cout << "Track your expenses using a simple validated menu.\n";

    while (true) {
        showMenu();
        int choice = readMenuChoice();

        switch (choice) {
            case 1:
                addExpense(expenses, nextId);
                break;
            case 2:
                listExpenses(expenses);
                break;
            case 3:
                showCategoryTotal(expenses);
                break;
            case 4:
                showOverallTotal(expenses);
                break;
            case 5:
                cout << "\nThank you for using the Expense Tracker. Goodbye!\n";
                return 0;
        }
    }
}

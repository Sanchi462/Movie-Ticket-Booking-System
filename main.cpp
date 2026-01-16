#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class Seats {
private:
    int seat[5][10];

public:
    Seats() {
        loadFromFile();
    }

    void loadFromFile() {
        ifstream in("seats.txt");

        if (!in) {
            for (int i = 0; i < 5; i++)
                for (int j = 0; j < 10; j++)
                    seat[i][j] = 1;
            saveToFile();
            return;
        }

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 10; j++)
                in >> seat[i][j];

        in.close();
    }

    void saveToFile() {
        ofstream out("seats.txt");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++)
                out << seat[i][j] << " ";
            out << endl;
        }
        out.close();
    }

    void display() {
        cout << "\n    ";
        for (int i = 1; i <= 10; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Row " << i + 1 << " ";
            for (int j = 0; j < 10; j++) {
                cout << (seat[i][j] ? "- " : "X ");
            }
            cout << endl;
        }
    }

    bool reserveSeat(int row, int col) {
        if (row < 1 || row > 5 || col < 1 || col > 10)
            return false;

        if (seat[row - 1][col - 1] == 0)
            return false;

        seat[row - 1][col - 1] = 0;
        saveToFile();
        return true;
    }
};

int main() {
    Seats s;
    bool exitProgram = false;

    while (!exitProgram) {
        system("cls");
        cout << " MOVIE TICKET BOOKING SYSTEM\n";
        cout << "--------------------------------\n";
        cout << "1. Book Seat\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number.\n";
            Sleep(1500);
            continue;
        }

        if (choice == 1) {
            s.display();

            int row, col;
            cout << "\nEnter Row (1-5): ";
            cin >> row;
            cout << "Enter Seat (1-10): ";
            cin >> col;

            if (s.reserveSeat(row, col))
                cout << "\n Seat booked successfully!\n";
            else
                cout << "\n Seat already booked or invalid!\n";

            Sleep(2000);
        }
        else if (choice == 2) {
            exitProgram = true;
            cout << "Thank you for using the system!\n";
            Sleep(1500);
        }
        else {
            cout << "Invalid choice!\n";
            Sleep(1500);
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <curses.h>

using namespace std;


typedef struct {
    unsigned short int **seats;     //1 для забронир. места и 0 для свободного места
    int length;     //количество мест в ряду
    int width;      // количество строк
    int *zones;     //первая половина массива содержит цены для каждой зоны, а вторая половина-диапазон строк для этих зон
    unsigned int zonesAmount;
} hall;

hall initialize () {

    hall resultingHall;
    unsigned short int zonesCount;
    int i, rows;
    int rowsFlag = 1;

    cout << "\nPlease enter hall dimensions: " << endl << "Length (of a single row):";
    cin >> resultingHall.length;
    cout << "Width (amount of rows):";
    cin >> resultingHall.width;
    rows = resultingHall.width;

    cout << "How many zones are there:";
    cin >> zonesCount;

    resultingHall.zonesAmount = zonesCount;

    resultingHall.zones = new int [zonesCount*2];

    cout << "\nPlease enter zones prices:" << endl;
    for (i = 1; i <= zonesCount; ++i) {
        cout << "Zone " << i << " price:";
        cin >> resultingHall.zones[i-1];
    }

    cout << "\nPlease locate the zones:\n";
    for (i = 1; i < zonesCount; ++i) {
        cout << "Zone " << i << " starts from row #" << rowsFlag << " and will end on row #";
        cin >> resultingHall.zones[zonesCount+i-1];
        rowsFlag = resultingHall.zones[zonesCount+i-1] + 1;
    }
    if (rowsFlag <= rows) {
        cout << "Then the last zone would start from row #" << rowsFlag << " and will end on row #" << rows << endl;
        resultingHall.zones[zonesCount*2-1] = rows;
    } else {
        cout << "Error in zones location! Program will be shut down!";
        delete [] (resultingHall.zones);
        resultingHall.zones = nullptr;
        system("pause");
    }

    resultingHall.seats = new unsigned short int* [resultingHall.width];
    for (i = 0; i < resultingHall.width; ++i) {
        resultingHall.seats[i] = new unsigned short int [resultingHall.length];
    }

    for (i = 0; i < resultingHall.width; ++i) {
        for (int j = 0; j < resultingHall.length; ++j) {
            resultingHall.seats[i][j] = 0;
        }
    }

    /*for (i = 0; i < resultingHall.zonesAmount*2; ++i) {
        cout << "zones array debug " << resultingHall.zones[i] << endl;
    }*/

    cout << "\nYour hall is initialized successfully!\n";

    return resultingHall;
}

void print_hall (hall hallToPrint) {
    int i, j;
    unsigned short int zoneCheck;

    zoneCheck = hallToPrint.zonesAmount;

    cout << "\n\t---";
    for (i = 0; i < hallToPrint.length; ++i) {
        cout << "---" << setw(2) << i+1;
    }

    for (i = hallToPrint.width; i > 0; --i) {
        cout << "\n";

        if (hallToPrint.zones[hallToPrint.zonesAmount + zoneCheck - 1] == i && zoneCheck != 0) {
            cout << "Zone #" << zoneCheck;
            zoneCheck--;
        }
        cout << "\t" << setw(2) << i << "|";
        for (j = 0; j < hallToPrint.length; ++j) {
            cout << setw(5) << hallToPrint.seats[i-1][j];
        }
    }

    cout << "\n\n";
}

void clear_hall (hall *hallToClear) {
    int i, j;

    for (i = 0; i < hallToClear->width; ++i) {
        for (j = 0; j < hallToClear->length; ++j) {
            hallToClear->seats[i][j] = 0;
        }
    }
}

int profit_estimation (hall hall) {
    int i, j, k;
    int zoneFirstRow = 1;
    int profit = 0;

    for (i = 0; i < hall.zonesAmount; ++i) {
        for (j = zoneFirstRow; j <= hall.zones[hall.zonesAmount+i];  ++j) {
            for (k = 0; k < hall.length; ++k) {
                if (hall.seats[j-1][k] != 0) {
                    profit += hall.zones[i];
                }
            }
        }
        zoneFirstRow = hall.zones[hall.zonesAmount + i] + 1;
    }

    return profit;
}

void reserve_place (hall *hall, vector<string> *resList, int *resAmount) {
    string name;
    int row, seat;

    cout << "\nWhat name do you want your seat to be reserved for";
    getchar();
    getline(cin, name, '\n');

    print_hall(*hall);

    tryAgain:
    cout << "\nPlease, select a seat to reserve (input ROW PLACE):";
    cin >> row;
    cin >> seat;

    if (hall->seats[row-1][seat-1] == 0) {
        *resAmount += 1;
        hall->seats[row-1][seat-1] = *resAmount;
        (*resList).emplace_back(name);
        cout << "You've successfully reserved a seat\n";
    } else {
        cout << "This place is already reserved! Please, choose a free one\n";
        goto tryAgain;
    }

}

void reserve_rectangle (hall *hall, vector<string> *resList, int *resAmount) {
    string groupName;
    int sSeat, sRow, eSeat, eRow;
    int i, j;
    bool reserveError = false;
    char choice;

    print_hall(*hall);
    cout << "\nEnter starting point for rectangle reservation (top left corner seat in format ROW SEAT):";
    cin >> sRow >> sSeat;

    getchar();
    cout << "Enter ending point for rectangle reservation (bottom right corner seat):";
    cin >> eRow >> eSeat;

    tryAgain:
    for (i = sRow-1; i >= eRow-1; --i) {
        for (j = sSeat-1; j < eSeat; ++j) {
            if (hall->seats[i][j] != 0) {
                if (!reserveError) {
                    getchar();
                    cout << "Error! The following seats of chosen rectangle are already reserved (ROW/SEAT): ";
                    cout << i << "/" << j << " ";
                    reserveError = true;
                } else {
                    cout << i << "/" << j << " ";
                }
            }
        }
    }

    if (reserveError) {
        cout << "\nWant to try reserving again? (Y/N):";
        cin >> choice;
        switch (choice) {
            case 'Y':
                cout << endl;
                goto tryAgain;
            case 'N':
                return;
            default:
                cout << "Input error!\n";
                cout << "Want to try reserving again? (Y/N):";
                cin >> choice;
        }
    } else {

        cout << "\nWhat name do you want your seats to be reserved for";
        getchar();
        getline(cin, groupName, '\n');

        *resAmount += 1;
        (*resList).emplace_back(groupName);

        for (i = sRow - 1; i >= eRow-1; --i) {
            for (j = sSeat - 1; j < eSeat; ++j) {
                hall->seats[i][j] = *resAmount;
            }
        }

        cout << "You've successfully reserved " << (sRow-eRow+1)*(eSeat-sSeat+1) << " seats for \"" << groupName << "\"\n";
    }
}

void cancel_reserved_by (hall *hall, vector<string> *resList, int *resAmount) {
    int i, j, k;
    string name;
    string check;
    bool isFound = false;
    char choice;

    tryAgain:
    cout << "\nWhat's the name of reservation that you want to cancel:";
    getchar();
    getline(cin, name, '\n');

    for (i = 0; i < *resAmount; ++i) {
        check = (*resList)[i];
        if (name == check) {
            if (!isFound) {

                for (k = 0; k < hall->width; ++k) {
                    for (j = 0; j < hall->length; ++j) {
                        if (hall->seats[k][j] == i+1) {
                            hall->seats[k][j] = 0;
                        }
                    }
                }

                (*resList)[i] = '0';
                isFound = true;
            }
        }
    }

    if (isFound) {
        cout << "Reservation in the name \"" << name << "\" has been canceled successfully\n";
    } else {
        cout << "No reservations in the name \"" << name << "\" were found\n";
        cout << "\nWant to try again? (Y/N):";
        cin >> choice;
        switch (choice) {
            case 'Y':
                cout << endl;
                goto tryAgain;
            case 'N':
                return;
            default:
                cout << "Input error!\n";
                cout << "Want to try again? (Y/N):";
                cin >> choice;
        }
    }
}

void reserve_closest (hall *hall, vector<string> *resList, int *resAmount) {
    int i, j;
    int amount;

    cout << "How many seats do you want to reserve:";
    cin >> amount;


}

void task_B () {

    int i, choice;
    bool isInitialized = false;
    bool flag = true;
    hall hall;
    char dummy;

    vector<string> reserves;
    int reservesAmount = 0;

    cout << "\n---------- BEGINNING TASK B ----------\n";

    while (flag) {
        cout << "\n========================================\nWhich operation do you want to perform:\n========================================\n\n";
        if (isInitialized) {
            cout << "1. Print\n";
            cout << "2. Reset hall\n";
            cout << "3. Calculate estimated profit\n";
            cout << "4. Reserve a single seat\n";
            cout << "5. Reserve a rectangle of seats (line is a 1xN rectangle)\n";
            cout << "6. Cancel reservation by the name\n";
            cout << "0. Exit task B\n";

            cout << "\nYour choice:";
            cin >> choice;

            switch (choice) {
                case 1:
                    print_hall(hall);
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 2:
                    clear_hall(&hall);
                    reservesAmount = 0;
                    reserves.clear();
                    cout << "Hall has been reset. All seats are now free to reserve!\n";
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 3:
                    cout << "Estimated profit = " << profit_estimation(hall) << endl;
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 4:
                    reserve_place(&hall, &reserves, &reservesAmount);
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 5:
                    reserve_rectangle(&hall, &reserves, &reservesAmount);
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 6:
                    cancel_reserved_by(&hall, &reserves, &reservesAmount);
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 0:
                    cout << "\n---------- QUITING TASK B ----------\n";
                    flag = false;
                    break;
                default:
                    cout << "\nInput error, try again!\n";
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
            }

        } else {
            cout << "1. Initialize \"hall\" array\n" << "0. Exit task B\n";

            cout << "\nYour choice:";
            cin >> choice;

            switch (choice) {
                case 1:
                    isInitialized = true;
                    hall = initialize();
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
                    break;
                case 0:
                    cout << "\n---------- QUITING TASK B ----------\n";
                    flag = false;
                    return;
                default:
                    cout << "\nInput error, try again!\n";
                    cout << "Press \"Enter\" to continue...";
                    dummy = getch();
            }
        }
    }


    delete [] (hall.zones);
    hall.zones = nullptr;

    for (i = 0; i < hall.width; ++i) {
        delete [] (hall.seats[i]);
        hall.seats[i] = nullptr;
    }
    delete [] (hall.seats);
    hall.seats = nullptr;

}

int main() {

    task_B();

    return 0;
}

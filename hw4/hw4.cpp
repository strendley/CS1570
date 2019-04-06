//Programmer: Skylar Trendley  //Date: 2/15/17
//Instructor: Clayton Price
//Section: CS1570A
//Description: Menu Driven Math Calculator
#include <iostream>
using namespace std;

int main()
{
    const int INITIALIZE_I = 1;
    const int INITIALIZE_J = 1;
    const int ITERATE_CONVERGENCE = 6;
    const int MIN_PROMPT = 0;
    const int MAX_EXPONENTIATE = 7;
    const int MAX_FACTORIAL = 6;
    const int MAX_K = 5;
    const int ERROR_RANGE = -1;
    const int CHOICE_SQRT = 2;
    const int CHOICE_CUBERT = 3;
    const int EXIT_PROMPT = 4;
    const int CHOICE_ENTER_X = 1;
    const int SQRT_DIVISOR = 2;
    const int CUBERT_DIVISOR = 3;
    const int CUBERT_MULTIPLER = 2;
    int option, choice; //prompts
    double x, k; //inputs
    double exp = 1, fact = 1, exponentiate = 1; //e^x calculation
    double term, sinX = 0;  //sinX calculation
    int sign = -1, factorial; //sinX calculation
    double guess, sqRt, cubeRt; //sqRt & cubeRt calculation
    bool quit = false; //exit prompt main menu
    bool quit2 = false; //exit prompt root menu
   
    do
    {
        cout << endl;
        cout << "-----Menu-----" << endl;
        cout << "1. Exponential of x" << endl;
        cout << "2. Sine of x" << endl;
        cout << "3. Roots of x" << endl;
        cout << "4. Quit" << endl;

        cout << "Enter option (1-4): ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            do
            {
                cout << "Enter a real number between 0 and 7: ";
                cin >> x;
            } while (x < MIN_PROMPT || x > MAX_EXPONENTIATE);

            for (int i = INITIALIZE_I; i <= MAX_FACTORIAL; i++)
            {
                exp *= x;
                fact *= i;
						    //exponentiate initalized
                exponentiate += exp / fact;         //to 1 to account for
            }                                       //x^0 = 1;

            cout << "e^"<< x <<" = " << exponentiate << endl;
        }
        break;

        case 2:
        {
            do
            {
                cout << "Enter a real number: ";
                cin >> x;
                term = x;

            } while (x < MIN_PROMPT);

            do
            {
                cout << "Enter a positive integer between 1 and 5: ";
                cin >> k;

            } while (k <= MIN_PROMPT || k > MAX_K);

            for (int i = INITIALIZE_I; i <= k; i += 2)
            {
                term = 1;
                factorial = 1;
                for (int j = INITIALIZE_J; j <= i; j++)
                {
                    term *= x;
                    factorial *= j;
                }

                sign *= -1;
                sinX += sign * term / factorial;
             }

            cout << "sin(" << x << ") = " << sinX << " [";
            cout  << k << " term accuracy]" << endl;

            break;
        }

        case 3:
        {
            x = ERROR_RANGE;
            
            do
            {
                cout << endl;
                cout << "-----Roots-----" << endl;
                cout << "1. Enter x" << endl;
                cout << "2. Square Root" << endl;
                cout << "3. Cube Root" << endl;
                cout << "4. Return to Main Menu" << endl;

                do
                {
                    cout << "Enter choice (1-4): ";
                    cin >> choice;

                    if ((choice == CHOICE_SQRT || choice == CHOICE_CUBERT)
                          && x == ERROR_RANGE)
                        {
                          cout << "Sorry, input for x";
                          cout << " must be provided first." << endl;
                        }
                    else if (choice <= MIN_PROMPT|| choice > EXIT_PROMPT)
                        cout << "Option not valid--Please retry." << endl;
                    else if (choice == CHOICE_ENTER_X)
                    {
                        do
                        {
                           cout << "Enter positive value of x: ";
                           cin >> x;

                        } while (x < MIN_PROMPT);
                    }

                } while (x == ERROR_RANGE);

                if (choice == CHOICE_SQRT)
                {
                    guess = x;
                    for (int i = INITIALIZE_I; i <= ITERATE_CONVERGENCE; i++)
                    {
                       sqRt = ((guess + (x / guess)) / SQRT_DIVISOR);
                       guess = sqRt;
                    }

                    cout << "The square root of " << x << " is " 
                         << sqRt << "." << endl;
                }
                else if (choice == CHOICE_CUBERT)
                {
                    guess = x;
                    for (int i = INITIALIZE_I; i <= ITERATE_CONVERGENCE; i++)
                    {
                       cubeRt = ((CUBERT_MULTIPLER * guess) +
                                 (x / (guess * guess))) / CUBERT_DIVISOR;
                       guess = cubeRt;
                    }

                    cout << "The cube root of " << x << " is " 
                         << cubeRt << "." << endl;
                }

                else if (choice == EXIT_PROMPT)
                {
                    quit2 = true;
                }

            } while (!quit2); //end root menu loop

            break;
        }
        case 4:
        {
            quit = true;
            break;
        }

        default:
            cout << "Option not valid--Please retry." << endl;
        } //end switch

    } while (!quit); //end menu loop

    return 0;
} //end main

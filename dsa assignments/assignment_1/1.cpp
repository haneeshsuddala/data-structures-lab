#include <iostream>
using namespace std;
#define MAX 100

void createarray(int arr[], int &n)
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void displayarray(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertelement(int arr[], int &n)
{
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int j = n; j >= pos; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[pos - 1] = val;
    n++;
}

void deleteelement(int arr[], int &n)
{
    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }
    int val;
    cout << "Enter value to search: ";
    cin >> val;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Element not found" << endl;
}

int main()
{
    int arr[MAX];
    int n = 0;
    int choice;

    do
    {
        cout << "\n—— MENU ——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createarray(arr, n);
            break;
        case 2:
            displayarray(arr, n);
            break;
        case 3:
            insertelement(arr, n);
            break;
        case 4:
            deleteelement(arr, n);
            break;
        case 5:
            linearSearch(arr, n);
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

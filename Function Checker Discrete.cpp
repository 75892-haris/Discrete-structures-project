#include <iostream>
using namespace std;

int main()
{
    int aSize, bSize, rSize;

    // ----- Input Set A -----
    cout << "Enter number of elements in Set A: ";
    cin >> aSize;
    int A[aSize];

    cout << "Enter elements of Set A:\n";
    for (int i = 0; i < aSize; i++)
        cin >> A[i];

    // ----- Input Set B -----
    cout << "\nEnter number of elements in Set B: ";
    cin >> bSize;
    int B[bSize];

    cout << "Enter elements of Set B:\n";
    for (int i = 0; i < bSize; i++)
        cin >> B[i];

    // ----- Input Relation R (ordered pairs) -----
    cout << "\nEnter number of ordered pairs in Relation R: ";
    cin >> rSize;

    int R[rSize][2];
    cout << "Enter ordered pairs (a b):\n";
    for (int i = 0; i < rSize; i++)
        cin >> R[i][0] >> R[i][1];

    // ----- Check if R is a Function -----
    bool isFunction = true;

    for (int i = 0; i < aSize; i++)
    {
        int count = 0;
        for (int j = 0; j < rSize; j++)
        {
            if (R[j][0] == A[i])
                count++;
        }
        if (count != 1)
        {
            isFunction = false;
            break;
        }
    }

    // If not a function, no need to check further
    if (!isFunction)
    {
        cout << "\nThe relation R is NOT a function.\n";
        return 0;
    }

    cout << "\nThe relation R is a FUNCTION.\n";

    // ----- Check One-One  -----
    bool isOneOne = true;

    for (int i = 0; i < rSize; i++)
    {
        for (int j = i + 1; j < rSize; j++)
        {
            if (R[i][1] == R[j][1])  // same output for two different inputs
            {
                isOneOne = false;
                break;
            }
        }
        if (!isOneOne) break;
    }

    if (isOneOne)
        cout << "The function is ONE-ONE (Injective).\n";
    else
        cout << "The function is NOT one-one.\n";

    // ----- Check Onto (Surjective) -----
    bool isOnto = true;

    for (int i = 0; i < bSize; i++)
    {
        bool found = false;

        for (int j = 0; j < rSize; j++)
        {
            if (R[j][1] == B[i])
                found = true;
        }

        if (!found)
        {
            isOnto = false;
            break;
        }
    }

    if (isOnto)
        cout << "The function is ONTO (Surjective).\n";
    else
        cout << "The function is NOT onto.\n";

    // ----- Bijective -----
    if (isOneOne && isOnto)
        cout << "The function is BIJECTIVE.\n";
    else
        cout << "The function is NOT bijective.\n";

    return 0;
}


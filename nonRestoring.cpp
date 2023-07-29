#include <iostream>
#include <bitset>
using namespace std;

int a[5] = {0, 0, 0, 0, 0};
int q[4] = {0, 0, 0, 0};
int b[5] = {0, 0, 0, 0, 0};
int b2c[5] = {0, 0, 0, 0, 0};

void comp() {
    int i = 4;
    do {
        b2c[i] = b[i];
        i--;
    } while (b[i + 1] != 1);

    while (i >= 0) {
        b2c[i] = (b[i] + 1) % 2;
        i--;
    }

    cout << "\n\tB's complement:";
    for (i = 0; i < 5; i++)
        cout << b2c[i];
    cout << endl;
}

void nonresdiv() {
    int i;
    // Shift left
    for (i = 0; i < 4; i++)
        a[i] = a[i + 1];
    a[4] = q[0];
    for (i = 0; i < 3; i++)
        q[i] = q[i + 1];

    // Check if a[0] is 0, then a_minus_b(), else a_plus_b()
    if (a[0] == 0) {
        int carry = 0, sum = 0;
        for (i = 4; i >= 0; i--) {
            sum = (a[i] + b2c[i] + carry);
            a[i] = sum % 2;
            carry = sum / 2;
        }
    } else {
        int carry = 0, sum = 0;
        for (i = 4; i >= 0; i--) {
            sum = (a[i] + b[i] + carry);
            a[i] = sum % 2;
            carry = sum / 2;
        }
    }

    // Calculate the new q[3]
    q[3] = (a[0] + 1) % 2;
}

void a_plus_b() {
    int i, carry = 0, sum = 0;
    for (i = 4; i >= 0; i--) {
        sum = (a[i] + b[i] + carry);
        a[i] = sum % 2;
        carry = sum / 2;
    }
}

int main() {
    int i, j, k;

    cout << "Enter dividend in binary form (4 bits): ";
    for (i = 0; i < 4; i++)
        cin >> q[i];

    cout << "Enter divisor in binary form (5 bits): ";
    for (i = 0; i < 5; i++)
        cin >> b[i];

    comp();

    cout << "\n\t[A]\t[M]\n";
    for (i = 0; i < 4; i++) {
        nonresdiv();
        cout << "\t";
        for (j = 0; j < 5; j++)
            cout << a[j];
        cout << "\t";
        for (k = 0; k < 4; k++)
            cout << q[k];
        cout << endl;
    }

    if (a[0] == 1)
        a_plus_b();
    cout << "\t";
    for (j = 0; j < 5; j++)
        cout << a[j];
    cout << "\t";
    for (k = 0; k < 4; k++)
        cout << q[k];
    cout << endl;

    cout << "\n\tThe Quotient Is\t: ";
    for (k = 0; k < 4; k++)
        cout << q[k];
    cout << endl;

    cout << "\tThe Remainder Is\t: ";
    for (j = 0; j < 5; j++)
        cout << a[j];
    cout << endl;

    return 0;
}

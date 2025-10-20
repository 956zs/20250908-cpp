#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstring>
#define mypi 3.14
#define maxv 999
using namespace std;

void show_title();
void f01();
void f02();
void f03();
void f04();
void f05();
void f06();

int main()
{
    string menuItem[] = {
        "[1]基本輸入與輸出1",
        "[2]基本輸入與輸出2",
        "[3]運算式與運算子2",
        "[4]遞增運算子",
        "[5]列舉",
        "[6]迴圈與陣列",
        "[7]字串與字元",
        "[8]遞迴",
        "[9]類別"};
    int i;
    int selMenu = 99;

    while (selMenu != 0)
    {
        system("clear"); // Linux 使用 clear 代替 cls
        cout << "-----------------------------" << endl;
        int arrLength = sizeof(menuItem) / sizeof(menuItem[0]);
        for (i = 0; i < arrLength; i++)
        {
            cout << menuItem[i] << endl;
        }
        cout << "請輸入：";
        cin >> selMenu;

        switch (selMenu)
        {
        case 1:
            f01();
            break;
        case 2:
            f02();
            break;
        case 3:
            f03();
            break;
        case 4:
            f04();
            break;
        case 5:
            f05();
            break;
        case 6:
            f06();
            break;
        }
        cout << "\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get(); // 代替 system("pause")
    }
    return 0;
}

void show_title()
{
    cout << "-----------------------------" << endl;
    cout << "---   班級 32 魯夫    ---\n";
    cout << "-----------------------------" << endl;
}

// [1]基本輸入與輸出1
void f01()
{
    int m, n, tmp, sum = 0;
    printf("Enter two numbers:");
    scanf("%d %d", &m, &n);
    if (m > n)
    {
        tmp = m;
        m = n;
        n = tmp;
    }
    for (int i = m; i <= n; i++)
    {
        sum += i;
    }
    printf("The sum is:%d\n", sum);
}

// [2]基本輸入與輸出2
void f02()
{
    int a, b;
    printf("Enter the numbers:");
    scanf("%d %d", &a, &b);
    b = (a / 10) * 100;
    b += (a / 10) * 10;
    b += (a / 100);
    printf("Out:%d", b);
}

// [3]運算式與運算子2
void f03()
{
    int a, b;
    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            printf("%dX%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }
    printf("\n");
}

// [4]遞增運算子
void f04()
{
    char h[17] = "0123456789ABCDEF";
    int a, b, c;
    char ansHex[4], ansBin[8];
    int count = 0;
    printf("Enter the numbers(10):");
    scanf("%d", &a);
    b = a;

    // 轉16進制
    printf("the HEX value is %x\n", a);
    count = 0;
    while (a > 0)
    {
        ansHex[count] = h[a % 16];
        a = a / 16;
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", ansHex[i]);
    }
    printf("\n");

    // 轉2進制
    count = 0;
    a = b;
    while (a > 0)
    {
        ansBin[count] = h[a % 2];
        a = a / 2;
        count++;
    }

    printf("the BINARY value is ");
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%c", ansBin[i]);
    }
    printf("\n");
}

// [5]列舉
void f05()
{
    int c = 0;
    for (int i = 150; i <= 300; i++)
    {
        int isPrime = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
        {
            printf("%d ", i);
            if (++c % 5 == 0)
                printf("\n");
        }
    }
    printf("\n");
}

// [6]迴圈與陣列
void f06()
{
    int num[5];
    int i, max = 0, min, sum = 0;
    printf("Enter the 5 numbers:");
    min = 9999;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > max)
            max = num[i];
        if (num[i] < min)
            min = num[i];
        sum += num[i];
    }
    printf("The maximal number is:%d\n", max);
    printf("The minimal number is:%d\n", min);
    printf("The sum number is:%d\n", sum);
    printf("The ave number is:%f\n", sum / 5.0);
}
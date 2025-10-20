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
void f07();
void f08();

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
        case 7:
            f07();
            break;
        case 8:
            f08();
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
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    cout << "-----------------------------" << endl;
    cout << "---   班級 " << s_class << " 座號 " << s_seat << " 姓名 " << s_name << "    ---\n";
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

// [7]字串與字元 - 排序
void f07()
{
    int A[] = {2, 0, 1, 8, 11, 5};
    int n = sizeof(A) / sizeof(int);
    int i, j, k, tmp, ch = 0, c = 0;

    // 顯示原始陣列
    for (i = 0; i < n; i++)
    {
        printf("\t%d", A[i]);
    }
    cout << endl;

    cout << "----------泡沫排序法------------------------\n";
    // 泡沫排序法 (由大到小)
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                // 交換元素 (由小到大的話)
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                ch++;
            }
        }
        // 輸出比較結果
        cout << "***c=" << c << "\t";
        for (k = 0; k < n; k++)
        {
            printf("%d\t", A[k]);
        }
        cout << endl;
    }

    cout << "\t---------------------------------\n";

    cout << "次數 = " << c << ",交換次數=" << ch << endl;
    cout << "請輸入資料筆數:";
    int N = 1;
    cin >> N;
    cout << "泡沫排序法比較次數: " << N * (N - 1) / 2 << "次" << endl;

    cout << "2.-------選擇排序法-------------------\n";

    // 重新設定陣列
    int min;
    int B[] = {41, 33, 17, 80, 61, 5, 55};
    c = 0;
    ch = 0;

    // 計算陣列大小
    n = sizeof(B) / sizeof(int);

    // 顯示原始陣列
    for (i = 0; i < n; i++)
    {
        printf("\t%d", B[i]);
    }
    cout << endl;

    // 選擇排序法
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            // 找出最小值的索引
            if (B[min] > B[j])
            {
                min = j;
            }
            c++;
        }

        // 交換最小值至第i個位置
        tmp = B[min];
        B[min] = B[i];
        B[i] = tmp;

        // 輸出排序過程
        for (j = 0; j < n; j++)
        {
            printf("\t%d", B[j]);
        }
        printf("\n");
    }

    cout << "次數 = " << c << endl;
    cout << "請輸入資料筆數:";
    cin >> N;
    cout << "選擇排序法比較次數: " << N * (N - 1) / 2 << "次" << endl;
}

// [8]遞迴 - 指標運算
void f08()
{
    int x = 89, y = 6, z = 4;
    cout << "[1]x y z變數記憶體位址0x" << &x << "\t0x" << &y << "\t0x" << &z << endl;
    cout << "[2]x y z變數位址 取值\t" << x << "\t" << y << "\t" << z << endl;

    int *p1;
    p1 = &x;
    y = *p1;
    cout << "[3]p1=" << &*p1 << "\t *p1=" << *p1 << endl;
    cout << "[4]p1=" << p1 << "\t *p1=" << *p1 << endl;
    cout << "[5]x=" << x << "\ty=" << y << "\tz=" << z << endl;

    int *p2;
    p2 = &z;
    *p2 = 3;
    cout << "[4]p2=" << p2 << "\t *p2=" << *p2 << endl;
    cout << "[5]x=" << x << "\ty=" << y << "\tz=" << z << endl;

    int *p3;
    int p4;
    p3 = p1;
    p4 = x;
    printf("[6]p3位址=%p,p1=%d\n", p1, *p1);
    printf("[7]p4位址=%x,p4=%d\n", &p4, p4);
    printf("[8]sizeof(p1)=%d Bytes,sizeof(*p1)=%d Bytes\n", (int)sizeof(p1), (int)sizeof(*p1));

    cout << "---------------------------------------\n";

    int a[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *pa = a;
    int *pb = &a[3];

    printf("[1]pa= %p =&a[0]= %p :*pa=%d=a[0]=%d\n", pa, &a[0], *pa, a[0]);
    printf("[2]pb= %p =&a[3]= %p :*pb=%d=a[3]=%d\n", pb, &a[3], *pb, a[3]);
    printf("[3]*(pb+2)=%d=a[3+2]=%d :*pb+2=a[3]+2=%d,*pb+2=%d\n", *(pb + 2), a[3 + 2], *pb + 2, *pb + 2);
    printf("[4]pb-pa=%ld,&a[3]-&a[0]=%ld\n", pb - pa, &a[3] - &a[0]);

    cout << "[5]練習:請以pb指標的方式計算a[0]的結果\n";
    cout << "    a[0]=" << "*(pb - 3)" << "=" << a[0] << endl;
    cout << "[6]練習:請以pb指標的方式計算a[3]+a[7]的結果\n";
    cout << "    a[3]+a[7]=" << "*pb + *(pb + 4)" << "=" << a[3] + a[7] << endl;
    cout << "[7]練習:請以pa指標的方式，以迴圈列出a陣列值的結果\n";
    // n為陣列長度
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]=%d ", i, *(pa + i));
    }
    cout << endl;

    cout << "---------------------------------------\n";

    int v;
    v = ++*pa; // ++(*pa)
    printf("[1]v=++*pa=%d,a[0] = %d, a[1] = %d, *pa = %d\n", v, a[0], a[1], *pa);

    v = *pa++; // *(pa++)
    printf("[2]v=*pa++=%d,a[0] = %d, a[1] = %d, *pa = %d\n", v, a[0], a[1], *pa);

    v = *++pa; // *(++pa)
    printf("[3]v=*++pa=%d,a[0] = %d, a[1] = %d, *pa = %d\n", v, a[0], a[1], *pa);
}
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
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
void f09();
void f10();
void f11();
int main() {
    string menuItem[] = {"[1]基本輸入與輸出1",
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

    while (selMenu != 0) {
        system("clear"); // Linux 使用 clear 代替 cls
        cout << "-----------------------------" << endl;
        int arrLength = sizeof(menuItem) / sizeof(menuItem[0]);
        for (i = 0; i < arrLength; i++) {
            cout << menuItem[i] << endl;
        }
        cout << "請輸入：";
        cin >> selMenu;

        switch (selMenu) {
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
        case 9:
            f09();
            break;
        case 10:
            f10();
            break;
        case 11:
            f11();
            break;
        }
        cout << "\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get(); // 代替 system("pause")
    }
    return 0;
}

void show_title() {
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    cout << "-----------------------------" << endl;
    cout << "---   班級 " << s_class << " 座號 " << s_seat << " 姓名 " << s_name
         << "    ---\n";
    cout << "-----------------------------" << endl;
}

// [1]基本輸入與輸出1
void f01() {
    int m, n, tmp, sum = 0;
    printf("Enter two numbers:");
    scanf("%d %d", &m, &n);
    if (m > n) {
        tmp = m;
        m = n;
        n = tmp;
    }
    for (int i = m; i <= n; i++) {
        sum += i;
    }
    printf("The sum is:%d\n", sum);
}

// [2]基本輸入與輸出2
void f02() {
    int a, b;
    printf("Enter the numbers:");
    scanf("%d %d", &a, &b);
    b = (a / 10) * 100;
    b += (a / 10) * 10;
    b += (a / 100);
    printf("Out:%d", b);
}

// [3]運算式與運算子2
void f03() {
    int a, b;
    printf("Enter two numbers:");
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        for (int j = 1; j <= b; j++) {
            printf("%dX%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }
    printf("\n");
}

// [4]遞增運算子
void f04() {
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
    while (a > 0) {
        ansHex[count] = h[a % 16];
        a = a / 16;
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%c", ansHex[i]);
    }
    printf("\n");

    // 轉2進制
    count = 0;
    a = b;
    while (a > 0) {
        ansBin[count] = h[a % 2];
        a = a / 2;
        count++;
    }

    printf("the BINARY value is ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%c", ansBin[i]);
    }
    printf("\n");
}

// [5]列舉
void f05() {
    int c = 0;
    for (int i = 150; i <= 300; i++) {
        int isPrime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
            if (++c % 5 == 0)
                printf("\n");
        }
    }
    printf("\n");
}

// [6]迴圈與陣列
void f06() {
    int num[5];
    int i, max = 0, min, sum = 0;
    printf("Enter the 5 numbers:");
    min = 9999;
    for (i = 0; i < 5; i++) {
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
void f07() {
    int A[] = {2, 0, 1, 8, 11, 5};
    int n = sizeof(A) / sizeof(int);
    int i, j, k, tmp, ch = 0, c = 0;

    // 顯示原始陣列
    for (i = 0; i < n; i++) {
        printf("\t%d", A[i]);
    }
    cout << endl;

    cout << "----------泡沫排序法------------------------\n";
    // 泡沫排序法 (由大到小)
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (A[j] > A[j + 1]) {
                // 交換元素 (由小到大的話)
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                ch++;
            }
        }
        // 輸出比較結果
        cout << "***c=" << c << "\t";
        for (k = 0; k < n; k++) {
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
    for (i = 0; i < n; i++) {
        printf("\t%d", B[i]);
    }
    cout << endl;

    // 選擇排序法
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            // 找出最小值的索引
            if (B[min] > B[j]) {
                min = j;
            }
            c++;
        }

        // 交換最小值至第i個位置
        tmp = B[min];
        B[min] = B[i];
        B[i] = tmp;

        // 輸出排序過程
        for (j = 0; j < n; j++) {
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
void f08() {
    int x = 89, y = 6, z = 4;
    cout << "[1]x y z變數記憶體位址0x" << &x << "\t0x" << &y << "\t0x" << &z
         << endl;
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
    printf("[8]sizeof(p1)=%d Bytes,sizeof(*p1)=%d Bytes\n", (int)sizeof(p1),
           (int)sizeof(*p1));

    cout << "---------------------------------------\n";

    int a[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *pa = a;
    int *pb = &a[3];

    printf("[1]pa= %p =&a[0]= %p :*pa=%d=a[0]=%d\n", pa, &a[0], *pa, a[0]);
    printf("[2]pb= %p =&a[3]= %p :*pb=%d=a[3]=%d\n", pb, &a[3], *pb, a[3]);
    printf("[3]*(pb+2)=%d=a[3+2]=%d :*pb+2=a[3]+2=%d,*pb+2=%d\n", *(pb + 2),
           a[3 + 2], *pb + 2, *pb + 2);
    printf("[4]pb-pa=%ld,&a[3]-&a[0]=%ld\n", pb - pa, &a[3] - &a[0]);

    cout << "[5]練習:請以pb指標的方式計算a[0]的結果\n";
    cout << "    a[0]=" << "*(pb - 3)" << "=" << a[0] << endl;
    cout << "[6]練習:請以pb指標的方式計算a[3]+a[7]的結果\n";
    cout << "    a[3]+a[7]=" << "*pb + *(pb + 4)" << "=" << a[3] + a[7] << endl;
    cout << "[7]練習:請以pa指標的方式，以迴圈列出a陣列值的結果\n";
    // n為陣列長度
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++) {
        printf("a[%d]=%d ", i, *(pa + i));
    }
    cout << endl;

    cout << "---------------------------------------\n";

    int v;
    v = ++*pa; // ++(*pa)
    printf("[1]v=++*pa=%d,a[0] = %d, a[1] = %d, *pa = %d\n", v, a[0], a[1],
           *pa);

    v = *pa++; // *(pa++)
    printf("[2]v=*pa++=%d,a[0] = %d, a[1] = %d, *pa = %d\n", v, a[0], a[1],
           *pa);

    v = *++pa; // *(++pa)
    printf("[3]v=*++pa=%d,a[0] = %d, a[1] = %d, *pa = %d\n", v, a[0], a[1],
           *pa);
}

void f09() {
    cout << "-------------------------------\n";
    int bk[3][4] = {0, 1, 2, 3, 11, 12, 13, 14, 21, 22, 23, 24};

    cout << "陣列指標\n";
    int (*p)[4] = bk;

    cout << "[1]&bk[0][0] =" << &bk[0][0] << endl;
    cout << "[2]*p = " << *p << endl;
    cout << "[3]*(p+2) = " << *(p + 2) << ",&bk[2][0]=" << &bk[2][0] << endl;
    cout << "[4]**(p+1) = " << **(p + 1) << endl;
    cout << "[5]*(*(p+1)+2) = " << *(*(p + 1) + 2) << endl;
    cout << "[6]bk[1][2] = " << bk[1][2] << endl;
    cout << "[7]bk[1][2] = " << bk[1][2] << endl;
    cout << "[7]練習:請以指標p的方式計算陣列值 3+13+22 的結果\n";
    cout << "*(p[0]+3)+*(p[1]+2)+*(p[2]+1)="
         << *(p[0] + 3) + *(p[1] + 2) + *(p[2] + 1) << endl;

    cout << "-------------------------------\n";
    cout << "指標陣列\n";

    int xx = 1, yy[4] = {2, 4, 6, 5}, zz[4] = {3, 7, 9, 5};
    int *pc[3] = {&xx, yy, &zz[1]};
    int *pc3 = &xx, *ptr_y = yy, *ptr_z = &zz[1];

    cout << "[1]xx=" << *pc[0] << endl;
    cout << "[2]yy[1]=" << yy[1] << ",*(pc[1]+1)=" << *(pc[1] + 1) << endl;
    cout << "[3]yy[2]+1=" << yy[2] + 1 << ",*(pc[1]+2)+1=" << *(pc[1] + 2) + 1
         << endl;
    cout << "[4]zz[2]*2=" << zz[2] * 2 << ",*(pc[2]+1)*2=" << *(pc[2] + 1) * 2
         << endl;
    cout << "[5]練習:請以指標pc的方式計算陣列值 xx+yy[1]+zz[2] 的結果\n";
    cout << "*pc[0]+" << "+*(pc[1]+1)"
         << "+*(pc[2]+1)=" << *pc[0] + *(pc[1] + 1) + *(pc[2] + 1) << endl;

    cout << "-------------------------------\n";

    int aa[] = {1, 2, 3, 4, 5};
    int *ptr = aa;
    cout << "[6]練習:請以指標ptr , 顯示陣列a所有值\n";
    for (int i = 0; i < 5; i++) {
        printf("aa[%d]=%3d ", i, *(ptr + i));
    }
    printf("\n");

    *(ptr++) += 100;
    *(++ptr) += 100;

    for (int i = 0; i < 5; i++) {
        printf("aa[%d]=%3d ", i, aa[i]);
    }
    cout << endl;
}

void f10() {
    string A = "A";
    printf("[1]'A'=%d,\"A\"=%d,\"ABC\"= %d A=%d\n", sizeof('A'), sizeof("A"),
           sizeof("ABC"), sizeof(A));

    char s1[] = "Hello";
    printf("[2]sizeof(s)=%d != strlen(s)=%d\n", sizeof(s1), strlen(s1));

    A = "macdonald";
    printf("[3]sizeof(\"macdonald\")=%d,sizeof(A)=%d\n", sizeof("macdonald"),
           sizeof(A));

    cout << sizeof("獵") << endl;
    cout << "-------------------------------\n";

    char c1[] = {'h', 'a', 'p', 'p', 'y'};
    char c2[] = {'h', 'a', 'p', 'p', 'y', '\0'};
    char c3[] = "happy";
    char *s = "happy";

    printf("[1]c1 = %s,sizeof(c1)=%d,strlen(c1)=%d\n", c1, sizeof(c1),
           strlen(c1));
    printf("[2]c2 = %s,sizeof(c2)=%d,strlen(c2)=%d\n", c2, sizeof(c2),
           strlen(c2));
    printf("[3]c3 = %s,sizeof(c3)=%d,strlen(c3)=%d\n", c3, sizeof(c3),
           strlen(c3));
    printf("[4]s = %s,sizeof(s)=%d,*s=%c,(s+1)=%s,*(s+1)=%c\n", s, sizeof(s),
           *s, (s + 1), *(s + 1));
    char c4[] = {'h', 'a', 'p', 'p', 'y', '\0', 'b', 'i',
                 'r', 't', 'h', 'd', 'a', 'y',  '\0'};
    s = &c4[6];
    printf("[5]c4 = %s,sizeof(c4)=%d,strlen(c4)=%d\n", c4, sizeof(c4),
           strlen(c4));
    printf("[6]c4[2] = %c =%d,sizeof(c4[2])=%d\n", c4[2], c4[2], sizeof(c4[2]));
    printf("[7]s = %s,(s+3)=%s,*(s+5)=%c\n", s, (s + 3), *(s + 5));

    printf("[8]試用指標s 顯示出 ayt \n");
    printf("%s%c\n", s + 6, *(s + 3));

    cout << "-------------------------------\n";
    char s2[] = "0123456789";
    char *pc = s2;
    char *pc2;
    pc2 = &s2[5];

    cout << "[1]sizeof(s2)=" << sizeof(s2) << endl;
    cout << "[2]*(pc+2)=" << *(pc + 2) << endl;
    cout << "[3]pc+2=" << pc + 2 << endl;
    cout << "[4]*pc2=" << *pc2 << endl;
    cout << "[5]pc2=" << pc2 << endl;

    cout << "[6]試用指標pc顯示出 8 , 指標pc2顯示出9" << endl;
    cout << *(pc + 8) << "+" << *(pc2 + 4) << "="
         << ((*(pc + 8) - '0') + (*(pc2 + 4) - '0')) << endl;

    cout << "[7]試用指標pc顯示出 789 , 指標pc2顯示出2" << endl;
    cout << (pc + 7) << *(pc2 - 3) << endl;
}

void f11() {
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    char data[3][20] = {"How are you?", "I am fine", "See you later"};
    char (*x)[20];
    x = data;
    printf("[1]%s %c\n", (*(x + 1) + 5), *(*(x + 1) + 5));

    printf("[2]練習:請以指標方式印出data的內容\n");
    printf("%s\n%s\n%s\n", *x, *(x + 1), *(x + 2));

    printf("[3]練習:請以指標方式印出later you? I\n");
    printf("%s %s %c\n", *(x + 2) + 8, *x + 8, **(x + 1));

    cout << "-------------------------------\n";
    int TotalSteps = 5;
    int Count = 0;
    char StepName[9][4] = {"拖", "脫", "洗", "沖", "蓋", "泡", "送"};
    int Select[5] = {3, 1, 5, 4, 6};

    for (Count = 0; Count < TotalSteps; Count += 1) {
        std::cout << StepName[Select[Count]];
    }
    cout << endl;

    printf("[4]練習:請以指標 p 印出結果\n");
    int *p = Select;
    for (Count = 0; Count < TotalSteps; Count += 1) {
        std::cout << StepName[p[Count]];
    }
    cout << endl;

    char (*y)[4];
    printf("[5]練習:請以陣列指標 y 印出[4]的結果\n");
    y = StepName;
    for (Count = 0; Count < TotalSteps; Count += 1) {
        printf("%s", *(y + p[Count]));
    }
    cout << endl;
    cout << "-------------------------------\n";

    char s1[] = "Make";
    char s2[] = {'F', 'a', 'k', 'e', 'r', '\0'};
    char *s3 = "Win Again";
    char s4 = 'g';
    char s5[] = {'F', 'a', 'k', 'e', 'r'};
    char *xx[4] = {s1, s2, &s3[4], &s4};

    printf("[1]%p %p %p\n", s1, s2, s3);
    printf("[2]%p %p %p\n", xx[0], xx[1], xx[2]);
    printf("[3]%s %s %s %c\n", s1, s2, s3, s4);
    printf("[4]%s %s %s %c\n", s1, s5, s3, s4);
    printf("[5]%c %c %c %c\n", *s1, *s2, *s3, s4);
    printf("[6]%s %s %c\n", xx[0], xx[1], xx[2][2], *xx[3]);
    printf("[6]%s %s %s %c\n", xx[0], xx[1], xx[2], *xx[3]);

    printf("[7]%c %c %c %c\n", *xx[0], *xx[1], *xx[2], *xx[3]);

    printf("[8]練習:請以指標xx 印出 k r Again gg\n");
    printf("%c %c %s %c%c\n", *(xx[0] + 2), *(xx[1] + 4), xx[2], *xx[3],
           *(xx[2] + 1));

    int n = 6;
    cout << "n=" << n << endl;
    int &g = n;
    int *k = &n;
    g++;
    printf("[5]n=%x,g=%x,k=%x\n", &n, &g, k);
    printf("[6]n=%d,g=%d,k=%d\n", n, g, *k);
    (*k)++;
    printf("[7]n=%d,g=%d,k=%d\n", n, g, *k);
}

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cmath>
#include <string>
#include <unistd.h>
#include <termios.h>
#define mypi 3.14
#define PI 3.14159 // 為 f05 新增的宏
using namespace std;

void loadEnv(const string &path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cerr << ".env file not found!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        size_t delimiter_pos = line.find('=');
        if (delimiter_pos != string::npos)
        {
            string key = line.substr(0, delimiter_pos);
            string value = line.substr(delimiter_pos + 1);
            // Remove quotes if they exist
            if (value.front() == '"' && value.back() == '"')
            {
                value = value.substr(1, value.length() - 2);
            }
            setenv(key.c_str(), value.c_str(), 1);
        }
    }
}

void f01();
void f02();
void f03();
void f04();
void f05();

int main()
{
    loadEnv(".env");
    string menuItem[] = {
        "[1]基本輸入與輸出",
        "[2]運算式與運算子1",
        "[3]運算式與運算子2",
        "[4]遞增遞減與位元運算",
        "[5]列舉與常數",
        "[6]陣列",
        "[7]搜尋",
        "[8]排序",
        "[9]函數與結構",
        "[10]遞迴"};
    int i, num;
    int selMenu = 99;
    while (selMenu != 0)
    {
        system("clear");
        cout << "-----------------------------" << endl;
        int arrLength = sizeof(menuItem) / sizeof(menuItem[0]);
        for (i = 0; i < arrLength; i++)
        {
            cout << menuItem[i] << endl;
        }
        cout << "-----------------------------" << endl;
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
        }
        cout << "\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }
}

void ClearScreen()
{
    // 使用 ANSI escape codes 清除螢幕
    std::cout << "\033[2J\033[1;1H";
}

void f01()
{
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    if (s_class && s_seat && s_name)
    {
        cout << "班級:" << s_class << " 座號:" << s_seat << " 姓名:" << s_name << "\n";
    }
    else
    {
        cout << "未在 .env 檔案中設定個人資訊，請檢查 .env 檔案。\n";
    }
    int aa = 5, bb; // bb 宣告了但未使用，與圖片程式碼一致
    aa *= 5 + 2;    // aa = 5 * (5 + 2) = 35
    std::cout << aa << std::endl;
    std::cout << "------------------1----------------\n";
    std::cout << "hint:%x 16進制 %o 8進制 %d %i 10進制 %c 字元\n";

    int x = 21;
    int y = 021;             // 8進位 (等於十進位的 17)
    int z = 0x0d;            // 16進位 (等於十進位的 13)
    float qe = 1.62e-19f, q; // q 宣告了但未使用
    float pi = 3.141596f;
    char a = 'a', A = 'A';
    int k = 2147483647;            // 32位元有符號整數的最大值
    char b1 = 0b10011001;          // 二進位 153，在 char 中會溢位變成 -103
    unsigned char b2 = 0b10011001; // 二進位 153

    // 根據圖片的輸出內容，使用 printf 進行格式化輸出
    // 註：要印出 '%' 字元本身，需要寫成 '%%'
    printf("[1]x=(%%d)%d=(%%o)%o=(%%x)%x\n", x, x, x);
    printf("   y=(%%d)%d=(%%o)%o=(%%x)%x\n", y, y, y);
    printf("   z=(%%d)%d=(%%o)%o=(%%x)%x\n", z, z, z);
    printf("[2]pi=(%%f)%f=(%%5.3f)%5.3f=(%%e)%e\n", pi, pi, pi);
    printf("   qe=(%%f)%f=(%%e)%e=(%%5.2e)%5.2e\n", qe, qe, qe);
    printf("[3]2147483647+1=%d\n", k + 1); // 整數溢位
    printf("[4]a(ascii)=(%%x)%xH=(%%d)%d=(%%c)%c\n", a, a, a);
    printf("[5]'A'=(%%d)%d, 'q'=(%%d)%d, '0'=(%%d)%d\n", 'A', 'q', '0');
    printf("   a-A=(%%d)%d, 'q'-'A'=(%%d)%d=(%%c)%c\n", a - A, 'q' - 'A', 'q' - 'A');
    printf("[6](char)    0b10011001=(%%d)%d=(%%x)%x\n", b1, b1);
    printf("   (unsigned)0b10011001=(%%d)%d=(%%x)%x\n", b2, b2);

    std::cout << "------------------2----------------\n";
    // 註：sizeof 的回傳型別為 size_t，為匹配 %d 格式符，將其轉型為 int
    printf("[7]sizeof(x)=%d\n", (int)sizeof(x));
    printf("[8]sizeof(qe)=%d\n", (int)sizeof(qe));
    printf("[9]sizeof('a')=%d\n", (int)sizeof('a'));     // 在 C++ 中，sizeof(char) 是 1
    printf("[a]sizeof(\"A\")=%d\n", (int)sizeof("A"));   // 包含字元 'A' 和結尾空字元 '\0'，所以是 2
    printf("[b]sizeof(\"AB\")=%d\n", (int)sizeof("AB")); // 包含 'A', 'B', '\0'，所以是 3
}

void f02()
{
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    if (s_class && s_seat && s_name)
    {
        cout << "班級:" << s_class << " 座號:" << s_seat << " 姓名:" << s_name << "\n";
    }
    else
    {
        cout << "未在 .env 檔案中設定個人資訊。\n";
    }
    cout << "-----------------1------------------\n";
    cout << "輸出格式練習\n";

    // 區塊 1: 整數格式化
    int a = 123;
    printf("a=(%%d)%d=(%%f)%f\n", a, a); // UB警告: %f 需要 double/float 型別，傳入 int
    printf(" 123456789\n");
    printf("[1]%5d(%%5d)\n", a);   // 寬度5，靠右對齊
    printf("[2]%-5d(%%-5d)\n", a); // 寬度5，靠左對齊
    printf("[3]%05d(%%05d)\n", a); // 寬度5，不足補0

    // 區塊 2: 浮點數格式化 (b)
    float b = 1.563;
    printf("[4]b=1.563=(%%f)%f=(%%d)%d\n", b, b); // UB警告: %d 需要 int 型別，傳入 float
    printf("[5]b=1.563=(%%2.1f)%2.1f\n", b);      // 寬度2(不足會忽略)，小數1位
    printf("[6]b=1.563=(%%6.2f)%6.2f\n", b);      // 寬度6，小數2位
    printf("[7]b=1.563=(%%5.3f)%5.3f\n", b);      // 寬度5，小數3位

    // 區塊 3: 浮點數格式化 (c)
    float c = 12345.163;
    printf("[9]c=12345.163=(%%f)%f=(%%d)%d\n", c, c); // UB警告: %d 需要 int 型別，傳入 float
    printf("[a]c=12345.163=(%%2.1f)%2.1f\n", c);      // 寬度2(不足會忽略)，小數1位
    printf("[b]c=12345.163=(%%6.2f)%6.2f\n", c);      // 寬度6(不足會忽略)，小數2位
    printf("[c]c=12345.163=(%%.3f)%.3f\n", c);        // 無寬度，小數3位
}

void f03()
{
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    if (s_class && s_seat && s_name)
    {
        cout << "班級:" << s_class << " 座號:" << s_seat << " 姓名:" << s_name << "\n";
    }
    else
    {
        cout << "未在 .env 檔案中設定個人資訊。\n";
    }
    cout << "-----------------1------------------\n";
    cout << "整數=整數/整數 浮點數=浮點數/整數\n";
    printf("\t\t\t%%d\t%%f\n");
    // UB: %f expects a double, but gets an int. The output matches the image.
    printf("[1]3/2\t\t%d\t%f\n", 3 / 2, 3 / 2);
    // UB: %d expects an int, but gets a double. The output matches the image.
    printf("[2]3/2.0\t\t%d\t%f\n", 3 / 2.0, 3 / 2.0);
    printf("   1/3.0\t\t%d\t%f\n", (int)(1 / 3.0), 1 / 3.0);
    printf("[3]sizeof(3-1.f)=%d\n", (int)sizeof(3 - 1.f)); // 3-1.f results in a float
    printf("   sizeof(3-1.)=%d\n", (int)sizeof(3 - 1.));   // 3-1. results in a double
    cout << "[4](cout)3/2=" << 3 / 2 << ",(cout)3/2.0=" << 3 / 2.0 << endl;

    cout << "-----------------1------------------\n";
    cout << "位元運算 關係運算\n";
    int b1 = 3, b2 = 5, b3 = -12;
    cout << "[5]b1|b2=" << (b1 | b2) << endl;
    cout << "[6]b1&b2=" << (b1 & b2) << endl;
    cout << "[7]b1<<1=" << (b1 << 1) << endl;
    cout << "[8]b3>>2=" << (b3 >> 2) << endl;
    cout << "[9]b1>b2 && b2>b3 =" << (b1 > b2 && b2 > b3) << endl;
    cout << "[a]b1>b2 || b2>b3 =" << (b1 > b2 || b2 > b3) << endl;
    cout << "[b]~b1+b1^b2=" << ((~b1 + b1) ^ b2) << endl;
    cout << "[c]~b1<<b1^b2=" << ((~b1 << b1) ^ b2) << endl;
    cout << "[d]1+2*5^4<<3=" << ((1 + 2 * 5) ^ (4 << 3)) << endl;
    cout << "[e]2<<2+4%6-2 = " << (2 << (2 + 4 % 6 - 2)) << endl;
    cout << "[f](14%(3^2)+2&-1)=" << ((14 % (3 ^ 2)) + (2 & -1)) << endl;

    cout << "-----------------2------------------\n";
    int x = 0x10, y = 10, z = 010; // x=16, y=10, z=8
    printf("[0]%-10s%6c%6c%6c\n", " ", 'x', 'y', 'z');
    printf("[0]%-10s%6d%6d%6d\n", " ", x, y, z);
    x += y += z; // x = x + (y = y + z) -> y=18, x=34
    printf("[1]%-10s%6d%6d%6d\n", "x+=y+=z", x, y, z);
    z += x += y; // z = z + (x = x + y) -> x=52, z=60
    printf("[2]%-10s%6d%6d%6d\n", "z+=x+=y", x, y, z);

    // 模擬圖片中的使用者輸入與判斷
    cout << "scores=";
    cin >> x;
    if (x > 60)
        printf("及格\n");
    else
        printf("不及格\n");

    // 圖片顯示了兩次輸入，這裡重現第二次輸入情境
    printf("scores=");
    scanf("%d", &x);
    printf("%s\n", x > 60 ? "及格" : "不及格");

    x = 8, y = 0, z = 2;
    z = x < 0 ? y : x > 0 ? 1
                          : 3; // z becomes 1
    printf("[3]%-10s%6d%6d%6d\n", "z=x<0?y:x>0?1:3", x, y, z);
}

void f04()
{
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    if (s_class && s_seat && s_name)
    {
        cout << "班級:" << s_class << " 座號:" << s_seat << " 姓名:" << s_name << "\n";
    }
    else
    {
        cout << "未在 .env 檔案中設定個人資訊。\n";
    }
    cout << "-----------------1------------------\n";
    cout << "遞增/遞減 運算子\n";
    int k = 3;
    cout << "k=" << k++ << std::endl; // 後置遞增：先取值 (3) 再遞增
    cout << "k=" << ++k << std::endl; // 前置遞增：先遞增 (k變5) 再取值
    cout << "k=" << k << std::endl;
    cout << "++k=" << ++k << std::endl;
    std::cout << "k++=" << k++ << std::endl;
    cout << "++k=" << ++k << std::endl;
    cout << "k=" << k << std::endl;
    float m = k++; // m=8, k=9
    cout << m << endl;
    cout << k << endl;

    cout << "-----------------2------------------\n";
    int x, y, z;
    x = 8, y = 0, z = 2;
    printf("[0]%-10s%4c%4c%4c\n", " ", 'x', 'y', 'z');
    printf("[0]%-10s%4d%4d%4d\n", " ", x, y, z);
    y = x++; // y=8, x=9
    printf("[1]%-10s%4d%4d%4d\n", "y=x++", x, y, z);

    // **警告**: 以下多個 printf 包含在單一表達式中使用多次自增/自減運算子修改同一變數的行為。
    // 這是 C/C++ 中的「未定義行為」(Undefined Behavior)，其結果會因編譯器、版本和最佳化設定而異。
    // 此處程式碼僅為重現圖片中的特定輸出，不應在實際專案中使用。

    x = 8, y = 0, z = 2;
    printf("[2]%-10s%4d%4d%4d (UB)\n", "x=x++", x++, x, z); // UB

    x = 8, y = 0, z = 2;
    y = x++ + 2; // y = 8 + 2 = 10, x becomes 9
    printf("[3]%-10s%4d%4d%4d\n", "y=x+++2", x, y, z);

    x = 8, y = 0, z = 2;
    y = x++ + x; // UB. 範例輸出顯示 y = 8 + 9 = 17
    printf("[4]%-10s%4d%4d%4d (UB)\n", "y=x+++x", x, y, z);

    x = 8, y = 0, z = 2;
    y = x++ + x++; // UB. 範例輸出顯示 y = 8 + 9 = 17
    printf("[5]%-10s%4d%4d%4d (UB)\n", "y=x+++x++", x, y, z);

    x = 8, y = 0, z = 2;
    x = x++ + x; // UB. 範例輸出顯示 x = 8 + 9 = 17
    printf("[6]%-10s%4d%4d%4d (UB)\n", "x=x+++x", x, y, z);

    x = 8, y = 0, z = 2;
    y = (x++) + x; // UB. 與 [4] 相同
    printf("[7]%-10s%4d%4d%4d (UB)\n", "y=(x++)+x", x, y, z);

    x = 8, y = 0, z = 2;
    y = (++x) + x; // UB. 範例輸出顯示 x 先變 9, y = 9 + 9 = 18
    printf("[8]%-10s%4d%4d%4d (UB)\n", "y=(++x)+x", x, y, z);

    x = 8, y = 0, z = 2;
    y = x++ + x++; // UB. 與 [5] 相同
    printf("[9]%-10s%4d%4d%4d (UB)\n", "y=x+++x++", x, y, z);

    x = 8, y = 0, z = 2;
    y = x-- + x; // UB. 範例輸出顯示 y = 8 + 7 = 15
    printf("[A]%-10s%4d%4d%4d (UB)\n", "y=x--+x", x, y, z);

    cout << "-----------------3------------------\n";
    int a, b;
    x = 3, y = 2, z = 1;
    a = (x *= (++y)) % (++z); // y=3, z=2. x=3*3=9. a=9%2=1
    printf("a=(x*=(++y))%%(++z)=%d,x=%d,y=%d,z=%d\n", a, x, y, z);

    x = 3, y = 2, z = 1;
    b = (x *= (++y)) * (++z); // y=3, z=2. x=3*3=9. b=9*2=18
    printf("b=(x*=(++y))*(++z)=%d,x=%d,y=%d,z=%d\n", b, x, y, z);

    x = 3, y = 2, z = 1;
    b = (x *= (++y)) % (++z); // y=3, z=2. x=3*3=9. b=9%2=1
    printf("b=(x*=(++y))%%(++z)=%d,x=%d,y=%d,z=%d\n", b, x, y, z);
}

void f05()
{
    const char *s_class = getenv("MY_CLASS");
    const char *s_seat = getenv("MY_SEAT");
    const char *s_name = getenv("MY_NAME");
    if (s_class && s_seat && s_name)
    {
        cout << "班級:" << s_class << " 座號:" << s_seat << " 姓名:" << s_name << "\n";
    }
    else
    {
        cout << "未在 .env 檔案中設定個人資訊。\n";
    }
    // enum: 一組具名的整數常數
    // x=0, y=1, z=10 (未指定則從前一個+1，第一個預設為0)
    enum dir
    {
        x,
        y,
        z = 10
    };
    const int DAY = 24;
    double area = 3 * 3 * PI;
    enum dir b = x;
    printf("一天有%d小時\n", DAY);
    printf("圓面積為:%.5f\n", area); // %.5f: 格式化為5位小數的浮點數
    printf("b = %d\ty = %d\tz=%d\n", b, y, z);

    // Run=1, Stop=2(自動), Pause=3, Exit=4(自動)
    enum States
    {
        Run = 1,
        Stop,
        Pause = 3,
        Exit
    };
    States StateMachine = Pause;
    int Command = 0;
    cout << "請輸入：";
    cin >> Command;
    if (Command == 1)
        StateMachine = Stop;
    if (Command == 2 && StateMachine == Pause)
        StateMachine = Run;
    if (Command == 3 || StateMachine == Stop)
        StateMachine = Exit;
    cout << StateMachine << endl;
}
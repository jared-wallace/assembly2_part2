#include <iostream>
using namespace std;

int a1[12],
    a2[12],
    a3[12];
char einStr[]    = "Enter integer #";
char moStr[]     = "Max of ";
char ieStr[]     = " ints entered...";
char emiStr[]    = "Enter more ints? (n or N = no, others = yes) ";
char begA1Str[]  = "beginning a1: ";
char procA1Str[] = "processed a1: ";
char commA2Str[] = "          a2: ";
char commA3Str[] = "          a3: ";
char dacStr[]    = "Do another case? (n or N = no, others = yes) ";
char dlStr[]     = "================================";
char byeStr[]    = "bye...";

int main()
{
      char reply;
      int used1,
          used2,
          used3,
          target,
          total,
          mean,
          *hopPtr1,
          *hopPtr2,
          *hopPtr21,
          *hopPtr3,
          *endPtr1,
          *endPtr2,
          *endPtr3;

      cout << endl;
      reply = 'y';
begW1:
      if (reply == 'n' || reply == 'N')
         goto endW1;
      used1 = 0;
      used2 = 0;
      used3 = 0;
      hopPtr1 = a1;
begW2:
      if (reply == 'n' || reply == 'N')
         goto endW2;
      cout << einStr;
      cout << (used1 + 1);
      cout << ':' << ' ';
      cin >> *hopPtr1;
      ++used1;
      ++hopPtr1;
begI1:
      if (used1 >= 12)
         goto E1;
      cout << emiStr;
      cin >> reply;
      goto endI1;
E1:
      cout << moStr << 12 << ieStr << endl;
      reply = 'n';
endI1:
      goto begW2;
endW2:
      cout << endl;
begI2:
      if (used1 <= 0)
         goto endI2;
      total = 0;
      hopPtr1 = a1;
      endPtr1 = a1 + used1;
begW3:
      if (hopPtr1 >= endPtr1)
         goto endW3;
      target = *hopPtr1;
      total += target;
begI3:
      if (target % 2 != 1)
         goto E3;
      hopPtr3 = a3 + used3 - 1;
      endPtr3 = a3;
      //while (hopPtr3 >= endPtr3)
begW4:      if (hopPtr3 < endPtr3)
         goto endW4;
begI4:
      if (*hopPtr3  <= target)
         goto E4;
      *(hopPtr3 + 1) = *hopPtr3;
      --hopPtr3;
      goto endI4;
E4:
      goto endW4;
endI4:
      goto begW4;
endW4:
      *(hopPtr3 + 1) = target;
      ++used3;
      goto endI3;
E3:
      hopPtr2 = a2;
      endPtr2 = a2 + used2;
begW5:
      if (hopPtr2 >= endPtr2)
         goto endW5;
begI5:
      if (*hopPtr2 < target)
         goto E5;
      hopPtr21 = endPtr2;
begW6:
      if (hopPtr21 <= hopPtr2)
         goto endW6;
      *hopPtr21 = *(hopPtr21 - 1);
      --hopPtr21;
      goto begW6;
endW6:
      goto endW5;
E5:
      ++hopPtr2;
endI5:
      goto begW5;
endW5:
      *hopPtr2 = target;
      ++used2;
endI3:
      mean = total/used1;
      hopPtr1++;
      goto begW3;
endW3:

      cout << begA1Str;
begI6:
      if (used1 <= 0)
         goto endI6;
      hopPtr1 = a1;
      endPtr1 = a1 + used1;
begDW1:
      cout << *hopPtr1 << ' ' << ' ';
      ++hopPtr1;
      if (hopPtr1 < endPtr1)
         goto begDW1;
endDW1:
endI6:
      cout << endl;

      cout << commA2Str;
begI7:
      if (used2 <= 0)
         goto endI7;
      hopPtr2 = a2;
      endPtr2 = a2 + used2;
begDW2:
      cout << *hopPtr2 << ' ' << ' ';
      ++hopPtr2;
      if (hopPtr2 < endPtr2)
         goto begDW2;
endDW2:
endI7:
      cout << endl;
      cout << commA3Str;
begI8:
      if (used3 <= 0)
         goto endI8;
      hopPtr3 = a3;
      endPtr3 = a3 + used3;
begDW3:
      cout << *hopPtr3 << ' ' << ' ';
      ++hopPtr3;
      if (hopPtr3 < endPtr3)
         goto begDW3;
endDW3:
endI8:
      cout << endl;

      hopPtr1 = a1;
      hopPtr2 = a2;
      hopPtr3 = a3;
      endPtr2 = a2 + used2;
      endPtr3 = a3 + used3;
begW7:
      if (hopPtr2 >= endPtr2 || hopPtr3 >= endPtr3)
         goto endW7;
begI9:
      if (*hopPtr2 >= *hopPtr3)
         goto E9;
      *hopPtr1 = *hopPtr2;
      ++hopPtr2;
      goto endI9;
E9:
      *hopPtr1 = *hopPtr3;
      ++hopPtr3;
endI9:
      ++hopPtr1;
      goto begW7;
endW7:
begW8:
      if (hopPtr2 >= endPtr2)
         goto endW8;
      *hopPtr1 = *hopPtr2;
      ++hopPtr2;
      ++hopPtr1;
      goto begW8;
endW8:
begW9:
      if (hopPtr3 >= endPtr3)
         goto endW9;
      *hopPtr1 = *hopPtr3;
      ++hopPtr3;
      ++hopPtr1;
      goto begW9;
endW9:

      hopPtr1 = a1;
      hopPtr2 = a2;
      hopPtr3 = a3;
      endPtr1 = a1 + used1;
      used2 = 0;
      used3 = 0;
begW10:
      if (hopPtr1 >= endPtr1)
         goto endW10;
      target = *hopPtr1;
begI10:
      if (target >= mean)
         goto E10;
      *hopPtr2 = target;
      ++used2;
      ++hopPtr2;
      goto endI10;
E10:
begI11:
      if (target <= mean)
         goto endI11;
      *hopPtr3 = target;
      ++used3;
      ++hopPtr3;
endI11:
endI10:
      ++hopPtr1;
      goto begW10;
endW10:

      cout << procA1Str;
begI12:
      if (used1 <= 0)
         goto endI12;
      hopPtr1 = a1;
      endPtr1 = a1 + used1;
begDW4:
      cout << *hopPtr1 << ' ' << ' ';
      ++hopPtr1;
      if (hopPtr1 < endPtr1)
         goto begDW4;
endDW4:
endI12:
      cout << endl;

      cout << commA2Str;
begI13:
      if (used2 <= 0)
         goto endI13;
      hopPtr2 = a2;
      endPtr2 = a2 + used2;
begDW5:
      cout << *hopPtr2 << ' ' << ' ';
      ++hopPtr2;
      if (hopPtr2 < endPtr2)
         goto begDW5;
endDW5:
endI13:
      cout << endl;
      cout << commA3Str;
begI14:
      if (used3 <= 0)
         goto endI14;
      hopPtr3 = a3;
      endPtr3 = a3 + used3;
begDW6:
      cout << *hopPtr3 << ' ' << ' ';
      ++hopPtr3;
      if (hopPtr3 < endPtr3)
         goto begDW6;
endDW6:
endI14:
      cout << endl;
endI2:
      cout << endl;
      cout << dacStr;
      cin >> reply;
      cout << endl;
      goto begW1;
endW1:
      cout << dlStr << '\n';
      cout << byeStr << '\n';
      cout << dlStr << '\n';

      return 0;
}


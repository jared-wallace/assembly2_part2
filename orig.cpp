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
               while (reply != 'n' && reply != 'N')
               {
                  used1 = 0;
                  used2 = 0;
                  used3 = 0;
                  hopPtr1 = a1;
                  while (reply != 'n' && reply != 'N')
                  {
                     cout << einStr;
                     cout << (used1 + 1);
                     cout << ':' << ' ';
                     cin >> *hopPtr1;
                     ++used1;
                     ++hopPtr1;
                     if (used1 < 12)
                     {
                        cout << emiStr;
                        cin >> reply;
                     }
                     else
                     {
                        cout << moStr << 12 << ieStr << endl;
                        reply = 'n';
                     }
                  }
                  cout << endl;

                  if (used1 > 0)
                  {
                     total = 0;
                     for (hopPtr1 = a1, endPtr1 = a1 + used1; hopPtr1 < endPtr1; ++hopPtr1)
                     {
                        target = *hopPtr1;
                        total += target;
                        if (target % 2 == 1)
                        {
                           hopPtr3 = a3 + used3 - 1;
                           endPtr3 = a3;
                           while (hopPtr3 >= endPtr3)
                           {
                              if (*hopPtr3 > target)
                              {
                                 *(hopPtr3 + 1) = *hopPtr3;
                                 --hopPtr3;
                              }
                              else
                              {
                                 break;
                              }
                           }
                           *(hopPtr3 + 1) = target;
                           ++used3;
                        }
                        else
                        {
                           hopPtr2 = a2;
                           endPtr2 = a2 + used2;
                           while (hopPtr2 < endPtr2)
                           {
                              if (*hopPtr2 >= target)
                              {
                                 hopPtr21 = endPtr2;
                                 while (hopPtr21 > hopPtr2)
                                 {
                                    *hopPtr21 = *(hopPtr21 - 1);
                                    --hopPtr21;
                                 }
                                 break;
                              }
                              else
                              {
                                 ++hopPtr2;
                              }
                           }
                           *hopPtr2 = target;
                           ++used2;
                        }
                        mean = total/used1;
                     }

                     cout << begA1Str;
                     if (used1 > 0)
                     {
                        hopPtr1 = a1;
                        endPtr1 = a1 + used1;
                        do
                        {
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
                        }
                        while (hopPtr1 < endPtr1);
                     }
                     cout << endl;

                     cout << commA2Str;
                     if (used2 > 0)
                     {
                        hopPtr2 = a2;
                        endPtr2 = a2 + used2;
                        do
                        {
                           cout << *hopPtr2 << ' ' << ' ';
                           ++hopPtr2;
                        }
                        while (hopPtr2 < endPtr2);
                     }
                     cout << endl;

                     cout << commA3Str;
                     if (used3 > 0)
                     {
                        hopPtr3 = a3;
                        endPtr3 = a3 + used3;
                        do
                        {
                           cout << *hopPtr3 << ' ' << ' ';
                           ++hopPtr3;
                        }
                        while (hopPtr3 < endPtr3);
                     }
                     cout << endl;

                     hopPtr1 = a1;
                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     endPtr2 = a2 + used2;
                     endPtr3 = a3 + used3;
                     while (hopPtr2 < endPtr2 && hopPtr3 < endPtr3)
                     {
                        if (*hopPtr2 < *hopPtr3)
                        {
                           *hopPtr1 = *hopPtr2;
                           ++hopPtr2;
                        }
                        else
                        {
                           *hopPtr1 = *hopPtr3;
                           ++hopPtr3;
                        }
                        ++hopPtr1;
                     }
                     while (hopPtr2 < endPtr2)
                     {
                        *hopPtr1 = *hopPtr2;
                        ++hopPtr2;
                        ++hopPtr1;
                     }
                     while (hopPtr3 < endPtr3)
                     {
                        *hopPtr1 = *hopPtr3;
                        ++hopPtr3;
                        ++hopPtr1;
                     }

                     hopPtr1 = a1;
                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     endPtr1 = a1 + used1;
                     used2 = 0;
                     used3 = 0;
                     while (hopPtr1 < endPtr1)
                     {
                        target = *hopPtr1;
                        if (target < mean)
                        {
                           *hopPtr2 = target;
                           ++used2;
                           ++hopPtr2;
                        }
                        else
                        {
                           if (target > mean)
                           {
                              *hopPtr3 = target;
                              ++used3;
                              ++hopPtr3;
                           }
                        }
                        ++hopPtr1;
                     }

                     cout << procA1Str;
                     if (used1 > 0)
                     {
                        hopPtr1 = a1;
                        endPtr1 = a1 + used1;
                        do
                        {
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
                        }
                        while (hopPtr1 < endPtr1);
                     }
                     cout << endl;

                     cout << commA2Str;
                     if (used2 > 0)
                     {
                        hopPtr2 = a2;
                        endPtr2 = a2 + used2;
                        do
                        {
                           cout << *hopPtr2 << ' ' << ' ';
                           ++hopPtr2;
                        }
                        while (hopPtr2 < endPtr2);
                     }
                     cout << endl;

                     cout << commA3Str;
                     if (used3 > 0)
                     {
                        hopPtr3 = a3;
                        endPtr3 = a3 + used3;
                        do
                        {
                           cout << *hopPtr3 << ' ' << ' ';
                           ++hopPtr3;
                        }
                        while (hopPtr3 < endPtr3);
                     }
                     cout << endl;
                  }

                  cout << endl;
                  cout << dacStr;
                  cin >> reply;
                  cout << endl;
               }

               cout << dlStr << '\n';
               cout << byeStr << '\n';
               cout << dlStr << '\n';

               return 0;
}


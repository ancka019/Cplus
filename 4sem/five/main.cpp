//Задача по  поиску кол. максимальных гостей в любое время на вечеринке
#include<iostream>
#include<algorithm>

using namespace std;


void findMaxGuests(int array[], int exit[], int n)
{
   // Сортировка массивов прибытия и выхода
   sort(array, array + n);
   sort(exit, exit+n);
   int guests = 1, max_guests = 1, time = array[0];
   int i = 1, j = 0;
   while (i < n && j < n)
   {
      if (array[i] <= exit[j])

      {
          guests++;
          if (guests > max_guests)
          {
              max_guests = guests;
              time = array[i];
          }

          i++;
      }
      else
      {
          guests--;
          j++;
      }
   }
   cout << "Maximum number of guests = " << max_guests << " at time " << time;

}

int main()
{
    int array[] = {1, 2, 10, 5, 5};
    int exit[] = {4, 5, 12, 9, 12};
    int n = sizeof(array)/sizeof(array[0]);
    findMaxGuests(array, exit, n);
    return 0;
}
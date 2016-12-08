/*
Задача на программирование: непрерывный рюкзак

Первая строка содержит количество предметов 1≤n≤10^3 и вместимость рюкзака 0≤W≤2*10^6.
Каждая из следующих nn строк задаёт стоимость 0≤ci≤2*10^6 и объём 0<wi≤2*10^6 предмета (n, W, ci, wi — целые числа).
Выведите максимальную стоимость частей предметов 
(от каждого предмета можно отделить любую часть, стоимость и объём при этом пропорционально уменьшатся), 
помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Item final {
  int weight;
  int value;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
  double value = 0.0;

  std::sort(items.begin(), items.end(), [] (const Item& a, const Item& b) { 
    auto aPrice = static_cast <double>(a.value) / a.weight;
    auto bPrice = static_cast <double>(b.value) / b.weight;
    return bPrice < aPrice; 
  });

  // take items while there is empty space in knapsack
  for (auto &item:items) {
    if (capacity > item.weight) {
      // can take full item and continue
      capacity -= item.weight;
      value += item.value;
    } else {
      value += item.value * (static_cast <double>(capacity) / item.weight);
      break;
    }
  }

  return value;
}

int main(void) {
  int number_of_items;
  int knapsack_capacity;
  std::cin >> number_of_items >> knapsack_capacity;
  std::vector <Item> items(number_of_items);
  for (auto &item : items) {
    std::cin >> item.value >> item.weight;
  }

  double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

  std::cout.precision(3);
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout << max_knapsack_value << std::endl;
  return 0;
}

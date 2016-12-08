#include <iostream>
#include <vector>
#include <ios>

unsigned long long counter = 0;
void merge(std::vector<int>& numbers, int l, int r) {
    int m = (l + r) * 0.5;
    int i = l;
    int j = m + 1;

    std::vector<int> temp(r-l+1);
    for (int k = 0; k < temp.size(); k++) {
        if (i <= m && j <= r) {
        	if (numbers[i] <= numbers[j]) {
        		temp[k] = numbers[i++];
        	}
        	else {
            	counter += j - k - l;
            	temp[k] = numbers[j++];
        	}
        }
        else if (i <= m) {
            temp[k] = numbers[i++];
        }
        else if (j <= r) {
            temp[k] = numbers[j++];
        }
    }

    for (int i = l, j = 0; i <= r; i++) {
        numbers[i] = temp[j++];
    }
}

void mergeSort(std::vector<int>& numbers, int l, int r) {
    if (l < r) {
        int m = (l + r) * 0.5;
        mergeSort(numbers, l, m);
        mergeSort(numbers, m + 1, r);
        merge(numbers, l, r);
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    size_t n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (auto &number : numbers) {
        std::cin >> number;
    }

    mergeSort(numbers, 0, n - 1);

    std::cout << counter;
    std::cout << std::endl;

    return 0;
}

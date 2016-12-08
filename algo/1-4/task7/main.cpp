#include <iostream>
#include <vector>

class PriorityQueue
{
public:
	int ExtractMax() {
		int result = _queue[0];
		int newMax = _queue.back();
		_queue.pop_back();
		if (_queue.size() > 0) {
			_queue[0] = newMax;
		}

		ShiftDown(0);

		return result;
	}

	void Insert(int num) {
		_queue.push_back(num);

		ShiftUp(_queue.size()-1);
	}

private:
	void ShiftDown(int index) {
		int size = _queue.size();
		int leftIndex = index * 2 + 1;
		int rightIndex = index * 2 + 2;
		int curNum = _queue[index];
		int left = leftIndex < size ? _queue[leftIndex] : -1;
		int right = rightIndex < size ? _queue[rightIndex] : -1;
		int maxIndex = left > right ? leftIndex : rightIndex;
		int maxNum = left > right ? left : right;

		if (curNum < maxNum) {
			int temp = _queue[index];
			_queue[index] = _queue[maxIndex];
			_queue[maxIndex] = temp;
			ShiftDown(maxIndex);
		}
	}

	void ShiftUp(int index) {
		int parentIndex = (index+1) / 2 - 1;
		int curNum = _queue[index];

		if (parentIndex >= 0) {
			int parentNum = _queue[parentIndex];
			if (curNum > parentNum) {
				int temp = _queue[index];
				_queue[index] = parentNum;
				_queue[parentIndex] = temp;
				ShiftUp(parentIndex);
			}
		}
	}

private:
	std::vector<int> _queue;
};


int main(void) {
    int length;
    std::cin >> length;

    PriorityQueue queue;
    for (int i = 0; i < length; i++) {
    	std::string command;
    	std::cin >> command;
    	if (command == "Insert") {
    		int num;
    		std::cin >> num;
    		queue.Insert(num);
    	} else if (command == "ExtractMax") {
    		std::cout << queue.ExtractMax() << " ";
    	} else {
    		std::cout << "Unknown command: " << command;
    		break;
    	}
    }

    std::cout << std::endl;

    return 0;
}

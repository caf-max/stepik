#pragma once

#include <map>
#define MEM_SIZE 1048576


class SmallAllocator {
private:
        char Memory[MEM_SIZE];
	std::map<int, int> PointersMap;
public:
        void *Alloc(unsigned int Size) {
		int offset = 0;
		for (auto &pointer : PointersMap) {
			if (offset + Size < pointer.first) {
				break;
			}
			else {
				offset = pointer.first + pointer.second;
			}
		}

		if (offset + Size > MEM_SIZE) return nullptr;
		PointersMap[offset] = Size;
		return static_cast<void*>(&Memory[offset]);
        };

        void *ReAlloc(void *Pointer, unsigned int Size) {
		int offset = (char*)Pointer - Memory;
		unsigned int oldSize = PointersMap[offset];
		auto nextPointer = PointersMap.upper_bound(offset);
		int nextOffset = nextPointer == PointersMap.end() ? MEM_SIZE : nextPointer->first;
		if (offset + Size <= nextOffset) {
			PointersMap[offset] = Size;
			return Pointer;
		}

		void *newPointer = Alloc(Size);
		if (!newPointer) return nullptr;

		for (int i = 0; i < oldSize; i++) {
			static_cast<char*>(newPointer)[i] = static_cast<char*>(Pointer)[i];
		}
		Free(Pointer);

		return newPointer;
        };

        void Free(void *Pointer) {
		int offset = (char*)Pointer - Memory;
		PointersMap.erase(offset);
        };
};

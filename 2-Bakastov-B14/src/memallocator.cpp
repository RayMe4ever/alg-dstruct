#ifdef __cplusplus
extern "C" {
#endif

#include"memallocator.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

	typedef struct memblock {
		int size;
		struct memblock* next;
		int isFree;
	}memblock;

	typedef struct {
		memblock* block;
		int size;
	}memAllocator;

	memAllocator Allocator = { (memblock*)NULL };

	int memgetminimumsize() {
		return sizeof(memblock);
	}

	int memgetblocksize() {
		return sizeof(memblock);
	}

	int meminit(void* InitMem, int size) {
		Allocator.size = size;
		Allocator.block = (memblock*)InitMem;
		Allocator.block->size = size - memgetminimumsize();
		Allocator.block->next = NULL;
		Allocator.block->isFree = 1;
		return 0;
	}

	void* memalloc(int size) {

		void* res = NULL;
		memblock* cur = Allocator.block;
		memblock* addnext = NULL;
		memblock* pointerBestFit = NULL;
		int blockSize = memgetblocksize();

		while (cur) {
			if ((cur->size >= size) && (pointerBestFit == NULL || (cur->size < pointerBestFit->size)) && (cur->isFree))
				pointerBestFit = cur;
			else cur = cur->next;
		}

		if (pointerBestFit) {
			if (pointerBestFit->size <= size + memgetminimumsize())
				pointerBestFit->isFree = 0;
			else {
				if (pointerBestFit->next && pointerBestFit->next - (pointerBestFit + size) < memgetminimumsize())
				{
					pointerBestFit->isFree = 0;
					pointerBestFit->size = size;
				}
				else {
					addnext = (memblock*)((char*)pointerBestFit + size + blockSize);
					addnext->next = pointerBestFit->next;
					addnext->isFree = 1;
					pointerBestFit->next = addnext;
					pointerBestFit->isFree = 0;
					addnext->size = pointerBestFit->size - size - blockSize;
					pointerBestFit->size = size;
				}
			}
			res = (void*)((char*)pointerBestFit + blockSize);
		}
		else {
			res = NULL;
		}
		return res;
	}

	void memfree(void* memory) {
		int blockSize = memgetblocksize();
		memblock* cur = Allocator.block;
		memblock* prev = NULL;
		memblock* next = NULL;
		while (cur) {
			if ((char*)memory != (char*)(cur + 1)) {
				prev = cur;
				cur = cur->next;
			}
			else if ((char*)(cur + 1) == (char*)memory)
				break;
			else return;
		}

		if (!cur || cur->isFree)
			return;

		if (cur->next && cur->next->isFree) {
			cur->size += cur->next->size + blockSize;
			cur->next = cur->next->next;
		}

		if (prev && prev->isFree) {
			prev->size += blockSize + cur->size;
			prev->next = cur->next;
		}

		cur->isFree = 1;
		return;
	}

	void memdone() {
		Allocator.size = 0;
		Allocator.block = NULL;
	}

#ifdef __cplusplus
}
#endif 
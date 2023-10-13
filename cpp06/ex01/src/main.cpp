#include "Serializer.hpp"

int	main(void)
{
	Data	stack;

	stack.value = 10;
	Data	*stackPtr = &stack;

	Serializer	s;

	uintptr_t	stackAddr = s.serialize(stackPtr);
	std::cout << HERB << "Stack) Serialized: " << stackAddr << RESET << std::endl;
	Data	*returnedStackPtr = s.deserialize(stackAddr);
	std::cout << HERB << "Stack) Stored value inside: " << returnedStackPtr->value << RESET << std::endl;
	
	Data	*heapPtr = new Data;
	heapPtr->value = 13;

	uintptr_t	heapAddr = s.serialize(heapPtr);
	std::cout << HERB << "Heap) Serialized: " << heapAddr << RESET << std::endl;
	Data	*returnedHeapPtr = s.deserialize(heapAddr);
	std::cout << HERB << "Heap) Stored value inside: " << returnedHeapPtr->value << RESET << std::endl;

	delete heapPtr;
	return (0);
}

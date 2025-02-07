
The new keyword performs the following actions: Allocates Memory: It dynamically
allocates memory for an object of the specified type (Zombie in this case) on the heap.
Unlike stack memory, heap memory is not automatically managed and must be explicitly
freed. Invokes the Constructor: After allocating memory, new calls the constructor of
the object and initializes it with the provided arguments (name in this case). Returns
a Pointer: The new keyword returns a pointer to the newly created object in heap memory.


### If you create an object without using new, it is allocated on the stack

// Allocated on the stack

- Zombie myZombie("StackZombie");

* The object is destroyed automatically when it goes out of scope (e.g., when the function ends).

### If you create an object using the new keyword, it is allocated on the heap.

// Allocated on the heap

- Zombie* myZombie = new Zombie("HeapZombie");

* The object persists until you explicitly free the memory using delete:

- delete myZombie;


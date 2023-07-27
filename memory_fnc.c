/**
 * _malloc - allocates memory and returns a pointer to it
 * @size: no. of bytes to be allocated
 * Return: a generic pointer allocated or -1 on faliure
 */

void *_malloc(unsigned int size)
{
	char *pointer = malloc(size);
	void *_pointer = NULL;
	unsigned int i = 0;

	if (!pointer)
	{
		print_error(NULL, NULL, "ERROR ALLOCATING MEMORY");
		exit(-1);
	}
	while (i < size)
	{
		pointer[i] = '\0';
		i += 1;
	}
	_pointer = (void *)pointer;
	return (_pointer);
}
/**
 * _realloc - rallocates a memory location and returns a pointer
 * @ptr: pointer to null terminated memory block
 * @size: new size
 *
 * Return: a generic pointer reallocated memory or -1 on faliure
 */

void *_realloc(void *ptr, unsigned int size)
{
	char *_pointer = (char *)_malloc(size), *_ptr = (char *)ptr;
	void *pointer = NULL;
	int i = 0;

	if (!_ptr)
	{
		pointer = _pointer;
		return (pointer);
	}
	while (_ptr[i])
	{
		_pointer[i] = _ptr[i];
		i += 1;
	}
	_pointer[i] = '\0';
	pointer = (void *)_pointer;
	free(ptr);
	return (pointer);
}

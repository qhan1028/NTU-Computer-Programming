void prepare_array(int buffer[], int *array[], int row, int column[])
{
	int i, a = 0;

	for (i = 0 ; i < row ; i++) {
		array[i] = &buffer[a];
		a = a + column[i];
	}
	return;
}
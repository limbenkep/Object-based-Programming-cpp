#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H



/**
 * Generate randome number in range specified
 * @param min The minimum value
 * @param max The maximum value
 * @return a random int in the range [min, max]
 */
int randomNumber(const int min, const int max);

/**
 * prompts the user for a size of array and controls that the size is greater than zero
 * @return the number entered by the user
 */
int getNumber();

/**
 * Iterate the pointer through the array and obtains a pointer to the smallest element in the array,
 * and in case there are more than one such element, then it points to the first one. The value of
 * the smallest element is obtained
 * @param arr the array
 * @param size the size of the array
 * @return the value of the smallest element in the array
 */
int minValueOfArray(int arr[], int size);

/**
 * Iterate the pointer through the array and obtains a pointer to the largest element in the array,
 * and in case there are more than one such element, then it points to the first one.
 * the largest element is obtained
 * @param arr the array
 * @param size the size of the array
 * @return the value of the largest element in the array
 */
int maxValueOfArray(int arr[], int size);

/**
 *  Starts from the first element and iterate through each element and add the current element to the sum
 * @param arr The array
 * @param size The size of the array
 * @return the sum of the all the elements in the array
 */
int sumOfArray(int arr[], int size);

/**
 * Prints the array, the value of largest element, the value of the smallest element and
 * the sum of the elements in the array.
 * @param arr The array
 * @param size the size of the array
 */
void arrayStatistics(int arr [], int size);

/**
 * Print elements of the array 200 at a time
 * @param arr
 * @param size
 */
void printArray(int arr[], int size);
int sumArray(int arr[], int size);
const int MIN_VALUE = -5000;
const int MAX_VALUE = 5000;
#endif  // DT018G_PROTOTYPES_H

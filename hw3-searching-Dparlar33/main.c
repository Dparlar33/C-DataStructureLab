#include <stdio.h>
void Yazdir(int ar[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%3d", ar[i]);
	}
	printf("\n");
}
void Sorting(int a[], int size) {
	int temp = 0, i;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int LinearIntArraySearch(int a[], int key, int Size) {
	for (int i = 0; i < Size; i++) {
		if (a[i] == key) {
			return i;
			break;
		}
	}
	return -1;
}
int BinaryIntArraySearch(int a[], int Size, int key) {
	int left = 0, right = Size - 1, middle;
	Sorting(a, Size);
	while (left <= right) {
		middle = (right + left) / 2;
		if (key == a[middle]) {
			return middle;
			break;
		}
		else if (key > a[middle]) {
			left = middle + 1;
		}
		else
			right = middle - 1;
	}
	return -1;
}
/*typedef struct StudentRecord {
	int no;
	char Fullname[50];
	int grade;
}Student;

int LinearSearchStruct(Student a[], int size, char *key) {
	for (int i = 0; i < size; i++) {
		if (a[i] == key) {
			return i;
			break;
		}
	}
	return -1;

}*/
int main() {
	int array1[15] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	int array2[15] = { 3,44,48,5,47,15,36,26,27,2,48,5,19,50,48 };
	int A[12];
	int k = sizeof(array1) / sizeof(array1[0]);
	printf("Array 1:"); Yazdir(array1, k);
	printf("Array 2:"); Yazdir(array2, k);
	printf("Searching keys are : 3 5 48\n");
	printf("With the Linear Searching\n");


	A[0] = LinearIntArraySearch(array1, 3, k);
	if (A[0] != -1) { printf("\n3 in the %d. index in Array1", A[0] + 1); }
	else printf("\nCouldnt find in array");
	A[1] = LinearIntArraySearch(array1, 5, k);
	if (A[1] != -1) { printf("\n5 in the %d. index in Array1", A[1] + 1); }
	else printf("\nCouldnt find in array");
	A[2] = LinearIntArraySearch(array1, 48, k);
	if (A[2] != -1) { printf("\n48 in the %d. index in Array1\n", A[2] + 1); }
	else printf("\nCouldnt find in array");

	A[3] = LinearIntArraySearch(array2, 3, k);
	if (A[3] != -1) { printf("\n3 in the %d. index in Array2", A[3] + 1); }
	else printf("\nCouldnt find in array");
	A[4] = LinearIntArraySearch(array2, 5, k);
	if (A[4] != -1) { printf("\n5 in the %d. index in Array2", A[4] + 1); }
	else printf("\nCouldnt find in array");
	A[5] = LinearIntArraySearch(array2, 48, k);
	if (A[5] != -1) { printf("\n48 in the %d. index in Array2", A[5] + 1); }
	else printf("\nCouldnt find in array");
	printf("\n\nWith the Binary Searching\n");



	A[6] = BinaryIntArraySearch(array1, k, 3);
	if (A[6] != -1) { printf("\n3 in the %d. index in Array1", A[6] + 1); }
	else printf("\nCouldnt find in array");
	A[7] = BinaryIntArraySearch(array1, k, 5);
	if (A[7] != -1) { printf("\n5 in the %d. index in Array1", A[7] + 1); }
	else printf("\nCouldnt find in array");
	A[8] = BinaryIntArraySearch(array1, k, 48);
	if (A[8] != -1) { printf("\n48 in the %d. index in Array1\n", A[8] + 1); }
	else printf("\nCouldnt find in array\n");


	A[9] = BinaryIntArraySearch(array2, k, 3);
	if (A[9] != -1) { printf("\n3 in the %d. index in Array2", A[9] + 1); }
	else printf("\nCouldnt find in array");
	A[10] = BinaryIntArraySearch(array2, k, 5);
	if (A[10] != -1) { printf("\n5 in the %d. index in Array2", A[10] + 1); }
	else printf("\nCouldnt find in array");
	A[11] = BinaryIntArraySearch(array2, k, 48);
	if (A[11] != -1) { printf("\n48 in the %d. index in Array2", A[11] + 1); }
	else printf("\nCouldnt find in array");


	/* Student *Student1[3];
char Names[3][25];
int Numaralar[3];
int Grade[3];
FILE* fp = fopen("data.txt", "r");
int i = 0;

if (fp != NULL) {
	while(!feof(fp)){
		fscanf(fp, "%d %s %d", &Numaralar[i],&Names[i],&Grade[i]);
		i++;
	}
}
	else
		printf("Couldnt find");                 //I tried but i couldn't . sorry for this ,teacher. I should work on Files i realized that at least :)
Student* ptr;
for (i; i < 3; i++) {
	ptr = (Student*)malloc(50 * sizeof(Student));
	Student1[i]->no = Numaralar[i];
	Student1[i]->Fullname = Names[i];
	Student1[i]->grade = Grade[i];
}

int indis1 = LinearSearchStruct(Student1, 3, "Mehmet Ipek");
int indis2 = LinearSearchStruct(Student1, 3, "Deniz Ugur");
int indis3 = LinearSearchStruct(Student1, 3, "2019556465");
int indis4 = LinearSearchStruct(Student1, 3,"100");
int indis5 = LinearSearchStruct(Student1, 3, "73"); */
}

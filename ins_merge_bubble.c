#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int roll_no;
    float total_marks;
};

// Global swap counters
int insertion_swaps = 0, bubble_swaps = 0, merge_swaps = 0;

// Swap two students
void swap(struct Student *a, struct Student *b)
{
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(struct Student s[], int n)
{
    for (int i = 1; i < n; i++)
    {
        struct Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll_no > key.roll_no)
        {
            s[j + 1] = s[j];
            j--;
            insertion_swaps++;
        }
        s[j + 1] = key;
    }
}

void bubbleSort(struct Student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].roll_no > s[j + 1].roll_no)
            {
                swap(&s[j], &s[j + 1]);
                bubble_swaps++;
            }
        }
    }
}

void merge(struct Student s[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int size = r - l + 1;
    struct Student temp[size];

    while (i <= m && j <= r)
    {
        if (s[i].roll_no <= s[j].roll_no)
            temp[k++] = s[i++];
        else
        {
            temp[k++] = s[j++];
            merge_swaps += (m - i + 1); // Count swap as inversion
        }
    }
    while (i <= m)
        temp[k++] = s[i++];
    while (j <= r)
        temp[k++] = s[j++];
    for (i = 0; i < k; i++)
        s[l + i] = temp[i];
}

void mergeSort(struct Student s[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(s, l, m);
        mergeSort(s, m + 1, r);
        merge(s, l, m, r);
    }
}

void display(struct Student s[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %d %.2f\n", s[i].name, s[i].roll_no, s[i].total_marks);
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n], copy[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter name, roll no, total marks: ");
        scanf("%s %d %f", s[i].name, &s[i].roll_no, &s[i].total_marks);
    }

    memcpy(copy, s, sizeof(s));
    insertionSort(copy, n);
    printf("\nInsertion Sort (by roll no):\n");
    display(copy, n);
    printf("Swaps: %d\n", insertion_swaps);

    memcpy(copy, s, sizeof(s));
    bubbleSort(copy, n);
    printf("\nBubble Sort (by roll no):\n");
    display(copy, n);
    printf("Swaps: %d\n", bubble_swaps);

    memcpy(copy, s, sizeof(s));
    mergeSort(copy, 0, n - 1);
    printf("\nMerge Sort (by roll no):\n");
    display(copy, n);
    printf("Swaps (inversions): %d\n", merge_swaps);

    return 0;
}

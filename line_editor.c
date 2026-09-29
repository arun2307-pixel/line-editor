#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char document[MAX_LINES][MAX_LENGTH];
int lineCount = 0;
void insertLine(int position, char text[])
{
    for (int i = lineCount; i >= position; i--)
    {
        strcpy(document[i], document[i - 1]);
    }

    strcpy(document[position - 1], text);
    lineCount++;
}
void deleteLine(int position)
{
    for (int i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(document[i], document[i + 1]);
    }

    lineCount--;
}
void displayDocument()
{
    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, document[i]);
    }
}
int main()
{
    int choice, position;
    char text[MAX_LENGTH];

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            printf("Enter line number: ");
            scanf("%d", &position);
            getchar();

            printf("Enter text: ");
            fgets(text, MAX_LENGTH, stdin);
            text[strcspn(text, "\n")] = '\0';

            insertLine(position, text);
        }
        else if (choice == 2)
        {
            printf("Enter line number: ");
            scanf("%d", &position);

            deleteLine(position);
        }
        else if (choice == 3)
        {
            displayDocument();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
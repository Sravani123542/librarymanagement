#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50], author[50];
};

struct Book library[100];
int count = 0;

void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);
    printf("Enter Title: ");
    getchar();  // Consume newline
    fgets(library[count].title, 50, stdin);
    library[count].title[strcspn(library[count].title, "\n")] = 0;  // Remove newline
    printf("Enter Author: ");
    fgets(library[count].author, 50, stdin);
    library[count].author[strcspn(library[count].author, "\n")] = 0;  // Remove newline
    count++;
}

void viewBooks() {
    for (int i = 0; i < count; i++)
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
}

void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("Found: ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. View Books\n3. Search Book\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) addBook();
        else if (choice == 2) viewBooks();
        else if (choice == 3) searchBook();
        else if (choice == 4) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}

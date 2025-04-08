import java.util.Scanner;

class Library {
    private java.util.ArrayList<String> books = new java.util.ArrayList<>();
    static int totalBooks = 0;
    final String LIBRARY_NAME = "MyLibrary";
    static final int MAX_BOOKS = 100;

    void addBook(String title) {
        if (totalBooks < MAX_BOOKS) {
            books.add(title);
            totalBooks++;
        } else {
            System.out.println("Library is full!");
        }
    }

    void addBook(String[] titles) {
        for (String title : titles) {
            addBook(title);
        }
    }

    void removeBook(String title) {
        if (books.remove(title)) {
            totalBooks--;
        } else {
            System.out.println("Book not found!");
        }
    }

    boolean searchBook(String title) {
        return searchBookRecursive(title, 0);
    }

    private boolean searchBookRecursive(String title, int index) {
        if (index >= books.size()) return false;
        if (books.get(index).equals(title)) return true;
        return searchBookRecursive(title, index + 1);
    }

    void displayBooks() {
        if (books.isEmpty()) {
            System.out.println("No books in the library.");
        } else {
            System.out.println("Books in " + LIBRARY_NAME + ": " + books);
        }
    }

    class Book {
        String title, author;
        int year;

        Book(String title, String author, int year) {
            this.title = title;
            this.author = author;
            this.year = year;
        }

        void displayDetails() {
            System.out.println("Title: " + title + ", Author: " + author + ", Year: " + year);
        }
    }
}

public class Library_Management {
    public static void main(String[] args) {
        Library myLibrary = new Library();
        Scanner scanner = new Scanner(System.in);

        boolean exit = false;
        while (!exit) {
            System.out.println("\nLibrary Management System");
            System.out.println("1. Add a Book");
            System.out.println("2. Add Multiple Books");
            System.out.println("3. Remove a Book");
            System.out.println("4. Search for a Book");
            System.out.println("5. Display All Books");
            System.out.println("6. Create and Display Book Details");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter the title of the book to add: ");
                    String title = scanner.nextLine();
                    myLibrary.addBook(title);
                    break;
                case 2:
                    System.out.print("Enter the titles of the books to add (comma-separated): ");
                    String[] titles = scanner.nextLine().split(",");
                    myLibrary.addBook(titles);
                    break;
                case 3:
                    System.out.print("Enter the title of the book to remove: ");
                    String removeTitle = scanner.nextLine();
                    myLibrary.removeBook(removeTitle);
                    break;
                case 4:
                    System.out.print("Enter the title of the book to search for: ");
                    String searchTitle = scanner.nextLine();
                    boolean found = myLibrary.searchBook(searchTitle);
                    System.out.println("Book found: " + found);
                    break;
                case 5:
                    myLibrary.displayBooks();
                    break;
                case 6:
                    System.out.print("Enter the title of the book: ");
                    String bookTitle = scanner.nextLine();
                    System.out.print("Enter the author of the book: ");
                    String author = scanner.nextLine();
                    System.out.print("Enter the publication year of the book: ");
                    int year = scanner.nextInt();
                    Library.Book book = myLibrary.new Book(bookTitle, author, year);
                    book.displayDetails();
                    break;
                case 7:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }

        scanner.close();
        System.out.println("Library management system exited.");
    }
}
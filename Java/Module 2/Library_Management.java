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

        myLibrary.addBook("The Great Gatsby");
        myLibrary.addBook(new String[]{"1984", "To Kill a Mockingbird", "Harry Potter"});

        myLibrary.displayBooks();

        myLibrary.removeBook("1984");
        myLibrary.displayBooks();

        System.out.println("Searching for 'Harry Potter': " + myLibrary.searchBook("Harry Potter"));
        System.out.println("Searching for 'The Catcher in the Rye': " + myLibrary.searchBook("The Catcher in the Rye"));

        Library.Book book1 = myLibrary.new Book("Pride and Prejudice", "Jane Austen", 1813);
        book1.displayDetails();

        System.out.println("Total books in library: " + Library.totalBooks);
    }
}

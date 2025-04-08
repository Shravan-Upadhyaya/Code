import java.util.ArrayList;
import java.util.Scanner;
class Book 
{
    private String title;
    private String author;
    private boolean Available;

    public Book(String title, String author) 
    {
        this.title = title;
        this.author = author;
        this.Available = true;
    }

    public String getTitle() 
    {
        return title;
    }

    public String getAuthor() 
    {
        return author;
    }

    public boolean Available() 
    {
        return Available;
    }

    public void borrow() 
    {
        if (Available) {
            Available = false;
        } else {
            System.out.println("This book is already borrowed.");
        }
    }

    public void returnbook() 
    {
        Available = true;
    }
    
    public String toString() 
    {
        return "Title: " + title + ", Author: " + author + ", Available: " + (Available ? "Yes" : "No");
    }
}
class Library 
{
    private ArrayList<Book> books;

    public Library() 
    {
        books = new ArrayList<>();
    }

    public void addBook(String title, String author) 
    {
        books.add(new Book(title, author));
        System.out.println("Book added successfully.");
    }

    public void displayAvailableBooks() 
    {
        System.out.println("Available Books:");
        for (Book book : books) 
        {
            if (book.Available()) 
            {
                System.out.println(book);
            }
        }
    }

    public void borrow(String title) 
    {
        for (Book book : books) 
        {
            if (book.getTitle().equalsIgnoreCase(title)) 
            {
                if (book.Available()) 
                {
                    book.borrow();
                    System.out.println("You have successfully borrowed the book: " + title);
                } else 
                {
                    System.out.println("Sorry, the book is currently unavailable.");
                }
                return;
            }
        }
        System.out.println("Book not found in the library.");
    }

    public void returnbook(String title) 
    {
        for (Book book : books) 
        {
            if (book.getTitle().equalsIgnoreCase(title)) 
            {
                if (!book.Available()) 
                {
                    book.returnbook();
                    System.out.println("You have successfully returned the book: " + title);
                } else 
                {
                    System.out.println("This book was not borrowed.");
                }
                return;
            }
        }
        System.out.println("Book not found in the library.");
    }
}

public class Q10 
{
    public static void main(String[] args) 
    {
        Library library = new Library();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do 
        {
            System.out.println("\nLibrary Menu:");
            System.out.println("1. Add a book");
            System.out.println("2. Display available books");
            System.out.println("3. Borrow a book");
            System.out.println("4. Return a book");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) 
            {
                case 1:
                    System.out.print("Enter book title: ");
                    String title = scanner.nextLine();
                    System.out.print("Enter book author: ");
                    String author = scanner.nextLine();
                    library.addBook(title, author);
                    break;
                case 2:
                    library.displayAvailableBooks();
                    break;
                case 3:
                    System.out.print("Enter the title of the book to borrow: ");
                    String borrowTitle = scanner.nextLine();
                    library.borrow(borrowTitle);
                    break;
                case 4:
                    System.out.print("Enter the title of the book to return: ");
                    String returnTitle = scanner.nextLine();
                    library.returnbook(returnTitle);
                    break;
                case 5:
                    System.out.println("Exiting the Library System. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);

        scanner.close();
    }
}

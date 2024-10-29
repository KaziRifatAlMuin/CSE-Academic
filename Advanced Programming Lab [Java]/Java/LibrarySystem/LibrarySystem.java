import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

// Abstract class representing a Book
abstract class Book {
    protected String title;
    protected String author;
    protected String isbn;

    // Constructor to initialize book details
    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }

    // Abstract method for book information
    public abstract void getInfo();

    // Getter for ISBN
    public String getIsbn() {
        return isbn;
    }
}

// Subclass representing a Novel, extending Book
class Novel extends Book {
    public Novel(String title, String author, String isbn) {
        super(title, author, isbn);
    }

    // Implementing getInfo() for a Novel
    @Override
    public void getInfo() {
        System.out.println("Novel - Title: " + title + ", Author: " + author + ", ISBN: " + isbn);
    }
}

// Subclass representing a Textbook, extending Book
class Textbook extends Book {
    public Textbook(String title, String author, String isbn) {
        super(title, author, isbn);
    }

    // Implementing getInfo() for a Textbook
    @Override
    public void getInfo() {
        System.out.println("Textbook - Title: " + title + ", Author: " + author + ", ISBN: " + isbn);
    }
}

// Interface defining operations for the Library
interface LibraryOperations {
    void borrowBook(String isbn);

    void returnBook(String isbn);

    void addBook(Book book);
}

// Library class implementing LibraryOperations
class Library implements LibraryOperations {
    private final Map<String, Book> books = new HashMap<>(); // Stores books by ISBN
    private final String fileName = "books.txt"; // File for storing book records

    public Library() {
        loadBooks(); // Load books from file on initialization
    }

    // Synchronized method to borrow a book
    @Override
    public synchronized void borrowBook(String isbn) {
        if (books.containsKey(isbn)) {
            Book book = books.remove(isbn); // Remove book from collection
            System.out.println(Thread.currentThread().getName() + " borrowed: ");
            book.getInfo();
            saveBooks(); // Save updated book list to file
        } else {
            System.out.println(Thread.currentThread().getName() + ": Book not available.");
        }
    }

    // Synchronized method to return a book
    @Override
    public synchronized void returnBook(String isbn) {
        Book book = new Novel("Returned Book", "Anonymous", isbn); // Placeholder for the returned book
        books.put(isbn, book); // Add book back to collection
        System.out.println(Thread.currentThread().getName() + " returned: ");
        book.getInfo();
        saveBooks(); // Save updated book list to file
    }

    // Synchronized method to add a new book
    @Override
    public synchronized void addBook(Book book) {
        books.put(book.getIsbn(), book); // Add book to collection
        System.out.println(Thread.currentThread().getName() + " added: ");
        book.getInfo();
        saveBooks(); // Save updated book list to file
    }

    // Load books from file on library initialization
    private void loadBooks() {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] details = line.split(",");
                Book book = new Novel(details[0], details[1], details[2]); // Creates a Novel by default
                books.put(details[2], book);
            }
        } catch (IOException e) {
            System.out.println("Error loading books: " + e.getMessage());
        }
    }

    // Save books to file after each modification
    private void saveBooks() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (Book book : books.values()) {
                writer.write(book.title + "," + book.author + "," + book.isbn + "\n");
            }
        } catch (IOException e) {
            System.out.println("Error saving books: " + e.getMessage());
        }
    }
}

// UserThread representing a user performing operations
class UserThread extends Thread {
    private final Library library;

    public UserThread(Library library, String name) {
        super(name);
        this.library = library;
    }

    // Run method to perform random actions on the library
    @Override
    public void run() {
        Random random = new Random();
        int action = random.nextInt(3); // 0 - borrow, 1 - return, 2 - add
        String sampleIsbn = "12345"; // Sample ISBN for simplicity

        switch (action) {
            case 0:
                library.borrowBook(sampleIsbn); // Try borrowing a book
            case 1:
                library.returnBook(sampleIsbn); // Try returning a book
            case 2:
                library.addBook(new Textbook("New Textbook", "Author Name", sampleIsbn)); // Add a new book
        }
    }
}

// Main class to start the library system
public class LibrarySystem {
    /**
     * @param args
     */
    public static void main(String[] args) {
        Library library = new Library();

        // Create multiple user threads simulating different users
        UserThread user1 = new UserThread(library, "User1");
        UserThread user2 = new UserThread(library, "User2");
        UserThread user3 = new UserThread(library, "User3");

        // Start the threads to perform library operations concurrently
        user1.start();
        user2.start();
        user3.start();
    }

    @Override
    public String toString() {
        return "LibrarySystem []";
    }
}
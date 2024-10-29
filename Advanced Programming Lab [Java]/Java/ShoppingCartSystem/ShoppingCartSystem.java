import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

// Abstract class for Product
abstract class Product {
    protected String name;
    protected double price;
    protected String productId;

    // Constructor
    public Product(String name, double price, String productId) {
        this.name = name;
        this.price = price;
        this.productId = productId;
    }

    // Abstract method for displaying product info
    public abstract void displayInfo();

    // Getter for productId
    public String getProductId() {
        return productId;
    }
}

// Electronics product class
class Electronics extends Product {
    public Electronics(String name, double price, String productId) {
        super(name, price, productId);
    }

    @Override
    public void displayInfo() {
        System.out.println("Electronics - " + name + ": $" + price + " (ID: " + productId + ")");
    }
}

// Clothing product class
class Clothing extends Product {
    public Clothing(String name, double price, String productId) {
        super(name, price, productId);
    }

    @Override
    public void displayInfo() {
        System.out.println("Clothing - " + name + ": $" + price + " (ID: " + productId + ")");
    }
}

// Grocery product class
class Grocery extends Product {
    public Grocery(String name, double price, String productId) {
        super(name, price, productId);
    }

    @Override
    public void displayInfo() {
        System.out.println("Grocery - " + name + ": $" + price + " (ID: " + productId + ")");
    }
}

// Interface for Cart operations
interface CartOperations {
    void addItem(Product product);

    void removeItem(String productId);

    void viewCart();
}

// Cart class implementing CartOperations
class Cart implements CartOperations {
    private final Map<String, Product> items = new HashMap<>();
    private final String cartFile = "cart.txt";

    public Cart() {
        loadCart(); // Load items from file
    }

    // Synchronized method to add item to cart
    @Override
    public synchronized void addItem(Product product) {
        items.put(product.getProductId(), product);
        System.out.println(Thread.currentThread().getName() + " added: " + product.name);
        saveCart();
    }

    // Synchronized method to remove item from cart
    @Override
    public synchronized void removeItem(String productId) {
        if (items.containsKey(productId)) {
            Product product = items.remove(productId);
            System.out.println(Thread.currentThread().getName() + " removed: " + product.name);
            saveCart();
        } else {
            System.out.println(Thread.currentThread().getName() + ": Item not found.");
        }
    }

    // View items in the cart
    @Override
    public synchronized void viewCart() {
        System.out.println("Cart Contents:");
        for (Product product : items.values()) {
            product.displayInfo();
        }
    }

    // Load items from file
    /**
     * 
     */
    private void loadCart() {
        try (BufferedReader reader = new BufferedReader(new FileReader(cartFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] details = line.split(",");
                final Product product;
                switch (details[0]) {
                    case "Electronics":
                        product = new Electronics(details[1], Double.parseDouble(details[2]), details[3]);
                        break;
                    case "Clothing":
                        product = new Clothing(details[1], Double.parseDouble(details[2]), details[3]);
                        break;
                    default:
                        product = new Grocery(details[1], Double.parseDouble(details[2]), details[3]);
                        break;
                }
                items.put(details[3], product);
            }
        } catch (IOException e) {
            System.out.println("Error loading cart: " + e.getMessage());
        }
    }

    // Save items to file
    private void saveCart() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(cartFile))) {
            for (Product product : items.values()) {
                writer.write(product.getClass().getSimpleName() + "," + product.name + "," + product.price + ","
                        + product.productId + "\n");
            }
        } catch (IOException e) {
            System.out.println("Error saving cart: " + e.getMessage());
        }
    }
}

// UserThread simulating user interactions with the cart
class UserThread extends Thread {
    private final Cart cart;

    public UserThread(Cart cart, String name) {
        super(name);
        this.cart = cart;
    }

    // Run method for thread actions
    @Override
    public void run() {
        Random random = new Random();
        int action = random.nextInt(3); // 0 - add, 1 - remove, 2 - view
        String sampleId = "P123"; // Sample product ID for simplicity

        switch (action) {
            case 0:
                cart.addItem(new Electronics("Laptop", 999.99, sampleId)); // Add item
            case 1:
                cart.removeItem(sampleId); // Remove item
            case 2:
                cart.viewCart(); // View cart
        }
    }
}

// Main class to test the cart system
public class ShoppingCartSystem {
    public static void main(String[] args) {
        Cart cart = new Cart();

        // Create and start user threads
        UserThread user1 = new UserThread(cart, "User1");
        UserThread user2 = new UserThread(cart, "User2");
        UserThread user3 = new UserThread(cart, "User3");

        user1.start();
        user2.start();
        user3.start();
    }
}
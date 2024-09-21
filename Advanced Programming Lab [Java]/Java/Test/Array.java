import java.util.Scanner;

public class Array {
    public static void main(String[] args) {
        // Input Array
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter 5 numbers: ");
        int[] numbers = new int[5];
        for (int i = 0; i < 5; i++) {
            numbers[i] = scanner.nextInt();
        }
        // Output Sum
        int sum = 0;
        for (int number : numbers) {
            sum += number;
        }
        System.out.println("Sum: " + sum);
        scanner.close();
    }
}

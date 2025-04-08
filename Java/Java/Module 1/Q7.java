import java.util.Scanner;

public class Q7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] numbers = new int[10];

        System.out.println("Enter 10 integers:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print("Enter number " + (i + 1) + ": ");
            numbers[i] = scanner.nextInt();
        }

        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }

        int largest = numbers[0];
        int smallest = numbers[0];
        for (int num : numbers) {
            if (num > largest) {
                largest = num;
            }
            if (num < smallest) {
                smallest = num;
            }
        }

        System.out.println("\nResults:");
        System.out.println("Sum of all elements: " + sum);
        System.out.println("Largest value: " + largest);
        System.out.println("Smallest value: " + smallest);

        scanner.close();
    }
}
import java.util.Scanner;

public class Q3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        double number1 = scanner.nextDouble();
        System.out.print("Enter the second number: ");
        double number2 = scanner.nextDouble();

        double addition = number1 + number2;
        double subtraction = number1 - number2;
        double multiplication = number1 * number2;
        double division = (number2 != 0) ? number1 / number2 : Double.NaN;

        boolean isLessThan = number1 < number2;
        boolean isGreaterThan = number1 > number2;
        boolean isEqual = number1 == number2;

        System.out.println("\nResults:");
        System.out.println("Addition: " + addition);
        System.out.println("Subtraction: " + subtraction);
        System.out.println("Multiplication: " + multiplication);
        System.out.println("Division: " + (number2 != 0 ? division : "Undefined (division by zero)"));

        System.out.println("\nComparisons:");
        System.out.println("Is the first number less than the second? " + isLessThan);
        System.out.println("Is the first number greater than the second? " + isGreaterThan);
        System.out.println("Are both numbers equal? " + isEqual);

        scanner.close();
    }
}

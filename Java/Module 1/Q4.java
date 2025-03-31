import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number (a): ");
        int a = scanner.nextInt();
        System.out.print("Enter the second number (b): ");
        int b = scanner.nextInt();
        System.out.print("Enter the third number (c): ");
        int c = scanner.nextInt();

        boolean logicalAnd = (a > b && b < c);
        boolean logicalOr = (a == b || b != c);

        int bitwiseAnd = a & b;
        int bitwiseOr = a | b;
        int bitwiseXor = a ^ b;
        int bitwiseNotA = ~a;

        System.out.println("\nLogical Expressions:");
        System.out.println("(a > b && b < c): " + logicalAnd);
        System.out.println("(a == b || b != c): " + logicalOr);

        System.out.println("\nBitwise Operations:");
        System.out.println("a & b: " + bitwiseAnd);
        System.out.println("a | b: " + bitwiseOr);
        System.out.println("a ^ b: " + bitwiseXor);
        System.out.println("~a: " + bitwiseNotA);

        scanner.close();
    }
}